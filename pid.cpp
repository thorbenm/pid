#include "pid.h"

pid::pid(double kp2, double ti2, double td2, double dt2){
	kp = kp2;
	ti  = ti2 ;
	td = td2;
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
	if(ti<1e-5){ //if ti == 0
		value = kp * (error +
			td * diff_error);
	}else{ value = kp * (error +
			int_error / ti +
			td * diff_error);
	}
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
