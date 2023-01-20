struct Transaction {
private:
	int acct;
	char type;
	char desc[21];
	double amount;
public:
	void enter();
	void display() const; //meaning?? 
};