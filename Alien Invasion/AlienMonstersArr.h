#pragma once
#include "AlienMonster.h"
//An array of AlienMonster objects that can be added to and removed from due to their dynamic nature
class AlienMonstersArray
{
private:
	AlienMonster** alienMonsters;
	int size;
	int count;
public:
	AlienMonstersArray(int size = 100) { //Creates an array of AlienMonster objects with a default size of 100
		this->size = size;
		this->count = 0;
		this->alienMonsters = new AlienMonster*[size];
	}
	void add(AlienMonster* alienMonster) { //Adds an AlienMonster object to the array
			if (count < size) {
			alienMonsters[count] = alienMonster;
			count++;
			}
			else
			{
				return;
			}
	
	}
	AlienMonster* remove(int index) { //Removes an AlienMonster object from the array
		AlienMonster* alienMonster = nullptr;
			if (index < count) {
			alienMonster = alienMonsters[index];
			for (int i = index; i < count - 1; i++) { //Shifts the elements to the left
				alienMonsters[i] = alienMonsters[i + 1];
			}
			count--;
		}
		return alienMonster;
	};

	void print() { //Prints the ID of AlienMonster objects in the array
		cout << "======================Alien Monster Units========================" << endl;
		cout << "Total Number of Alien Monster Units: " << count << " [";
		for(int i = 0; i < count; i++) {
			cout << alienMonsters[i]->get_id()<<",";
		}
		cout << "]" << endl;
	}

	int get_count() { //Returns the number of AlienMonster objects in the array
		return count;
	}
};