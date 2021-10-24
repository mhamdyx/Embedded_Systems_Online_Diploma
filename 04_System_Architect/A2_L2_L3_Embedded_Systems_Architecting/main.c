/*
 * main.c
 *
 *  Created on: Oct 23, 2021
 *      Author: MahmoudH
 */

#include <stdio.h>
#include "US_sensor.h"
#include "DC_Motor.h"
#include "Collision_Avoidance.h"

// Pointers to next state function for each module
void (*US_state)() = STATE(US_init);
void (*DC_state)() = STATE(DC_init);
void (*CA_state)() = STATE(CA_waiting);

int main(void)
{
	// Run state machine
	while(1)
	{
		US_state();
		DC_state();
		CA_state();
	}

	return 0;
}
