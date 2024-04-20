#include "EarthGunnery.h"

EarthGunnery::EarthGunnery(int id, int health, int power, int jointime, int attackcapacity) :ArmyUnit(id, GUNNERY, health, jointime, power, attackcapacity) {
}

bool EarthGunnery::attack()
{
	return true;
}

