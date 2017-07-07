#include "pid.h"

pid::pid(double kp2, double ti2, double td2, double offset2){
	kp = kp2;
	ti  = ti2;
	td = td2;
	offset = offset2;
	first_update = true;
}

double pid::update(double input){

	time_point = std::chrono::system_clock::now();
	error = goal - input;
	if(first_update){
		int_error = 0.0;
		diff_error = 0.0;
	}else{
		std::chrono::duration<double>
		elapsed_seconds = time_point-previous_time_point;
		dt = elapsed_seconds.count();
		int_error += error * dt;
		diff_error = (error - prev_error) / dt;
	}

	if(ti<1e-5){ //if ti == 0
		value = kp * (error +
			td * diff_error);
	}else{ value = kp * (error +
			int_error / ti +
			td * diff_error);
	}
	value += offset;
	prev_error = error;
	previous_time_point = time_point;
	first_update = false;
	return value;
}

void pid::set_value(double input){
	value = input; 
}

void pid::set_goal(double input){
	goal = input;
}

double pid::read_goal(){
	return goal;
}
