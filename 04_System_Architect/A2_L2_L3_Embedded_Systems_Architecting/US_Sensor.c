/*
 * US_Sensor.c
 *
 *  Created on: Oct 23, 2021
 *      Author: MahmoudH
 */

#include "US_Sensor.h"
#include <stdio.h>
#include <stdlib.h>

enum
{
	US_INIT,
	US_BUSY
} US_state_id;

extern void (*US_state)();

static unsigned int distance;

static unsigned int generate_random(int l, int r, int count)
{
	int i, rand_num;

	for(i = 0; i < count; i++)
	{
		rand_num = (rand() % (r - l + 1)) + l;
	}

	return rand_num;
}


STATE_DEFINE(US_init)
{
	// Init the US Sensor
	// Call the US driver functions
	US_state_id = US_INIT;
	printf("\nUS_init_state\n");

	// Check event and update state
	US_state = STATE(US_busy);
}

STATE_DEFINE(US_busy)
{
	// State Action
	US_state_id = US_BUSY;

	// Read from US
	distance = generate_random(45, 55, 1);
	printf("\nUS_busy_state: distance = %d\n", distance);

	// Check event and update state
	US_state = STATE(US_busy);
}

// Interface with CA Module (set distance in CA)
unsigned int US_Sensor_distance(void)
{
	printf("\nUS -> -> distance -> -> CA\n");
	return distance;
}
