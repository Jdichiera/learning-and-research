#include "gumball-machine.h"

int main() {
	std::cout << "\nCreating Gumball Machine.";
	GumballMachine gumballMachine = GumballMachine(5);

	gumballMachine.machineStatus();

	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();

	gumballMachine.machineStatus();

	gumballMachine.insertQuarter();
	gumballMachine.ejectQuarter();
	gumballMachine.turnCrank();

	gumballMachine.machineStatus();

	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	gumballMachine.ejectQuarter();

	gumballMachine.machineStatus();

	gumballMachine.insertQuarter();
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();
	gumballMachine.insertQuarter();
	gumballMachine.turnCrank();

	gumballMachine.machineStatus();

	system("PAUSE");
	return 0;
}