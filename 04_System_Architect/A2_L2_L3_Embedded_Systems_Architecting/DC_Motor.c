/*
 * DC_Motor.c
 *
 *  Created on: Oct 23, 2021
 *      Author: MahmoudH
 */

#include "DC_Motor.h"
#include <stdio.h>

enum
{
	DC_INIT,
	DC_IDLE,
	DC_BUSY
} DC_state_id;

extern void (*DC_state)();

static unsigned int speed;

STATE_DEFINE(DC_init)
{
	// Init DC
	DC_state_id = DC_INIT;
	printf("\nDC_init_state\n");

	// Check event and update state
	DC_state = STATE(DC_idle);
}

STATE_DEFINE(DC_idle)
{
	// State Action
	DC_state_id = DC_IDLE;

	printf("\nDC_idle_state: speed = %d\n", speed);

	// Check event and update state
	DC_state = STATE(DC_idle); // As long as no speed is received
}

STATE_DEFINE(DC_busy)
{
	// State Action
	DC_state_id = DC_BUSY;

	printf("\nDC_busy_state: speed = %d\n", speed);

	// Check event and update state
	DC_state = STATE(DC_idle);
}


// Interface with CA (get speed from CA)
void DC_Motor_speed(unsigned int s)
{
	speed = s;
	printf("\nCA -> -> speed -> -> DC\n");
	DC_state = STATE(DC_busy);
}
