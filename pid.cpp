#include "pid.h"

pid::pid(double kprop2, double kint2, double kdiff2, double dt2){
	kprop = kprop2;
	kint  = kint2 ;
	kdiff = kdiff2;
	dt = dt2;
	first_update = true;
}

double pid::update(double input){
	error = goal - input;
	int_error += error * dt;
	if(first_update){
		diff_error = 0.0;
	}else{
	diff_error = (error - prev_error) / dt;
	}
	value = kprop * error + kint * int_error + kdiff * diff_error;
	prev_error = error;
	first_update = false;
	return value;
}

void pid::set_value(double input){
	value = input; 
}

void pid::set_goal(double input){
	goal = input;
}
