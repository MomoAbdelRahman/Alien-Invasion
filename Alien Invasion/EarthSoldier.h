#pragma once
#include"ArmyUnit.h"
#include"LinkedQueue.h"
#include"RandomGenerator.h"

//Earth Soldier Class that inherits from the more general ArmyUnit
class EarthSoldier : public ArmyUnit
{
public:
	EarthSoldier(int id, int health,int jointime,int power,int attack_capacity):ArmyUnit(id,EARTHSOLDIER,health,jointime,power,attack_capacity){
	}

	//Attack Function that will be overrided by the derived classes
	bool attack() override{
		return true;
	}
};