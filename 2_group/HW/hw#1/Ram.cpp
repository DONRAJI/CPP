#include<iostream>
using namespace std;
#include "Ram.h"
Ram::Ram() {
	size = 100 * 1024;
	for (int i = 0; i < 100 * 1024; i++) {
		mem[i] = 0;
	}
}
Ram:: ~Ram() {
	cout << "메모리 제거됨" << endl;
}
char Ram::read(int address) {
	return mem[address];
}
void Ram::write(int address, char value) {
	mem[address] = value;
}
