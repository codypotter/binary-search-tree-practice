#include"LinkedList.h"
#include"BinarySearchTree.h"

int main(void) {

	LinkedList llist;
	llist.print();
	llist.append((char*)"Suzy");
	llist.append((char*)"Eric");
	llist.append((char*)"Joshua");
	llist.append((char*)"Joshua");
	std::cout << "Printing forward..." << std::endl;
	llist.print();
	std::cout << std::endl;

	llist.moveLastNodeToBeginning();
	llist.print();
	std::cout << std::endl;

	std::cout << "Printing backward..." << std::endl;
	llist.printReverse();
	std::cout <<std::endl;

	std::cout << "Total chars: " << llist.getTotalChars() << std::endl;

	std::cout << "Length of first and last nodes: " << llist.getLengthOfFirstAndLast() << std::endl;	

	std::cout << std::endl;

	BinarySearchTree tree;
	tree.printInOrder();
	tree.add(1);
	tree.add(5);
	tree.add(-5);
	tree.printInOrder();

	std::cout << "copying..." << std::endl;
	BinarySearchTree copyTree = *tree.copyTree();
	tree.add(7);
	copyTree.printInOrder();

	tree.printInOrder();

	return 0;
}
