#include <iostream>
using namespace std;
#include <iomanip>
#include "h3.h"
#include "Transaction.h"

int main() {

	int n; 
	Transaction* tr = nullptr; //allocate space for a pointer to a single Transaction

	cout << "Enter the number of transactions : "; 
	cin >> n;

	//allocate dynamic memory for an array of Transactions that contains the specified number of elements
	tr = new Transaction[n]; //pointer = new Type[size]; this is pointer

	cout << "Enter " << n << " Transactions" << endl;
	for (int i = 0; i < n; i++)
		tr[i].enter(); //single element is not a pointer. it's a single struct Transaction
	cout << endl;

	cout << "	Account Description" << setw(10) << "Credit" << setw(20) << "Debit" << endl;
	for (int i = 0; i < n; i++) {
	
		tr[i].display();
		cout << endl;
	}

	//deallocate the dynamic memory before returning control to the operating system
	delete[] tr; 
	tr = nullptr;
}