#pragma once
#include <iostream> 
using namespace std;
//Structure to store the game configuration
struct gameconfig
{
	int N;
	int ES;
	int ET;
	int EG;
	int EH;
	int AS;
	int AM;
	int AD;
	int prob;

	int min_earth_power;
	int max_earth_power;

	int min_earth_health;
	int max_earth_health;

	int min_earth_capacity;
	int max_earth_capacity;

	int min_alien_power;
	int max_alien_power;

	int min_alien_health;
	int max_alien_health;

	int min_alien_capacity;
	int max_alien_capacity;

	//Function to print the game configuration for testing
	void print_config() {
		cout << "N: " << N << endl;
		cout << "ES: " << ES << endl;
		cout << "ET: " << ET << endl;
		cout << "EG: " << EG << endl;
		cout << "EH: " << EH << endl;
		cout << "AS: " << AS << endl;
		cout << "AM: " << AM << endl;
		cout << "AD: " << AD << endl;
		cout << "prob: " << prob << endl;
		cout << "min_earth_power: " << min_earth_power << endl;
		cout << "max_earth_power: " << max_earth_power << endl;
		cout << "min_earth_health: " << min_earth_health << endl;
		cout << "max_earth_health: " << max_earth_health << endl;
		cout << "min_earth_capacity: " << min_earth_capacity << endl;
		cout << "max_earth_capacity: " << max_earth_capacity << endl;
		cout << "min_alien_power: " << min_alien_power << endl;
		cout << "max_alien_power: " << max_alien_power << endl;
		cout << "min_alien_health: " << min_alien_health << endl;
		cout << "max_alien_health: " << max_alien_health << endl;
		cout << "min_alien_capacity: " << min_alien_capacity << endl;
		cout << "max_alien_capacity: " << max_alien_capacity << endl;
	}
};