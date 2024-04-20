#pragma once
#include <iostream>
#include"ArmyUnit.h"
#include"LinkedQueue.h"
using namespace std;
//Earth Soldier Class that inherits from the more general ArmyUnit
class EarthSoldier : public ArmyUnit
{
public:
	EarthSoldier(int id, int health, int jointime, int power, int attack_capacity);
	//Attack Function that will be overrided by the derived classes
	bool attack() override;
};