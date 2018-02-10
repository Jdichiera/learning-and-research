#include "StringLinkedList.h"



StringLinkedList::StringLinkedList()
{
	:head(NULL) {}
}


StringLinkedList::~StringLinkedList()
{
	while (!empty()) 
		removeFront();
}

