#include "Builder.h"
#include <iostream>
using namespace std;

int main()
{
	Director dir;
	BoardBusBuilder bus_builder;
	BoardTaxiBuilder taxi_builder;

	int bus_driver = 1;
	int adult_in_bus = 35;
	int child_in_bus = 2;
	int beneficiary_in_bus = 2;

	BoardAnyCar* BB = dir.createBoard(bus_builder, bus_driver, adult_in_bus, child_in_bus, beneficiary_in_bus, child_in_bus);
	if (BB->isReady())
		cout << "Ready!\n" << endl;
	else
		cout << "The bus is not running!\n";

	cout << endl;

	int taxi_driver = 1;
	int adult_in_taxi = 1;
	int child_in_taxi = 2;
	int childSafetySeat_in_taxi = 1;

	BoardAnyCar* BT = dir.createBoard(taxi_builder, taxi_driver, adult_in_taxi, child_in_taxi, 0, childSafetySeat_in_taxi);
	if (BT->isReady())
		cout << "Ready!\n" << endl;
	else
		cout << "Taxi is not running!\n";
	system("pause");
	return 0;
}
