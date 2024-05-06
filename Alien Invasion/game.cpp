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
	int A = rand() % 100;
	if (A < config.prob) {
		add_humans();
		add_aliens();
	}
	update_UML();
	print_UML();
	UML_new = 0;
	print_killed();
	cout << endl << endl;
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
		u->set_time_of_death(time);
		killed.enqueue(u);
		killcount++;
	}
}

void game::silent_step()
{
	Humans.attack();
	Aliens.Attack();
	update_UML();
	int A = rand() % 100;
	if (A < config.prob) {
		add_humans();
		add_aliens();
	}
	UML_new = 0;
	time++;
}

void game::generate_output_file()
{
	int destructed_es = 0;
	int destructed_et = 0;
	int destructed_eg = 0;
	int destructed_eh = 0;
	int destructed_as = 0;
	int destructed_am = 0;
	int destructed_ad = 0;

	int sum_df_e = 0;
	int sum_dd_e = 0;
	int sum_db_e = 0;
	int sum_df_a = 0;
	int sum_dd_a = 0;
	int sum_db_a = 0;


	ofstream output;
	output.open("output.txt");
	ArmyUnit* temp;
	output << "td" << ", " << "id" << ", " << "tj" << ", " << "df" << ", " << "dd" << ", " << "db" << endl;
	while (!killed.isEmpty()) {
		killed.dequeue(temp);
		int ta = temp->get_first_attack_time();
		int td = temp->get_time_of_death();
		int id = temp->get_id();
		int tj = temp->get_join_time();
		int df;
		int dd;
		int db = td - tj;
		if (ta) {
			df = ta - tj;
			dd = td - ta;
			output << td << ", " << id << ", " << tj << ", " << df << ", " << dd << ", " << db << endl;
		}
		else {
			df = 0;
			dd = 0;
			output << td << ", " << id << ", " << tj << ", " << "Never attacked" << ", " << "Never attacked" << ", " << db << endl;
		}
		if (temp->get_type() == EARTHSOLDIER) {
			destructed_es++;
			sum_db_e += db;
			sum_dd_e += dd;
			sum_df_e += df;
		}
		else if (temp->get_type() == TANK) {
			destructed_et++;
			sum_db_e += db;
			sum_dd_e += dd;
			sum_df_e += df;
		}
		else if (temp->get_type() == GUNNERY) {
			destructed_eg++;
			sum_db_e += db;
			sum_dd_e += dd;
			sum_df_e += df;
		}
		else if (temp->get_type() == HEALER) {
			destructed_eh++;
			sum_db_e += db;
			sum_dd_e += dd;
			sum_df_e += df;
		}
		else if (temp->get_type() == ALIENSOLDIER) {
			destructed_as++;
			sum_db_a += db;
			sum_dd_a += dd;
			sum_df_a += df;
		}
		else if (temp->get_type() == MONSTER) {
			destructed_am++;
			sum_db_a += db;
			sum_dd_a += dd;
			sum_df_a += df;
		}
		else if (temp->get_type() == DRONE) {
			destructed_ad++;
			sum_db_a += db;
			sum_dd_a += dd;
			sum_df_a += df;
		}
	}
	int total_es = Humans.get_soldier_id() + destructed_es;
	int total_et = Humans.get_tank_id() + destructed_et;
	int total_eg = Humans.get_gunnery_id() + destructed_eg;
	int total_eh = Humans.get_healer_id() + destructed_eh;
	int total_as = Aliens.get_soldier_id() + destructed_as;
	int total_am = Aliens.get_monster_id() + destructed_am;
	int total_ad = Aliens.get_drone_id() + destructed_ad;
	int total_earth= total_es + total_et + total_eg + total_eh;
	int total_dest_earth = destructed_es + destructed_et + destructed_eg + destructed_eh;
	int total_alien = total_as + total_am + total_ad;
	int total_dest_alien = destructed_as + destructed_am + destructed_ad;
	float avg_df_e = sum_df_e / (float)total_dest_earth;
	float avg_dd_e = sum_dd_e / (float)total_dest_earth;
	float avg_db_e = sum_db_e / (float)total_dest_earth;
	float avg_df_a = sum_df_a / (float)total_dest_alien;
	float avg_dd_a = sum_dd_a / (float)total_dest_alien;
	float avg_db_a = sum_db_a / (float)total_dest_alien;
	float total_healed = healed_successfully;

	output<<"Earth Army:"<<endl;
	output << "Total Earth Soldiers: " << total_es << endl;
	output << "Total Earth Tanks: " << total_et << endl;
	output << "Total Earth Gunnery: " << total_eg << endl;
	output << "Total Earth Healers: " << total_eh << endl;
	if (total_es) {
		output<<"Precentage of Destrcuted Earth Soldiers: "<<(destructed_es*100)/total_es<<"%"<<endl;
	}
	else {
		output << "Precentage of Destrcuted Earth Soldiers: " << 0 << "%" << endl;
	}
	if (total_et) {
		output << "Precentage of Destrcuted Earth Tanks: " << (destructed_et * 100) / total_et << "%" << endl;
	}
	else {
		output << "Precentage of Destrcuted Earth Tanks: " << 0<< "%" << endl;
	}
	if (total_eg) {
		output << "Precentage of Destrcuted Earth Gunnery: " << (destructed_eg * 100) / total_eg << "%" << endl;
	}
	else {
		output << "Precentage of Destrcuted Earth Gunnery: " << 0 << "%" << endl;
	}
	output<<"Precentage of Destrcuted Earth Army: "<<(total_dest_earth*100)/total_earth<<"%"<<endl;
	output<<"Average DF of Earth Army: "<<avg_df_e<<endl;
	output << "Average DD of Earth Army: " << avg_dd_e << endl;
	output << "Average DB of Earth Army: " << avg_db_e << endl;
	output << "DF/DB=" << 100 * avg_df_e / avg_db_e << "%" << endl;
	output << "DD/DB=" << 100 * avg_dd_e / avg_db_e << "%" << endl;
	output<< "Total Healed Percentage: " << 100* (float)total_healed/total_earth << "%" << endl;
	output<< endl;


	output << "Alien Army:" << endl;
	output << "Total Alien Soldiers: " << total_as << endl;
	output << "Total Alien Monsters: " << total_am << endl;
	output << "Total Alien Drones: " << total_ad << endl;
	if (total_as) {
		output << "Precentage of Destrcuted Alien Soldiers: " << (destructed_as * 100) / total_as << "%" << endl;
	}
	else {
		output<<"Precentage of Destrcuted Alien Soldiers: " << 0 << "%" << endl;
	}
	if (total_am) {
		output << "Precentage of Destrcuted Alien Monsters: " << (destructed_am * 100) / total_am << "%" << endl;
	}
	else {
		output<<"Precentage of Destrcuted Alien Monsters: " << 0 << "%" << endl;
	}
	if (total_ad) {
		output << "Precentage of Destrcuted Alien Drones: " << (destructed_ad * 100) / total_ad << "%" << endl;
	}
	else {
		output<< "Precentage of Destrcuted Alien Drones: " << 0 << "%" << endl;
	}
	output << "Precentage of Destrcuted Alien Soldiers: " << (destructed_as * 100) / total_as << "%" << endl;
	output << "Precentage of Destrcuted Alien Monsters: " << (destructed_am * 100) / total_am << "%" << endl;
	output << "Precentage of Destrcuted Alien Drones: " << (destructed_ad * 100) / total_ad << "%" << endl;
	output << "Precentage of Destrcuted Alien Army: " << (total_dest_alien * 100) / total_alien << "%" << endl;
	output << "Average DF of Alien Army: " << avg_df_a << endl;
	output << "Average DD of Alien Army: " << avg_dd_a << endl;
	output << "Average DB of Alien Army: " << avg_db_a << endl;
	output << "DF/DB=" << 100 * avg_df_a / avg_db_a << "%" << endl;
	output << "DD/DB=" << 100 * avg_dd_a / avg_db_a << "%" << endl;
	output.close();
}
