#pragma once
#define ROOMTEMP 21.0
#include "Pomieszczenie.h"
#include "Radiator.h"

class Regulator
{
protected:
	Pomieszczenie* roomptr = nullptr;
	Radiator* heaterptr = nullptr;
	float targetTemp;
public:
	Regulator() : targetTemp(ROOMTEMP) {}
	Regulator(float _target): targetTemp(_target) {}
	virtual void control(float dt) = 0;
	void setPomieszczenie(Pomieszczenie* _roomptr) { roomptr = _roomptr; }
	void setRadiator(Radiator* _heaterptr) { heaterptr = _heaterptr; }
};