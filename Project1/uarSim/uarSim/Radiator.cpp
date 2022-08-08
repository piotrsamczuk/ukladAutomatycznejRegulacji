#include "Radiator.h"

Radiator::Radiator(float _nominalPower, float _powerLevel)		//nie ma zabezpieczenia na moc nominalna, bo uzytkownik nie jest nigdzie proszony o wpisanie jej, a moc jest stala
	: nominalPower(_nominalPower)
{
	if (_powerLevel > 1.0)
		powerLevel = 1.0;
	else if (_powerLevel < 0.0)
		powerLevel = 0.0;
	else
		powerLevel = _powerLevel;
}

void Radiator::setPower(float _powerLevel)
{
	if (_powerLevel > 1.0)
		powerLevel = 1.0;
	else if (_powerLevel < 0.0)
		powerLevel = 0.0;
	else
		powerLevel = _powerLevel;
}