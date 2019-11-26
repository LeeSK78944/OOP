#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/String.h"
#include "data/Integer.h"

int json_object::_index=0;

json_object *json_object::parse(const std::string &str){
	json_object::_index = 0;
	return json_object::parse(str.c_str(), str.length());
}

json_object *json_object::parse(const char *input, int length){
	json_object *object = nullptr;
	int k=0; int num=0;

	switch(input[json_object::_index]){
		case '{':
			++k;
			num=0;

			while(1){
				if(input[json_object::_index+k] == '{')
					++num;
				else if(input[json_object::_index+k] == '}'){
					if(num == 0){
						++k;
						break;
					}else
						--num;
				}
				++k;
			}
			object = json_dict::parse(input, k);
			break;
		case '[':
			++k;
			num = 0;

			while(1){
				if(input[json_object::_index+k] == '[')
					++num;
				else if(input[json_object::_index+k] == ']'){
					if(num == 0){
						++k;
						break;
					}else
						--num;
				}
				++k;
			}
			object = json_list::parse(input, k);
			break;
		case '-':
			++k;
		case '0' ... '9':
			while(1){
				if(input[json_object::_index+k]<'0'||input[json_object::_index+k]>'9')
					break;
				++k;
			}
			object =Integer::parse(input, k);
			break;
		case '\'':case '\"':
			++k;

			while(1){
				++k;
				if(input[json_object::_index+k] == input[json_object::_index])
					break;
			}
			object = String::parse(input, k, input[json_object::_index]);
			break;
	}

	++json_object::_index;

	return object;
}
