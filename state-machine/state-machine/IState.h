#ifndef ISTATE_H
#define ISTATE_H
#include <string>

class IState {
public:
	virtual std::string GetName() { return std::string(); }
	virtual void Run() {};
};
#endif // !ISTATE
