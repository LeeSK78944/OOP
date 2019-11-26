#include "String.h"

String::String(const std::string &str){
	this->_val = str;
}

std::string String::val(){
	return this->_val;
}

void String::set_val(const std::string &str){
	this->_val = str;
}

json_object::_type String::type(){
	return this->STRING;
}

std::string String::to_string(){
	std::string str;
	char ch = '\0'; //char null
	int i=0;
	while(i<(int)this->_val.length()){
		switch(this->_val.at(i)){
			case '\'':case '"':
				if(ch == '\0')
					ch = this->_val[i];
			default:
				str += this->_val.at(i);
		}
		++i;
	}

	switch(ch){
		case '"':case '\0':
			ch = '\'';
			break;
		case '\'':
			ch = '"';
			break;
	}

	str.insert(0, std::string(1, ch));
	str.append(std::string(1, ch));
	return str;
}

json_object *String::parse(const char *input, int length, char base){
	std::string str;
	++json_object::_index;

	int k=0;
	while(json_object::_index+k < json_object::_index+length-1){
		switch(input[json_object::_index+k]){
			case '\\':
				switch(input[json_object::_index+k+1]){
					case '"':
						str += '"';
						break;
					case '\'':
						str += '\'';
						break;
				}
			default:
				str += input[json_object::_index + k];
		}
		++k;
	}

	json_object::_index += k+1;

	return new String(str);
}
