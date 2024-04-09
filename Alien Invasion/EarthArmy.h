#pragma once
#include"EarthSoldierQ.h"
#include"GunneryPriQ.h"
#include "TanksStack.h"
#include "ArmyUnit.h"

//EarthArmy class that holds all the units of the Earth Army
class EarthArmy {
private:
	EarthSoldierQueue EarthSoldiers; //Queue of soldiers
	EarthTankStack EarthTanks; //Stack of tanks
	GunneryPriQueue EarthGunnery; //Priority Queue of gunnery
	LinkedQueue<ArmyUnit*> KilledEarth; //Queue of all the units in the army
public:
	EarthArmy();
	bool attack(); //Attack function that attacks the Alien army
	bool addunit(ArmyUnit* unit); //Adds any army unit to the army based on the enum type
	bool removeunit(ArmyUnit* unit); //Remove unit from the army based on the enum type
	void print(); //Prints all the units in the army

	int get_soldier_id() {
		return EarthSoldiers.get_count();
	}
	int get_tank_id() {
		return EarthTanks.get_count();
	}
	int get_gunnery_id() {
		return EarthGunnery.get_count();
	}
};