/*
 * state.h
 *
 *  Created on: Oct 25, 2021
 *      Author: MahmoudH
 */

#ifndef STATE_H_
#define STATE_H_

#include "driver.h"

// State function declaration
// Line 15: Misra Violation 20.10 (Advisory)
#define STATE_DEFINE(_stateFunc_) void ST_##_stateFunc_()

// State funtion address
// Line 19: Misra Violation 20.10 (Advisory)
#define STATE(_stateFunc_) ST_##_stateFunc_

// Common signals between Modules:

// Main Algorithm <----- Pressure_Sensor
unsigned int get_pressure_val(void);

// Main Algorithm -----> Alarm Monitor
int high_pressure_detected(void);

// Alarm Monitor -----> Alarm Actuator
void start_alarm(void);

// Alarm Monitor -----> Alarm Actuator
void stop_alarm(void);

#endif /* STATE_H_ */
