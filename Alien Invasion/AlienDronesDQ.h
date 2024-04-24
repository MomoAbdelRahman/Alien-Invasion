#pragma once
#include "Deque.h"
#include "AlienDrone.h"
//A class that stores the AlienDrone units in a Deque data structure
class AlienDronesDequeue{
private:
	int count; //number of AlienDrone units
	Deque<AlienDrone*> alienDD; //Deque data structure that stores AlienDrone units
public:
	AlienDronesDequeue(); //constructor
	void insertDrone(AlienDrone* alienDrone1, AlienDrone* alienDrone2); //inserts 2 AlienDrone units into the Deque
	void removeDrones(AlienDrone*& removed1, AlienDrone*& removed2); //removes 2 AlienDrone units from the Deque

	void print(); //prints the AlienDrone units in the Deque
	int get_count(); //returns the number of AlienDrone units in the Deque

	void select_drone(AlienDrone* &ad1, AlienDrone* &ad2); //selects 2 AlienDrone units from the Deque
	bool isEmpty(); //checks if the Deque is empty
	LinkedQueue<ArmyUnit*>* get_drones(int n); //returns the AlienDrone units in the Deque
};
