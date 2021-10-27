/*
 * Alarm_Actuator.c
 *
 *  Created on: Oct 25, 2021
 *      Author: MahmoudH
 */

#include "Alarm_Actuator.h"

enum
{
	AlarmAct_INIT,
	AlarmAct_WAITING,
	AlarmAct_ALARM_OFF,
	AlarmAct_ALARM_ON
} AlarmAct_state_id;

extern void (*AlarmAct_state)();

STATE_DEFINE(AlarmAct_init)
{
	// State Action
	// State ID
	AlarmAct_state_id = AlarmAct_INIT;

	// Check event and update state
	AlarmAct_state = STATE(AlarmAct_waiting);
}

STATE_DEFINE(AlarmAct_waiting)
{
	// State Action
	// State ID
	AlarmAct_state_id = AlarmAct_WAITING;
}

STATE_DEFINE(AlarmAct_alarm_off)
{
	// State Action
	// State ID
	AlarmAct_state_id = AlarmAct_ALARM_OFF;

	// Stop Actuator
	Set_Alarm_actuator(1);

	// Check event and update state
	AlarmAct_state = STATE(AlarmAct_waiting);
}

STATE_DEFINE(AlarmAct_alarm_on)
{
	// State Action
	// State ID
	AlarmAct_state_id = AlarmAct_ALARM_ON;

	// Start Actuator
	Set_Alarm_actuator(0);

	// Check event and update state
	AlarmAct_state = STATE(AlarmAct_waiting);
}

void start_alarm(void)
{
	// Update state
	AlarmAct_state = STATE(AlarmAct_alarm_on);
}

void stop_alarm(void)
{
	// Update state
	AlarmAct_state = STATE(AlarmAct_alarm_off);
}
