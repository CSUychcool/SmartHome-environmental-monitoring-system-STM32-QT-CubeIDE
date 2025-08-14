#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
#include<QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <deepseekapi.h>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , mMaxDataCount(30)
{
    ui->setupUi(this);

    // 初始化光照进度条范围（0-1000 lux）
    ui->progressBar_lux->setRange(0, 1000);
    ui->progressBar_lux->setTextVisible(false); // 隐藏默认百分比文字（可选，根据需求）

    // ========== 初始化温度折线图 ==========
    // 1. 创建温度折线系列（设置样式：科技蓝，线宽2px）
    mTempSeries = new QSplineSeries();
    mTempSeries->setName("温度 (℃)");
    mTempSeries->setPen(QPen(QColor("#165DFF"), 2));  // 与美化风格统一的科技蓝

    // 2. 创建图表并添加系列
    mChart = new QChart();
    mChart->addSeries(mTempSeries);
    mChart->setTitle("温度实时趋势");  // 图表标题
    mChart->setTitleFont(QFont("Inter", 12, QFont::Medium));  // 标题字体
    mChart->legend()->setAlignment(Qt::AlignBottom);  // 图例在底部
    mChart->setBackgroundVisible(false);  // 透明背景（与卡片融合）
    // 调整图表边距（缩小上下左右边距，扩大绘图区域）
    mChart->setMargins(QMargins(5, 5, 5, 5)); // 边距设为5像素（默认更大，会留白）

    // 3. 配置X轴（时间轴）
    mAxisX = new QDateTimeAxis();
    mAxisX->setFormat("HH:mm:ss");  // 时间格式（时:分:秒）
    mAxisX->setTitleText("时间");
    mAxisX->setTitleFont(QFont("Inter", 10));
    mChart->addAxis(mAxisX, Qt::AlignBottom);  // X轴在底部
    mTempSeries->attachAxis(mAxisX);  // 折线绑定X轴

    // 4. 配置Y轴（温度值，范围根据实际传感器调整，这里设0-50℃）
    mAxisY = new QValueAxis();
    mAxisY->setRange(15, 40);
    mAxisY->setTitleText("温度 (℃)");
    mAxisY->setTitleFont(QFont("Inter", 10));
    mAxisY->setTickCount(5);  // 刻度：0/10/20/30/40/50
    mChart->addAxis(mAxisY, Qt::AlignLeft);  // Y轴在左侧
    mTempSeries->attachAxis(mAxisY);  // 折线绑定Y轴

    // 5. 关联UI中的chartView
    ui->ChartView_wendu->setChart(mChart);
    ui->ChartView_wendu->setRenderHint(QPainter::Antialiasing);  // 抗锯齿
    // 设置图表容器样式（与圆角卡片融合）
    ui->ChartView_wendu->setStyleSheet(R"(
        background-color: white;
        border-radius: 12px;
        padding: 10px;
    )");


    // ========== 光照图表（新增） ==========
    mLuxSeries = new QLineSeries();
    mLuxSeries->setName("光照 (lux)");
    mLuxSeries->setPen(QPen(QColor("#FF7D00"), 2)); // 橙色（区分温度）

    mLuxChart = new QChart();
    mLuxChart->addSeries(mLuxSeries);
    mLuxChart->setTitle("光照强度实时趋势");
    mLuxChart->setTitleFont(QFont("Inter", 12, QFont::Medium));
    mLuxChart->legend()->setAlignment(Qt::AlignBottom);
    mLuxChart->setBackgroundVisible(false);
    mLuxChart->setMargins(QMargins(5, 5, 5, 5));

    mLuxAxisX = new QDateTimeAxis();
    mLuxAxisX->setFormat("HH:mm:ss");
    mLuxAxisX->setTitleText("时间");
    mLuxAxisX->setTitleFont(QFont("Inter", 10));
    mLuxChart->addAxis(mLuxAxisX, Qt::AlignBottom);
    mLuxSeries->attachAxis(mLuxAxisX);

    mLuxAxisY = new QValueAxis();
    mLuxAxisY->setRange(0, 1000); // 光照范围0-1000lux（根据传感器调整）
    mLuxAxisY->setTitleText("光照 (lux)");
    mLuxAxisY->setTitleFont(QFont("Inter", 10));
    mLuxAxisY->setTickCount(5);
    mLuxChart->addAxis(mLuxAxisY, Qt::AlignLeft);
    mLuxSeries->attachAxis(mLuxAxisY);

    ui->ChartView_guangzhao->setChart(mLuxChart); // 关联UI中的光照图表
    ui->ChartView_guangzhao->setRenderHint(QPainter::Antialiasing);
    ui->ChartView_guangzhao->setStyleSheet(R"(
        background-color: white;
        border-radius: 12px;
        padding: 10px;
    )");


    // ========== CO浓度图表（新增） ==========
    mCoSeries = new QLineSeries();
    mCoSeries->setName("CO浓度 (ppm)");
    mCoSeries->setPen(QPen(QColor("#F53F3F"), 2)); // 红色（区分温度/光照）

    mCoChart = new QChart();
    mCoChart->addSeries(mCoSeries);
    mCoChart->setTitle("CO浓度实时趋势");
    mCoChart->setTitleFont(QFont("Inter", 12, QFont::Medium));
    mCoChart->legend()->setAlignment(Qt::AlignBottom);
    mCoChart->setBackgroundVisible(false);
    mCoChart->setMargins(QMargins(5, 5, 5, 5));

    mCoAxisX = new QDateTimeAxis();
    mCoAxisX->setFormat("HH:mm:ss");
    mCoAxisX->setTitleText("时间");
    mCoAxisX->setTitleFont(QFont("Inter", 10));
    mCoChart->addAxis(mCoAxisX, Qt::AlignBottom);
    mCoSeries->attachAxis(mCoAxisX);

    mCoAxisY = new QValueAxis();
    mCoAxisY->setRange(0, 10); // CO浓度范围0-10ppm（根据传感器调整）
    mCoAxisY->setTitleText("CO浓度 (ppm)");
    mCoAxisY->setTitleFont(QFont("Inter", 10));
    mCoAxisY->setTickCount(5);
    mCoChart->addAxis(mCoAxisY, Qt::AlignLeft);
    mCoSeries->attachAxis(mCoAxisY);

    ui->ChartView_CO->setChart(mCoChart); // 关联UI中的CO图表
    ui->ChartView_CO->setRenderHint(QPainter::Antialiasing);
    ui->ChartView_CO->setStyleSheet(R"(
        background-color: white;
        border-radius: 12px;
        padding: 10px;
    )");


    m_deepseek=new deepseekapi(this);
    m_deepseek->Set_apikey("你的deepseekapi接口密匙");
    QObject::connect(m_deepseek,&deepseekapi::requestFinished,[this](const QString &response){
        ui->textEdit_dpseekre->append(response);
    });


    Myport=new QSerialPort(this);
    QList<QSerialPortInfo> Allports= QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo portinfo:Allports){
        qDebug()<<portinfo.portName();
    }

    Myport->setPortName("ttyUSB0");
    Myport->setBaudRate(QSerialPort::Baud115200);
    Myport->setFlowControl(QSerialPort::NoFlowControl);
    Myport->setParity(QSerialPort::NoParity);
    Myport->setDataBits(QSerialPort::Data8);
    Myport->setStopBits(QSerialPort::OneStop);

    if(Myport->isOpen())
        Myport->close();

    if (!Myport->open(QIODeviceBase::ReadWrite)) {
        qDebug() << "串口打开失败：" << Myport->errorString();
    } else {
        qDebug() << "串口打开成功";
    }

    // 增加错误处理连接
    connect(Myport, &QSerialPort::errorOccurred, this, [=](QSerialPort::SerialPortError error) {
        if (error != QSerialPort::NoError) {
            qDebug() << "串口错误：" << Myport->errorString();
        }
    });

    // 数据接收保持不变，但可以根据需要处理
    connect(Myport,&QSerialPort::readyRead,this,&Widget::onReadyRead);

    MyTimer=new QTimer(this);
    MyTimer->setInterval(1000);
    connect(MyTimer,&QTimer::timeout,this,&Widget::onUpdateClo);
    MyTimer->start();
    manger=new QNetworkAccessManager(this);
    strUrl="http://v1.yiketianqi.com/free/day?appid=92677139&appsecret=BqiLX4zQ&city=长沙&unescape=1";
    QUrl Urltianqi(strUrl);
    QNetworkRequest res(Urltianqi);
    reply=manger->get(res);
    connect(manger,&QNetworkAccessManager::finished,this,&Widget::onreadhttpdata);

    onUpdateClo();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::parseJson(const QByteArray &jsonData)
{
    // 跳过空数据（避免空行）
    if (jsonData.isEmpty()) return;

    // 解析JSON
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &error);

    // 检查解析错误
    if (error.error != QJsonParseError::NoError) {
        qDebug() << "JSON解析失败：" << error.errorString()
            << "，原始数据：" << QString(jsonData);
        return;
    }

    // 提取JSON对象
    QJsonObject obj = doc.object();

    // 4. 提取字段（根据实际键名匹配，注意大小写）
    co = obj["co"].toDouble();       // co是浮点型
    temp = obj["temp"].toDouble();   // temp是浮点型
    lux = obj["lux"].toInt();          // lux是整数

    // 5. 处理解析结果
    // CO浓度（浮点数，保留1位小数）
    ui->label_CO->setText(QString("CO浓度：%1 ppm").arg(co, 0, 'f', 1));
    // 温度（浮点数，保留1位小数）
    ui->label_wendu->setText(QString("温度：%1 ℃").arg(temp, 0, 'f', 1));
    // 光照（整数）
    ui->label_lux->setText(QString("光照：%1 lux").arg(lux));

    // ========== 新增：添加温度数据到折线图 ==========
    // 获取当前时间（作为X轴坐标）
    qint64 currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
    qDebug() << "[Debug] Append to series: time=" << currentTime
             << ", temp=" << temp;
    // 添加新数据点（时间戳，温度值）
    mTempSeries->append(currentTime, temp);

    qDebug() << "[Debug] Series count after append:" << mTempSeries->count();

    // 限制数据点数量（只保留最近mMaxDataCount个点）
    if (mTempSeries->count() > mMaxDataCount) {
        mTempSeries->remove(0);  // 删除最早的点
    }

    // 更新X轴范围（始终显示最新的30个点的时间范围）
    if (mTempSeries->count() > 0) {
        // 获取最早和最新的时间戳
        qint64 minTime = mTempSeries->at(0).x();
        qint64 maxTime = mTempSeries->at(mTempSeries->count() - 1).x();
        // 扩展X轴范围（前后各加1秒，避免数据贴边）
        mAxisX->setRange(
            QDateTime::fromMSecsSinceEpoch(minTime - 1000),
            QDateTime::fromMSecsSinceEpoch(maxTime + 1000)
            );
    }

    // ========== 光照数据追加（新增） ==========
    mLuxSeries->append(currentTime, lux);
    if (mLuxSeries->count() > mMaxDataCount) mLuxSeries->remove(0);
    if (mLuxSeries->count() > 0) {
        qint64 minL = mLuxSeries->at(0).x(), maxL = mLuxSeries->at(mLuxSeries->count()-1).x();
        mLuxAxisX->setRange(QDateTime::fromMSecsSinceEpoch(minL-1000), QDateTime::fromMSecsSinceEpoch(maxL+1000));
    }


    // ========== CO浓度数据追加（新增） ==========
    mCoSeries->append(currentTime, co);
    if (mCoSeries->count() > mMaxDataCount) mCoSeries->remove(0);
    if (mCoSeries->count() > 0) {
        qint64 minC = mCoSeries->at(0).x(), maxC = mCoSeries->at(mCoSeries->count()-1).x();
        mCoAxisX->setRange(QDateTime::fromMSecsSinceEpoch(minC-1000), QDateTime::fromMSecsSinceEpoch(maxC+1000));
    }

    // 光照进度条更新
    ui->progressBar_lux->setValue(lux);

    qDebug() << "解析结果：";
    qDebug() << "CO浓度：" << co << "ppm";
    qDebug() << "温度：" << temp << "℃";
    qDebug() << "光照：" << lux << "lux";
    qDebug() << "-------------------";
}

