/*
 * gy_521.h
 *
 *  Created on: Jun 19, 2024
 *      Author: GreatTomato
 */
#include "stm32f4xx_hal.h"
#include "arm_math.h"

#ifndef GT_GY_87_H_
#define GT_GY_87_H_
#endif

#define MPU6050_ACCEL_ERROR 8*0.02			//max_g*error_%
#define MPU6050_GYRO_ERROR 1000*0.02		//max_speed*error_%
#define MPU6050_ACCEL_ERROR_SQR MPU6050_ACCEL_ERROR*MPU6050_ACCEL_ERROR			//max_g*error_%
#define MPU6050_GYRO_ERROR_SQR 	MPU6050_GYRO_ERROR*MPU6050_GYRO_ERROR			//max_speed*error_%

#include <stdint.h>
#include "stm32f4xx_hal.h"

typedef struct
{
	float X;
	float Y;
	float Z;
} MPU6050_gyro_vectors_t;

typedef struct
{
	float32_t X;
	float32_t Y;
	float32_t Z;
} MPU6050_accel_vectors_t;

uint8_t MPU6050_Init(I2C_HandleTypeDef *I2Cx);

void MPU6050_Read_Accel(I2C_HandleTypeDef *I2Cx, MPU6050_accel_vectors_t *DataStruct);
void MPU6050_Read_Gyro(I2C_HandleTypeDef *I2Cx, MPU6050_gyro_vectors_t *DataStruct);
