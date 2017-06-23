class pid{
public:
	void read_value(double value = 0);
	pid(double kprop2 = 1, double kint2 = 0, double kdiff2 = 0);
private:
	double kprop;
	double kint;
	double kdiff;
	double goal;
	double error;
	double int_error;
	double diff_error;
	double prev_error;
};
