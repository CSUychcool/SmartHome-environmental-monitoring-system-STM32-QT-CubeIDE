/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QFrame *frame_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_shouye;
    QPushButton *pushButton_wenshidu;
    QPushButton *pushButton_CO;
    QPushButton *pushButton_guangzhao;
    QPushButton *pushButton_aizhushou;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QWidget *widget_2;
    QFrame *frame_3;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_shouye_2;
    QPushButton *pushButton_wenshidu_2;
    QPushButton *pushButton_CO_2;
    QPushButton *pushButton_guangzhao_3;
    QPushButton *pushButton_guangzhao_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QLCDNumber *lcdNumber;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QFrame *frame_4;
    QGridLayout *gridLayout;
    QLabel *label_week;
    QLabel *label_date;
    QLabel *label_city;
    QFrame *frame_5;
    QGridLayout *gridLayout_4;
    QLabel *label_wea;
    QLabel *label_tem;
    QLabel *label_hum;
    QWidget *page_2;
    QLabel *label;
    QFrame *frame_6;
    QGridLayout *gridLayout_5;
    QLabel *label_wendu;
    QChartView *ChartView_wendu;
    QWidget *page_3;
    QLabel *label_CO;
    QLabel *label_2;
    QChartView *ChartView_CO;
    QWidget *page_4;
    QLabel *label_lux;
    QLabel *label_3;
    QProgressBar *progressBar_lux;
    QChartView *ChartView_guangzhao;
    QWidget *page_5;
    QLineEdit *lineEdit_deseekse;
    QTextEdit *textEdit_dpseekre;
    QPushButton *pushButton_dsChatRe;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(587, 542);
        Widget->setStyleSheet(QString::fromUtf8("background-color: #F5F7FA; "));
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName("gridLayout_2");
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        frame_2 = new QFrame(widget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(20, 440, 511, 50));
        frame_2->setStyleSheet(QString::fromUtf8(" background-color: white; /* \345\215\241\347\211\207\347\272\257\347\231\275\350\203\214\346\231\257 */\n"
"    border-radius: 12px;    /* \345\234\206\350\247\222\345\215\212\345\276\204\357\274\214\350\247\206\350\247\211\346\233\264\346\237\224\345\222\214 */\n"
"    border: none;           /* \351\232\220\350\227\217\351\273\230\350\256\244\350\276\271\346\241\206 */"));
        layoutWidget = new QWidget(frame_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(31, 10, 461, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_shouye = new QPushButton(layoutWidget);
        pushButton_shouye->setObjectName("pushButton_shouye");
        pushButton_shouye->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F2F3F5; /* \346\265\205\347\201\260\350\203\214\346\231\257 */\n"
"    color: #1D2129;            /* \346\226\207\345\255\227\346\267\261\347\201\260 */\n"
"    border-radius: 6px;\n"
"    border: none;              /* \351\232\220\350\227\217\351\273\230\350\256\244\350\276\271\346\241\206 */\n"
"}\n"
"QPushButton:checked, QPushButton:hover {\n"
"    background-color: #165DFF; /* \351\200\211\344\270\255/hover\346\227\266\357\274\214\347\247\221\346\212\200\350\223\235\350\203\214\346\231\257 */\n"
"    color: white;              /* \346\226\207\345\255\227\345\217\230\347\231\275 */\n"
"}\n"
"\n"
""));
        pushButton_shouye->setCheckable(true);

        horizontalLayout->addWidget(pushButton_shouye);

        pushButton_wenshidu = new QPushButton(layoutWidget);
        pushButton_wenshidu->setObjectName("pushButton_wenshidu");
        pushButton_wenshidu->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F2F3F5; /* \346\265\205\347\201\260\350\203\214\346\231\257 */\n"
"    color: #1D2129;            /* \346\226\207\345\255\227\346\267\261\347\201\260 */\n"
"    border-radius: 6px;\n"
"    border: none;              /* \351\232\220\350\227\217\351\273\230\350\256\244\350\276\271\346\241\206 */\n"
"}\n"
"QPushButton:checked, QPushButton:hover {\n"
"    background-color: #165DFF; /* \351\200\211\344\270\255/hover\346\227\266\357\274\214\347\247\221\346\212\200\350\223\235\350\203\214\346\231\257 */\n"
"    color: white;              /* \346\226\207\345\255\227\345\217\230\347\231\275 */\n"
"}\n"
"\n"
""));
        pushButton_wenshidu->setCheckable(true);

        horizontalLayout->addWidget(pushButton_wenshidu);

        pushButton_CO = new QPushButton(layoutWidget);
        pushButton_CO->setObjectName("pushButton_CO");
        pushButton_CO->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F2F3F5; /* \346\265\205\347\201\260\350\203\214\346\231\257 */\n"
