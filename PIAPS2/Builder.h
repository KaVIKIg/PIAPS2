#pragma once
#include "Board.h"
#include "Driver.h"


class BoardBuilder
{
protected:
	BoardAnyCar* p;
public:
	
	virtual void createBoard() = 0;
	virtual void buildAdult() = 0;
	virtual void buildBeneficiary() = 0;
	virtual void buildChild() = 0;
	virtual void buildDriver() = 0;
	virtual void buildChildSafetySeat() = 0;

	BoardAnyCar* getBoard() 
	{ 
		return p; 
	}
};

class BoardTaxiBuilder : public BoardBuilder
{
public:
	void createBoard() 
	{ 
		p = new BoardTaxi; 
	}
	void buildDriver() 
	{ 
		p->BoardDriver(new TaxiDriver());
	}

	void buildAdult() 
	{
		p->BoardPassenger(new Adult()); 
	}

	void buildChild() 
	{
		p->BoardPassenger(new Child()); 
		//p->childSafetySeat++; 
		//cout << "Child safety seat installed!\n";
	}

	void buildChildSafetySeat()
	{
		p->BoardSeat(new ChildSafetySeat());

	}

	void buildBeneficiary() {};
};

class BoardBusBuilder : public BoardBuilder
{
public:
	void createBoard() 
	{
		p = new BoardBus; 
	}

	void buildDriver() 
	{ 
		p->BoardDriver(new BusDriver());
	}

	void buildAdult() 
	{
		p->BoardPassenger(new Adult()); 
	}

	void buildChild() 
	{ 
		p->BoardPassenger(new Child()); 
	}

	void buildBeneficiary() 
	{
		p->BoardPassenger(new Beneficiary()); 

	}

	void buildChildSafetySeat()
	{}

};

class Director
{
public:
	BoardAnyCar* createBoard(BoardBuilder& builder, size_t driver, size_t AdultNum = 0, size_t ChildNum = 0, size_t BeneficiaryNum = 0, size_t ChildSafetySeatNum = 0)
	{
		builder.createBoard();

		for (int i = 0; i < driver; i++)
		builder.buildDriver();

		for ( int i = 0; i < AdultNum; i++)
			builder.buildAdult();

		for (int i = 0; i < ChildNum; i++)
			builder.buildChild();

		for (int i = 0; i < BeneficiaryNum; i++)
			builder.buildBeneficiary();

		for (int i = 0; i < ChildSafetySeatNum; i++)
			builder.buildChildSafetySeat();
		
		
			if (driver > 1)
				cout << "There must be no more than one driver!\n";

			else {


				if (ChildSafetySeatNum < ChildNum)
				{
					cout << "There are not enough child safety seats!\n" << endl;

				}

				else


				return builder.getBoard();
			}
		
	}
};