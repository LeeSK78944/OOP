#include "car.h"

car::car() : vehicle(){
}

car::car(int number, int speed) : vehicle(number, speed){
}

car::car(int number, int speed, char* cName) : vehicle(number, speed){
	set_car_name(cName);
}

car::car(int number, int speed, char* cName, bool hName) : vehicle(number, speed, hName){
	set_car_name(cName);
}

char* car::get_car_name(){
	return this->car_name;
}

const char* car::get_class_name(){
	return "car";
}

void car::set_car_name(char* cName){
	this->car_name = cName;
}