void Widget::updateNavButtonsChecked(int currentPageIndex)
{
    ui->pushButton_shouye->setCheckable(false);
    ui->pushButton_wenshidu->setChecked(false);
    ui->pushButton_CO->setChecked(false);
    ui->pushButton_guangzhao->setChecked(false);
    ui->pushButton_aizhushou->setChecked(false);

    // 2. 根据当前页面索引，激活对应按钮
    switch (currentPageIndex) {
    case 0: // 首页
        ui->pushButton_shouye->setChecked(true);
        break;
    case 1: // 温湿度
        ui->pushButton_wenshidu->setChecked(true);
        break;
    case 2: // CO浓度
        ui->pushButton_CO->setChecked(true);
        break;
    case 3: // 光照强度
        ui->pushButton_guangzhao->setChecked(true);
        break;
    case 4: // AI助手
        ui->pushButton_aizhushou->setChecked(true);
        break;
    default:
        break;
    }
}

void Widget::onreadhttpdata(QNetworkReply *reply)
{
    int rescode=reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if(reply->error()==QNetworkReply::NoError&&rescode==200){
        QByteArray bytearray=reply->readAll();
        //qDebug() << QString::fromUtf8(bytearray);
        JieXiJson(bytearray);
    }
}



void Widget::onUpdateClo()
{
    QDateTime currentime= QDateTime::currentDateTime();
    QString goaltime=currentime.toString("HH:mm:ss");
    ui->lcdNumber->display(goaltime);
}