"    color: #1D2129;            /* \346\226\207\345\255\227\346\267\261\347\201\260 */\n"
"    border-radius: 6px;\n"
"    border: none;              /* \351\232\220\350\227\217\351\273\230\350\256\244\350\276\271\346\241\206 */\n"
"}\n"
"QPushButton:checked, QPushButton:hover {\n"
"    background-color: #165DFF; /* \351\200\211\344\270\255/hover\346\227\266\357\274\214\347\247\221\346\212\200\350\223\235\350\203\214\346\231\257 */\n"
"    color: white;              /* \346\226\207\345\255\227\345\217\230\347\231\275 */\n"
"}\n"
"\n"
""));
        pushButton_CO->setCheckable(true);

        horizontalLayout->addWidget(pushButton_CO);

        pushButton_guangzhao = new QPushButton(layoutWidget);
        pushButton_guangzhao->setObjectName("pushButton_guangzhao");
        pushButton_guangzhao->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F2F3F5; /* \346\265\205\347\201\260\350\203\214\346\231\257 */\n"
"    color: #1D2129;            /* \346\226\207\345\255\227\346\267\261\347\201\260 */\n"
"    border-radius: 6px;\n"
"    border: none;              /* \351\232\220\350\227\217\351\273\230\350\256\244\350\276\271\346\241\206 */\n"
"}\n"
"QPushButton:checked, QPushButton:hover {\n"
"    background-color: #165DFF; /* \351\200\211\344\270\255/hover\346\227\266\357\274\214\347\247\221\346\212\200\350\223\235\350\203\214\346\231\257 */\n"
"    color: white;              /* \346\226\207\345\255\227\345\217\230\347\231\275 */\n"
"}\n"
"\n"
""));
        pushButton_guangzhao->setCheckable(true);
        pushButton_guangzhao->setChecked(false);
        pushButton_guangzhao->setAutoRepeat(false);

        horizontalLayout->addWidget(pushButton_guangzhao);

        pushButton_aizhushou = new QPushButton(layoutWidget);
        pushButton_aizhushou->setObjectName("pushButton_aizhushou");
        pushButton_aizhushou->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F2F3F5; /* \346\265\205\347\201\260\350\203\214\346\231\257 */\n"
