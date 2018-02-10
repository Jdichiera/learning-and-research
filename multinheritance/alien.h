#ifndef ALIEN_H
#define ALIEN_H
#include <string>
class Alien {
private:
	//std::string type;
	//std::string className;
	std::string ability;
	
public:
	Alien();
	//std::string getType();
	//std::string getClassName();
	std::string getAbility();
	virtual void printInfo();
};
#endif // !ALIEN_H
