#include <iostream>
#include "Heap/Heap.hpp"



using namespace std;

int main(){
    int i [18] = {1, 8, 9, 5, 0, 9, 1, 2, 0, 9, 8, 10, 11, 3, 4, 5, 6, 7};
    Heap<int> myHeap = Heap<int>(18, 200, i, false);
    
    myHeap.print();

	return 0;
}
