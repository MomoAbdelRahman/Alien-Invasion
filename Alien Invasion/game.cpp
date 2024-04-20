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
	cout << "======================Earth Army========================" << endl;
	Humans.print();
	cout << "======================Alien Army========================" << endl;
	Aliens.print();
	cout << "======================Killed========================" << endl;
	print_killed();
	cout << "======================================================" << endl << endl << endl;
}

void game::steptime()
{
	Humans.attack();
	int A = rand() % 100;
	if (A < config.prob) {
		add_humans();
		add_aliens();
	}
	time++;
}

void game::print_killed()
{
	cout << "Killed:" << Humans.get_killcount() + Aliens.get_killcount() << " [";
	Humans.print_killed();
	Aliens.print_killed();
	cout << "]" << endl;;
}

