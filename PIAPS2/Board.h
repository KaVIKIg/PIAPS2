#include <vector>
#include "Driver.h"
using namespace std;


class BoardAnyCar
{
protected:
	vector<Driver*> driver;
	vector<Passenger*> passengers;
	int maxPassengers;
	vector<ChildSafetySeat*> childSafetySeat;
	

public:
	//int childSafetySeat = 0;
	
	bool isReady()
	{
		if (driver.size() != 1)
			return false;
		if (passengers.size() < 1)
			return false;
		if (passengers.size() > maxPassengers)
			return false;
		return true;
	}

	void BoardSeat(ChildSafetySeat* c) {
		
	}


	void BoardPassenger(Passenger* p) {
		if (passengers.size() == maxPassengers)
		{
			cout << "Not enough seating!\n" << endl;
			passengers.push_back(p);
		}
		else
			passengers.push_back(p);
	}

	
	virtual void BoardDriver(Driver* p) = 0;
};

class BoardTaxi : public BoardAnyCar
{
public:
	BoardTaxi()
	{
		maxPassengers = 3;
		cout << "BoardTaxi is created\n";
	}

	void BoardDriver(Driver * p) { 
		
		driver.push_back(p);
	}
	~BoardTaxi() {};
};

class BoardBus : public BoardAnyCar
{
public:
	BoardBus()
	{
		maxPassengers = 29;
		cout << "BoardBus is created\n";
	}
	void BoardDriver(Driver* p) {
		 
		driver.push_back(p);

	}
	~BoardBus() {};
};