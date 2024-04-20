#pragma once
#include "Deque.h"
#include "AlienDrone.h"
//A class that stores the AlienDrone units in a Deque data structure
class AlienDronesDequeue{
private:
	int count;
	Deque<AlienDrone*> alienDD;
public:
	AlienDronesDequeue();
	void insertDrone(AlienDrone* alienDrone1, AlienDrone* alienDrone2);
	void removeDrones(AlienDrone*& removed1, AlienDrone*& removed2);

	void print();
	int get_count();

	void select_drone(AlienDrone* &ad1, AlienDrone* &ad2);
	bool isEmpty();
};