void Widget::JieXiJson(QByteArray bytearray)
{
    QJsonDocument JsonDoc=QJsonDocument::fromJson(bytearray);
    if(!JsonDoc.isNull()&&JsonDoc.isObject()){
        QJsonObject JsonObj=JsonDoc.object();
        QString city=JsonObj["city"].toString();
        QString date=JsonObj["date"].toString();
        QString week=JsonObj["week"].toString();
        QString wea=JsonObj["wea"].toString();
        QString tem=JsonObj["tem"].toString();
        QString humidity=JsonObj["humidity"].toString();
        ui->label_city->setText(city);
        ui->label_date->setText(date);
        ui->label_hum->setText(QString("湿度:%1").arg(humidity));
        ui->label_tem->setText(QString("温度:%1").arg(tem));
        ui->label_wea->setText(wea);
        ui->label_week->setText(week);
        qDebug()<<city<<date<<week<<wea<<tem<<humidity;
    }
}




void Widget::on_pushButton_shouye_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    updateNavButtonsChecked(0);
}


void Widget::on_pushButton_wenshidu_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    updateNavButtonsChecked(1);
}


void Widget::on_pushButton_CO_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    updateNavButtonsChecked(2);
}


void Widget::on_pushButton_guangzhao_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    updateNavButtonsChecked(3);
}


