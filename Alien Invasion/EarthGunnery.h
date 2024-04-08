#pragma once
#include "ArmyUnit.h"
//EarthGunnery class that inherits from the more general ArmyUnit class

class EarthGunnery : public ArmyUnit
{
	EarthGunnery(int id, int health, int power,int jointime,int attackcapacity):ArmyUnit(id,GUNNERY,health,jointime,power,attackcapacity){
	
	}
	//Attack Function that will be overrided by the derived classes
	bool attack() override {
		return true;
	}
};