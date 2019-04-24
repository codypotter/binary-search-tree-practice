#include<cstring>
#include<iostream>

struct listNode {
	char* data;
	listNode* next;
};

class LinkedList {
	private:
		listNode* head;
		bool append(listNode* current, char* word);
		bool remove(listNode* &current, char* word);
		void print(listNode* current);
		void printReverse(listNode* current);
		int getTotalChars(listNode* current);
		int getLengthOfNodeMatching(listNode* current, char* word);
		int getLengthOfFirstAndLast(listNode* current);
		void moveLastNodeToBeginning(listNode* &current);

	public:
		LinkedList();
		bool append(char* word);
		bool remove(char* word);
		void print();
		void printReverse();
		int getTotalChars();
		int getLengthOfNodeMatching(char* word);
		int getLengthOfFirstAndLast();
		void moveLastNodeToBeginning();
};

/*
 *	Public methods
 *
 */

LinkedList::LinkedList() {
	head = NULL;
}

bool LinkedList::append(char* word) {
	return this->append(head, word);
}

bool LinkedList::remove(char* word) {
	return this->remove(head, word);
}

void LinkedList::print() {
	this->print(head);
}

void LinkedList::printReverse() {
	this->printReverse(head);
}

int LinkedList::getTotalChars() {
	return this->getTotalChars(head);
}

int LinkedList::getLengthOfNodeMatching(char* word) {
	return getLengthOfNodeMatching(head, word);
}

int LinkedList::getLengthOfFirstAndLast() {
	return getLengthOfFirstAndLast(head);
}

void LinkedList::moveLastNodeToBeginning() {
	moveLastNodeToBeginning(head);
}


/*
 *	Private methods
 *
 */

bool LinkedList::append(listNode* current, char* word) {
	if (current) {
		if (strcmp(current->data,word) == 0) {
			return false;
		} else if (current->next == NULL) {
			listNode* newNode = new listNode;
			newNode->data = new char[strlen(word) + 1];
			strcpy(newNode->data, word);
			newNode->next = NULL;
			current->next = newNode;
			return true;
		} else {
			return append(current->next, word);
		}
	} else if (current == head) {
		listNode* newNode = new listNode;
		newNode->data = new char[strlen(word) + 1];
		strcpy(newNode->data, word);
		newNode->next = NULL;
		head = newNode;
		return true;
	} else {
		return false;
	}
}

bool LinkedList::remove(listNode* &current, char* word) {
	if (current == NULL) {
		return false;
	} else if (strcmp(current->data, word) == 0) {
		if (current == head) {
			// its the first listNode
			listNode* temp = current;
			head = current->next;
			delete temp;
		} else if (current->next == NULL){
			// its the last listNode
			delete current;
			current = NULL;		
		} else {
			// its a middle listNode
			listNode* temp = current;
			current = current->next;
			delete temp;
		}
		return true;
	} else {
		return remove(current->next, word);
	}
}

void LinkedList::print(listNode* current) {
	if (current) {
		std::cout << current->data << " has length: " << getLengthOfNodeMatching(current->data) << std::endl;
		print(current->next);
	}
}

void LinkedList::printReverse(listNode* current) {
	if (current) {
		printReverse(current->next);
		std::cout << current->data << std::endl;
	}
}

int LinkedList::getTotalChars(listNode* current) {
	if (current) {
		return strlen(current->data) + getTotalChars(current->next);
	} else {
		return 0;
	}
}

int LinkedList::getLengthOfNodeMatching(listNode* current, char* word) {
	if (current == NULL) {
		return 0;
	} else if (strcmp(current->data, word) == 0) {
		return strlen(word);
	} else {
		return getLengthOfNodeMatching(current->next, word);
	}
}

int LinkedList::getLengthOfFirstAndLast(listNode* current) {
	if (current == NULL) {
		return 0;
	} else if (current->next == NULL) {
		return strlen(current->data);
	} else if (current == head) {
		return strlen(current->data) + getLengthOfFirstAndLast(current->next);
	} else {
		return getLengthOfFirstAndLast(current->next);
	}

}

void LinkedList::moveLastNodeToBeginning(listNode* &current) {
	if (current == NULL) {
		return;
	} else if (current->next == NULL) {
		listNode* newNode = new listNode;
		newNode = current;
		newNode->next = head;
		head = newNode;
		current = NULL;
	} else {
		moveLastNodeToBeginning(current->next);
	}
}









