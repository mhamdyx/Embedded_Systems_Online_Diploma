/*
 * state.h
 *
 *  Created on: Oct 23, 2021
 *      Author: MahmoudH
 */

#ifndef STATE_H_
#define STATE_H_

// State function declaration
#define STATE_DEFINE(_stateFunc_) void ST_##_stateFunc_()

// State funtion address
#define STATE(_stateFunc_) ST_##_stateFunc_

// Common signals between Modules:
// CA <-----> DC_Motor
void DC_Motor_speed(unsigned int s);

// CA <-----> Ultrasonic_Sensor
unsigned int US_Sensor_distance(void);

#endif /* STATE_H_ */
