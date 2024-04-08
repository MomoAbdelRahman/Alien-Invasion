#pragma once
#include "AlienDrone.h"
#include "AlienMonster.h"
#include "AlienSoldier.h"
#include "LinkedQueue.h"
#include "Deque.h"

//AlienArmy class that holds all the units of aliens army
class AlienArmy {
private:
	LinkedQueue<AlienSoldier*> AlienSoldiers; //Queue of AlienSoldiers
	Deque<AlienDrone*> AlienDrones; //Deque of AlienDrones
	AlienMonster** AlienMonsters = new AlienMonster*[100]; //Dynamic Array of AlienMonsters
	LinkedQueue<ArmyUnit*> KilledAliens; //Queue of KilledAliens
public:
	AlienArmy();
	bool Attack(); //Attack function that attacks the human army
	bool addunit(ArmyUnit* unit); //Adds any army unit to the AlienArmy based on the enum type
	bool removeunit(ArmyUnit* unit); //Removes any army unit from the AlienArmy based on the enum type
	void print(); //Prints all the units of the AlienArmy
};