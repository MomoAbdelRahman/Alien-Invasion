#pragma once
#include "ArmyUnit.h"

//Alien Drone class that inherits from the more general Army Unit class
class AlienDrone : public ArmyUnit
{
public:
	AlienDrone(int id, int health, int power, int jointime, int attackcapcity);

	//Attack Function that will be overrided by the derived classes
	bool attack() override;
};