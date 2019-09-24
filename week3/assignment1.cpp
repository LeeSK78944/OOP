#include <iostream>

int* code(){
	return 0;
};

int data = 1;
int bss;

int main(){
	const int rodata = 2;
	int stack;
	int* heap = new int[1];

	std::cout << "code\t" << (void*)code << std::endl;
	std::cout << "Rodata\t" << (void*)rodata << std::endl;
	std::cout << "data\t" << &data << std::endl;
	std::cout << "BSS\t" << &bss << std::endl;
	std::cout << "HEAP\t" << heap << std::endl;
	std::cout << "Stack\t" << &stack << std::endl;
}
