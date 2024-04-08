#pragma once
#include "LinkedQueue.h"

template <typename T>
class Deque:public LinkedQueue<T> {
public:
	bool enqueue_back(const T& x) {
		this->enqueue(x);
		return true;
	}
	
	bool enqueue_front(const T& x) {
		if(this->isEmpty()) {
			this->enqueue(x);
			return true;
		}
		else {
			Node<T>* p = new Node<T>;
			p->setItem(x);
			p->setNext(this->frontPtr);
			this->frontPtr = p;
			return true;
		}
	}

	bool double_dequeue() {
		if (this->isEmpty()) {
			return false;
		}
		if(this->frontPtr == this->backPtr ) {
			delete this->frontPtr;
			this->frontPtr = nullptr;
			this->backPtr= nullptr;
			return true;
		}
		else
		{
			Node<T>* newfront = this->frontPtr->getNext();
			Node<T>* newrear = this->frontPtr;
			while(newrear->getNext()!= this->backPtr) {
				newrear = newrear->getNext();
			}
			if(newfront==this->backPtr && newrear==this->frontPtr) {
				delete this->frontPtr;
				delete this->backPtr;
				this->frontPtr = nullptr;
				this->backPtr = nullptr;
				return true;
			}
			delete this->frontPtr;
			this->frontPtr = newfront;
			delete this->backPtr;
			this->backPtr = newrear;
			newrear->setNext(nullptr);
		}
	}

};