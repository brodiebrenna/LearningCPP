#pragma once
#include <memory>

/*
	@TODO
	single linked list
	doubly linked list


*/

namespace learncpp {


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
		int numberOfElements = 0;
	public:
		LinkedList() : head(nullptr) {}

		int size() {
			return numberOfElements;
		}

		void insertAtHead(DataType value) {
			std::unique_ptr<SinglyLinkedNode<DataType>> newNode = std::make_unique<SinglyLinkedNode<DataType>>(value);
			newNode->nextNode = std::move(head);
			head = std::move(newNode);
			numberOfElements++;
		}

		void insertAtEnd(DataType value) {
			std::unique_ptr<SinglyLinkedNode<DataType>> newNode = std::make_unique<SinglyLinkedNode<DataType>>(value);
			if (!head) {
				head = std::move(newNode);
				numberOfElements++;
				return;
			}
			SinglyLinkedNode<DataType>* temp = head.get();
			while (temp->nextNode) {
				temp = temp->nextNode.get();
			}
			temp->nextNode = std::move(newNode);
			numberOfElements++;
		}
		void deleteHead() {
			if (!head) {
				return;
			}
			if (head->nextNode) {
				head = std::move(head->nextNode);
			}
			else {
				head.reset();
			}
			numberOfElements--;
		}
		void deleteFromEnd(){
			if (!head) {
				return;
			}
			if (!head->nextNode) {
				deleteHead();
				return;
			}
			SinglyLinkedNode<DataType>* temp = head.get();
			while (temp->nextNode->nextNode) {
				temp = temp->nextNode.get();
			}
			temp->nextNode.reset();
			numberOfElements--;
		}
		void deleteByValue(DataType valueToDelete) {
			if (!head) {
				return;
			}
			if (head->data == valueToDelete) {
				deleteHead();
				return;
			}
			SinglyLinkedNode<DataType>* temp = head.get();
			while (temp->nextNode && temp->nextNode->data != valueToDelete) {
				temp = temp->nextNode.get();
			}
			if (temp->nextNode) {
				temp->nextNode = std::move(temp->nextNode->nextNode);
			}
			numberOfElements--;
		}

		void deleteByIndex(int index) {
			if (!head) {
				return;
			}
			if (index == 0) {
				deleteHead();
				return;
			}
			int counter = 1;
			SinglyLinkedNode<DataType>* temp = head.get();
			while (counter < index && temp->nextNode) {
				temp = temp->nextNode.get();
				counter++;
			}
			if (temp->nextNode) {
				temp->nextNode = std::move(temp->nextNode->nextNode);
			}
			numberOfElements--;
		}

		void reverse() {
			std::unique_ptr<SinglyLinkedNode<DataType>> previousNode = nullptr;
			std::unique_ptr<SinglyLinkedNode<DataType>> currentNode = std::move(head);

			while (currentNode) {
				std::unique_ptr<SinglyLinkedNode<DataType>> next = std::move(currentNode->nextNode);
				currentNode->nextNode = std::move(previousNode);
				currentNode = std::move(next);
			}
			head = std::move(previousNode);

		}

		DataType getValueByIndex(int index) {
			if (!head) {
				return NULL;
			}
			if (index > size()) {
				return NULL;
			}

			SinglyLinkedNode<DataType>* temp = head.get();
			int counter = 0;
			while (counter < index && temp->nextNode) {
				temp = temp->nextNode.get();
				counter++;
			}
			return temp->data;

		}
	};
}