/*
 * mq7.h - 无需标定的MQ-7 CO传感器通用驱动
 * 适用于一般环境，基于典型参数估算浓度（误差±30%）
 */
#ifndef INC_MQ7_H_
#define INC_MQ7_H_
#include "stm32f1xx_hal.h"

// 配置参数（根据硬件修改）
#define MQ7_AO_ADC_CHANNEL ADC_CHANNEL_1  // AO连接的ADC通道
#define MQ7_READ_TIMES 10                 // 采样次数（参考原代码）
#define MQ7_VREF 3.3f                     // 参考电压（原代码用5V）
#define MQ7_RL 2000.0f                    // 负载电阻（2kΩ，推导自原代码RS计算）

typedef struct {
	ADC_HandleTypeDef *hadc;  // ADC句柄
} MQ7_HandleTypeDef;

/**
 * @brief 初始化MQ-7传感器（AO模式）
 * @param mq7：传感器句柄
 * @param hadc：ADC句柄（CubeMX初始化的ADC）
 */
void MQ7_Init(MQ7_HandleTypeDef *mq7, ADC_HandleTypeDef *hadc);

/**
 * @brief 读取ADC原始值（多次采样平均）
 * @param mq7：传感器句柄
 * @return 平均ADC值
 */
uint16_t MQ7_ReadADC(MQ7_HandleTypeDef *mq7);

/**
 * @brief 计算CO浓度（ppm），基于参考代码的公式
 * @param mq7：传感器句柄
 * @return CO浓度（ppm）
 */
float MQ7_GetPPM(MQ7_HandleTypeDef *mq7);

#endif
