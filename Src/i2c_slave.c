/*
 * i2c_slave.c
 *
 *  Created on: Oct 9, 2024
 *      Author: thuyh
 */

	#include "i2c_slave.h"

	#define RxSize 6
	uint8_t Rxdata[RxSize];
	void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c){
		HAL_I2C_EnableListen_IT(hi2c);
	}
	void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode){
		if(TransferDirection == I2C_DIRECTION_TRANSMIT){
			HAL_I2C_Slave_Seq_Receive_IT( hi2c, Rxdata, RxSize,I2C_FIRST_AND_LAST_FRAME);
		}
		else{
			Error_Handler();
		}
	}
	void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c){

	}
	void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c){
		HAL_I2C_EnableListen_IT(hi2c);
	}