//实现串口接收与解析的槽函数
void Widget::onReadyRead()
{
    // 1. 读取串口数据并追加到缓冲区
    recvBuffer += Myport->readAll();

    // 2. 按"\n"分割缓冲区，提取完整行（每个JSON以\n结尾）
    int endIndex = recvBuffer.indexOf('\n');  // 查找换行符
    while (endIndex != -1) {
        // 提取一行完整数据（不包含最后的\n）
        QByteArray jsonData = recvBuffer.left(endIndex);
        // 移除已处理的数据（包括\n）
        recvBuffer.remove(0, endIndex + 1);

        // 3. 解析JSON
        parseJson(jsonData);

        // 继续查找下一个换行符
        endIndex = recvBuffer.indexOf('\n');
    }
}


void Widget::on_pushButton_clicked()
{
    QByteArray SendData;
    SendData.append(1);
    qint64 bytesWritten = Myport->write(SendData); // 获取实际发送字节数
    Myport->flush();
    if (bytesWritten == -1) {
        qDebug() << "亮灯指令发送失败：" << Myport->errorString();
    } else {
        qDebug() << "亮灯指令发送成功，字节数：" << bytesWritten;
    }
}


void Widget::on_pushButton_2_clicked()
{
    QByteArray SendData;
    SendData.append(5);
    qint64 bytesWritten = Myport->write(SendData); // 获取实际发送字节数
    Myport->flush();
    if (bytesWritten == -1) {
        qDebug() << "亮灯指令发送失败：" << Myport->errorString();
    } else {
        qDebug() << "亮灯指令发送成功，字节数：" << bytesWritten;
    }
}

void Widget::on_pushButton_dsChatRe_clicked()
{
    m_deepseek->SendChatRequest(ui->lineEdit_deseekse->text());
    ui->lineEdit_deseekse->clear();
}



void Widget::on_pushButton_aizhushou_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    updateNavButtonsChecked(4);
}


