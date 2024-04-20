#include "AlienSoldier.h"

AlienSoldier::AlienSoldier(int id, int health, int power, int jointime, int attackcapacity):ArmyUnit(id, ALIENSOLDIER, health, jointime, power, attackcapacity) {

}

bool AlienSoldier::attack()
{
	return true;
}
