#include "LL.h"

LL::LL() {
	this->size = 0;
}

LL::~LL() {
	Node* tmp = this->head;
	if (tmp) {
		Node* tmpNext = this->head->next;
		while (tmp) {
			delete tmp;
			tmp = tmpNext;
			if (tmpNext) {
				tmpNext = tmpNext->next;
			}
			else {
				break;
			}
		}
	}
}


void LL::pushFront(int& data) {
	if (this->head) {
        Node* head = new Node{data};
        head->next = this->head;
        this->head = head;
	}
    else{
        this->head = new Node{data};
    }
	this->size++;
}

void LL::pushBack(int& data){
    if (this->head) {
        Node* tmp = this->head;
        Node* tail = new Node{data};
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = tail;
    }
    else{
        this->head = new Node{data};
    }
	this->size++;
}

void LL::deleteFront(){
	if (this->head) {
		Node* head = this->head->next;
		delete this->head;
		this->head = head;
	}
	else {
		throw std::exception{"Nothing to delete, list is empty..."};
	}
}

void LL::deleteBack(){
	if (this->head) {
		Node* tmp = this->head;
		Node* tmpNextNext = this->head->next->next;
		while (tmpNextNext) {
			tmp = tmp->next;
			tmpNextNext = tmpNextNext->next;
		}
		delete tmp->next;
		tmp->next = nullptr;
		this->size--;
	}
	else {
		throw std::exception{ "Nothing to delete, list is empty..." };
	}
}

const int LL::getSize() const {
	return this->size;
}

const Node* LL::getHead() const {
	return this->head;
}