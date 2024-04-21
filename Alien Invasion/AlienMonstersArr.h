#pragma once
#include "AlienMonster.h"
#include "LinkedQueue.h"
//An array of AlienMonster objects that can be added to and removed from due to their dynamic nature
class AlienMonstersArray
{
private:
	AlienMonster** alienMonsters; //Array of AlienMonster objects
	int size; //Size of the array
	int count; //Number of AlienMonster objects in the array
	int next=-1; //Index of the next AlienMonster object to be selected which is
public:
	AlienMonstersArray(int size = 100); //Creates an array of AlienMonster objects with a default size of 100

	void add(AlienMonster* alienMonster); //Adds an AlienMonster object to the array
	void remove(AlienMonster*& monster); //Removes an AlienMonster object from the array

	void print(); //Prints the ID of AlienMonster objects in the array
	int get_count(); //Returns the number of AlienMonster objects in the array
	
	void select_monster(AlienMonster* &monster); //Returns a pointer to a the next AlienMonster object from the array

	LinkedQueue<ArmyUnit*>* get_monsters(int n); //Returns a queue of AlienMonster objects from the array

	bool isEmpty(); //Checks if the array is empty
};
