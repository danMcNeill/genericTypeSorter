#ifndef TSORTER_H
#define TSORTER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

template <typename T> class TSorter {

	private:
		vector<T> array; 
      		unsigned int numElements;
     	 	unsigned int capacity;

      		void swap(typename vector<T>::iterator, typename vector<T>::iterator);

	public:
      		TSorter();
      		TSorter(unsigned int initialCapacity);
      		~TSorter();

	      void clear(); 
	      bool insert(T); 

	      // Make sure the array contains at least newCapacity elements.
	      // If not, grow it to that size and copy in old values
	      unsigned int makeSpace(unsigned int newCapacity); 

	      // Show the first n elements, k per line using << 
	      void show(unsigned int n, unsigned int k); 

	      // "Shuffle" the array elements
	      void shuffle(); 

	      // These are the functions you should implement for Lab 5
	      // You should keep these interfaces the same, but you may add
	      // other "helper" functions if necessary.
	      void insertionSortI();
	      void selectionSortI();
	      void bubbleSortI();     
	      void insertionSortR(); 
	      void selectionSortR();	
	      void bubbleSortR(); 


	void bubbleRecursiveAux(typename vector<T>::iterator, typename vector<T>::reverse_iterator);
	typename vector<T>::iterator findMax(typename vector<T>::iterator);
	void selectionRecursiveAux(typename vector<T>::iterator);

	void insertionRecursiveAux(typename vector<T>::iterator);
	void insertionRecursiveAux2(typename vector<T>::iterator);

	
};

#include "TSorter.cpp"

#endif
