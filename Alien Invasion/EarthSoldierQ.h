#pragma once
#include "LinkedQueue.h"
#include <iostream>
#include "EarthSoldier.h"
using namespace std;
//This Class inherits from LinkedQueue and is used to store EarthSoldier objects
class EarthSoldierQueue
{
private:
	int count; //Keeps track of the number of EarthSoldier objects in the queue
	LinkedQueue<EarthSoldier*> soldiers; //Queue to store EarthSoldier objects
public:
	EarthSoldierQueue();
	void add_earthsoldier(EarthSoldier* soldier); //Adds an EarthSoldier object to the queue which is passed as a parameter


	void remove_earthsoldier(EarthSoldier*& soldier); //Dequeues an EarthSoldier object from the queue and returns a pointer to it


	void print(); //Prints the ID of all EarthSoldier objects in the queue along with the total number of EarthSoldier objects
		
	
	int get_count(); //Returns the total number of EarthSoldier objects in the queue

	void select_soldier(EarthSoldier* &soldier); //Returns a pointer to the EarthSoldier object at the front of the queue
	bool isempty(); //Returns true if the queue is empty, false otherwise
};
