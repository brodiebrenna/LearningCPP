#pragma once
#include <memory>

/*
	@TODO
	single linked list
	doubly linked list


*/


template<typename DataType>
struct SinglyLinkedNode {
	DataType data;
	std::unique_ptr<SinglyLinkedNode<DataType>> nextNode;

	SinglyLinkedNode(DataType value) : data(value), nextNode(nullptr) {}
};

template<typename DataType>
class LinkedList {
private:
	std::unique_ptr<SinglyLinkedNode<DataType>> head;
public:
	LinkedList() : head(nullptr) {}

	void insertAtHead(DataType value) {
		std::unique_ptr<SinglyLinkedNode<DataType>> newNode = make_unique<SinglyLinkedNode<DataType>>(value);
		newNode->nextNode = move(head);
		head = move(newNode);
	}

	void insertAtEnd(DataType value) {
		std::unique_ptr<SinglyLinkedNode<DataType>> newNode = make_unique<SinglyLinkedNode<DataType>>(value);
		if (!head) {
			head = move(newNode);
			return;
		}
		SinglyLinkedNode<DataType>* temp = head.get();
		while (temp->nextNode) {
			temp = temp->nextNode.get();
		}
		temp -> nextNode = move(newNode)
	}
	void deleteByValye(DataType value) {

	}

};