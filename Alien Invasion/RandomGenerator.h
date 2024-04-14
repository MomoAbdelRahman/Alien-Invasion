#pragma once
#include "gameconfig.h"
#include "ArmyUnit.h"
#include "EarthSoldier.h"
#include "EarthTank.h"
#include "EarthGunnery.h"
#include "AlienSoldier.h"
#include "AlienMonster.h"
#include "AlienDrone.h"
#include"AlienArmy.h"
#include"EarthArmy.h"
class randgen {
private:
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

public:
	randgen(gameconfig &config) {
		N = config.N;
		ES = config.ES;
		ET = config.ET;
		EG = config.EG;
		AS = config.AS;
		AM = config.AM;
		AD = config.AD;
		prob = config.prob;
		min_earth_health = config.min_earth_health;
		max_earth_health = config.max_earth_health;
		min_earth_power = config.min_earth_power;
		max_earth_power = config.max_earth_power;
		min_earth_capacity = config.min_earth_capacity;
		max_earth_capacity = config.max_earth_capacity;
		min_alien_health = config.min_alien_health;
		max_alien_health = config.max_alien_health;
		min_alien_power = config.min_alien_power;
		max_alien_power = config.max_alien_power;
		min_alien_capacity = config.min_alien_capacity;
		max_alien_capacity = config.max_alien_capacity;

	}

	ArmyUnit* Earthgenerator(int ID, int jt) {
		int rand_health = rand() % (max_earth_health - min_earth_health + 1) + min_earth_health; //Generates a random number between min and max health
		int rand_power= rand() % (max_earth_power - min_earth_power + 1) + min_earth_power; //Generates a random number between min and max power
		int rand_capacity = rand() % (max_earth_capacity - min_earth_capacity + 1) + min_earth_capacity; //Generates a random number between min and max capacity
		ArmyUnit* unit = nullptr;
		int B = rand() % 100; //Generates a random number between 0 and 100
		if (B <= ES) {
			unit = new EarthSoldier(ID, rand_health,jt , rand_power, rand_capacity); //Creates a new EarthSoldier object if B is less than or equal to ES
		}
		else if (B <= ES + ET) {
			unit=new EarthTank(ID, rand_health, jt, rand_power, rand_capacity); //Creates a new EarthTank object if B is less than or equal to ES + ET
		}
		else if (B <= ES + ET + EG) {
			unit=new EarthGunnery(ID, rand_health, jt, rand_power, rand_capacity); //Creates a new EarthGunnery object if B is less than or equal to ES + ET + EG
		}	
		return unit;
	}

	ArmyUnit* Aliengenerator(int ID, int jt) {
		ArmyUnit* unit = nullptr;
		int rand_health = rand() % (max_alien_health - min_alien_health + 1) + min_alien_health;
		int rand_power = rand() % (max_alien_power - min_alien_power + 1) + min_alien_power;
		int rand_capacity = rand() % (max_alien_capacity - min_alien_capacity + 1) + min_alien_capacity;	
		int B = rand() % 100;
			if (B <= AS) {
				unit = new AlienSoldier(ID, rand_health, jt, rand_power, rand_capacity);
			}
			else if (B <= AS + AM) {
				unit = new AlienMonster(ID, rand_health, jt, rand_power, rand_capacity);
			}
			else if (B <= AS + AM + AD) {
				unit=new AlienDrone(ID, rand_health, jt, rand_power, rand_capacity);
			}
		return unit;
	}


};