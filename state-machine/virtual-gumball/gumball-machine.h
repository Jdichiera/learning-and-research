#ifndef GUMBALLMACHINE_H
#define GUMBALLMACHINE_H
#include <iostream>
#include <string>

enum States{
	SOLD_OUT,
	NO_QUARTER,
	HAS_QUARTER,
	SOLD
};

class GumballMachine {
public:
	GumballMachine(int gumballs);
	~GumballMachine();
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispenseGumball();
	void getState();
	void getInventory();
	void machineStatus();

private:
	States m_state;
	int m_inventory;
};
#endif // !GUMBALLMACHINE_H
