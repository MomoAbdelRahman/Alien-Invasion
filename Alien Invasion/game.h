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
	//Function to read the configuration data from a text file
	void read_data();
	//An instance of the random generator to manage the random creation of units
	randgen* generator;
	//The two armies
	AlienArmy Aliens;
	EarthArmy Humans;
	//The function called to start the game
	void go();
	game();

	void add_humans();
	void add_aliens();

	void printstate();

	void print_humans();

	void print_aliens();

	void steptime(); //Function to simulate a time step and add new units to the armies if the probability is met

	void print_killed();

	
};
