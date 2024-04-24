#pragma once
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <math.h>
#include "RandomGenerator.h"
#include"game.h"
using namespace std;
class game{
public:
	
	//Instance of gameconfig to held values
	gameconfig config;
	int time;
	int killcount;
	//Function to read the configuration data from a text file
	void read_data();
	
	//An instance of the random generator to manage the random creation of units
	randgen* generator;
	
	//The two armies
	AlienArmy Aliens;
	EarthArmy Humans;
	LinkedQueue<ArmyUnit*> killed;
	void go(); //The function called to start the game
	game(); //Constructor

	void add_humans(); //Function to add humans to the army
	void add_aliens(); //Function to add aliens to the army

	void printstate(); //Function to print the state of the game

	void print_humans(); //Function to print the humans in the army

	void print_aliens(); //Function to print the aliens in the army

	void steptime(); //Function to simulate a time step and add new units to the armies if the probability is met

	void print_killed(); //Function to print the units killed in the last time step

	LinkedQueue<ArmyUnit*>* get_enemies(TYPE t, int n); //Function to get the enemies of a unit
	void kill_unit(ArmyUnit* u); //Function to kill a unit
	
};
