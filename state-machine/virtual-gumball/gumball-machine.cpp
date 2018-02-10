#include "gumball-machine.h"

GumballMachine::GumballMachine(int gumballs)
{
	m_inventory = gumballs;

	// If the machine has inventory then the state is set to NO_QUARTER
	// else the machine is empty and the state is set to SOLD_OUT
	if (m_inventory > 0) {
		m_state = States::NO_QUARTER;
	}
	else {
		m_state = States::SOLD_OUT;
	}
}

GumballMachine::~GumballMachine()
{
}

void GumballMachine::insertQuarter()
{
	std::cout << "\nInserting quarter ...";
	if (m_state == States::HAS_QUARTER) {
		std::cout << "\n++The machine already has a quarter inserted ...";
	}
	else if (m_state == States::NO_QUARTER) {
		// Change state to HAS_QUARTER
		m_state = States::HAS_QUARTER;
		std::cout << "\n++You inserted a quarter.";
	}
	else if (m_state == States::SOLD_OUT) {
		std::cout << "\n++The machine is sold out. Do not insert quarter.";
	}
	else if (m_state == States::SOLD) {
		std::cout << "\n++Currently dispensing gumball. Please wait ...";
	}
}

void GumballMachine::ejectQuarter()
{
	std::cout << "\nPressing quarter eject ...";

	if (m_state == States::HAS_QUARTER) {
		std::cout << "\n++Returning quarter ...";
		m_state = States::NO_QUARTER;
	}
	else if (m_state == States::NO_QUARTER) {
		std::cout << "\n++No quarter inserted ...";
	}
	else if (m_state == States::SOLD) {
		std::cout << "\n++Cant return quarter, gumball already sold ...";
	}
	else if (m_state == States::SOLD_OUT) {
		std::cout << "\n++Machine is sold out. No quarter inserted ...";
	}
}

void GumballMachine::turnCrank()
{
	std::cout << "\nTurning crank ...";
	if (m_state == States::SOLD) {
		std::cout << "\n++Already dispensing gumball. Purchase another once finished ...";
	}
	else if (m_state == States::NO_QUARTER) {
		std::cout << "\n++Please insert quarter before turning crank ...";
	}
	else if (m_state == States::SOLD_OUT) {
		std::cout << "\n++Please wait for inventory to be refilled before turning crank ...";
	}
	else if (m_state == States::HAS_QUARTER) {
		std::cout << "\n++Turning crank ...";
		m_state = States::SOLD;
		dispenseGumball();
	}
}

void GumballMachine::dispenseGumball()
{
	if (m_state == States::SOLD) {
		std::cout << "\n++Gumball dispensed. Thank you for your purchase!";
		m_inventory--;
		if (m_inventory == 0) {
			std::cout << "\n++Last gumball sold. Machine empty.";
			m_state = States::SOLD_OUT;
		}
		else {
			m_state = States::NO_QUARTER;
		}
	}
	else if (m_state == States::NO_QUARTER) {
		std::cout << "\n++Please insert quarter and turn crank to purchase gumball ...";
	}
	else if (m_state == States::SOLD_OUT) {
		std::cout << "\n++Machine sold out. Try again later.";
	}
	else if (m_state == States::HAS_QUARTER) {
		std::cout << "\n++Please turn crank to dispense gumball.";
	}
}

void GumballMachine::getState()
{
	std::string stateName;
	switch (m_state) {
	case 0:
		stateName = "SOLD_OUT";
		break;
	case 1:
		stateName = "NO_QUARTER";
		break;
	case 2:
		stateName = "HAS_QUARTER";
		break;
	case 3:
		stateName = "SOLD";
		break;

	}
	std::cout << "\n     [STATE] : " << stateName;
}

void GumballMachine::getInventory()
{
	std::cout << "\n     [INVENTORY] : " << m_inventory;
}

void GumballMachine::machineStatus()
{
	std::cout << "\n--== Machine Status ==--";
	getState();
	getInventory();
	std::cout << "\n--== ==--\n";
}
