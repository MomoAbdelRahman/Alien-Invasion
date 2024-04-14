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
	int killcount = 0; //Counter to keep track of the number of units killed
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

	void removeunit(TYPE t, ArmyUnit* &unit){ //Removes any army unit from the army based on the enum type
		EarthSoldier* temp=nullptr;
		EarthTank* temp2=nullptr;
		EarthGunnery* temp3=nullptr;
		switch (t) {
		case EARTHSOLDIER:
			EarthSoldiers.remove_earthsoldier(temp);
			unit = temp;
			break;
		case TANK:
			EarthTanks.removeTank(temp2);
			unit = temp2;
			break;
		case GUNNERY:
			EarthGunneries.RemoveGunnery(temp3);
			unit = temp3;
			break;
		}
	}
	

	void killunit(ArmyUnit* unit) { //Kills any army unit and adds it to the KilledEarth queue
		KilledEarth.enqueue(unit);
		killcount++;
	}
	void print() { //Prints the army
		EarthSoldiers.print(); //Prints the soldiers in the army
		EarthTanks.print(); //Prints the tanks in the army
		EarthGunneries.print(); //Prints the gunnery in the army
	} 

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
	int get_killcount() {
		return killcount; //Returns the total number of units killed
	}
	void print_killed() {
		LinkedQueue<ArmyUnit*> temp;
		while (!KilledEarth.isEmpty()) {
			ArmyUnit* temp2;
			KilledEarth.dequeue(temp2);
			temp.enqueue(temp2);
			cout << temp2->get_id();
			if (!KilledEarth.isEmpty()) {
				cout << ",";
			}
		}
		while (!temp.isEmpty()) {
			ArmyUnit* temp3;
			temp.dequeue(temp3);
			KilledEarth.enqueue(temp3);
		}
	}
};