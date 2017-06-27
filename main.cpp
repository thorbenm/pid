#include <iostream>
#include "pid.h"

double goal = 1;
double value = 0;

pid control(.1,.1,.1);

int main(void){
	control.set_value(value);
	control.set_goal(goal);
	int time = 0;

	std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	for(int j = 0; j<200;j++){
		value = control.update(value);
		std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	}
	goal = 2;
	control.set_goal(goal);
	for(int j = 0; j<200;j++){
		value = control.update(value);
		std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	}
	goal = 0;
	control.set_goal(goal);
	for(int j = 0; j<200;j++){
		value = control.update(value);
		std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	}
	for(int j = 0; j<200;j++){
		goal = 2.0 / 200.0 * j;
		control.set_goal(goal);
		value = control.update(value);
		std::cout << time++ << "\t" << goal << "\t" << value << std::endl;
	}
	return 0;
	}
