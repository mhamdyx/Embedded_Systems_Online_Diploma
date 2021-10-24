/*
 * Collision_Avoidance.c
 *
 *  Created on: Oct 23, 2021
 *      Author: MahmoudH
 */

#include "Collision_Avoidance.h"
#include <stdio.h>

enum
{
	CA_WAITING,
	CA_DRIVING
} CA_state_id;

extern void (*CA_state)();

static unsigned int speed, distance, threshold = 50;

STATE_DEFINE(CA_waiting)
{
	// State Actions
	CA_state_id = CA_WAITING;
	speed = 0;
	DC_Motor_speed(speed);
	distance = US_Sensor_distance();
	printf("\nCA_waiting_state: distance = %d  speed = %d\n", distance, speed);

	// Check event and update state
	(distance <= threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
}

STATE_DEFINE(CA_driving)
{
	// State Actions
	CA_state_id = CA_DRIVING;
	speed = 30;
	DC_Motor_speed(speed);
	distance = US_Sensor_distance();
	printf("\nCA_driving_state: distance = %d  speed = %d\n", distance, speed);

	// Check event
	(distance <= threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
}

