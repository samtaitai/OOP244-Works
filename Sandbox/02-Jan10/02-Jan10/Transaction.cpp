#include <iostream>
#include <iomanip>
using namespace std;
#include "Transaction.h"

void Transaction::enter() {

	cout << "Enter the account number : ";
	cin >> acct;
	cin.ignore();
	cout << "Enter the description : ";
	cin.getline(desc, 21);
	cout << "Enter the account type (d for debit, c for credit) : ";
	cin >> type;
	cout << "Enter the account amount : ";
	cin >> amount; 
}

void Transaction::display() const {
	
	cout << setw(10) << acct;
	cout << ' ' << setw(20) << left << desc << right;
	cout << setprecision(2) << fixed; 
	if (type == 'd')
		cout << setw(20) << amount;
	else
		cout << setw(10) << amount;
}