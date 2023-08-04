#pragma once
#pragma once
#include <iostream>
using namespace std;


class Passenger
{
protected:

public:
	Passenger() {  };
	//Passenger& operator=(Passenger&) {};
};

class Adult : public Passenger
{
public:
	Adult() {
		cout << "Adult is created\n";
	}
};

class Beneficiary : public Passenger
{
public:
	Beneficiary() 
	{
		cout << "Beneficiary is created\n"; 
	}
};

class Child : public Passenger
{
public:
	Child() 
	{
	
		cout << "Child is created\n"; 
	}

	
};

class ChildSafetySeat
{
public:
	ChildSafetySeat()
	{
		cout << "Child safety seat installed!\n";
	}
};

enum Licenze { BCategory, DCategory };

class Driver
{
public:
	Licenze licenze;
	Driver() {};
};

class TaxiDriver : public Driver
{
public:
	TaxiDriver()
	{
		cout << "TaxiDriver is created\n";
		licenze = BCategory;
	}
};
class BusDriver : public Driver
{
public:
	BusDriver()
	{
		cout << "BusDriver is created\n";
		licenze = DCategory;
	}
};
