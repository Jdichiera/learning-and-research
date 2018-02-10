#include <cstdlib>
#include <iostream>


template <class T>

struct Node {
	T value;
	Node *left;
	Node *right;

	Node(T value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}

	Node(T value, Node<T> left, Node<T> right) {
		this->value = value;
		this->left = left;
		this->right = right;
	}
};


template <class T>

class Tree {
private:
	Node<T> *root;

public:
	Tree() {
		root = NULL;
	}
	void AddNodeHelper(Node<T> *root, T value) {
		if (root->value > value) {
			if (root->left == NULL) {
				root->left = new Node<T>(value);
			}
			else {
				AddNodeHelper(root->left, value);
			}
		}
		else {
			if (root->right == NULL) {
				root->right = new Node<T>(value);
			}
			else {
				AddNodeHelper(root->right, value);
			}
		}
	}
	void AddNode(T value) {
		std::cout << "\nAdding node";
		if (root != NULL) {
			this->AddNodeHelper(root, value);
		}
		else {
				root = new Node<T>(value);
		}
	}

	void Print() {
		this->PrintHelper(root);
	}

	void PrintHelper(Node<T> *root) {
		if (root == NULL) {
			return;
		}
		PrintHelper(root->left);
		std::cout << root->value << ' ';
		PrintHelper(root->right);
	}
	int Count() {
		return CountHelper(root);
	}

	int CountHelper(Node<T> *root) {
		if (root == NULL) {
			return 0;
		}
		else {
			return 1 + CountHelper(root->left) + CountHelper(root->right);
		}
	}
	// TODO:
	// Height
	// Print max path
	// Delete node
	// Find node
};


int main() {
	Tree<int> *tree = new Tree<int>();

	
	tree->AddNode(5);
	tree->AddNode(4);
	tree->AddNode(11);
	tree->AddNode(3);
	std::cout << "\nPrinting nodes :";
	tree->Print();
	int count = tree->Count();
	std::cout << "\nNode count: " << count;;
	std::cout << std::endl;
	system("pause");
	return 0;
}