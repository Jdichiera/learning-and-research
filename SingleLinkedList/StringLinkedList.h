#pragma once
#include <string>;

class StringLinkedList
{
public:
	StringLinkedList();
	~StringLinkedList();

	bool empty() const;
	const std::string& front() const;
	void addFront(const std::string& element);
	void removeFront();

private:
	StringNode* head;
};

