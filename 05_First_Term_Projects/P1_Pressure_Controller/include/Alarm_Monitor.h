/*
 * Alarm_Monitor.h
 *
 *  Created on: Oct 25, 2021
 *      Author: MahmoudH
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"

// Prototypes
STATE_DEFINE(AlarmMon_alarm_off);
STATE_DEFINE(AlarmMon_alarm_on);
STATE_DEFINE(AlarmMon_waiting);

#endif /* ALARM_MONITOR_H_ */
