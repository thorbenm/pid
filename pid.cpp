#include "pid.h"

pid::pid(double kprop2, double kint2, double kdiff2){
	kprop = kprop2;
	kint  = kint2 ;
	kdiff = kdiff2;
}

void pid::read_value(double value){
	error = value - goal;
	int_error += error;
	diff_error = error - prev_error;
}

