#pragma once
#include "priQueue.h"
#include "EarthSoldier.h"
#include "EarthTank.h"
class UnitMaintenanceList {
private:
	int maxH;
	int count=0;
	int soldiers_count = 0;
	int tanks_count = 0;
	priQueue<EarthSoldier*> soldiers;
	LinkedQueue<EarthTank*> tanks;
public:
	UnitMaintenanceList();
	UnitMaintenanceList(int max_health);
	void set_max_health(int max_health);
	void add_tank(EarthTank* unit);
	void add_soldier(EarthSoldier* unit);
	void add_unit(ArmyUnit* unit);
	bool remove_tank(EarthTank*& unit);
	bool remove_soldier(EarthSoldier*& unit);
	bool remove_unit(ArmyUnit*& unit);
	bool is_empty();
	bool is_soldiers_empty();
	LinkedQueue<ArmyUnit*>* get_injured(int n);
	int get_count() const;
	int get_soldier_count() const;
	int get_tank_count() const;
	void print();

};
