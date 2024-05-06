#include "game.h"

void game::read_data()
{
	ifstream Data("Generator_Sample.txt");
	Data >> config.N;
	Data >> config.ES;
	Data >> config.ET;
	Data >> config.EG;
	Data >> config.EH;
	Data >> config.AS;
	Data >> config.AM;
	Data >> config.AD;
	Data >> config.prob;
	Data >> config.min_earth_power;
	Data >> config.max_earth_power;
	Data >> config.min_earth_health;
	Data >> config.max_earth_health;
	Data >> config.min_earth_capacity;
	Data >> config.max_earth_capacity;
	Data >> config.min_alien_power;
	Data >> config.max_alien_power;
	Data >> config.min_alien_health;
	Data >> config.max_alien_health;
	Data >> config.min_alien_capacity;
	Data >> config.max_alien_capacity;
	Data.close();
	config.max_earth_power = abs(config.max_earth_power);
	config.max_earth_health = abs(config.max_earth_health);
	config.max_earth_capacity = abs(config.max_earth_capacity);
	config.max_alien_power = abs(config.max_alien_power);
	config.max_alien_health = abs(config.max_alien_health);
	config.max_alien_capacity = abs(config.max_alien_capacity);
}

void game::update_tank_status()
{
	if (tank_anxiety) {
		if (Humans.get_soldier_id() >= 0.8 * Aliens.get_soldier_id()) tank_anxiety = false;
	}
	else{
		if (Humans.get_soldier_id() <= 0.3 * Aliens.get_soldier_id()) tank_anxiety = true;
	}
}

void game::go()
{
	read_data();//Read the data from the file
	generator = new randgen(config); //Create the random generator with the configuration data
	UML.set_max_health(config.max_earth_health);
}

game::game()
{
	time = 0;
	go();
}

void game::add_humans()
{
	int next_Earth_ID;
	for (int i = 0; i < config.N; i++) {
		next_Earth_ID = Humans.get_next_id();//Get the ID of the next Earth unit
		ArmyUnit* newunit = generator->Earthgenerator(next_Earth_ID, time);//Generate new units for the Earth Army
		newunit->set_game(this);
		Humans.addunit(newunit); //Generate new units for the Earth Army and adds it to the army
	}
}

void game::add_aliens()
{
	int next_alien_ID;
	int count = 0;
	for (int i = 0; count < config.N; i++) {
		next_alien_ID = Aliens.get_next_id();//Get the ID of the next Alien unit
		ArmyUnit* newunit = generator->Aliengenerator(next_alien_ID, time);//Generate new units for the Alien Army
		newunit->set_game(this);
		if (newunit->get_type() == DRONE) {
			count = count + 2;
		}
		else {
			count++;
		}
		Aliens.addunit(newunit); //Generate new units for the Alien Army and adds it to the army
	}
}

void game::printstate()
{
	cout << "Time:" << time << endl;//Print the time"
	print_humans();
	print_aliens();
}

void game::print_humans() {
	cout << "======================Earth Army========================" << endl;
	Humans.print();
}
void game::print_aliens() {
	cout << "======================Alien Army========================" << endl;
	Aliens.print();
}

void game::steptime()
{
	printstate();
	cout << "=========================Attacks========================"<<endl;
	Humans.attack();
	Aliens.Attack();
	update_UML();
	int A = rand() % 100;
	if (A < config.prob) {
		add_humans();
		add_aliens();
	}
	print_UML();
	print_killed();
	cout << endl << endl;
	UML_new = 0;
	time++;
}

void game::print_UML()
{
	cout << "==================Unit Maintenance List=================" << endl;
	UML.print();
	cout << "(" << UML_new << " units added)" << endl;

}

void game::print_killed()
{
	cout << "=========================Killed=========================" << endl;
	cout << "Killed:" << killcount << " [";
	killed.printQ();
	cout << "]" << endl;
	//Humans.print_killed();
	//Aliens.print_killed();
	/*ArmyUnit* temp;
	LinkedQueue<ArmyUnit*> tempkilled;
	while (killed.dequeue(temp)) {
		if (temp) {
			cout << temp->get_id();
			if (!killed.isEmpty()) {
				cout << ",";
			}
			tempkilled.enqueue(temp);
		}
	}
	while (tempkilled.dequeue(temp)) {
		if (temp) {
			killed.enqueue(temp);
		}
	}

	cout << "]" << endl;;*/
}

