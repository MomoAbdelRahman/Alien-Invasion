#include "game.h"

void game::read_data()
{
	ifstream Data("Generator_Sample.txt");
	Data >> config.N;
	Data >> config.ES;
	Data >> config.ET;
	Data >> config.EG;
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

void game::go()
{
	read_data();//Read the data from the file
	generator = new randgen(config);//Create the random generator with the configuration data
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
		next_alien_ID = 1000 + Aliens.get_next_id();//Get the ID of the next Alien unit
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
	int A = rand() % 100;
	if (A < config.prob) {
		add_humans();
		add_aliens();
	}
	print_killed();
	cout << endl << endl;
	time++;
}

void game::print_killed()
{
	cout << "=========================Killed=========================" << endl;
	cout << "Killed:" << Humans.get_killcount() + Aliens.get_killcount() << " [";
	Humans.print_killed();
	Aliens.print_killed();
	cout << "]" << endl;;
}

LinkedQueue<ArmyUnit*>* game::get_enemies(TYPE t, int n) {
	switch (t)
	{
	case EARTHSOLDIER:
		return Aliens.get_soldiers(n);
		break;
	case TANK:
		if (Humans.get_soldier_id() <= 0.3 * Aliens.get_soldier_id()) {
			ArmyUnit* temp;
			int soldiercount = Aliens.get_soldier_id();
			int monstercount = Aliens.get_monster_id();
			int soldierlength;
			int monsterlength;
			LinkedQueue<ArmyUnit*>* t1;
			LinkedQueue<ArmyUnit*>* t2;
			if (soldiercount >= n / 2 && monstercount >= n / 2) {
				t1 = Aliens.get_soldiers(n / 2);
				t2 = Aliens.get_monsters(n / 2);
				soldierlength = n / 2;
				monsterlength = n / 2;
			}
			else if (soldiercount <= n / 2 && monstercount >= n / 2) {
				t1 = Aliens.get_soldiers(soldiercount);
				t2 = Aliens.get_monsters(n - soldiercount);
				soldierlength = soldiercount;
				monsterlength = n - soldiercount;
			}
			else if (soldiercount >= n / 2 && monstercount <= n / 2) {
				t2 = Aliens.get_monsters(monstercount);
				t1 = Aliens.get_soldiers(n - monstercount);
				monsterlength = monstercount;
				soldierlength = n - monstercount;
			}
			else {
				t2 = Aliens.get_monsters(monstercount);
				t1 = Aliens.get_soldiers(soldiercount);
				soldierlength = soldiercount;
				monsterlength = monstercount;
			}
			
			LinkedQueue<ArmyUnit*>* tr=new LinkedQueue<ArmyUnit*>;
			for (int i = 0; i < soldierlength; i++) {
				t1->dequeue(temp);
				if(temp)
				tr->enqueue(temp);
			}
			for (int i = 0; i < monsterlength; i++) {
				t2->dequeue(temp);
				if (temp)
				tr->enqueue(temp);
			}
			delete t1;
			delete t2;
			return tr;

			//ArmyUnit** tr = new ArmyUnit * [n];
			//for (int i = 0; i < n; i++) { tr[i] = nullptr; }
			//for (int i = 0; i < soldierlength; i++) {
			//	if(t1[i])
			//	tr[i] = t1[i];
			//}
			//for (int i = 0; i < monsterlength; i++) {
			//	if (t2[i]) {
			//		tr[i + soldierlength] = t2[i];
			//	}
			//}
			//return tr;
		}
		else {
			return Aliens.get_monsters(n);
		}
		break;
	case GUNNERY:
		break;
	case ALIENSOLDIER:
		break;
	case MONSTER:
		break;
	case DRONE:
		break;
	default:
		break;
	}

}
