#include "bike.h"

bike::bike() : vehicle(){
}

bike::bike(int number, int speed) : vehicle(number, speed){
}

bike::bike(int number, int speed, char* bName) : vehicle(number, speed){
	set_bike_name(bName);
}

bike::bike(int number, int speed, char* bName, int bNumber) : vehicle(number, speed){
	set_bike_name(bName);
	set_bike_number(bNumber);
}

bike::bike(int number, int speed, char* bName, int bNumber, bool hName) : vehicle(number, speed, hName){
	set_bike_name(bName);
	set_bike_number(bNumber);
}

int bike::get_bike_number(){
	return this->bike_number;
}

char* bike::get_bike_name(){
	return this->bike_name;
}

const char* bike::get_class_name(){
	return "bike";
}

void bike::set_bike_name(char* bName){
	this->bike_name = bName;
}

void bike::set_bike_number(int bNumber){
	this->bike_number = bNumber;
}
