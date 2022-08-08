#pragma once
#include <iostream>
#include <exception>

template <typename T>
T userInput() {
	T input;
	while (1) {
		//std::cout << std::endl;
		std::cin >> input;
		if (std::cin.fail()) {
			std::cout << "Blad wprowadzania." << std::endl;
			std::cin.clear();														//reset flagi bledu
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//czyszczenie bufora maksymalnego rozmiaru bufora lub do znaku nowej linii
		}
		else
			break;
	}
	return input;
}

static void viewHeadline() {
	std::cout << std::right;
	std::cout.width(50);
	std::cout.fill(':');
	std::cout << "\n";
	std::cout.width(10);
	std::cout << "";
	std::cout << "UKLAD AUTOMATYCZNEJ REGULACJI";
	std::cout.width(11);
	std::cout.fill(':');
	std::cout << "\n";
	std::cout.width(50);
	std::cout.fill(':');
	std::cout << "\n" << std::endl;
	std::cout.fill(' ');
}

class nullptrException : public std::exception
{
	virtual const char* what() const throw()			//syntax const throw()????
	{
		return "Dereferencja nullptr";
	}
};

class divisionbyzeroException: public std::exception
{
	virtual const char* what() const throw()
	{
		return "Dzielenie przez zero";
	}
};