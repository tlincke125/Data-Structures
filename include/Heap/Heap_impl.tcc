
template <class T>
void swap(T * a, T * b){
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
MinHeap<T>::MinHeap(int cap){
	currentSize = 0;
	capacity = cap;
	heapArr = new T[capacity];
}

template <class T>
int MinHeap<T>::parent(int index){
	return (index-1)/2;
}

template <class T>
int MinHeap<T>::leftChild(int index){
	return ((2 * index) + 1);
}

template <class T>
int MinHeap<T>::rightChild(int index){
	return ((2 * index) + 2);
}

template <class T>
T MinHeap<T>::getMin()
{
	return heapArr[0];
}

template <class T>
void MinHeap<T>::heapify(int i){
	int l = leftChild(i);
	int r = rightChild(i);
	int small = i;

	if(l < currentSize && heapArr[l] < heapArr[i])small = l;
	if(r < currentSize && heapArr[r] < heapArr[small])small = r;
	if(small != i){
		swap(heapArr + i, heapArr + small);
		heapify(small);
	}
}

template <class T>
void MinHeap<T>::insertElement(T val){
	if(currentSize == capacity){
		std::cout<<"Max heap size"<<std::endl;
		return;
	}
	int index = currentSize++;
	heapArr[index] = val;

	while(index && heapArr[parent(index)] > heapArr[index]){
		swap(heapArr + index, heapArr + parent(index));
		index = parent(index);
	}
}


template <class T>
void MinHeap<T>::print(){
	for(int i = 0; i < currentSize; i++)std::cout<<heapArr[i]<<" ";
	std::cout<<std::endl;
}

template <class T>
T MinHeap<T>::extractMin()
{
	if(currentSize <=0)exit(1);
	if(currentSize == 1)return heapArr[--currentSize];
	T min = heapArr[0];
	heapArr[0] = heapArr[--currentSize];
	heapify(0);
}

