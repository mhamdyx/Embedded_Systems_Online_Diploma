/*
 * Pressure_Sensor.c
 *
 *  Created on: Oct 25, 2021
 *      Author: MahmoudH
 */

#include "Pressure_Sensor.h"

enum
{
	PS_INIT,
	PS_READING,
	PS_WAITING
} PS_state_id;

extern void (*PS_state)();

static unsigned int pressure_val;

STATE_DEFINE(PS_init)
{
	// Init the Pressure Sensor
	// Call the Pressure Sensor driver functions
	PS_state_id = PS_INIT;

	// Check event and update state
	PS_state = STATE(PS_reading);
}

STATE_DEFINE(PS_reading)
{
	// State Action
	PS_state_id = PS_READING;

	// Read from pressure sensor
	pressure_val = getPressureVal();

	// Check event and update state
	PS_state = STATE(PS_waiting);
}

STATE_DEFINE(PS_waiting)
{
	// State Action
	PS_state_id = PS_WAITING;

	Delay(1000);
	//DELAY(100);

	// Check event and update state
	PS_state = STATE(PS_reading);
}

// Interface with main algorithm 
// (set pressure in main algorithm)
unsigned int get_pressure_val(void)
{
	return pressure_val;
}

