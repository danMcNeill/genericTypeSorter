#include <iostream>
using namespace std;

#include "Sorter.h"

void Sorter::swap(int i, int j) {
   int tmp; 
   tmp = array[i]; 
   array[i] = array[j];
   array[j] = tmp; 
   return; 
}

Sorter::Sorter() {
   numElements = 0;
   capacity = 0;
   array = NULL;  
}

Sorter::Sorter(unsigned int initialCapacity) {
   capacity = initialCapacity; 
   numElements = 0;
   array = new int[capacity]; 
}

unsigned int Sorter::makeSpace(unsigned int newCapacity) {
   int *old; 
   unsigned int i;
   if (newCapacity > capacity) {
      old = array; 
      array = new int[newCapacity]; 
      for (i=0; i<numElements; i++) 
         array[i] = old[i]; 
      capacity = newCapacity;
      delete old; 
   }

   return capacity;
}

void Sorter::clear() {
   numElements = 0;
   return; 
}

bool Sorter::insert(int element) {
   if (numElements >= capacity) 
      return false;
   array[numElements++] = element;  
   return true;
}

Sorter::~Sorter() {
   if (array) {
      delete array; 
      numElements = 0; 
   }
}

// Shuffle array elements
void Sorter::shuffle() {
   unsigned int j; 
   for (unsigned int i=1; i<numElements; i++) {
      j = rand() % i; 
      swap(i, j); 
   }
}

// Show the first n elements, k per line, using << 
void Sorter::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << array[i] << " "; 
   }
   cout << endl << endl;
} 

// Iterative Insertion Sort
void Sorter::insertionSortI() {
	int i, j, insertNum;
	for(i=1; i<numElements; i++) {
		insertNum = array[i];
		j = i;
		while((j > 0) && (array[j-1] > insertNum)) {
			array[j] = array[j-1];
			j = j - 1;
		}
		array[j] = insertNum;
	}
}

// Iterative Selection Sort
void Sorter::selectionSortI() {
	int i, j, min;
	for(i=0; i<numElements-1; i++) {
		min = i;
		for(j=i+1; j <numElements; j++) {
			if(array[j] < array[min])
				min = j;
		}
		swap(i, min);
	}
}

// Iterative Bubble Sort
void Sorter::bubbleSortI() {
	int i, j, temp;
	for(i=numElements-1; i>=0; i--) {
		for(j=1; j<=i; j++) {
			if(array[j-1] > array[j])
				swap(j-1, j);
		}
	}
}
     
// Recursive Insertion Sort
void Sorter::insertionSortR() {
   //cout << "Sorter::insertionSortI() not implemented yet." << endl << endl;

      if(numElements == 1) return;

	insertionRecursiveAux(1);
	
}
 
// Recursive Selection Sort
void Sorter::selectionSortR() {
	selectionRecursiveAux(numElements);
}
	
// Recursive Bubble Sort
void Sorter::bubbleSortR() {
	bubbleRecursiveAux(0, numElements-1);
}

void Sorter::insertionRecursiveAux(unsigned int first) {
	unsigned int insertNum, j, k;
	if(first < numElements) {
		//insertNum = array[first];
		j = first;
		 insertionRecursiveAux2(j);
		//array[k] = insertNum;
		insertionRecursiveAux(first+1);
	}

       //first++;
        //if(first < numElements) insertionRecursiveAux(first);
	





	/*int i, j, insertNum;
	for(i=1; i<numElements; i++) {
		insertNum = array[i];
		j = i;
		while((j > 0) && (array[j-1] > insertNum)) {
			array[j] = array[j-1];
			j = j - 1;
		}
		array[j] = insertNum;
	}*/

}

void Sorter::insertionRecursiveAux2(int j) {
	if((j > 0) && (array[j-1] > array[j])) {
		swap(j, j-1);
                //array[j] = array[j-1];
		//j = j - 1;
                j--;
		insertionRecursiveAux2(j);
	}
	//return j;
}


void Sorter::bubbleRecursiveAux(int first, int last) {
	if(last <= 0)
		return;
	if(last == first) {
		bubbleRecursiveAux(0, last-1);
		return;
	}
	if(array[first] > array[first+1])
		swap(first, first+1);
	bubbleRecursiveAux(first+1, last);

}

int Sorter::findMax(int size) {
	if(size == 1)
		return 0;
	int max = findMax(size-1);
	if(array[size-1] > array[max])
		return size-1;
	else
		return max;
}

void Sorter::selectionRecursiveAux(int size) {
	if(size == 1)
		return;
	//int min = first;
	int max = findMax(size);
	swap(max, size-1);
	selectionRecursiveAux(size-1);

}
