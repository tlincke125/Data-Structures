#ifndef LINKED_LIST_H
#define LINKED_LIST_H


template <class T>
struct singleNode{
    T val;
    singleNode * next;
};

template <class T>
class SingleLinkedList{
    public:
    SingleLinkedList();
    ~SingleLinkedList();

    void insertVal(T val, int index);
    void deleteVal(int index);
    void insertFront(T val);
    void insertEnd(T val);
    
    void reverseLL();
    void get(int index);
    void printLL();
    
    bool isEmpty();

    private:
    singleNode<T> * head;    
};

template <class T>
struct doubleNode{
    T val;

    doubleNode * next;
    doubleNode * previous;
};

template <class T>
class DoubleLinkedList{
     public:
    DoubleLinkedList();
        ~DoubleLinkedList();

        void insertVal(T val, int index);
        void deleteVal(int index);
        void insertFront(T val);
        void insertEnd(T val);

        void reverseLL();
        doubleNode<T> * get(int index);
        void printLL();
    
        bool isEmpty();

    private:
        doubleNode<T> * tail;
        doubleNode<T> * head;
};
//The implementation of a non-specialized template  must be visible  to a translation unit that uses it
//The compiler  must be able to see the implimentation in order to generate code for all specializations
//in the code - so I must import the implimentation to the header
#include "SLinkedList_impl.tcc"
#include "DLinkedList_impl.tcc"
#endif
