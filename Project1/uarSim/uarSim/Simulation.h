#pragma once
#include <fstream>
#include <vector>
#include <exception>
#include "Radiator.h"
#include "Pomieszczenie.h"
#include "Regulator.h"
#include "utilities.h"

class Simulation
{
	Pomieszczenie room;
	Radiator heater;
	Regulator* regulator;
	std::vector<float> temp;
	std::vector<float> time;
	std::vector<float> power;
public:
	Simulation(): room(5.6, 4.0, 2.5), heater(), regulator(nullptr) {}
	void iterate(float _dt);
	void sequence(int n, float _dt);
	void save(const char* _filename);
	void setRegulator(Regulator* _regulator);
};