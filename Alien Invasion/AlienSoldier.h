#pragma once
#include "ArmyUnit.h"

//Alien Soldier class that inherits from the more general Army Unit class
class AlienSoldier : public ArmyUnit
{
	AlienSoldier(int id, int health, int power, int jointime, int attackcapacity):ArmyUnit(id,ALIENSOLDIER,health,jointime,power,attackcapacity){
	
	}

	//Attack Function that will be overrided by the derived classes
	bool attack(){
		return true;
	}
};