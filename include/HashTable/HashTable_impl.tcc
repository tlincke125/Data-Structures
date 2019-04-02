template <class T>
HashTable<T>::HashTable(int _size){
	size = _size;
	numCollisions = 0;
	numItems = 0;
	hashTable = new Node<T>*[size];
	for(register int i = 0; i < hashTableSize; i++)hashTable[i] = nullptr;
}
template <class T>
HashTable::~HashTable(){

}
void HashTable<T>::print();
void HashTable<T>::printTopN(int n);

template <class T>
void addVal(T val){
	!isInTable(val) ? numItems++ : numItems;	
	addItemLL(hashTable[getHash(T)], T){
		numCollisions++;
	}
}
bool isInTable(T val);
int getNumCollisions();
int getNumItems();
int getTotalNumWords();



unsigned int getHash(T val);
Node * searchTable(T val);
Node<T> ** hashTable;
int size;
int numItems;
int numCollisions;

