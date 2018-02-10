#include <cstdlib>;
#include <iostream>;

// Create a struct for our node objects. The data variable will hold our int element for the node
// and the node variable will hold a pointer to the address of the next node.
struct node {
	int data;
	node *next;
};

// This class will hold a series of node structs, and provide different methods for working with
// the linked list. The class will consist of a series of node structs and a pointer pointing to 
// both the head and tail of the Head and tail pointers are initially set to NULL for safety.
class LinkedList {
private:
	node *head;
	node *tail;

public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	// Check to see if the head is empty. We can test this by checking to see if the head is NULL.
	// If the head is NULL then the linked list should be empty. We make this function a const
	// because it should never be changing this value, just checking to see if it is NULL.
	bool empty(){
		return head == NULL;
	}

	// Prints out the linked list.
	void display() {
		// Create a new temporary node for printing
		node *temp = new node;
		// Set the temporary node to the node element currently listed as the head. We are essentially
		// grabbing the address of the first element in the list.
		temp = head;
		// While temp is not null (while it holds the address of a node element) print out the element
		// Then point to the next element. Continue until the temp element is NULL.
		std::cout << "\n\n====Display List====\n";
		while (temp != NULL) {
			std::cout << temp->data << "\t";
			temp = temp->next;
		}
		std::cout << "\n========\n";
	}

	// This will add a node to the list. If the list is empty (the head is NULL) then we can add the 
	// new node right to the head of the list. If it is not empty then we add the new node to the end
	// of the list and then point the tail to the new node, since it is now the new tail of the list.
	void addNode(const int value) {
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;

		// If the list is currently empty then there is no head or tail. We set the head and the tail
		// to point at the new node since it is the single element in the list, and then we remove the
		// reference stored in the pointer temp.
		if (this->empty()) {
			head = temp;
			tail = temp;
			temp = NULL;
		}
		// If the list is not empty we point the current tail elements next value at the new node we have created. 
		// Then we set the tail to the new node since it is now the last element in our list. Note that we are not
		// moving the current tail, we are just telling the list that the tail is now the last element in the list.
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	// Inserts a node at the head of the list. This is done by creating a new node, pointing the new node at the current
	// head. Then declaring the new node as the head of the list.
	void insertHead(int value) {
		node *temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}

	// Inserts a new node at a specific position in the list.
	void insertPosition(int position, int value) {
		// Create new temporary pointers to the current node, the node immediately before the current node,
		// and a temporary node that will be inserted.
		node *previousNode = new node;
		node *currentNode = new node;
		node *temp = new node;

		// Set the current node to point to the head of the list.
		currentNode = head;
		for (int i = 1; i < position; i++)
		{
			// Move through the list. At each node, set the previousNode to the currentNode, then set the current
			// node to the node immediately after the currentNode. We are iterating down the list until we reach the
			// desired position.
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		// Now that we have found the right position, we insert the new node between the previousNode and currentNode.
		temp->data = value;
		previousNode->next = temp;
		temp->next = currentNode;
	}

	// Deletes the node at the head of the linked list.
	void deleteHead() {
		// Declare a temporary node so we can target the current head node.
		node *temp = new node;
		temp = head;

		// Set the head node to point at the node immediately after the head.
		head = head->next;

		//Delete the temp node, which is pointing at the old head of the linked list.
		delete temp;
	}

	// Deletes the tail of the linked list. Since we can not jump right to the tail of the list (unless we made a method
	// that does that) we have to iterate through the list until we get to the end.
	void deleteTail() {
		// Declare two new temp pointers which will point to the current and previous nodes in the list as we
		// iterate through.
		node *current = new node;
		node *previous = new node;

		// Start at the head of the linked list
		current = head;

		// Loop through the list as long as the current pointer does not == null. When it equals null we know
		// that we are at the end of the list.
		while (current->next != NULL) {
			// At each step we set the previous pointer to point at the current node, and the current pointer to point
			// at the next node.
			previous = current;
			current = current->next;
		}

		// When the current pointer's next is null we break out of the while loop and we know we have reached the end of
		// the list. At this point, the current pointer is at the tail of the list and the previous pointer is pointing
		// at the node immediately before the current tail. We can set the previous pointer as the new tail, and delete
		// the current pointer, deleting the old tail.
		tail = previous;
		previous->next = NULL;
		delete current;
	}

	// Deletes a node at a specific position. This works similarly to the delete tail function in that we need to iterate
	// through the list to get to the right spot, then delete from there.
	void deletePosition(int position) {
		// Create our current and previous temporary nodes.
		node *current = new node;
		node *previous = new node;

		current = head;
		for (int i = 1; i < position; i++) {
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		delete current;
	}

	// Search for a value in the list. We are simply iterating through the list and comparing values.
	void valueSearch(int value) {
		bool valueFound = false;
		int positionCounter = 0;

		node *previous = new node;
		node *current = new node;
		current = head;

		while (current->next != NULL && valueFound == false) {
			positionCounter++;
			previous = current;
			current = current->next;
			if (value == previous->data) {
				valueFound = true;
			}
		}
		if (valueFound == true) {
			std::cout << "\nValue found at position " << positionCounter << std::endl;
		}
		else {
			std::cout << "\nValue not found in linked list" << std::endl;
		}
	}
};

void main() {
	LinkedList list = LinkedList();

	// Check to see if the list is empty
	std::cout << "\nList is empty : " << list.empty();
	list.display();

	// Add nodes to the list
	list.addNode(1);
	list.addNode(2);
	list.addNode(3);
	list.addNode(4);
	list.addNode(5);
	list.addNode(10);

	// Print out list of nodes
	list.display();

	// Add a node to the head of the list
	std::cout << "Add new node to head ...";
	list.insertHead(100);
	list.display();

	// Add a node at position 3
	std::cout << "Add new node at position 3 ...";
	list.insertPosition(3, 99);
	list.display();

	// Delete a node at position 3
	std::cout << "Deleting node at position 3 ...";
	list.deletePosition(3);
	list.display();

	// Add another node at position 3
	std::cout << "Add new node at position 3 ...";
	list.insertPosition(3, 45);
	list.display();

	// Find a specific node
	std::cout << "Find node with value of 45 ...";
	list.valueSearch(45);

	// Search for a node that does not exist
	std::cout << "Find node that does not exist ...";
	list.valueSearch(999);

	system("pause");
}