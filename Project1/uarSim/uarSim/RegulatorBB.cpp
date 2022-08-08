#include "RegulatorBB.h"

void RegulatorBB::control(float dt)
{
	if (targetTemp > roomptr->getTemperatura())
		heaterptr->setPower(1.0);
	else
		heaterptr->setPower(0.0);
}