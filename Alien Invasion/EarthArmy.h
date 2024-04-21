#pragma once
#include "ArmyUnit.h"
#include"EarthSoldierQ.h"
#include"GunneryPriQ.h"
#include "TanksStack.h"

//EarthArmy class that holds all the units of the Earth Army
class EarthArmy {
private:
	EarthSoldierQueue EarthSoldiers; //Queue of soldiers
	EarthTankStack EarthTanks; //Stack of tanks
	GunneryPriQueue EarthGunneries; //Priority Queue of gunnery
	LinkedQueue<ArmyUnit*> KilledEarth; //Queue of all the units in the army
	int killcount = 0; //Counter to keep track of the number of units killed
	int current_id = 0; //Counter to keep track of the next id to be assigned to a new unit
public:
	EarthArmy();
	bool attack(); //Attack function that attacks the Alien army
	bool addunit(ArmyUnit* unit); //Adds any army unit to the army based on the enum type
	void removeunit(TYPE t, ArmyUnit*& unit); //Removes any army unit from the army based on the enum type
//TODO: make the killunit function remove unit automatically
	void killunit(ArmyUnit* unit); //Kills any army unit and adds it to the KilledEarth queue

	
	void print(); //Prints the army
	int get_soldier_id();//Returns the total number of soldiers in the army
	int get_tank_id();//Returns the total number of tanks in the army
	int get_gunnery_id();//Returns the total number of gunnery in the army
	int get_next_id();//Returns the next id to be assigned to a new unit by adding the total number of units in the army
	int get_killcount();//Returns the total number of units killed
	
	void print_killed(); //Prints the KilledEarth queue


};
