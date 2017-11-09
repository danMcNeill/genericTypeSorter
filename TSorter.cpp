#ifndef TSORTER_CPP
#define TSORTER_CPP

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include "TSorter.h"

template <typename T>
void TSorter<T>::swap(typename vector<T>::iterator i1, typename vector<T>::iterator i2) {
	T temp = *i1;
	*i1 = *i2;
	*i2 = temp;
	return; 
}

template <typename T>
TSorter<T>::TSorter() {
   numElements = 0;
   capacity = 0;
   //array = NULL;  
}

template <typename T>
TSorter<T>::TSorter(unsigned int initialCapacity) {
   capacity = initialCapacity;
	array.reserve(initialCapacity);
   numElements = 0; 
}

template <typename T>
unsigned int TSorter<T>::makeSpace(unsigned int newCapacity) {
  /* int *old; 
   unsigned int i;
   if (newCapacity > capacity) {
      old = array; 
      array = new int[newCapacity]; 
      for (i=0; i<numElements; i++) 
         array[i] = old[i]; 
      capacity = newCapacity;
      delete old; 
   }

   return capacity;*/

	array.reserve(newCapacity);
	capacity = newCapacity;
	return capacity;
}

template <typename T>
void TSorter<T>::clear() {
	array.clear();
   numElements = 0;
   return; 
}

template <typename T>
bool TSorter<T>::insert(T element) {
   if (numElements >= capacity) 
      return false;
   array.push_back(element);
   numElements++; 
   return true;
}

template <typename T>
TSorter<T>::~TSorter() {
   /*if (array) {
      delete array; 
      numElements = 0; 
   }*/
}

// Shuffle array elements
template <typename T>
void TSorter<T>::shuffle() {
	random_shuffle(array.begin(), array.end());
}

// Show the first n elements, k per line, using << 
template <typename T>
void TSorter<T>::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << array[i] << " "; 
   }
   cout << endl << endl;
} 

// Iterative Insertion Sort
template <typename T>
void TSorter<T>::insertionSortI() {

	typename vector<T>::iterator i1 = array.begin() + 1;
	typename vector<T>::iterator i2;
	typename vector<T>::iterator i3;
	T insertEl;

	for(; i1!=array.end(); i1++) {
		insertEl = *i1;
		i2 = i1;
		while((i2 > array.begin()) && (*(i2-1) > insertEl)) {
			*i2 = *(i2-1);
			i2 = i2 - 1;
		}
		*i2 = insertEl;
	}


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

// Iterative Selection Sort
template <typename T>
void TSorter<T>::selectionSortI() {

	typename vector<T>::iterator i1 = array.begin();
	typename vector<T>::iterator i2;
	typename vector<T>::iterator min;

	for(; i1!=array.end()-1; i1++) {
		min = i1;
		for(i2=i1+1; i2!=array.end(); i2++) {
			if(*i2 < *min)
				min = i2;
		}
		swap(i1, min);
	}


/*	int i, j, min;
	for(i=0; i<numElements-1; i++) {
		min = i;
		for(j=i+1; j <numElements; j++) {
			if(array[j] < array[min])
				min = j;
		}
		swap(i, min);
	}*/
}

// Iterative Bubble Sort
template <typename T>
void TSorter<T>::bubbleSortI() { // sometimes changes largest element to zero
	typename vector<T>::reverse_iterator i1 = array.rbegin();
	typename vector<T>::iterator i2;
	typename vector<T>::iterator i2Prev;
	typename vector<T>::iterator temp;

	for(; i1!=array.rend(); i1++) {
		for(i2=array.begin()+1; i2<=i1.base()-1; i2++) {
			i2Prev = i2-1;
			if(*i2Prev > *i2)
				swap(i2Prev, i2);
		}
	} 



/*	int i, j, temp;
	for(i=numElements-1; i>=0; i--) {
		for(j=1; j<=i; j++) {
			if(array[j-1] > array[j])
				swap(j-1, j);
		}
	}*/
}
     
// Recursive Insertion Sort
template <typename T>
void TSorter<T>::insertionSortR() {
   //cout << "TSorter::insertionSortR() not implemented yet." << endl << endl;
	insertionRecursiveAux(array.begin());
	
}

template <typename T>
void TSorter<T>::insertionRecursiveAux(typename vector<T>::iterator first) {
	typename vector<T>::iterator j;
	typename vector<T>::reverse_iterator end = array.rbegin();
	if(first < end.base()) {
		j = first;
		insertionRecursiveAux2(j);
		insertionRecursiveAux(first+1);
	}



	/*unsigned int insertNum, j, k;
	if(first < numElements) {
		//insertNum = array[first];
		j = first;
		 insertionRecursiveAux2(j);
		//array[k] = insertNum;
		insertionRecursiveAux(first+1);
	}*/
}

template <typename T>
void TSorter<T>::insertionRecursiveAux2(typename vector<T>::iterator j) {
	if((j > array.begin()) && (*(j-1) > *j)) {
		swap(j-1, j);
		j--;
		insertionRecursiveAux2(j);
	}


	/*if((j > 0) && (array[j-1] > array[j])) {
		swap(j, j-1);
                //array[j] = array[j-1];
		//j = j - 1;
                j--;
		insertionRecursiveAux2(j);
	}*/
}
 
// Recursive Selection Sort
template <typename T>
void TSorter<T>::selectionSortR() {
	selectionRecursiveAux(array.end());
}
	
// Recursive Bubble Sort
template <typename T>
void TSorter<T>::bubbleSortR() {
	typename vector<T>::reverse_iterator i = array.rbegin();
   bubbleRecursiveAux(array.begin(), i);
}

template <typename T>
void TSorter<T>::bubbleRecursiveAux(typename vector<T>::iterator first, typename vector<T>::reverse_iterator last) {
	if(first == last.base()-1) {
		bubbleRecursiveAux(array.begin(), last + 1);
		return;
	}
	if(last.base()-1 <= array.begin())
		return;
	typename vector<T>::iterator firstNext = first+1;
	if(*first > *firstNext)
		swap(first, firstNext);
	bubbleRecursiveAux(first+1, last);
	





	/*if(last <= 0)
		return;
	if(last == first) {
		bubbleRecursiveAux(0, last-1);
		return;
	}
	template vector<T>::iterator i1 = 
	if(array[first] > array[first+1])
		swap(first, first+1);
	bubbleRecursiveAux(first+1, last);
*/
}

template <typename T>
typename vector<T>::iterator TSorter<T>::findMax(typename vector<T>::iterator size) {
	if(size == array.begin())
		return array.begin();
	typename vector<T>::iterator max = findMax(size-1);
	if(*(size-1) > *max)
		return (size-1);
	else
		return max;





	/*if(size == 1)
		return 0;
	int max = findMax(size-1);
	if(array[size-1] > array[max])
		return size-1;
	else
		return max;*/
}

template <typename T>
void TSorter<T>::selectionRecursiveAux(typename vector<T>::iterator size) {
	if(size == array.begin())
		return;
	typename vector<T>::iterator max = findMax(size);
	swap(max, (size-1));
	selectionRecursiveAux(size-1);




	/*if(size == 1)
		return;
	//int min = first;
	int max = findMax(size);
	swap(max, size-1);
	selectionRecursiveAux(size-1);*/

}

#endif

