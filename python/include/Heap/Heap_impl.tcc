
template <class T>
void swap(T * a, T * b){
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <class T>
Heap<T>::Heap(int cap, bool Min){
	currentSize = 0;
	capacity = cap;
    min = Min;
	heapArr = new T[capacity];
}

template <class T>
Heap<T>::Heap(int size, int cap, T * arr, bool Min){
    currentSize = 0;
    capacity = cap;
    min = Min;
    heapArr = new T[capacity];
    for(int i = 0; i < size && i < cap; i++){
        insertElement(arr[i]);
    }
}

template <class T>
int Heap<T>::parent(int index){
	return (index-1)/2;
}

template <class T>
int Heap<T>::leftChild(int index){
	return ((2 * index) + 1);
}

template <class T>
int Heap<T>::rightChild(int index){
	return ((2 * index) + 2);
}

template <class T>
T Heap<T>::getMinMax()
{
	return heapArr[0];
}

template <class T>
void Heap<T>::heapify(int i){
	int l = leftChild(i);
	int r = rightChild(i);
	int value = i;
    if(min){
	    if(l < currentSize && heapArr[l] < heapArr[i])value = l;
	    if(r < currentSize && heapArr[r] < heapArr[value])value = r;
	    if(value != i){
		    swap(heapArr + i, heapArr + value);
		    heapify(value);
	    }
        return;
    }
    if(l < currentSize && heapArr[l] > heapArr[i])value = l;
    if(r < currentSize && heapArr[r] > heapArr[value])value = r;
    if(value != i){
        swap(heapArr + i, heapArr + value);
        heapify(value);
    }

}

template <class T>
void Heap<T>::insertElement(T val){
	if(currentSize == capacity){
		std::cout<<"Max heap size"<<std::endl;
		return;
	}
    int index = currentSize++; 
    if(min){
        heapArr[index] = val;
    //    heapify(index);
	    while(index && heapArr[parent(index)] > heapArr[index]){
		    swap(heapArr + index, heapArr + parent(index));
		    index = parent(index);
	    }
        return;
    }
    heapArr[index] = val;
    while(index && heapArr[parent(index)] < heapArr[index]){
        swap(heapArr + index, heapArr + parent(index));
        index = parent(index);
    }

}


template <class T>
void Heap<T>::print(){
	for(int i = 0; i < currentSize; i++)std::cout<<heapArr[i]<<" ";
	std::cout<<std::endl;
}

template <class T>
T Heap<T>::extractMinMax()
{
	if(currentSize <=0)exit(1);
	if(currentSize == 1)return heapArr[--currentSize];
	T min = heapArr[0];
	heapArr[0] = heapArr[--currentSize];
	heapify(0);
}

