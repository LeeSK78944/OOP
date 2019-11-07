#include "vehicle.h"

class bike : public vehicle {
	private:
		char* bike_name;
		int bike_number;

	public:
		bike();
		bike(int number, int speed);
		bike(int number, int speed, char* bName);
		bike(int number, int speed, char* bName, int bNumber);
		bike(int number, int speed, char* bName, int bNumber, bool hName);

		int get_bike_number();
		char* get_bike_name();
		const char* get_class_name();
		void set_bike_name(char* bName);
		void set_bike_number(int bNumber);
};
