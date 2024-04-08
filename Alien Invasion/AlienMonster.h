#pragma once
#include "ArmyUnit.h"

//Alien Monster class that inherits from the more general Army Unit class
class AlienMonster : public ArmyUnit
{
	AlienMonster(int id, int health, int power, int jointime, int attackcapcity):ArmyUnit(id,MONSTER,health,jointime,power,attackcapcity){
	}

	//Attack Function that will be overrided by the derived classes
	bool attack() override {
		return true;
	}
};