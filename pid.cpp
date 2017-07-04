#include "pid.h"

pid::pid(double kp2, double ki2, double kd2, double dt2){
	kp = kp2;
	ki  = ki2 ;
	kd = kd2;
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
	if(ki<1e-5){ //if ki == 0
		value = kp * (error +
			kd * diff_error);
	}else{
		value = kp * (error +
			int_error / ki +
			kd * diff_error);
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
