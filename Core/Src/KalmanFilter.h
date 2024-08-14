/*
 * KalmanFilter.h
 *
 *  Created on: Aug 8, 2024
 *      Author: 09miy
 */
#ifndef ARM_MATH_CM4
#define ARM_MATH_CM4
#endif

#include "arm_math.h"
#include "constants.h"

#ifndef SRC_KALMANFILTER_H_
#define SRC_KALMANFILTER_H_

typedef struct
{													//every variable there is "Prediction", i.e. x_(n, n-1)
	float32_t x;									//variable
	float32_t xdt;									//variable's first derivative by time
	float32_t xdt2;									//variable's second derivative by time
	float32_t p_x;									//Estimated variance for variable
	float32_t p_xdt;								//Estimated variance for variable's first derivative by time
	float32_t p_xdt2;								//Estimated variance for variable's second derivative by time
	float32_t q_x;									//process noise variance for variable
	float32_t q_xdt;								//process noise variance for variable's first derivative by time
	float32_t q_xdt2;								//process noise variance for variable's second derivative by time
	float32_t r_x;									//measurement variance for variable
	float32_t r_xdt;								//measurement variance for variable's first derivative by time
	float32_t r_xdt2;								//measurement variance for variable's second derivative by time
} KF_second_struct_t;								//Structure to save parameters for variable filtering that changes up to second time derivative

void InitializeKalman_second(KF_second_struct_t* KF_struct);
void CalculateKalman_second(KF_second_struct_t* KF_struct, float32_t measured);
#endif /* SRC_KALMANFILTER_H_ */
