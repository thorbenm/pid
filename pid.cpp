#include "pid.h"

void pid::read_value(double value){
	error = value - goal;
	int_error += error;
	diff_error = error - prev_error;
}
