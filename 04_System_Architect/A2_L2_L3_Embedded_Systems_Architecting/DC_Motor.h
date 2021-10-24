/*
 * DC_Motor.h
 *
 *  Created on: Oct 23, 2021
 *      Author: MahmoudH
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"

// Prototypes
STATE_DEFINE(DC_init);
STATE_DEFINE(DC_idle);
STATE_DEFINE(DC_busy);

#endif /* DC_MOTOR_H_ */
