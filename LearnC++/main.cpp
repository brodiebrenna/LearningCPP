#include <iostream>
#include "datastructs.h"

void printLinkedList(learncpp::LinkedList<int>& linkedlist) {
	int size = linkedlist.size();
	for (int i = 0; i < size; i++) {
		std::cout << linkedlist.getValueByIndex(i);
	}
	std::cout << std::endl;
}

void LinkedListTest() {
	int data[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	learncpp::LinkedList<int> linkedlist;
	for (int iterator = 0; iterator < 9; iterator++) {
		linkedlist.insertAtEnd(data[iterator]);
	}
	std::cout << linkedlist.size() << std::endl;
	printLinkedList(linkedlist);
	linkedlist.deleteByIndex(3);
	printLinkedList(linkedlist);
	linkedlist.deleteByIndex(2);
	printLinkedList(linkedlist);
	linkedlist.deleteByIndex(1);
	printLinkedList(linkedlist);
	linkedlist.deleteByIndex(0);
	printLinkedList(linkedlist);
	
}

int main() {
	LinkedListTest();
	return 0;
}