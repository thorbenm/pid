#include <iostream>
#include "pid.h"

double goal = 1;
double starting_value = 0;

pid control;

int main(void){
	control.read_value(goal);
	std::cout << "hello world" << std::endl ;
	return 0;
	}
