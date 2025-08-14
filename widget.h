#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <deepseekapi.h>
#include <QSerialPort>
#include <QtCharts>
#include <QChartView>
#include <QSplineSeries>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void parseJson(const QByteArray &jsonData);

    void updateNavButtonsChecked(int currentPageIndex);


public slots:
    void onreadhttpdata(QNetworkReply *reply);

private slots:

    void onUpdateClo();

    void on_pushButton_shouye_clicked();

    void on_pushButton_wenshidu_clicked();

    void on_pushButton_CO_clicked();

    void on_pushButton_guangzhao_clicked();

    void onReadyRead();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_dsChatRe_clicked();

    void on_pushButton_aizhushou_clicked();

private:
    void JieXiJson(QByteArray bytearray);
    QTimer *MyTimer;
    QNetworkAccessManager *manger;
    QNetworkReply *reply;
    QString strUrl;
    Ui::Widget *ui;
     deepseekapi *m_deepseek;
    QSerialPort *Myport;
    QByteArray recvBuffer;
     QChart *mChart;
    float co;
    float temp ;
    int lux ;
    QLineSeries *mTempSeries;       // 温度折线系列
    QDateTimeAxis *mAxisX;          // X轴（时间轴）
    QValueAxis *mAxisY;             // Y轴（温度值）

    // 光照相关（新增）
    QLineSeries *mLuxSeries;
    QChart *mLuxChart;
    QDateTimeAxis *mLuxAxisX;
    QValueAxis *mLuxAxisY;

    // CO浓度相关（新增）
    QLineSeries *mCoSeries;
    QChart *mCoChart;
    QDateTimeAxis *mCoAxisX;
    QValueAxis *mCoAxisY;

    int mMaxDataCount;              // 最大数据点数量（避免图表拥挤）
};
#endif // WIDGET_H
