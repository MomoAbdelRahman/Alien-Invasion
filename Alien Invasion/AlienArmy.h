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
	int current_id= 2000; //Counter for the current id of the aliens
public:
	AlienArmy(); //Default Constructor

	bool Attack(); //Attack function that attacks the human army

	bool addunit(ArmyUnit* unit);//Adds any army unit to the AlienArmy based on the enum type
	
	
	void removeunit(TYPE t, ArmyUnit*& unit, ArmyUnit*& unit2);//Removes any army unit from the AlienArmy based on the enum type
		
	

	void killunit(ArmyUnit* unit);//Kills any army unit from the AlienArmy



	void print();//Prints all the units of the AlienArmy

	bool isEmpty(); //Checks if all of the army is gone
	
	int get_soldier_id(); //Returns the number of AlienSoldiers
	int get_drone_id(); //Returns the number of AlienDrones
	int get_monster_id(); //Returns the number of AlienMonsters

	int get_next_id(); //Returns the id of the next alien to be used
	int get_killcount(); //Returns the number of killed aliens

	void print_killed(); //Prints all the killed aliens
	LinkedQueue<ArmyUnit*>* get_soldiers(int n); //Returns n number of AlienSoldiers
	LinkedQueue<ArmyUnit*>* get_monsters(int n); //Returns n number of AlienMonsters
	LinkedQueue<ArmyUnit*>* get_drones(int n); //Returns n number of AlienDrones
};