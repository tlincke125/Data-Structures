#include <iostream>

template <class T>
SingleLinkedList<T>::SingleLinkedList(){
	head = nullptr;
}

template <class T>
SingleLinkedList<T>::~SingleLinkedList(){
	while(head){
		singleNode<T> * next = head;
		head = head->next;
		delete next;
	}	
}

template <class T>
bool SingleLinkedList<T>::isEmpty(){
	return head == nullptr;
}


template <class T>
void SingleLinkedList<T>::insertFront(T val){
	singleNode<T> * newNode = new singleNode<T>;
	newNode->val = val;
	newNode->next = head;
	head = newNode;
}

template <class T>
void SingleLinkedList<T>::insertEnd(T val){

	singleNode<T> * newNode = new singleNode<T>;
	newNode->val = val;
	newNode->next = nullptr;
	if(head == nullptr){
		head = newNode;
		return;
	}
	singleNode<T> * temp = head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = newNode;
	return;
}

template <class T>
void SingleLinkedList<T>::printLL(){
	singleNode<T> * temp = head;
	while(temp){
		std::cout<<temp->val<<" ";
		temp=temp->next;
	}
	std::cout<<std::endl;

}

template <class T>
void SingleLinkedList<T>::insertVal(T val, int index){
	singleNode<T> * temp = new singleNode<T>;
	temp->val = val;
	temp->next = nullptr;
	singleNode<T> * tempH = head;
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
			return;
		}
		tempH = tempH->next;

	}
	tempH = temp;
}


/*
template <class T>
void SingleLinkedList<T>::reverseLL(){

}

template <class T>
void SingleLinkedList<T>::reverseLL(){

}

template <class T>
void SingleLinkedList<T>::get(int index){

}

*/
