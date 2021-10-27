/*
 * Pressure_Sensor.h
 *
 *  Created on: Oct 25, 2021
 *      Author: MahmoudH
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"

// Prototypes
STATE_DEFINE(PS_init);
STATE_DEFINE(PS_reading);
STATE_DEFINE(PS_waiting);

#endif /* PRESSURE_SENSOR_H_ */
