#include "Integer.h"

Integer::Integer(int value){
	this->_val = value;
}

int Integer::val(){
	return this->_val;
}

void Integer::set_val(const int &value){
	this->_val = value;
}

json_object::_type Integer::type(){
	return this->INT;
}

std::string Integer::to_string(){
	return std::to_string(this->_val);
}

json_object *Integer::parse(const char *input, int length){
	bool flag = false; //false -> +  , true -> -
	if(input[json_object::_index] == '-'){
		++json_object::_index;
		flag = true;
	}

	int k=0, val=0;
	while(json_object::_index+k < json_object::_index + length){
		switch(input[json_object::_index+k]){
			case '0' ... '9':
				int temp = input[json_object::_index+k]-48; //ASCII
				val *= 10;
				val += temp;
				break;
		}
		++k;
	}

	json_object::_index += k;

	if(flag)
		val = -val;

	return new Integer(val);
}
