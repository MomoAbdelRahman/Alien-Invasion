#pragma once
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <math.h>
#include "gameconfig.h"
using namespace std;
class game{
private:
	//Instance of gameconfig to held values
	gameconfig config;

	//Function to read the configuration data from a text file
	void read_data() {
		ifstream Data("Generator_Sample.txt");
		Data >> config.N;
		Data >> config.ES;
		Data >> config.ET;
		Data >> config.EG;
		Data >> config.AS;
		Data >> config.AM;
		Data >> config.AD;
		Data >> config.prob;
		Data >> config.min_earth_power;
		Data >> config.max_earth_power;
		Data >> config.min_earth_health;
		Data >> config.max_earth_health;
		Data >> config.min_earth_capacity;
		Data >> config.max_earth_capacity;
		Data >> config.min_alien_power;
		Data >> config.max_alien_power;
		Data >> config.min_alien_health;
		Data >> config.max_alien_health;
		Data >> config.min_alien_capacity;
		Data >> config.max_alien_capacity;
		Data.close();
		config.max_earth_power = abs(config.max_earth_power);
		config.max_earth_health = abs(config.max_earth_health);
		config.max_earth_capacity = abs(config.max_earth_capacity);
		config.max_alien_power = abs(config.max_alien_power);
		config.max_alien_health = abs(config.max_alien_health);
		config.max_alien_capacity = abs(config.max_alien_capacity);
	}


};