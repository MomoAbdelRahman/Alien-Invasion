#pragma once
#include "AlienSoldiersQ.h"
#include "AlienDronesDQ.h"
#include "AlienMonstersArr.h"

//AlienArmy class that holds all the units of aliens army
class AlienArmy {
private:
	AlienSoldierQueue AlienSoldiers; //Queue of AlienSoldiers
	AlienDronesDequeue AlienDrones; //Deque of AlienDrones
	AlienMonstersArray AlienMonsters;//Dynamic Array of AlienMonsters
	LinkedQueue<ArmyUnit*> KilledAliens; //Queue of KilledAliens
	int killcount = 0; //Counter for the number of killed aliens
public:
	AlienArmy(); //Default Constructor

	bool Attack(); //Attack function that attacks the human army

	bool addunit(ArmyUnit* unit);//Adds any army unit to the AlienArmy based on the enum type
	
	
	void removeunit(TYPE t, ArmyUnit*& unit, ArmyUnit*& unit2);//Removes any army unit from the AlienArmy based on the enum type
		
	

	void killunit(ArmyUnit* unit);//Kills any army unit from the AlienArmy



	void print();//Prints all the units of the AlienArmy


	
	int get_soldier_id();
	int get_drone_id();
	int get_monster_id();

	int get_next_id();
	int get_killcount();

	void print_killed();
	LinkedQueue<ArmyUnit*> get_soldiers(int n);
};
