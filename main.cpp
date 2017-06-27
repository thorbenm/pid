#include <iostream>
#include "pid.h"

double goal = 1;
double value = 0;

pid control(1,0.5,0.25);

int main(void){
	control.set_value(value);
	control.set_goal(goal);
	int time = 0;

	std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	for(int j = 0; j<20;j++){
		value = control.update(value);
		std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	}
	goal = 2;
	control.set_goal(goal);
	for(int j = 0; j<20;j++){
		value = control.update(value);
		std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	}
	return 0;
	}
