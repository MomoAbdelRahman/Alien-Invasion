#include "AlienDrone.h"

AlienDrone::AlienDrone(int id, int health, int power, int jointime, int attackcapcity):ArmyUnit(id, DRONE, health, jointime, power, attackcapcity)
{
}

bool AlienDrone::attack()
{
	return true;
}
