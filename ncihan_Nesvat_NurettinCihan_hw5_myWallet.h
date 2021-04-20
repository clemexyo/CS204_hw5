#ifndef _MY_WALLET_
#define _MY_WALLET_
//Cihan Nesvat 22422
#include <string>

struct Money
{
	std::string currency;
	double amount;

	Money():	//default constructor
		currency(""), amount(0.0)
	{}

	Money(std::string cur, double a): //parametric constructor
		currency(cur), amount(a)
	{}
};

class Wallet
{
private:
	Money* arr;		//dynamic array to store the money struct objects in wallet object
	int size;		//size of the dynamically allocated array

public:
	Wallet();						//Default constructor
	Wallet(int);					//Parametric constuctor
	~Wallet();						//Destructor
	Wallet(const Wallet& copy);		//Deep copy constructor
	Money* get_arr() const;			//arr getter
	int get_size() const;			//size getter
	Wallet& operator=(const Wallet& rhs);				//assing rhs wallet to lhs wallet
	int isUnique(const Money& m)				const;	//check if a money struct object is contained in a wallet object, if found return its index, return -1 if not found
	Wallet operator+(const Money& rhs_money)	const;	//sum rhs money with lhs wallet
	Wallet operator+(const Wallet& rhs)			const;	//sum rhs wallet with lhs wallet
	Wallet operator-(const Money& rhs)			const;	//substract rhs money from lhs wallet
};

bool operator==(const Wallet& lhs, const Wallet& rhs);			//return true if lhs == rhs
bool operator>=(const Wallet& lhs, const Money& rhs);			//return true if lhs >= rhs
bool operator<=(const Money& lhs, const Wallet& rhs);			//return true if lhs <= rhs
Wallet& operator+=(Wallet& lhs, const Wallet& rhs);				//short for lhs = lhs + rhs, usage: lhs += rhs	
std::ostream& operator<<(std::ostream& os, const Wallet& wa);	//store the contents of a wallet into a ostream object then return the ostream object

#endif