#pragma once
#include "ArmyUnit.h"
#include "LinkedQueue.h"
//EarthHealer class that inherits from the more general ArmyUnit class

class EarthHealer : public ArmyUnit
{
public:
	EarthHealer(int id, int health, int jointime, int power, int attackcapacity);

	//Attack Function that will be overrided by the derived classes
	bool attack() override;
};