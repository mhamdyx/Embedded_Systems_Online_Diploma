/*
 * Alarm_Actuator.h
 *
 *  Created on: Oct 25, 2021
 *      Author: MahmoudH
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include "state.h"

// Prototypes
STATE_DEFINE(AlarmAct_init);
STATE_DEFINE(AlarmAct_waiting);
STATE_DEFINE(AlarmAct_alarm_off);
STATE_DEFINE(AlarmAct_alarm_on);


#endif /* ALARM_ACTUATOR_H_ */
