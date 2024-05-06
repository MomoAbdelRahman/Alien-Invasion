#pragma once
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <math.h>
#include "RandomGenerator.h"
using namespace std;
class game{
public:
	bool silent = false; //Bool variable to indicate whether the game is in silent mode or not
	//Instance of gameconfig to held values
	gameconfig config;
	int time;
	int killcount;
	int healed_successfully=0;
	int UML_new = 0; //Units added to UML this round
	bool tank_anxiety=false; //Bool variable to indicate whether earth soldiers fell below 30% of alien soldiers count and gets turned back off when ES is back to 80% of AS
	//Function to read the configuration data from a text file
	void read_data();
	
	void update_tank_status(); //Updates tank_anxiety

	randgen* generator=nullptr; //An instance of the random generator to manage the random creation of units
	
	//The two armies
	AlienArmy Aliens;
	EarthArmy Humans;
	UnitMaintenanceList UML;
	LinkedQueue<ArmyUnit*> killed;
	void go(); //The function called to start the game
	game(); //Constructor

	void add_humans(); //Function to add humans to the army
	void add_aliens(); //Function to add aliens to the army

	void printstate(); //Function to print the state of the game

	void print_humans(); //Function to print the humans in the army

	void print_aliens(); //Function to print the aliens in the army

	void print_UML(); //Function to print who is in the UML and how many 

	void update_UML(); //Function to move hurt soldiers and tanks to UML

	void steptime(); //Function to simulate a time step and add new units to the armies if the probability is met

	void print_killed(); //Function to print the units killed in the last time step

	void generate_output_file();

	LinkedQueue<ArmyUnit*>* get_enemies(TYPE t, int n); //Function to get the enemies of a unit
	void kill_unit(ArmyUnit* u); //Function to kill a unit

	void silent_step(); //Function to simulate a time step without printing the state of the game
};
