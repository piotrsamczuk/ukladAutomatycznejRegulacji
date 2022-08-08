#pragma once
#include "Regulator.h"
#define KP 4.0
#define KI 0.02
#define KD 0.1

class RegulatorPID: public Regulator
{
	float kp, ki, kd,  eprev, ec;
public:
	RegulatorPID(float _target): Regulator(_target), kp(KP), ki(KI), kd(KD), ec(0.0), eprev(0.0) {}
	RegulatorPID() : kp(KP), ki(KI), kd(KD), eprev(0.0), ec(0.0) {}
	void control(float dt);
};	