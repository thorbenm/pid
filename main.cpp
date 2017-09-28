#include <iostream>
#include "pid.h"

double goal = 1;
double value = 0;
double value_percentage = .1;

pid control(2,10000,0,0,.0001);

int main(void){
	control.set_value(value);
	control.set_goal(goal);
	int time = 0;

	std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	for(int j = 0; j<200;j++){
		value += value_percentage * ( control.update(value) - value);
		std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	}
	goal = 2;
	control.set_goal(goal);
	for(int j = 0; j<200;j++){
		value += value_percentage * ( control.update(value) - value);
		std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	}
	goal = 0;
	control.set_goal(goal);
	for(int j = 0; j<200;j++){
		value += value_percentage * ( control.update(value) - value);
		std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	}
	for(int j = 0; j<200;j++){
		goal = 2.0 / 200.0 * j;
		control.set_goal(goal);
		value += value_percentage * ( control.update(value) - value);
		std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	}
	return 0;
	}
