#include<iostream>
#include<conio.h>

using namespace std;

#define MIN_TANK_VOLUME 40
#define MAX_TANK_VOLUME 80
#define DEFAULT_TANK_VOLUME 60

class Tank
{
	int VOLUME;
	double fuel_level;
public:
	int get_volume()const
	{
		return VOLUME;
	}
	double get_fuel_level()const
	{
		return fuel_level;
	}
	double give_fuel(double amount)
	{
		return (fuel_level - amount > 0) ? fuel_level -= amount : fuel_level = 0;
	}
	void fill(double amount)
	{
		if (amount < 0)return;
		(fuel_level + amount < VOLUME) ? fuel_level += amount : fuel_level = VOLUME;
	}
	void info()const
	{
		cout << "Volume: " << VOLUME << " litters\n";
		cout << "Fuel level: " << fuel_level << " litters\n";
	}

	Tank(int volume) :VOLUME(volume>MIN_TANK_VOLUME&&volume<MAX_TANK_VOLUME?volume:DEFAULT_TANK_VOLUME)
	{
		this->fuel_level = 0;
		cout << "Tank is ready " << this << endl;
	}
	~Tank()
	{
		cout << "Tank is over " << this << endl;

	}
};

#define MIN_ENGINE_CONSUMTION 5
#define MAX_ENGINE_CONSUMTION 40
#define DEFAULT_ENGINE_CONSUMTION 12
class Engine
{
	double consumption;  //расход на 100 км
	double consumption_per_second; //расход в сек
	bool is_started;
public:
	double get_consumption()const
	{
		return consumption;
	}
	double get_consumtion_per_second()const
	{
		return consumption_per_second;
	}
	void set_consumtion(double consumption)
	{
		this->consumption = consumption > MIN_ENGINE_CONSUMTION && consumption < MAX_ENGINE_CONSUMTION ? consumption : DEFAULT_ENGINE_CONSUMTION;
		this->consumption_per_second = this->consumption * 3e-5;
	}

	void start()
	{
		is_started = true;
	}
	void stop()
	{
		is_started = false;
	}
	bool started()const
	{
		return is_started;
	}
	void info()const
	{
		cout << "Consumption per 100 km: " << consumption << " littesr\n";
		cout << "Consumption per sec: " << consumption_per_second << " littesr\n";
		cout << "Engine is " << (is_started ? "started" : "stopped") << endl;

	}
	Engine(double consumption)
	{
		set_consumtion(consumption);
		this->is_started = false;
		cout << "Engine is ready " << this << endl;
	}
	~Engine()
	{
		cout << "Engine is over " << this << endl;
	}
};

#define MAX_SPPED_LOW_LIMIT 60
#define MAX_SPPED_MAX_LIMIT 300
#define DEFAULT_MAX_SPEED 200

#define Escape 27
#define Enter 13

class Car
{
	Engine engine;
	Tank tank;
	bool driver_inside;
	int speed;
	const int MAX_SPEED;
	double acceleration;

public:

	Car(double consumption, int volume, int max_speed):
		engine(consumption),
		tank(volume),
		MAX_SPEED((max_speed > MAX_SPPED_LOW_LIMIT&& max_speed < MAX_SPPED_MAX_LIMIT) ? max_speed : DEFAULT_MAX_SPEED)
	{
		driver_inside = false;
		acceleration = MAX_SPEED / 10;
		cout << "Your car is ready to go " << this << endl;
	}
	~Car()
	{
		cout << "Your car is over " << this << endl;
	}
	void fill(double amount)
	{
		tank.fill(amount);
	}
	void get_in()
	{
		driver_inside = true;
		panel();
	}
	void get_out()
	{
		driver_inside = false;
		system("CLS");
		cout << "You are out of your car" << endl;
	}
	void control_car()
	{
		char key;
		do
		{
			key = _getch();
			switch (key)
			{
			case Enter:(driver_inside) ? get_out(): get_in();break;
			case 'F': case 'f': 
				double fuel;
				cout << "Введите объем топлива: "; cin >> fuel;
				fill(fuel);
				break;
			}

		} while (key != Escape);
	}
	void panel()const
	{
		system("CLS");
		cout << "Fuel level: " << tank.get_fuel_level() << " litters\n";
		cout << "Engine is " << (engine.started() ? "started" : "stopped") << endl;
	}
};
//#define TANK_CHECK
//#define ENGINE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef TANK_CHECK
	Tank tank(100);
	int amount;

	do
	{
		tank.info();
		cout << "Введите объем топлива: "; cin >> amount;
		tank.fill(amount);
	} while (true);

#endif // TANK_CHECK
#ifdef ENGINE_CHECK
	Engine engine(3);
	engine.info();
#endif // ENGINE_CHECK
	Car bmw(10, 60, 250);
	bmw.control_car();
}