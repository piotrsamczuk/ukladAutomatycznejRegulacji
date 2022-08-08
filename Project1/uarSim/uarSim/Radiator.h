#pragma once
#define NOMINALHEATERPOWER 10000.0

class Radiator
{
	const float nominalPower;
	float powerLevel;	//range 0.0-0.1
public:
	Radiator(): nominalPower(NOMINALHEATERPOWER), powerLevel(0.0) {}
	Radiator(const float _nominalPower, float _powerLevel);
	Radiator(const float _nominalPower) : nominalPower(_nominalPower) {}
	float currPower() { return nominalPower * powerLevel; }
	void setPower(float _powerLevel);
};