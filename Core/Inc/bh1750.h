/*
 * bh1750.h
 *
 *  Created on: Aug 11, 2025
 *      Author: yc
 */

#ifndef INC_BH1750_H_
#define INC_BH1750_H_

#include "stdint.h"

/*外部函数区*/
/*通过指针获取光照强度值*/
uint16_t Get_BH1750_Value(void);


/*	//用法

	uint16_t bh1750_lux;
	bh1750_lux = Get_BH1750_Value();
	printf("current: %5d lux\r\n", bh1750_lux);

*/


/*bh1750地址*/
#define	BH1750_ADDR_WRITE	0x46	//01000110
#define	BH1750_ADDR_READ	0x47	//01000111


typedef enum
{
	POWER_OFF_CMD	=	0x00,	//断电：无激活状态
	POWER_ON_CMD	=	0x01,	//通电：等待测量指令
	RESET_REGISTER	=	0x07,	//重置数字寄存器（在断电状态下不起作用）
	CONT_H_MODE		=	0x10,	//连续H分辨率模式：在11x分辨率下开始测量，测量时间120ms
	CONT_H_MODE2	=	0x11,	//连续H分辨率模式2：在0.51x分辨率下开始测量，测量时间120ms
	CONT_L_MODE		=	0x13,	//连续L分辨率模式：在411分辨率下开始测量，测量时间16ms
	ONCE_H_MODE		=	0x20,	//一次高分辨率模式：在11x分辨率下开始测量，测量时间120ms，测量后自动设置为断电模式
	ONCE_H_MODE2	=	0x21,	//一次高分辨率模式2：在0.51x分辨率下开始测量，测量时间120ms，测量后自动设置为断电模式
	ONCE_L_MODE		=	0x23	//一次低分辨率模式：在411x分辨率下开始测量，测量时间16ms，测量后自动设置为断电模式
} BH1750_MODE;

#endif /* INC_BH1750_H_ */
