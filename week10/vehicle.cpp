#include "vehicle.h"

vehicle::vehicle(){
	set_has_name(false);
}

vehicle::vehicle(int number, int speed){
	set_wheel_number(number);
	set_max_speed(speed);
}

vehicle::vehicle(int number, int speed, bool b){
	set_wheel_number(number);
	set_max_speed(speed);
	set_has_name(b);
}

int vehicle::get_wheel_number(){
	return this->wheel_number;
}

int vehicle::get_max_speed(){
	return this->max_speed;
}

bool vehicle::get_has_name(){
	return this->has_name;
}

const char* vehicle::get_class_name(){
	return "vehicle";
}

void vehicle::set_wheel_number(int number){
	this->wheel_number = number;
}

void vehicle::set_max_speed(int speed){
	this->max_speed = speed;
}

void vehicle::set_has_name(bool b){
	this->has_name = b;
}
