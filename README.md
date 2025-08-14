_#智能家居/环境检测系统，linux环境用STM32C8T6采集传感器数据，QT作为上位机编写界面良好，两者之间通过USART串口通信，附加天气预报和deepseekAI小助手的功能

版本：Version:

Ubuntu    24.04

Cubeide  1.19.0

Qt       6.9.1

通过api接口接受天气预报的json数据，进行解析后显示

通过密匙接入deepseek，可以实时对接受到的数据进行提问，比如询问达到某CO浓度代表什么等

开关灯按钮控制STM32相连的LED灯

传感器采集信号输出到STM32
STM32采集到信号处理为数据
数据显示到OLED进行调试
数据通过串口发送json数据包到QT读取解析数据包
将阅读的信息进行实时显示
QT通过串口通信发送数据到下位机
下位机通过数据进行逻辑判断运行不同的代码逻辑

外设：

 1.温度传感器DS18B20

接线：
 VCC
 DQ
 GND 3~5V

采用单总线协议，需要手搓协议，DQ接口，任意指定GPIO，这里指定PA2引脚

GPIO接口配置： 推挽输出（开漏需外部上拉）

2.光强传感器BH1750FVI

接线：
 ADDR:IIC设备地址引脚
 GND
 SCL
 SDA
 VCC:3.3V

GPIO接口配置：无须特别配置，使用IIC默认配置

采用I2C协议，使用I2C2：PB10,11引脚


 3.CO传感器YX55704-MQ-7

接线：
 VCC 5V
 GND
 AO:输出0~5V
 DO

4.LED灯
GPIOA5,推勉输出，下拉模式

5.按钮
GPIOA12，输入，上拉模式

LED两种控制方式：
（1）外设按钮外部中断
（2）上位机QT端发送串口数据控制，即开关灯pushbutton按钮

GPIO接口配置：模拟输入（Analog）

采用AO口输出，需要ADC功能，使用PA1引脚：ADC12_IN1

通过传感器数据绘制折线图

<img width="587" height="573" alt="image" src="https://github.com/user-attachments/assets/3d128c45-b7c8-437f-92ec-214cd58071c4" />

<img width="600" height="595" alt="image" src="https://github.com/user-attachments/assets/47d79d57-f2d4-4db6-a3fc-cda8bbfb2c12" />

<img width="593" height="542" alt="image" src="https://github.com/user-attachments/assets/8d805aad-5e07-4276-8a5e-72f8c98f9b30" />

<img width="581" height="597" alt="image" src="https://github.com/user-attachments/assets/aff05523-5ff8-41a5-a822-57d98381284a" />

发送hello之后收到的回复：

<img width="591" height="581" alt="image" src="https://github.com/user-attachments/assets/c951b812-8fcc-4f79-9f3e-b54aed48fbc8" />


_
