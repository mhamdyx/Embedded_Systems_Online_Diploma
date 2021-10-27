/*
 * Alarm_Monitor.c
 *
 *  Created on: Oct 25, 2021
 *      Author: MahmoudH
 */

#include "Alarm_Monitor.h"

enum
{
	AlarmMon_ALARM_OFF,
	AlarmMon_ALARM_ON,
	AlarmMon_WAITING
} AlarmMon_state_id;

extern void (*AlarmMon_state)();

STATE_DEFINE(AlarmMon_alarm_off)
{
	// State Action
	// State ID
	AlarmMon_state_id = AlarmMon_ALARM_OFF;

	// Stop alarm actuator
	stop_alarm();

	// Check event and update state
	// Removing == 1 will cause Misra Violation 14.4 (Required)
	if(high_pressure_detected() == 1)
	{
		AlarmMon_state = STATE(AlarmMon_alarm_on);
	}
}

STATE_DEFINE(AlarmMon_alarm_on)
{
	// State Action
	// State ID
	AlarmMon_state_id = AlarmMon_ALARM_ON;
	
	// Start alarm actuator
	start_alarm();

	// Check event and update state
	AlarmMon_state = STATE(AlarmMon_waiting);
}

STATE_DEFINE(AlarmMon_waiting)
{
	// State Action
	// State ID
	AlarmMon_state_id = AlarmMon_WAITING;

	Delay(600);
	//DELAY(60);

	// Check event and update state
	AlarmMon_state = STATE(AlarmMon_alarm_off);
}
