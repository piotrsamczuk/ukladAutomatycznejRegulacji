#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "utilities.h" //iostream w utilities.h
#include "Simulation.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"

int main()
{
	int n = 1000;
	float dt = 0.5;

	int ch = 0;
	while (1)
	{
		viewHeadline();
		std::cout << "Wybor regulatora: " << std::endl;
		std::cout << "1: Regulator Bang-Bang" << std::endl;
		std::cout << "2: Regulator PID" << std::endl;
		std::cout << "3: Wyjscie z programu" << std::endl;
		switch (userInput<int>())
		{
		//regulator bang-bang
		case 1:
		{
			Simulation sim;
			RegulatorBB bang;
			sim.setRegulator(&bang);
			if (dt > 0)
				sim.sequence(n, dt);
			const char* filename = "bangbang.csv";
			sim.save(filename);
			break;
		}
		//regulator pid
		case 2:
		{
			Simulation sim;
			RegulatorPID pid;
			sim.setRegulator(&pid);
			if (dt > 0)
				sim.sequence(n, dt);
			const char* filename = "pid.csv";
			sim.save(filename);
			break;
		}		
		//wyjscie
		case 3:
		{
			_CrtDumpMemoryLeaks();
			return 0;
		}
		default:
			std::cout << "Nie rozpoznano akcji." << std::endl;
		}
		system("pause");
		system("cls");
	}
	_CrtDumpMemoryLeaks();
	return 0;
}