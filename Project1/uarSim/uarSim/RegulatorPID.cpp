#include "RegulatorPID.h"

void RegulatorPID::control(float dt)
{
	float up, ui, ud, de;

	float e = targetTemp - roomptr->getTemperatura();			//czy tworzenie i przypisanie e jest szybsze niz zapisywanie do atrybutu e?
	up = kp * e;												//czy na pewno oplaca sie robic zmienne up, ui, de, ud dla samej przejrzystosci kodu?

	ec += (e * dt);
	ui = ki * ec;

	de = (e - eprev) / dt;
	ud = kd * de;

	eprev = e;
	heaterptr->setPower(up + ui + ud);
}