void game::update_UML()
{
	LinkedQueue<EarthSoldier*>* hurt_soldiers = Humans.get_hurt_soldiers();
	LinkedQueue<EarthTank*>* hurt_tanks = Humans.get_hurt_tanks();
	EarthSoldier* soldier;
	EarthTank* tank;
	while (!hurt_soldiers->isEmpty()) {
		hurt_soldiers->dequeue(soldier);
		UML.add_soldier(soldier);
		soldier->set_UML_time(time);
		UML_new++;
	}
	while (!hurt_tanks->isEmpty()) {
		hurt_tanks->dequeue(tank);
		UML.add_tank(tank);
		tank->set_UML_time(time);
		UML_new++;
	}
}

LinkedQueue<ArmyUnit*>* game::get_enemies(TYPE t, int n) {
	int soldiercount = Aliens.get_soldier_id();
	int monstercount = Aliens.get_monster_id();
	int dronecount = Aliens.get_drone_id();
	int tankscount = Humans.get_tank_id();
	int humansoldierc = Humans.get_soldier_id();
	int gunnerycount= Humans.get_gunnery_id();
	ArmyUnit* temp;
	LinkedQueue<ArmyUnit*>* t1;
	LinkedQueue<ArmyUnit*>* t2;
	LinkedQueue<ArmyUnit*>* tr = new LinkedQueue<ArmyUnit*>;
	switch (t)
	{
	case EARTHSOLDIER:
		return Aliens.get_soldiers(n);
		break;
	case TANK:
		update_tank_status();
		if (tank_anxiety) {
			ArmyUnit* temp;
			int soldierlength;
			int monsterlength;
			if (soldiercount <= n / 2 && monstercount <= n / 2) {
				t1 = Aliens.get_soldiers(soldiercount);
				t2 = Aliens.get_monsters(monstercount);
				soldierlength = soldiercount;
				monsterlength = monstercount;
			}
			else if (soldiercount >= n / 2 && monstercount > n / 2) {
				t1 = Aliens.get_soldiers(n - (n / 2));
				t2 = Aliens.get_monsters(n / 2);
				soldierlength = n - (n / 2);
				monsterlength = n / 2;
			}
			else if (soldiercount <= n / 2 && monstercount > n / 2) {
				t2 = Aliens.get_monsters(min(n - soldiercount, monstercount));
				t1 = Aliens.get_soldiers(soldiercount);
				monsterlength = min(n - soldiercount, monstercount);
				soldierlength = soldiercount;
			}
			else { //soldiercount > n / 2 && monstercount < n / 2
				t2 = Aliens.get_monsters(monstercount);
				t1 = Aliens.get_soldiers(min(soldiercount, n - soldiercount));
				soldierlength = min(soldiercount, n - soldiercount);
				monsterlength = monstercount;
			}
			LinkedQueue<ArmyUnit*>* tr=new LinkedQueue<ArmyUnit*>;
			for (int i = 0; i < soldierlength; i++) {
				if(t1->dequeue(temp))
				tr->enqueue(temp);
			}
			for (int i = 0; i < monsterlength; i++) {
				if (t2->dequeue(temp))
				tr->enqueue(temp);
			}
			delete t1;
			delete t2;
			return tr;
		}
		else {
			return Aliens.get_monsters(n);
		}
		break;
	case GUNNERY:
		int monsterlength;
		int dronelength;
		if (monstercount >= n / 2 && dronecount >= n / 2) {
			t1 = Aliens.get_monsters(n / 2);
			t2 = Aliens.get_drones(n / 2);
			monsterlength = n / 2;
			dronelength = n / 2;
		}
		else if (monstercount <= n / 2 && dronecount >= n / 2) {
			t1 = Aliens.get_monsters(monstercount);
			t2 = Aliens.get_drones(n - monstercount);
			monsterlength = monstercount;
			dronelength = n - monstercount;
		}
		else if (monstercount >= n / 2 && dronecount <= n / 2) {
			t2 = Aliens.get_drones(dronecount);
			t1 = Aliens.get_monsters(n - dronecount);
			dronelength = dronecount;
			monsterlength = n - dronecount;
		}
		else {
			t2 = Aliens.get_drones(dronecount);
			t1 = Aliens.get_monsters(monstercount);
			monsterlength = monstercount;
			dronelength = dronecount;
		}
		
		for (int i = 0; i < monsterlength; i++) {
			if (t1->dequeue(temp))
				tr->enqueue(temp);
		}
		for (int i = 0; i < dronelength; i++) {
			if (t2->dequeue(temp))
				tr->enqueue(temp);
		}
		delete t1;
		delete t2;
		return tr;
		break;
	case HEALER:
		return UML.get_injured(n);
		break;
	case ALIENSOLDIER:
		return Humans.get_soldiers(n);
		break;
	case MONSTER:
		int humansoldierlength;
		int tanklength;
		if (humansoldierc <= n / 2 && tankscount <= n / 2) {
			t1 = Aliens.get_soldiers(humansoldierc);
			t2 = Aliens.get_monsters(monstercount);
			humansoldierlength = humansoldierc;
			tanklength = monstercount;
		}
		else if (humansoldierc >= n / 2 && monstercount > n / 2) {
			t1 = Aliens.get_soldiers(n - (n / 2));
			t2 = Aliens.get_monsters(n / 2);
			humansoldierlength = n - (n / 2);
			tanklength = n / 2;
		}
		else if (humansoldierc <= n / 2 && monstercount > n / 2) {
			t2 = Aliens.get_monsters(min(n - humansoldierc, monstercount));
			t1 = Aliens.get_soldiers(humansoldierc);
			tanklength = min(n - humansoldierc, monstercount);
			humansoldierlength = humansoldierc;
		}
		else { //humansoldierc > n / 2 && monstercount < n / 2
			t2 = Aliens.get_monsters(monstercount);
			t1 = Aliens.get_soldiers(min(humansoldierc, n - humansoldierc));
			humansoldierlength = min(humansoldierc, n - humansoldierc);
			tanklength = monstercount;
		}

		for (int i = 0; i < tanklength; i++) {
			if (t1->dequeue(temp))
				tr->enqueue(temp);
		}
		for (int i = 0; i < humansoldierlength; i++) {
			if (t2->dequeue(temp))
				tr->enqueue(temp);
		}
		delete t1;
		delete t2;
		return tr;
		break;
	case DRONE:
		int gunnerylength;
		int tankslength;
		if (gunnerycount >= n / 2 && tankscount >= n / 2) {
			t1 = Humans.get_gunneries(n / 2);
			t2 = Humans.get_tanks(n / 2);
			gunnerylength = n / 2;
			tankslength = n / 2;
		}
		else if (gunnerycount <= n / 2 && tankscount >= n / 2) {
			t1 = Humans.get_soldiers(gunnerycount);
			t2 = Humans.get_gunneries(n - gunnerycount);
			gunnerylength = gunnerycount;
			tankslength = n - humansoldierc;
		}
		else if (gunnerycount >= n / 2 && tankscount <= n / 2) {
			t2 = Humans.get_tanks(tankscount);
			t1 = Humans.get_gunneries(n - tankscount);
			tankslength = tankscount;
			gunnerylength = n - tankscount;
		}
		else {
			t2 = Humans.get_tanks(tankscount);
			t1 = Humans.get_gunneries(soldiercount);
			tankslength = tankscount;
			gunnerylength = gunnerycount;
		}

		for (int i = 0; i < tankslength; i++) {
			if (t1->dequeue(temp))
				tr->enqueue(temp);
		}
		for (int i = 0; i < gunnerylength; i++) {
			if (t2->dequeue(temp))
				tr->enqueue(temp);
		}
		delete t1;
		delete t2;
		return tr;
		break;

	}

}

void game::kill_unit(ArmyUnit* u)
{
	if (u) {
		killed.enqueue(u);
		killcount++;
	}
}
