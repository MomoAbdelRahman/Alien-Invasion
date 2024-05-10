#pragma once
#include "ArmyUnit.h"

//Alien Monster class that inherits from the more general Army Unit class
class AlienMonster : public ArmyUnit
{
public:
	AlienMonster(int id, int health, int jointime, int power, int attackcapcity);

	//Attack Function that will be overrided by the derived classes
	bool attack() override;
};