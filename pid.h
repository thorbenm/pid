#pragma omp once

class pid{
public:
	void set_value(double input = 0);
	void set_goal(double input = 0);
	double update(double input = 0);
	pid(double kp2 = 1, double ti2 = 0, double td2 = 0, double dt2 = 1);
private:
	double kp;
	double ki;
	double kd;
	double dt;
	double goal;
	double value;
	double error;
	double int_error;
	double diff_error;
	double prev_error;
	bool first_update;
};
