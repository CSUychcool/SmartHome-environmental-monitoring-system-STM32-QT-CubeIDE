#include "mq7.h"
#include <math.h>
#include "tim.h"
//#include <HAL_Delay.h>
//需包含你的延时函数头文件

/**
 * @brief 初始化传感器（配置ADC）
 */
void MQ7_Init(MQ7_HandleTypeDef *mq7, ADC_HandleTypeDef *hadc) {
    mq7->hadc = hadc;
    // ADC已由CubeMX初始化，此处无需额外配置
}

/**
 * @brief 读取ADC平均值（参考原代码的多次采样逻辑）
 */
uint16_t MQ7_ReadADC(MQ7_HandleTypeDef *mq7) {
    uint32_t adc_sum = 0;
    for (uint8_t i = 0; i < MQ7_READ_TIMES; i++) {
        // 启动ADC转换
        HAL_ADC_Start(mq7->hadc);
        // 等待转换完成（超时100ms）
        if (HAL_ADC_PollForConversion(mq7->hadc, 100) == HAL_OK) {
            adc_sum += HAL_ADC_GetValue(mq7->hadc);
        }
        HAL_ADC_Stop(mq7->hadc);
        delay_us(5000); // 每次采样间隔5ms
    }
    return (uint16_t)(adc_sum / MQ7_READ_TIMES);  // 返回平均值
}

/**
 * @brief 计算CO浓度（完全沿用参考代码的计算逻辑）
 */
float MQ7_GetPPM(MQ7_HandleTypeDef *mq7) {
    // 1. 读取ADC平均值
    uint16_t adc_val = MQ7_ReadADC(mq7);

    // 2. 计算电压（参考原代码：Vol = (tempData * 5 / 4096)）
    float vol = (adc_val * MQ7_VREF) / 4096.0f;  // 12位ADC，4096为满量程

    // 3. 计算RS（参考原代码：RS = (5 - Vol) / (Vol * 0.5)）
    // 推导：原代码中0.5 = 1/2kΩ（因RL=2kΩ），故RS = (VREF - Vol)/(Vol * (1/RL)) = RL*(VREF - Vol)/Vol
    float rs = (MQ7_VREF - vol) / (vol * (1.0f / MQ7_RL));

    // 4. 计算浓度（参考原代码的经验公式）
    float r0 = 6.64f;  // 原代码固定R0值
    float ppm = pow(11.5428f * r0 / rs, 0.6549f);  // 原代码的幂函数公式

    return ppm;
}
