#include "EarthTank.h"

EarthTank::EarthTank(int id, int health, int jointime, int power, int attackcapacity) :ArmyUnit(id, TANK, health, jointime, power, attackcapacity) {

}

bool EarthTank::attack()
{
	return true;
}
