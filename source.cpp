// assignment 2 bigNum
// David Maye
// cd SCHOOL/PROG/"NEW CLASS"/"PART 2"/HOMEWORK/"10 OVERLAODING"

#include<iostream>
#include<string>
#include"bigNum.h"
using namespace std;

// This program will use three functions capable of reading, adding, and printing 100-digit numbers.
int main()
{
	bool done = false;
	char response;								

	while (not done)								//need to change back to "not done"
	{
		bigNumber num1, num2, sum;					// Declaring the three objects.

		cout << "\nPlease enter a number up to " << MAX_DIGITS << " digits: ";
		num1.readBig();

		cout << "\nPlease enter a number up to " << MAX_DIGITS << " digits: ";
		num2.readBig();
		
		// cout << "\n";
		// cout << "  ";
		// ++num1;
		// cout<<num1;

		// cout << "\n";
		// cout << "enter another number"<<endl;
		// cout << "  ";
		// cin>>num1;
		// cout << "  ";
		// cout<<num1;

		if(num1 < num2){
			cout<<"it fucking works!!!!!!!!!!!!!!!";
		}

		//num1.printBig();

		// cout << "\n";
		// cout << "  ";
		// num2++;
		// num2.printBig();

		// cout << "\n";
		// cout << "  ";
		// sum+=(num1+2);
		// sum.printBig();

		cout << "\n\n";
		cout << "  ";
		cout << "Test again? ";
		cin >> response;
		cin.ignore(900, '\n');
		done = toupper(response) != 'Y';	
	}
	return 0;
}