"    color: #1D2129;            /* \346\226\207\345\255\227\346\267\261\347\201\260 */\n"
"    border-radius: 6px;\n"
"    border: none;              /* \351\232\220\350\227\217\351\273\230\350\256\244\350\276\271\346\241\206 */\n"
"}\n"
"QPushButton:checked, QPushButton:hover {\n"
"    background-color: #165DFF; /* \351\200\211\344\270\255/hover\346\227\266\357\274\214\347\247\221\346\212\200\350\223\235\350\203\214\346\231\257 */\n"
"    color: white;              /* \346\226\207\345\255\227\345\217\230\347\231\275 */\n"
"}\n"
"\n"
""));
        pushButton_aizhushou->setCheckable(true);

        horizontalLayout->addWidget(pushButton_aizhushou);

        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 30, 571, 361));
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        widget_2 = new QWidget(page_1);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(-50, 350, 581, 201));
        frame_3 = new QFrame(widget_2);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(20, 390, 511, 50));
        layoutWidget_2 = new QWidget(frame_3);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(31, 10, 461, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_shouye_2 = new QPushButton(layoutWidget_2);
        pushButton_shouye_2->setObjectName("pushButton_shouye_2");

        horizontalLayout_2->addWidget(pushButton_shouye_2);

        pushButton_wenshidu_2 = new QPushButton(layoutWidget_2);
        pushButton_wenshidu_2->setObjectName("pushButton_wenshidu_2");

        horizontalLayout_2->addWidget(pushButton_wenshidu_2);

        pushButton_CO_2 = new QPushButton(layoutWidget_2);
        pushButton_CO_2->setObjectName("pushButton_CO_2");

        horizontalLayout_2->addWidget(pushButton_CO_2);

        pushButton_guangzhao_3 = new QPushButton(layoutWidget_2);
        pushButton_guangzhao_3->setObjectName("pushButton_guangzhao_3");

        horizontalLayout_2->addWidget(pushButton_guangzhao_3);

        pushButton_guangzhao_4 = new QPushButton(layoutWidget_2);
        pushButton_guangzhao_4->setObjectName("pushButton_guangzhao_4");

        horizontalLayout_2->addWidget(pushButton_guangzhao_4);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(130, 340, 94, 26));
        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(310, 340, 94, 26));
        frame = new QFrame(page_1);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 110, 251, 141));
        frame->setStyleSheet(QString::fromUtf8(" background-color: white; /* \345\215\241\347\211\207\347\272\257\347\231\275\350\203\214\346\231\257 */\n"
"    border-radius: 12px;    /* \345\234\206\350\247\222\345\215\212\345\276\204\357\274\214\350\247\206\350\247\211\346\233\264\346\237\224\345\222\214 */\n"
"    border: none;           /* \351\232\220\350\227\217\351\273\230\350\256\244\350\276\271\346\241\206 */"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName("gridLayout_3");
        lcdNumber = new QLCDNumber(frame);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"background-color:  #F2F3F5;\n"
""));
        lcdNumber->setDigitCount(8);

        gridLayout_3->addWidget(lcdNumber, 0, 0, 1, 1);

        widget1 = new QWidget(page_1);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(300, 30, 231, 311));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(widget1);
        frame_4->setObjectName("frame_4");
        frame_4->setStyleSheet(QString::fromUtf8(" background-color: white; /* \345\215\241\347\211\207\347\272\257\347\231\275\350\203\214\346\231\257 */\n"
"    border-radius: 12px;    /* \345\234\206\350\247\222\345\215\212\345\276\204\357\274\214\350\247\206\350\247\211\346\233\264\346\237\224\345\222\214 */\n"
"    border: none;           /* \351\232\220\350\227\217\351\273\230\350\256\244\350\276\271\346\241\206 */"));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frame_4);
        gridLayout->setObjectName("gridLayout");
        label_week = new QLabel(frame_4);
        label_week->setObjectName("label_week");
        label_week->setStyleSheet(QString::fromUtf8("color: #4E5969;\n"
"font:14px;"));

        gridLayout->addWidget(label_week, 3, 0, 1, 1);

        label_date = new QLabel(frame_4);
        label_date->setObjectName("label_date");
        label_date->setStyleSheet(QString::fromUtf8("color: #4E5969;\n"
"font:14px;"));

        gridLayout->addWidget(label_date, 2, 0, 1, 1);

        label_city = new QLabel(frame_4);
        label_city->setObjectName("label_city");
        label_city->setStyleSheet(QString::fromUtf8("color: #4E5969;\n"
"font:14px;"));

        gridLayout->addWidget(label_city, 1, 0, 1, 1);


        verticalLayout->addWidget(frame_4);

        frame_5 = new QFrame(widget1);
        frame_5->setObjectName("frame_5");
        frame_5->setStyleSheet(QString::fromUtf8(" background-color:  #F2F3F5; /* \345\215\241\347\211\207\347\272\257\347\231\275\350\203\214\346\231\257 */\n"
"    border-radius: 8px;    /* \345\234\206\350\247\222\345\215\212\345\276\204\357\274\214\350\247\206\350\247\211\346\233\264\346\237\224\345\222\214 */\n"
"    border: none;           /* \351\232\220\350\227\217\351\273\230\350\256\244\350\276\271\346\241\206 */\n"
""));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_4 = new QGridLayout(frame_5);
        gridLayout_4->setObjectName("gridLayout_4");
        label_wea = new QLabel(frame_5);
        label_wea->setObjectName("label_wea");

        gridLayout_4->addWidget(label_wea, 0, 0, 1, 1);

        label_tem = new QLabel(frame_5);
        label_tem->setObjectName("label_tem");

        gridLayout_4->addWidget(label_tem, 1, 0, 1, 1);

        label_hum = new QLabel(frame_5);
        label_hum->setObjectName("label_hum");

        gridLayout_4->addWidget(label_hum, 2, 0, 1, 1);


        verticalLayout->addWidget(frame_5);

        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 111, 41));
        label->setStyleSheet(QString::fromUtf8("color: #1D2129;\n"
"font:20px"));
        frame_6 = new QFrame(page_2);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(100, -10, 191, 61));
        frame_6->setStyleSheet(QString::fromUtf8(" background-color: white; /* \345\215\241\347\211\207\347\272\257\347\231\275\350\203\214\346\231\257 */\n"
"    border-radius: 12px;    /* \345\234\206\350\247\222\345\215\212\345\276\204\357\274\214\350\247\206\350\247\211\346\233\264\346\237\224\345\222\214 */\n"
"    border: none;           /* \351\232\220\350\227\217\351\273\230\350\256\244\350\276\271\346\241\206 */"));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_5 = new QGridLayout(frame_6);
        gridLayout_5->setObjectName("gridLayout_5");
        label_wendu = new QLabel(frame_6);
        label_wendu->setObjectName("label_wendu");
        label_wendu->setStyleSheet(QString::fromUtf8("font:28px;\n"
""));

        gridLayout_5->addWidget(label_wendu, 0, 0, 1, 1);

        ChartView_wendu = new QChartView(page_2);
        ChartView_wendu->setObjectName("ChartView_wendu");
        ChartView_wendu->setGeometry(QRect(10, 70, 541, 291));
        ChartView_wendu->setStyleSheet(QString::fromUtf8(" background-color: white; border-radius: 12px;"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_CO = new QLabel(page_3);
        label_CO->setObjectName("label_CO");
        label_CO->setGeometry(QRect(150, 0, 121, 41));
        label_CO->setStyleSheet(QString::fromUtf8(" background-color: white; /* \345\215\241\347\211\207\347\272\257\347\231\275\350\203\214\346\231\257 */\n"
"    border-radius: 12px;    /* \345\234\206\350\247\222\345\215\212\345\276\204\357\274\214\350\247\206\350\247\211\346\233\264\346\237\224\345\222\214 */\n"
"    border: none;           /* \351\232\220\350\227\217\351\273\230\350\256\244\350\276\271\346\241\206 */"));
        label_2 = new QLabel(page_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 0, 121, 41));
        label_2->setStyleSheet(QString::fromUtf8("color: #1D2129;\n"
"font:20px"));
        ChartView_CO = new QChartView(page_3);
        ChartView_CO->setObjectName("ChartView_CO");
        ChartView_CO->setGeometry(QRect(50, 60, 481, 291));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        label_lux = new QLabel(page_4);
        label_lux->setObjectName("label_lux");
        label_lux->setGeometry(QRect(150, 0, 131, 41));
        label_lux->setStyleSheet(QString::fromUtf8(" background-color: white; /* \345\215\241\347\211\207\347\272\257\347\231\275\350\203\214\346\231\257 */\n"
"    border-radius: 12px;    /* \345\234\206\350\247\222\345\215\212\345\276\204\357\274\214\350\247\206\350\247\211\346\233\264\346\237\224\345\222\214 */\n"
"    border: none;           /* \351\232\220\350\227\217\351\273\230\350\256\244\350\276\271\346\241\206 */"));
        label_3 = new QLabel(page_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 0, 131, 41));
        label_3->setStyleSheet(QString::fromUtf8("color: #1D2129;\n"
"font:20px"));
        progressBar_lux = new QProgressBar(page_4);
        progressBar_lux->setObjectName("progressBar_lux");
        progressBar_lux->setGeometry(QRect(310, 2, 118, 31));
        progressBar_lux->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    background: #F2F3F5; /* \350\277\233\345\272\246\346\235\241\350\203\214\346\231\257 */\n"
