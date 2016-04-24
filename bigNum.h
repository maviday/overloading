#include<iostream>

using namespace std;

const int MAX_DIGITS = 100;

class bigNumber{
	friend ostream& operator <<(ostream&, bigNumber);	//input
	friend istream& operator >>(istream&, bigNumber&);	//output
	public:
		void readBig();
		void printBig();
		bigNumber();
		bigNumber(int);						//integer constructor, takes an integer and converts it to bigNumber type

		bigNumber operator  +(bigNumber);		//adder
		bigNumber operator ++();				//incromentor
		bigNumber operator ++(int);				//incromentor	
		bigNumber operator +=(bigNumber);		//adder
		bool	  operator  <(bigNumber);		//less than
		//bool	  operator  >(bigNumber);		//greater than
		// bigNumber operator =(bigNumber);		//equal to
		// bigNumber operator ==(bigNumber);	//comparitor
	private:
		int num[MAX_DIGITS];
};
