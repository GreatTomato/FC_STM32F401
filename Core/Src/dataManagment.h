/*
 * dataManagment.h
 *
 *  Created on: Aug 12, 2024
 *      Author: 09miy
 */

#ifndef SRC_DATAMANAGMENT_H_
#define SRC_DATAMANAGMENT_H_

#include "arm_math.h"
#include "KalmanFilter.h"
#include <Math.h>
#include "gy_87.h"

//DAMA is dataManager
typedef enum
{
	DAMA_ANGLETYPE_PITCH = (unsigned char)1,	//defines ID for pitch calculation
	DAMA_ANGLETYPE_ROLL = (unsigned char)2	//defines ID for roll calculation
} daMa_angle_types;

typedef enum
  {
	DAMA_CALC_STATUS_SUCCSESS = 0,
	DAMA_CALC_STATUS_OTHER = -1,
	DAMA_CALC_STATUS_ARGUMENT_ERROR = -2,
	DAMA_CALC_STATUS_ARM_ERROR = -3
  }	daMa_calc_status;

daMa_calc_status calculateAngle_acc(KF_second_struct_t * KF_struct, MPU6050_accel_vectors_t measured, float32_t *z, daMa_angle_types AngleID);
#endif /* SRC_DATAMANAGMENT_H_ */
