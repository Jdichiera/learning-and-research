// https://www.gamedev.net/articles/programming/general-and-gameplay-programming/state-machines-in-games-r2982/
#include <iostream>
#include "BoringMachine.h"


int main() {
	BoringMachine machine;
	std::vector<std::string> choices;
	std::string selection;
	while (machine.IsComplete()) {
		std::cout << "[STATE] - " << machine.CurrentState().GetName() << std::endl;
		machine.CurrentState().Run();
		choices = machine.PossibleTransactions();
		std::cout << "Potential actions are: " << std::endl;
		for (auto choice : choices) {
			std::cout << choice << " " << std::endl;
		}
		std::cout << "what to do?" << std::endl;
		std::cin >> selection;
		machine.Advance(selection);
	}
	system("PAUSE");


}