#pragma once
#include "AlienMonster.h"
//An array of AlienMonster objects that can be added to and removed from due to their dynamic nature
class AlienMonstersArray
{
private:
	AlienMonster** alienMonsters;
	int size;
	int count;
	int next=-1;
public:
	AlienMonstersArray(int size = 100); //Creates an array of AlienMonster objects with a default size of 100

	void add(AlienMonster* alienMonster); //Adds an AlienMonster object to the array
	void remove(AlienMonster*& monster); //Removes an AlienMonster object from the array


	void print(); //Prints the ID of AlienMonster objects in the array
	int get_count(); //Returns the number of AlienMonster objects in the array
	
	void select_monster(AlienMonster* &monster);

};
