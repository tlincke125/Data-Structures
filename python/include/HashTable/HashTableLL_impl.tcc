#include <string>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::string;

template <class T>
unsigned int HashTable<T>::getHash(char * wordC)
{
    string word(wordC);
    unsigned int hashValue = 5381;
    int length = word.length();
    for(int i = 0; i < length; i++)
    {
        hashValue = ((hashValue<<5) + hashValue) + word[i];
    }
    hashValue %= size;
    return hashValue;
}



template <class T>
HashTable<T>::HashTable(int _size){
	size = _size;
	numCollisions = 0;
	numItems = 0;
	hashTable = new Node<T>*[size];
	for(int i = 0; i < size; i++)hashTable[i] = nullptr;
}

template <class T>
HashTable<T>::HashTable(int _size, int number, T * arr, char ** arrChar){
    size = _size;
    numCollisions = 0;
    numItems = 0;
    hashTable = new Node<T>*[size];
    for(int i = 0; i < size; i++)hashTable[i] = nullptr;   
    for(int i = 0; i < number; i++)addVal(arr[i], arrChar[i]);
}


template <class T>
HashTable<T>::~HashTable(){
    delete [] hashTable;
}

template <class T>
void printLL(Node<T> * head){
    while(head){
        cout<<"Key = "<<head->val.hashKey<<" --- Value = "<<head->val.val;
        head = head->next;
    }
    cout<<endl;
}

template <class T>
void HashTable<T>::print(){
    for(int i = 0; i < size; i++){
        if(hashTable[i] != nullptr){
            printLL(hashTable[i]);
        }
    }
}
/*
template <class T>
void HashTable<T>::printTopN(int n);
*/
template <class T>
bool addItemLL(Node<T> * &head, nodeData<T> val){
    Node<T> * temp = new Node<T>;
    temp->val = val;
    temp->next = nullptr;
    if(!head){
        head = temp;
        return false;
    }
    Node<T> * tempH = head;
    for(int i = 0; tempH; i++){
        if(tempH->val.hashKey == val.hashKey){
            cout<<"hashKey "<<val.hashKey<<" has already been used"<<endl;
            return true;
        }
        if(tempH->val.hashKey < val.hashKey){
            nodeData<T> tempT = tempH->val;
            tempH->val = temp->val;
            temp->val = tempT;
            temp->next = tempH->next;
            head->next = temp;
            return true;
        }
        tempH = tempH->next;
    }
    tempH = temp;
    return true;
}

template <class T>
void HashTable<T>::addVal(T val, char * hashKey){
    nodeData<T> node;
    node.val = val;
    node.hashKey = hashKey; 
    if(addItemLL(hashTable[getHash(hashKey)], node))numCollisions++;
}

template <class T>
bool HashTable<T>::isInTable(T val){return searchLL(hashTable[getHash(val.hashKey)], val.hashKey);}

template <class T>
int HashTable<T>::getNumCollisions(){return numCollisions;}

template <class T>
int HashTable<T>::getNumItems(){return numItems;}
/*
template <class T>
Node<T>* searchLL(Node * head, string word){
    Node * temp = head;
    while(temp && head->val->hashKey){

    }
}
*/
/*
template <class T>
Node<T>* HashTable<T>::searchTable(T val){return searchLL(hashTable[getHash(word)], word);}
*/