"    height: 12px;        /* \350\277\233\345\272\246\346\235\241\351\253\230\345\272\246 */\n"
"}\n"
"QProgressBar::chunk {\n"
"    border-radius: 6px;\n"
"    /* \344\273\216\351\273\204\345\210\260\346\251\231\347\232\204\346\270\220\345\217\230\357\274\214\346\250\241\346\213\237\342\200\234\344\272\256\345\272\246\342\200\235\350\247\206\350\247\211 */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #FFD700, stop:1 #FF7D00);\n"
"}"));
        progressBar_lux->setValue(24);
        ChartView_guangzhao = new QChartView(page_4);
        ChartView_guangzhao->setObjectName("ChartView_guangzhao");
        ChartView_guangzhao->setGeometry(QRect(29, 79, 481, 281));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        lineEdit_deseekse = new QLineEdit(page_5);
        lineEdit_deseekse->setObjectName("lineEdit_deseekse");
        lineEdit_deseekse->setGeometry(QRect(10, 50, 261, 221));
        lineEdit_deseekse->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border-radius: 6px;\n"
"    border: 1px solid #E5E6EB; /* \346\265\205\347\201\260\350\276\271\346\241\206 */\n"
"    padding: 6px 12px;         /* \345\206\205\350\276\271\350\267\235\357\274\214\344\274\230\345\214\226\350\276\223\345\205\245\344\275\223\351\252\214 */\n"
"}"));
        textEdit_dpseekre = new QTextEdit(page_5);
        textEdit_dpseekre->setObjectName("textEdit_dpseekre");
        textEdit_dpseekre->setGeometry(QRect(310, 50, 241, 271));
        textEdit_dpseekre->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: white;\n"
