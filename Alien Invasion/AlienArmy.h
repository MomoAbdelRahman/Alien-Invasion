#pragma once
#include "AlienSoldiersQ.h"
#include "AlienDronesDQ.h"
#include "AlienMonstersArr.h"
#include "LinkedQueue.h"

//AlienArmy class that holds all the units of aliens army
class AlienArmy {
private:
	AlienSoldierQueue AlienSoldiers; //Queue of AlienSoldiers
	AlienDronesDequeue AlienDrones; //Deque of AlienDrones
	AlienMonstersArray AlienMonsters;//Dynamic Array of AlienMonsters
	LinkedQueue<ArmyUnit*> KilledAliens; //Queue of KilledAliens
public:
	AlienArmy();
	bool Attack(); //Attack function that attacks the human army
	bool addunit(ArmyUnit* unit); //Adds any army unit to the AlienArmy based on the enum type
	bool removeunit(ArmyUnit* unit); //Removes any army unit from the AlienArmy based on the enum type
	void print(); //Prints all the units of the AlienArmy
};