#pragma once
#include "ArmyUnit.h"

//Alien Soldier class that inherits from the more general Army Unit class
class AlienSoldier : public ArmyUnit
{
public:
	AlienSoldier(int id, int health, int jointime, int power, int attackcapacity);

	//Attack Function that will be overrided by the derived classes
	bool attack();
};