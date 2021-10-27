/*
 * Main_Algorithm.c
 *
 *  Created on: Oct 25, 2021
 *      Author: MahmoudH
 */

#include "Main_Algorithm.h"

enum
{
	MainAlg_PRESSURE_DETECT
} MainAlg_state_id;

extern void (*MainAlg_state)();

// Line 18: Misra Violation 12.3 (Advisory)
static unsigned int pressure_val, threshold = 20;

STATE_DEFINE(MainAlg_pressure_detect)
{
	// State Action
	// State ID
	MainAlg_state_id = MainAlg_PRESSURE_DETECT;

	// Read pressure value from pressure sensor
	pressure_val = get_pressure_val();

	// Check event and update state
	MainAlg_state = STATE(MainAlg_pressure_detect);
}

// Main Algorithm -----> Alarm Monitor
int high_pressure_detected(void)
{
	return (pressure_val > threshold);
}
