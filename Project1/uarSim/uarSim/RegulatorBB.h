#pragma once
#include "Regulator.h"

class RegulatorBB : public Regulator
{
public:
	RegulatorBB(): Regulator() {}
	RegulatorBB(float _target) : Regulator(_target) {}
	void control(float dt);
};