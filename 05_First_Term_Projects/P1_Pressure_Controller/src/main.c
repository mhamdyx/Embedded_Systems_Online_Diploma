#include "driver.h"
#include "Pressure_Sensor.h"
#include "Alarm_Monitor.h"
#include "Alarm_Actuator.h"
#include "Main_Algorithm.h"

void (*PS_state)() = STATE(PS_init);
void (*AlarmMon_state)() = STATE(AlarmMon_alarm_off);
void (*AlarmAct_state)() = STATE(AlarmAct_init);
void (*MainAlg_state)() = STATE(MainAlg_pressure_detect);


int main(void)
{
	// Hardware Initialization
	GPIO_INITIALIZATION();

	// Run state machine forever
	while (1)
	{
		PS_state();
		MainAlg_state();
		AlarmMon_state();
		AlarmAct_state();
	}

	return 0;
}
