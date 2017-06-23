class pid{
private:
	double goal;
	double error;
	double int_error;
	double diff_error;
	double prev_error;
public:
	void read_value(double value = 0);
};
