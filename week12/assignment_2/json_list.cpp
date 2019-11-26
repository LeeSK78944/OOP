#include "json_list.h"
#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"

json_list::json_list(){}

json_object *json_list::operator[](int key) const{
	return this->v[key];
}

json_object:: _type json_list::type(){
	return this->LIST;
}

std::string json_list::to_string(){
	std::string str("[");
	
	for(int i=0; i<(int)this->v.size(); i++){
		str += v[i]->to_string();
		if(i+1 < (int)this->v.size())
			str += ", ";
	}
	str += "]";
	return str;
}

json_object *json_list::parse(const char *input, int length){
	json_list *list = new json_list();
	int startIndex = json_object::_index;
	json_object *val;
	++json_object::_index;

	int index, dict, lIndex;
	while(json_object::_index < startIndex+length-1){
		index = 0;

		switch(input[json_object::_index]){
			case ' ':case '\n':case '\t': case '\r':
				++json_object::_index;
				break;
			case '{':
				dict=0;
				++index;

				while(1){
					if(input[json_object::_index+index] == '{')
						++dict;
					else if(input[json_object::_index+index] == '}'){
						if(dict == 0){
							++index;
							break;
						}else
							--dict;
					}
					++index;
				}
				val = json_dict::parse(input, index);
				list->v.push_back(val);
				break;
			case ',':
				++json_object::_index;
				break;
			case '[':
				lIndex=0;
				++index;

				while(1){
					if(input[json_object::_index + index] == '[')
						++lIndex;
					else if(input[json_object::_index + index] == ']'){
						if(lIndex == 0){
							++index;
							break;
						}else
							--lIndex;
					}
					++index;
				}
				val = json_list::parse(input, index);
				list->v.push_back(val);
				break;
			case '-':
				++index;
			case '0' ... '9':
				while(1){
					if(input[json_object::_index+index]<'0' || input[json_object::_index+index]>'9')
						break;
					++index;
				}
				val = Integer::parse(input, index);
				list->v.push_back(val);
				break;
			case '\'':case '\"':
				++index;
				while(1){
					++index;
					if(input[json_object::_index+index] == input[json_object::_index])
						break;
				}
				val = String::parse(input, index, input[json_object::_index]);
				list->v.push_back(val);
				break;
		}
	}

	++json_object::_index;

	return list;
}
