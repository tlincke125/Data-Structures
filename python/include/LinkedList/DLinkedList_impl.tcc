#include <iostream>

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(){
	head = nullptr;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList(){
	while(head){
		doubleNode<T> * next = head;
		head = head->next;
		delete next;
	}	
}

template <class T>
bool DoubleLinkedList<T>::isEmpty(){
	return head == nullptr;
}


template <class T>
void DoubleLinkedList<T>::insertFront(T val){
	if(head == nullptr){
		head = new doubleNode<T>;
		head->val = val;
		head->next = nullptr;
		head->previous = nullptr;
		tail = head;
		return;
	}
	doubleNode<T> * newNode = new doubleNode<T>;
	newNode->val = val;
	newNode->next = head;
	head->previous = newNode;
	newNode->previous = nullptr;
	head = newNode;
}

template <class T>
void DoubleLinkedList<T>::insertEnd(T val){
    if(head == nullptr){
        head = new doubleNode<T>;
        head->val = val;
        head->next = nullptr;
        head->previous = nullptr;
		tail=head;
        return;
    }
	doubleNode<T> * newNode = new doubleNode<T>;
	newNode->val = val;
	newNode->next = nullptr;
	newNode->previous = tail;
	tail->next = newNode;
	tail = newNode;
}

template <class T>
void DoubleLinkedList<T>::printLL(){
	doubleNode<T> * temp = head;
	while(temp){
		std::cout<<temp->val<<" ";
		temp=temp->next;
	}
	std::cout<<std::endl;
}

template <class T>
void DoubleLinkedList<T>::insertVal(T val, int index){
	doubleNode<T> * temp = new doubleNode<T>;
	temp->val = val;
	temp->next = nullptr;
	temp->previous = nullptr;
	doubleNode<T> * tempH = head;
	if(head == nullptr){
		head = temp;
		return;
	}
	for(int i = 0; tempH; i++){
		if(i == index){
            T tempT = tempH->val;
            tempH->val = temp->val;
            temp->val = tempT;
            temp->next = tempH->next;
            tempH->next = temp;

			//temp->previous = tempH;
            return;
		}
		tempH = tempH->next;

	}
	tempH = temp;
}

template <class T>
void DoubleLinkedList<T>::reverseLL(){
	if(head == nullptr){
		return;
	}

	doubleNode<T> * temp = head;

	for(int i = 0; temp; i++, temp=temp->next){
		doubleNode<T> * temp2 = temp->next;
		temp->next = temp->previous;
		temp->previous = temp2;
	}
	doubleNode<T> * temp3 = tail;
	tail = head;
	head = temp3;

}

template <class T>
void DoubleLinkedList<T>::deleteVal(int index){
	doubleNode<T>* temp = head;
	if(head == nullptr){
		return;
	}
	if(index == 0){
		head = head->next;
		delete temp;
		return;
	}
	for(int i = 1; temp->next; i++, temp=temp->next){
		if(i == index){
			doubleNode<T> * temp2 = temp->next->next;
			delete temp->next;
			temp->next = temp2;
			return;
		}
	}
	std::cout<<"Err Outof Bounds"<<std::endl;
}

template <class T>
doubleNode<T>* DoubleLinkedList<T>::get(int index){
	doubleNode<T>* temp = head;
	for(int i = 0; temp; i++, temp=temp->next){
		if(i == index){
            std::cout<<"here"<<std::endl;
			return temp;
		}
	}
	return nullptr;
}


