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
	GunneryPriQueue EarthGunneries; //Priority Queue of gunnery
	LinkedQueue<ArmyUnit*> KilledEarth; //Queue of all the units in the army
public:
	EarthArmy() {

	}
	bool attack(); //Attack function that attacks the Alien army

	bool addunit(ArmyUnit* unit) { //Adds any army unit to the army based on the enum type
		switch (unit->get_type()) {
		case EARTHSOLDIER:
			EarthSoldiers.add_earthsoldier((EarthSoldier*)unit);
			break;
		case TANK:
			EarthTanks.AddTank((EarthTank*)unit);
			break;
		case GUNNERY:
			int priority = ((EarthGunnery*)unit)->get_health()+((EarthGunnery*)unit)->get_power();
			EarthGunneries.AddGunnery((EarthGunnery*)unit);
			break;
		}
		return true;
	
	}

	bool removeunit(ArmyUnit* unit); //Remove unit from the army based on the enum type
	void print(); //Prints all the units in the army

	int get_soldier_id() {
		return EarthSoldiers.get_count(); //Returns the total number of soldiers in the army
	}
	int get_tank_id() {
		return EarthTanks.get_count(); //Returns the total number of tanks in the army
	}
	int get_gunnery_id() {
		return EarthGunneries.get_count(); //Returns the total number of gunnery in the army
	}
	int get_next_id() {
		return get_soldier_id()+get_tank_id()+get_gunnery_id()+1; //Returns the next id to be assigned to a new unit by adding the total number of units in the army
	}
};