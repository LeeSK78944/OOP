#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class vehicle {
	private:
		bool has_name;
		int wheel_number;
		int max_speed;

	public:
		vehicle();

		vehicle(int number, int speed);

		vehicle(int number, int speed, bool b);

		int get_wheel_number();

		int get_max_speed();

		bool get_has_name();

		const char* get_class_name();

		void set_wheel_number(int number);

		void set_max_speed(int speed);

		void set_has_name(bool b);
};

#endif
