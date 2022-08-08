#include "Simulation.h"

void Simulation::iterate(float _dt)
{
	regulator->control(_dt);
	room.dodajCieplo(heater.currPower());
	room.aktualizuj(_dt);
}

void Simulation::sequence(int n, float _dt)
{
	try
	{
		if (regulator == nullptr)	//undefined behaviour
			throw nullptrException();
		regulator->setPomieszczenie(&room);
		regulator->setRadiator(&heater);

		//czy w tym miejscu nie lepiej zrobic drugi try i catch?
		if (_dt == 0)	//undefined behaviour
			throw divisionbyzeroException();
		for (int i = 0; i < n; i++)
		{
			iterate(_dt);
			time.push_back(_dt * i);
			temp.push_back(room.getTemperatura());
			power.push_back(heater.currPower());
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
}

void Simulation::save(const char* _filename = "wyniki.csv")
{
	//metoda nie stworzy pliku jesli nie ma wynikow do zapisania
	if(time.empty() == 1)
		return;
	std::ofstream file(_filename);
	//zmiana locale na polskie, aby dane zapisaly sie w postaci zmiennoprzecinkowej
	std::locale pol("pl_PL");
	file.imbue(pol);
	file.clear();
	if (file.is_open() && !file.fail())
	{
		file << "Czas[s]" << ";" << "Temperatura[C]" << ";" << "Moc[W]" << std::endl;
		for (int i = 0; i < time.size(); i++)
		{
			file << time[i] << ";" << temp[i] << ";" << power[i] << std::endl;
		}
	}
	else
		std::cout << "Blad zapisu pliku z wynikami." << std::endl;
	file.close();

	time.clear();
	temp.clear();
	power.clear();
}

void Simulation::setRegulator(Regulator* _regulator)
{
	regulator = _regulator;
}