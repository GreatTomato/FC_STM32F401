/*
 * dataManagment.c
 *
 *  Created on: Aug 12, 2024
 *      Author: 09miy
 */

#include "dataManagment.h"

//Returns status that is measured angle from accelerometer readings
daMa_calc_status calculateAngle_acc(KF_second_struct_t * KF_struct, MPU6050_accel_vectors_t measured, float32_t *z, daMa_angle_types AngleID) {
	*z = 0;	//Measured angle
	float32_t SecondVector;
	switch (AngleID) {
	case DAMA_ANGLETYPE_PITCH:
		SecondVector = measured.Y;
	break;
	case DAMA_ANGLETYPE_ROLL:
		SecondVector = - measured.X;
	break;
	default: return DAMA_CALC_STATUS_ARGUMENT_ERROR;
	}

	arm_status armStatus = arm_atan2_f32(SecondVector, measured.Z, z);
	if (armStatus!= ARM_MATH_SUCCESS) return DAMA_CALC_STATUS_ARM_ERROR;
	{
		float32_t SeVe_sqr = SecondVector*SecondVector;
		float32_t Z_sqr = measured.Z*measured.Z;
		KF_struct->r_x = sqrt((SeVe_sqr*MPU6050_ACCEL_ERROR_SQR+Z_sqr*MPU6050_ACCEL_ERROR_SQR)
										/(SeVe_sqr+Z_sqr));
		//KF_struct->r_xdt = KF_struct->r_x/1;/* 1 second*/
		//KF_struct->r_xdt2 = 2*KF_struct->r_x/(1*1);/* 1 second^2*/
	}
	return DAMA_CALC_STATUS_SUCCSESS;
}
