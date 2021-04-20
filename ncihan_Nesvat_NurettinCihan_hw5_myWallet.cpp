#include "ncihan_Nesvat_NurettinCihan_hw5_myWallet.h"
// Cihan Nesvat 22422

//class constructors
Wallet::Wallet():  //default constructor
	arr(nullptr), size(0)
{}

Wallet::Wallet(int s): //parametric constructor
	arr(new Money[s]), size(s)
{}

Wallet::~Wallet() //destructor
{ delete[] arr;
}

Wallet::Wallet(const Wallet& copy) //deep copy constructor
{
	size = copy.size;
	arr = new Money[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = copy.arr[i];
	}
}
//class getters
Money* Wallet::get_arr() const
{return this->arr;
}

int Wallet::get_size() const
{return this->size;
}

//class member functions
Wallet& Wallet::operator=(const Wallet& rhs)
{
	if(this != &rhs) //avoid self assignment
	{
		delete[] this->arr;
		this->arr = new Money[rhs.size];
		this->size = rhs.size;

		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = rhs.arr[i];
		}
	}
	return *this;
}
int Wallet::isUnique(const Money& m) const
{	//postcondition: index of the given money object is returned, return -1 if not found within the wallet
	int index = -1;
	for(int i = 0; i < this->size && index == -1; i++)
	{
		if(this->arr[i].currency == m.currency)
		{
			index = i;
		}
	}
	return index;
}
Wallet Wallet::operator+(const Money& rhs_money) const
{
	int index = this->isUnique(rhs_money);
	if(index != -1)
	{
		this->arr[index].amount += rhs_money.amount;
		return *this;
	}
	else
	{
		Wallet result(this->size+1);
		for(int i = 0; i < this->size; i++)
		{
			result.arr[i] = this->arr[i];
		}
		result.arr[this->size] = rhs_money;
		return result;
	}
}
Wallet Wallet::operator+(const Wallet& rhs) const
{   //postcondition: rhs content is added to lhs item-by-item, return lhs
	Wallet result(*this);
	for (int i = 0; i < rhs.size; i++)
	{
		int index = result.isUnique(rhs.arr[i]);
		if (index == -1)
		{
			result = result + rhs.arr[i]; //wallet + money operator is called
		}
		else
		{
			result.arr[index].amount += rhs.arr[i].amount;
		}
	}
	return result;
}
Wallet Wallet::operator-(const Money& rhs) const
{
	int index = this->isUnique(rhs); 
	if(index != -1) //make sure the given money object is contained within the wallet so that it can be subtracted from wallet's amount
	{
		if(this->arr[index].amount > rhs.amount)
			 this->arr[index].amount -= rhs.amount;

		else if(arr[index].amount < rhs.amount)
			return  *this;

		else
		{
			if(this->size == 1) //if rhs is the only item in the wallet and rhs.amount == this->arr[index], return empty wallet
			{
				Wallet w;
				return w;
			}
			else
			{
				Wallet newWallet(this->size-1); //initialize with parametric constructor, allocate new memory and set size
				//newWallet.size =  this->size-1;
				int new_index = 0;
				for(int i = 0; i < this->size; i++)
				{
					if(this->arr[i].currency != rhs.currency)
					{
						newWallet.arr[new_index] = this->arr[i];
						new_index++;
					}
				}
				return newWallet;
			}
		}
	}
	return *this;
}

//free functions
bool operator==(const Wallet& lhs, const Wallet& rhs)
{
	bool valid = true;
	if(lhs.get_size() != rhs.get_size()) //if sizes are different they can't be equal to each other
		valid = false;
	else
	{
		int size = rhs.get_size();
		Money* arr_rhs = rhs.get_arr();
		Money* arr_lhs = lhs.get_arr();
		int index = -1;
		for(int i = 0; i < size && valid == true; i++)
		{
			index = lhs.isUnique(arr_rhs[i]);
			if(index == -1)
				valid = false;

			else if(arr_lhs[index].amount != arr_rhs[i].amount)
				valid = false;
		}
	}
	return valid;
}
bool operator>=(const Wallet& lhs, const Money& rhs)
{
	bool valid = true;
	int index = lhs.isUnique(rhs);
	if(index == -1) //rhs is not constained in lhs
		valid = false;
	else
	{
		Money* arr = lhs.get_arr();
		if(!(arr[index].amount >= rhs.amount))
			valid = false;
	}
	return valid;
}
bool operator<=(const Money& lhs, const Wallet& rhs)
{
	bool valid = true;
	int index = rhs.isUnique(lhs);
	if(index == -1)	//lhs is not constained in rhs
		valid = false;
	else
	{
		Money* arr = rhs.get_arr();
		if(!(arr[index].amount <= lhs.amount))
			valid = false;
	}
	return valid;
}
Wallet& operator+=(Wallet& lhs, const Wallet& rhs) 
{
	Money* arr = rhs.get_arr();
	int index = -1;
	for (int i = 0; i < rhs.get_size(); i++)
	{
		index = lhs.isUnique(arr[i]);
		if(index == -1)
			lhs = lhs + arr[i]; //wallet + money operator called
		else
			lhs.get_arr()[index].amount += arr[i].amount;
	}
	return lhs;
}
std::ostream& operator<<(std::ostream& os, const Wallet& wa)
{
	int size = wa.get_size();
	if(size != 0) //wallet is not empty
	{
		Money* arr = wa.get_arr();
		for(int i = 0; i < size-1; i++)
		{
			os << arr[i].currency << " " << arr[i].amount << "  -  ";
		}
		os << arr[size-1].currency << " " << arr[size-1].amount;
	}
	return os;
}