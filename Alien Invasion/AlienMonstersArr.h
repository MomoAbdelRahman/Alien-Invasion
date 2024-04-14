#pragma once
#include "AlienMonster.h"
//An array of AlienMonster objects that can be added to and removed from due to their dynamic nature
class AlienMonstersArray
{
private:
	AlienMonster** alienMonsters;
	int size;
	int count;
	int next;
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
	void remove(AlienMonster* &monster ) { //Removes an AlienMonster object from the array
		if(count>0){
			monster = alienMonsters[next];
			for (int i = next; i < count - 1; i++) { //Shifts the elements to the left
				alienMonsters[i] = alienMonsters[i + 1];
			}
			count--;
		}
	};

	void print() { //Prints the ID of AlienMonster objects in the array
		//cout << "======================Alien Monster Units========================" << endl;
		cout << "AM:" << count << " [";
		for(int i = 0; i < count-1; i++) {
			cout << alienMonsters[i]->get_id()<<",";
		}
		cout<<alienMonsters[count-1]->get_id();
		cout << "]" << endl;
	}

	int get_count() { //Returns the number of AlienMonster objects in the array
		return count;
	}
	void select_monster(AlienMonster* monster) {
		monster=alienMonsters[next];
	}
};