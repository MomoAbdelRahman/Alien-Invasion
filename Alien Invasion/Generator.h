#pragma once
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;
int N;
int ES;
int ET;
int EG;
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


void read_data() {
	ifstream Data("Generator_Sample.txt");
	Data >> N;
	Data >> ES;
	Data >> ET;
	Data >> EG;
	Data >> AS;
	Data >> AM;
	Data >> AD;
	Data >> prob;
	Data>>min_earth_power;
	Data >> max_earth_power;
	Data>>min_earth_health;
	Data>>max_earth_health;
	Data>>min_earth_capacity;
	Data>>max_earth_capacity;
	Data>>min_alien_power;
	Data>>max_alien_power;
	Data>>min_alien_health;
	Data>>max_alien_health;
	Data>>min_alien_capacity;
	Data>>max_alien_capacity;
	Data.close();
	max_earth_power = abs(max_earth_power);
	max_earth_health= abs(max_earth_health);
	max_earth_capacity= abs(max_earth_capacity);
	max_alien_power= abs(max_alien_power);
	max_alien_health= abs(max_alien_health);
	max_alien_capacity = abs(max_alien_capacity);
}


void Earthgenerator() {
	int A = rand() % 100;
	if (A < prob) {
		for (int i = 0; i < N; i++) {
		int B = rand() % 100;
			if(B<=ES) {
				//ES
			}
			else if (B <= ES + ET) {
				//ET
			}
			else if (B <= ES + ET + EG) {
				//EG
			}
		}
	}

}

void Aliengenerator() {
	int A = rand() % 100;
	if (A < prob) {
		for (int i = 0; i < N; i++) {
			int B = rand() % 100;
			if (B <= AS) {
				//AS
			}
			else if (B <= AS + AM) {
				//AM
			}
			else if (B <= AS + AM + AD) {
				//AD
			}
		}
	}
}

void stepgenerator() {
	Earthgenerator();
	Aliengenerator();
}

void print_config() {
	cout<<"N: "<<N<<endl;
	cout<<"ES: "<<ES<<endl;
	cout<<"ET: "<<ET<<endl;
	cout<<"EG: "<<EG<<endl;
	cout<<"AS: "<<AS<<endl;
	cout<<"AM: "<<AM<<endl;
	cout<<"AD: "<<AD<<endl;
	cout<<"prob: "<<prob<<endl;
	cout<<"min_earth_power: "<<min_earth_power<<endl;
	cout<<"max_earth_power: "<<max_earth_power<<endl;
	cout<<"min_earth_health: "<<min_earth_health<<endl;
	cout<<"max_earth_health: "<<max_earth_health<<endl;
	cout<<"min_earth_capacity: "<<min_earth_capacity<<endl;
	cout<<"max_earth_capacity: "<<max_earth_capacity<<endl;
	cout<<"min_alien_power: "<<min_alien_power<<endl;
	cout<<"max_alien_power: "<<max_alien_power<<endl;
	cout<<"min_alien_health: "<<min_alien_health<<endl;
	cout<<"max_alien_health: "<<max_alien_health<<endl;
	cout<<"min_alien_capacity: "<<min_alien_capacity<<endl;
	cout<<"max_alien_capacity: "<<max_alien_capacity<<endl;
}