"    border-radius: 12px;\n"
"    border: none;\n"
"}"));
        pushButton_dsChatRe = new QPushButton(page_5);
        pushButton_dsChatRe->setObjectName("pushButton_dsChatRe");
        pushButton_dsChatRe->setGeometry(QRect(10, 290, 261, 26));
        pushButton_dsChatRe->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #165DFF;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #0E42D2;\n"
"}"));
        label_4 = new QLabel(page_5);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 0, 81, 41));
        label_4->setStyleSheet(QString::fromUtf8("color: #1D2129;\n"
"font:20px"));
        stackedWidget->addWidget(page_5);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 400, 94, 26));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #00B42A; /* \347\273\277\350\211\262\357\274\214\344\273\243\350\241\250\342\200\234\345\274\200\345\220\257\342\200\235 */\n"
"    color: white;              /* \346\226\207\345\255\227\347\231\275\350\211\262 */\n"
"    border-radius: 6px;        /* \346\214\211\351\222\256\345\234\206\350\247\222 */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #00A327; /*  hover\346\227\266\345\212\240\346\267\261\351\242\234\350\211\262 */\n"
"}"));
        pushButton->setCheckable(true);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(310, 400, 94, 26));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F53F3F; /* \347\272\242\350\211\262\357\274\214\344\273\243\350\241\250\342\200\234\345\205\263\351\227\255\342\200\235 */\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #E43838;\n"
"}"));
        pushButton_2->setCheckable(true);

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_shouye->setText(QCoreApplication::translate("Widget", "\351\246\226\351\241\265", nullptr));
        pushButton_wenshidu->setText(QCoreApplication::translate("Widget", "\346\270\251\346\271\277\345\272\246", nullptr));
        pushButton_CO->setText(QCoreApplication::translate("Widget", "CO\346\265\223\345\272\246", nullptr));
        pushButton_guangzhao->setText(QCoreApplication::translate("Widget", "\345\205\211\347\205\247\345\274\272\345\272\246", nullptr));
        pushButton_aizhushou->setText(QCoreApplication::translate("Widget", "AI\345\212\251\346\211\213", nullptr));
        pushButton_shouye_2->setText(QCoreApplication::translate("Widget", "\351\246\226\351\241\265", nullptr));
        pushButton_wenshidu_2->setText(QCoreApplication::translate("Widget", "\346\270\251\346\271\277\345\272\246", nullptr));
        pushButton_CO_2->setText(QCoreApplication::translate("Widget", "CO\346\265\223\345\272\246", nullptr));
        pushButton_guangzhao_3->setText(QCoreApplication::translate("Widget", "\345\205\211\347\205\247\345\274\272\345\272\246", nullptr));
        pushButton_guangzhao_4->setText(QCoreApplication::translate("Widget", "AI\345\212\251\346\211\213", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\345\274\200\347\201\257", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\345\205\263\347\201\257", nullptr));
        label_week->setText(QCoreApplication::translate("Widget", "\345\221\250\345\207\240", nullptr));
        label_date->setText(QCoreApplication::translate("Widget", "\346\227\245\346\234\237", nullptr));
        label_city->setText(QCoreApplication::translate("Widget", "\345\237\216\345\270\202", nullptr));
        label_wea->setText(QCoreApplication::translate("Widget", "\345\244\251\346\260\224", nullptr));
        label_tem->setText(QCoreApplication::translate("Widget", "\346\270\251\345\272\246", nullptr));
        label_hum->setText(QCoreApplication::translate("Widget", "\346\271\277\345\272\246", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\270\251\345\272\246\347\233\221\346\265\213", nullptr));
        label_wendu->setText(QCoreApplication::translate("Widget", "wendu", nullptr));
        label_CO->setText(QCoreApplication::translate("Widget", "CO\346\265\223\345\272\246", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "CO \346\265\223\345\272\246\347\233\221\346\265\213", nullptr));
        label_lux->setText(QCoreApplication::translate("Widget", "\345\205\211\345\274\272", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\205\211\347\205\247\345\274\272\345\272\246\347\233\221\346\265\213", nullptr));
        pushButton_dsChatRe->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "AI\345\212\251\346\211\213", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\274\200\347\201\257", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\345\205\263\347\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
