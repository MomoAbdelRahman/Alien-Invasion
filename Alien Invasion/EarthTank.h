#pragma once
#include "ArmyUnit.h"

//EarthTank class that inherits from the more general ArmyUnit class
class EarthTank : public ArmyUnit {
public:
	EarthTank(int id,int health, int jointime, int power,int attackcapacity):ArmyUnit(id,TANK,health,jointime,power,attackcapacity){
	
	}

	//Attack Function that will be overrided by the derived classes
	bool attack() override {
		return true;
	}
};