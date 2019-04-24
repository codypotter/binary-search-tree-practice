#include<iostream>

struct node {
	int data;
	node* left;
	node* right;
};

class BinarySearchTree {
	private:
		node* root;
		void add(node* &current, int data);
		void printInOrder(node* current);
		node* copyTree(node* current);

	public:
		BinarySearchTree();
		BinarySearchTree(node* newRoot);
		void add(int data);
		void printInOrder();
		BinarySearchTree* copyTree();
};

/*
 * Public Methods
 */

BinarySearchTree::BinarySearchTree() {
	root = NULL;
}

BinarySearchTree::BinarySearchTree(node* newRoot) {
	root = newRoot;
}

void BinarySearchTree::add(int data) {
	this->add(root, data);
}

void BinarySearchTree::printInOrder() {
	this->printInOrder(root);
}

BinarySearchTree* BinarySearchTree::copyTree() {
	return new BinarySearchTree(this->copyTree(root));
}


/*
 * Private Methods
 */

void BinarySearchTree::add(node* &current, int data) {
	if (current == NULL) {
		node* newNode = new node;
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		current = newNode;
		return;
	} else if (current->data < data) {
		add(current->right, data);
		return;
	} else if (current->data > data) {
		add(current->left, data);
		return;
	} else {
		return;
	}
}

void BinarySearchTree::printInOrder(node* current) {
	if (current) {
		printInOrder(current->left);
		std::cout << current->data << std::endl;
		printInOrder(current->right);
	} else return;
}


node* BinarySearchTree::copyTree(node* current) {
	if (current == NULL) {
		node* newNode = NULL;
		return newNode;
	} else {
		node* newNode = new node;
		newNode->left = copyTree(current->left);
		newNode->right = copyTree(current->right);
		newNode->data = current->data;
		return newNode;
	}
}









