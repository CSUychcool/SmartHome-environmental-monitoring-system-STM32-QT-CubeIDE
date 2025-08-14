/*
 * bh1750.c
 *
 *  Created on: Aug 11, 2025
 *      Author: yc
 */

#include "bh1750.h"
#include "i2c.h"


/*i2c句柄*/
#define bh1750_i2c hi2c2

/*内部函数声明区*/
static uint8_t	BH1750_Send_Cmd(BH1750_MODE cmd);
static uint8_t BH1750_Read_Dat(uint8_t* dat);
static uint16_t BH1750_Dat_To_Lux(uint8_t* dat);



/**
 * @brief	向BH1750发送一条指令
 * @param	cmd —— BH1750工作模式指令（在BH1750_MODE中枚举定义）
 * @retval	成功返回HAL_OK
*/
static uint8_t	BH1750_Send_Cmd(BH1750_MODE cmd)
{
	return HAL_I2C_Master_Transmit(&bh1750_i2c, BH1750_ADDR_WRITE, (uint8_t*)&cmd, 1, 0xFFFF);
}


/**
 * @brief	从BH1750接收一次光强数据
 * @param	dat —— 存储光照强度的地址（两个字节数组）
 * @retval	成功 —— 返回HAL_OK
*/
static uint8_t BH1750_Read_Dat(uint8_t* dat)
{
	return HAL_I2C_Master_Receive(&bh1750_i2c, BH1750_ADDR_READ, dat, 2, 0xFFFF);
}


/**
 * @brief	将BH1750的两个字节数据转换为光照强度值（0-65535）
 * @param	dat  —— 存储光照强度的地址（两个字节数组）
 * @retval	成功 —— 返回光照强度值
*/
static uint16_t BH1750_Dat_To_Lux(uint8_t* dat)
{
	uint16_t lux = 0;
	lux = dat[0];
	lux <<= 8;
	lux |= dat[1];
	lux = (int)(lux / 1.2);

	return lux;
}


/**
 * @brief	返回光照强度值
 * @param	无
 * @retval	成功 —— 返回光照强度值
*/
uint16_t Get_BH1750_Value(void)
{
	uint8_t dat[2] = {0};		//dat[0]是高字节，dat[1]是低字节
	uint16_t lux;

	if(HAL_OK != BH1750_Send_Cmd(ONCE_H_MODE))
	{
		return 0;
	}
	HAL_Delay(120);
	if(HAL_OK != BH1750_Read_Dat(dat))
	{
		return 0;
	}

	lux = BH1750_Dat_To_Lux(dat);
	return lux;
}


