#include "json_dict.h"
#include "json_list.h"
#include "data/String.h"
#include "data/Integer.h"

json_dict::json_dict(){}

void json_dict::put(json_object *key, json_object *val){
	int index = this->find(key);

	if(index == -1)
		this->v.push_back(std::make_pair(key, val));
	else
		this->v[index].second = val;
	return;
}

int json_dict::find(json_object *key){
	int index=0;
	for(auto it = v.begin(); it != v.end(); it++){
		if(key->type() != it->first->type()){
			++index;
			continue;
		}

		switch(it->first->type()){
			case STRING:
				if(((String *)it->first)->val().compare(((String *)key)->val())==0)
					return index;
				break;
			case INT:
				if(((Integer *)it->first)->val() == ((Integer *)key)->val())
					return index;
				break;
		}
		++index;
	}

	return -1;
}

json_object *json_dict::parse(const char *input, int length){
	json_dict *dict = new json_dict();
	json_object *key = nullptr;
	json_object *val = nullptr;
	int startIndex = json_object::_index;
	bool flag = false;
	
	++json_object::_index;

	int index, dIndex, lIndex;
	while(json_object::_index < startIndex+length-1){
		index=0;

		switch(input[json_object::_index]){
			case ' ':case ':':case ',':case '\n':case '\t':case '\r':
				++json_object::_index;
				break;
			case '{':
				++index;
				dIndex=0;

				while(1){
					if(input[json_object::_index + index] == '{')
						++dIndex;
					else if(input[json_object::_index + index] == '}'){
						if(dIndex == 0){
							++index;
							break;
						}else
							--dIndex;
					}
					++index;
				}

				if(!flag){
					flag = true;
					key = json_dict::parse(input, index);
				}else{
					flag = false;
					val = json_dict::parse(input, index);
					dict->put(key, val);
				}
				break;
			case '[':
				++index;
				lIndex=0;

				while(1){
					if(input[json_object::_index + index] == '[')
						++lIndex;
					else if(input[json_object::_index+ index] == ']'){
						if(lIndex == 0){
							++index;
							break;
						}else
							--lIndex;
					}
					++index;
				}

				if(!flag){
					flag = true;
					key = json_list::parse(input, index);
				}else{
					flag = false;
					val = json_list::parse(input, index);
					dict->put(key, val);
				}
				break;
			case '-':
				++index;
			case '0' ... '9':
				while(1){
					if(input[json_object::_index+index]<'0'||input[json_object::_index+index]>'9')
						break;
					++index;
				}

				if(!flag){
					flag = true;
					key = Integer::parse(input, index);
				}else{
					flag = false;
					val = Integer::parse(input, index);
					dict->put(key, val);
				}
				break;
			case '\'':case '\"':
				++index;
				while(1){
					++index;
					if(input[json_object::_index + index] == input[json_object::_index])
						break;
				}

				if(!flag){
					flag = true;
					key = String::parse(input, index, input[json_object::_index]);
				}else{
					flag = false;
					val = String::parse(input, index, input[json_object::_index]);
					dict->put(key, val);
				}
				break;
		}
	}

	++json_object::_index;
	
	return dict;
}

json_object *json_dict::operator[](json_object *key) const{
	for(auto it=this->v.begin(); it != this->v.end(); it++)
		if(it->first == key)
			return it->second;
	return nullptr;
}

json_object *json_dict::operator[](const std::string &key) const{
	for(auto it=this->v.begin(); it != this->v.end(); it++){
		if(it->first->type() != json_object::_type::STRING)
			continue;

		if(((String *)(it->first))->val().compare(key)==0)
			return it->second;
	}
	return nullptr;
}

json_object *json_dict::operator[](int key) const{
    for(auto it=this->v.begin(); it != this->v.end(); it++){
        if(it->first->type() != json_object::_type::INT)
            continue;
        if(((Integer *)(it->first))->val() == key)
            return it->second;
    }
    return nullptr;
}

json_object::_type json_dict::type(){
	return this->DICT;
}

std::string json_dict::to_string(){
	std::string str("{");
	for(int i=0; i<(int)this->v.size(); i++){
		str += this->v[i].first->to_string();
		str += ": ";
		str += this->v[i].second->to_string();
		if(i+1 < (int)this->v.size())
			str += ", ";
	}
	str += "}";
	return str;
}
