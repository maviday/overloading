#include<iostream>
#include<string>
#include"bigNum.h"
using namespace std;

// READBIG will read a number as a string, it then converts each element of
// the string to an integer and stores it in an integer array. Finally,
// it reverses the elements of the array so that the ones digit is in element zero,
// the tens digit is in element 1, the hundreds digit is in element 2, etc.
// This is done to make carrying digits easier for purposes of addition later.
// ".length" must be converted to an integer for purposes of unsined integers

bigNumber::bigNumber(){										//default constructor
	int i;
	for(i=0; i <= MAX_DIGITS - 1; i++)
		num[i] = 0;
}

bigNumber::bigNumber(int x){								//integer constructor
	int i;
	for(i=0; i <= MAX_DIGITS - 1; i++){
		num[i] = x % 10;
		x = x / 10;
	}
}

bigNumber bigNumber::operator +(bigNumber x){		
	bigNumber sumOf;
	int carry = 0;
	int i;
	for (i = 0; i <= MAX_DIGITS - 1; i++) {
		sumOf.num[i] = num[i] + x.num[i] + carry;
		if (sumOf.num[i] / 10) {
			carry = 1;
			sumOf.num[i] = sumOf.num[i] % 10;
		}
		else
			carry = 0;
	}
	return sumOf;		
}

void bigNumber::readBig(){	
	string inputString;
	cin >> inputString;						
	int length = inputString.length();
	int i;
	for (i = 0; i <= MAX_DIGITS - 1; i++)			//initialise everything to 0
		num[i] = 0;
	for (i = 0; i <= length - 1; i++)				//fills array
		num[i] = inputString.at(i) - '0';
	int tempHold, countUp = 0;
	for (i = (length - 1); i >= length / 2; i--) {	//reverses array
		tempHold = num[countUp];
		num[countUp] = num[i];
		num[i] = tempHold;
		countUp++;
	}
}

void bigNumber::printBig(){		
	int temp = MAX_DIGITS - 1;
	while (num[temp] == 0 and temp > 0) 
		temp--;
	for (temp; temp >= 0; temp--)
		cout << num[temp];
}


bigNumber bigNumber::operator ++(){							//incromentor
	*this = *this + 1;
	return *this;
}

bigNumber bigNumber::operator ++(int x){					//incromentor also
	bigNumber premod = *this;
	*this = *this + 1;
	return premod;
}

bigNumber bigNumber::operator +=(bigNumber x){				//adder
	*this = *this + x;
	return *this;
}	

ostream& operator <<(ostream &out, bigNumber x){			//output
	int temp = MAX_DIGITS - 1;
	while (x.num[temp] == 0 and temp > 0)
		temp--;
	for (temp; temp >= 0; temp--)
		cout << x.num[temp];
}	

istream& operator >>(istream &in, bigNumber &x){			//input
	string inputString;
	cin >> inputString;						
	int length = inputString.length();
	int i;
	for (i = 0; i <= MAX_DIGITS - 1; i++)			//initialise everything to 0
		x.num[i] = 0;
	for (i = 0; i <= length - 1; i++)
		x.num[i] = inputString.at(i) - '0';
	int tempHold, countUp = 0;
	for (i = (length - 1); i >= length / 2; i--) {
		tempHold = x.num[countUp];
		x.num[countUp] = x.num[i];
		x.num[i] = tempHold;
		countUp++;
	}
}

bool bigNumber::operator <(bigNumber x){					//less than
	int temp = MAX_DIGITS;
	bigNumber y = *this;
	while (x.num[temp] == 0 and y.num[temp] == 0 and temp > 0) 
		temp--;
		for (temp; temp >= 0; temp--){
			if(y.num[temp] > x.num[temp]) 
				return false;
			else
				return true;
		}			
}

//bool bigNumber::operator  >(bigNumber){			//greater than
//bool bigNumber::operator ==(bigNumber){			//comparitor
//bigNumber bigNumber::operator =(bigNumber){		//equal to







