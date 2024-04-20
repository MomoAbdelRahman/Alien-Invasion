#include "AlienMonster.h"

AlienMonster::AlienMonster(int id, int health, int power, int jointime, int attackcapcity) :ArmyUnit(id, MONSTER, health, jointime, power, attackcapcity) {
}

bool AlienMonster::attack()
{
	return true;
}
