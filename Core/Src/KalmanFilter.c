/*
 * KalmanFilter.c
 *
 *  Created on: Aug 8, 2024
 *      Author: 09miy
 */

#include "KalmanFilter.h"
#define DEG_TO_PI 0.01745329251994329576923690768489
#define DEG_TO_PI_sqr 0.00030461741978670859934674354937889

//Initialization of Kalaman structure for variable that changes up to second time derivative
void InitializeKalman_second(KF_second_struct_t* KF_struct){
	KF_struct->xdt2 = KF_struct->xdt = KF_struct->x = 0.00001;

	KF_struct->p_xdt2 = KF_struct->p_xdt =KF_struct->p_x = DEG_TO_PI*DEG_TO_PI*180*180;

	KF_struct->q_x = 0.001;
	KF_struct->q_xdt = 0.01;
	KF_struct->q_xdt2 = 10000;
}

//Calculation with Kalman filter for variable that changes up to second time derivative
void CalculateKalman_second(KF_second_struct_t* KF_struct, float32_t measured){
	/*Inputed structure's variables have indexes n, n-1*/
	float32_t K_x,	//Kalman gain of variable
	K_xdt,			//Kalman gain of variable's first derivative
	K_xdt2,			//Kalman gain of variable's second derivative
	p_11_x,			//Estimate variance of variable with indexes n, n
	p_11_xdt,		//Estimate variance of variable's first time derivative with indexes n, n
	p_11_xdt2,		//Estimate variance of variable's second time derivative with indexes n, n
	x_11,			//Variable with index n, n
	xdt_11,			//Variable's first time derivative with index n,n
	xdt2_11;		//Variable's second time derivative with index n,n

	/*		Update		*/
	K_x = KF_struct->p_x/(KF_struct->p_x+KF_struct->r_x);
	K_xdt = KF_struct->p_xdt/(KF_struct->p_xdt+KF_struct->r_xdt);
	K_xdt2 = KF_struct->p_xdt2/(KF_struct->p_xdt2+KF_struct->r_xdt2);

	/*		Estimate		*/
	float32_t x_change = measured-KF_struct->x;
	x_11 = KF_struct->x + K_x*(x_change);
	p_11_x = (1-K_x)*KF_struct->p_x;
	xdt_11 = KF_struct->xdt + K_xdt*(x_change/READ_MPU_TIME);
	p_11_xdt = (1-K_xdt)*KF_struct->p_xdt;
	xdt2_11 = KF_struct->xdt2 + K_xdt2*(2*x_change/(READ_MPU_TIME*READ_MPU_TIME));
	p_11_xdt2 = (1-K_xdt2)*KF_struct->p_xdt2;

	/*		Predict		*/
	KF_struct->x = x_11 + xdt_11*READ_MPU_TIME + xdt2_11*READ_MPU_TIME*READ_MPU_TIME*.5;
	KF_struct->xdt = xdt_11 + xdt2_11 * READ_MPU_TIME;
	KF_struct->xdt2 = xdt2_11;

	KF_struct->p_x = p_11_x + p_11_xdt*READ_MPU_TIME*READ_MPU_TIME + p_11_xdt2 * READ_MPU_TIME*READ_MPU_TIME*READ_MPU_TIME*READ_MPU_TIME * 0.25;
	KF_struct->p_xdt =	p_11_xdt + p_11_xdt2 * READ_MPU_TIME*READ_MPU_TIME;
	KF_struct->p_xdt2 = p_11_xdt2 + KF_struct->q_xdt2;
};


