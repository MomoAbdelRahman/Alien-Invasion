#pragma once
#include "priQueue.h"
#include"EarthGunnery.h"
#include <iostream>
using namespace std;
//This class is a priority queue of EarthGunnery objects. It is used to store the EarthGunnery objects in a priority queue based on their health and power.
class GunneryPriQueue
{
private:
	int count = 0; //Total number of Gunnery Units
	int next = 0; //Priority of the next Gunnery Unit to be removed
	priQueue<EarthGunnery*> gunnerys; //Priority queue to store the Gunnery Units
public:
	GunneryPriQueue();//Constructor	
	void AddGunnery(EarthGunnery* gunnery); //Add a new Gunnery Unit to the priority queue
	void RemoveGunnery(EarthGunnery*& gunner);//Remove the Gunnery Unit with the highest priority
	void print(); //Print the Gunnery Units in the priority queue
	int get_count(); //Return the total number of Gunnery Units
	void select_gunnery(EarthGunnery* &gunnery); //Select the Gunnery Unit with the highest priority
	bool isEmpty(); //Check if the priority queue is empty
};
