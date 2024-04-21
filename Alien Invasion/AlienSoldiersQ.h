#pragma once
#include "LinkedQueue.h"
#include "AlienSoldier.h"
#include <iostream>
using namespace std;
//This Class inherits from LinkedQueue and is used to store AlienSoldier objects
class AlienSoldierQueue
{
private:
	int count=0; //Keeps track of the number of AlienSoldier objects in the queue
	LinkedQueue <AlienSoldier*> soldiers; //Queue to store AlienSoldier objects
public:
	AlienSoldierQueue();

	void add_aliensoldier(AlienSoldier* soldier); //Adds an AlienSoldier object to the queue which is passed as a parameter


	void remove_aliensoldier(AlienSoldier*& soldier); //Dequeues an AlienSoldier object from the queue and returns a pointer to it

	void print();  //Prints the ID of all AlienSoldier objects in the queue along with the total number of EarthSoldier objects
		
	int get_count(); //Returns the total number of AlienSoldier objects in the queue
		

	void select_soldier(AlienSoldier* &soldier); //Returns a pointer to the next AlienSoldier object in the queue

	bool isEmpty(); //Checks if the queue is empty

	LinkedQueue<ArmyUnit*>* get_soldiers(int n); //Returns a queue of AlienSoldier objects from the queue
};