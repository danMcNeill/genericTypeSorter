#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>

#include "TSorter.h"
#include "TesterClass.h"

#define DEFAULT_NUMVALUES 10
#define MAX_NUMVALUES 1000
#define MIN_NUMVALUES 1

int main (int argc, char **argv) {
   unsigned int numValues = DEFAULT_NUMVALUES; 
   int value;
/*
   if (argc > 1)
      numValues = atoi(argv[1]);  
   if ((numValues < MIN_NUMVALUES) || (numValues > MAX_NUMVALUES)) {
      cerr << "Specify numValues in the range [" << MIN_NUMVALUES; 
      cerr << ", " << MAX_NUMVALUES << endl; 
      cerr << "\nUsage: " << argv[0] << " {numValues}" << endl; 
   }
   if (argc > 2) 
      cerr << "Ignoring extra command line arguments." << endl; */

   cout << endl << "Generating " << numValues << " values for sorting." << endl; 
   TSorter<int> intSort;
   intSort.makeSpace(numValues); 

   srand(time(NULL)); // use this line for pseudo-random numbers 
   // srand(23);      // use this line for deterministic "random" numbers
  
   for (unsigned int i=0; i < numValues; i++) {
      value = rand() % 100;  
      intSort.insert(value); 
   } 

   cout << "Initial array: ";
   intSort.show(25, 10); 

   intSort.insertionSortI();
   cout << "After iterative Insertion Sort:";
   intSort.show(25, 10);

   intSort.shuffle(); 
   cout << "Shuffled: "; 
   intSort.show(25, 10); 

   intSort.selectionSortI();
   cout << "After iterative Selection Sort:";
   intSort.show(25, 10);

   intSort.shuffle(); 
   cout << "Shuffled: "; 
   intSort.show(25, 10); 

   intSort.bubbleSortI();
   cout << "After iterative Bubble Sort:";
   intSort.show(25, 10); 

   intSort.shuffle(); 
   cout << "Shuffled: "; 
   intSort.show(25, 10); 

   intSort.insertionSortR();
   cout << "After recursive Insertion Sort:";
   intSort.show(25, 10); 

   intSort.shuffle(); 
   cout << "Shuffled: "; 
   intSort.show(25, 10); 

   intSort.selectionSortR();
   cout << "After recursive Selection Sort:";
   intSort.show(25, 10); 

   intSort.shuffle(); 
   cout << "Shuffled: "; 
   intSort.show(25, 10); 

   intSort.bubbleSortR();
   cout << "After recursive Bubble Sort:";
   intSort.show(25, 10); 

   intSort.shuffle(); 
   cout << "Shuffled: "; 
   intSort.show(25, 10); 


// making string tester
   TSorter<string> stringSort;
   stringSort.makeSpace(numValues); 

   srand(time(NULL)); // use this line for pseudo-random numbers 
   // srand(23);      // use this line for deterministic "random" numbers

	string tempStrings[] = {"Hello", "Dan", "hello", "apple", "RqWe", "1number", "4numbeR", "DAN", "TIM", "dawg"};
  
   for (unsigned int i=0; i < numValues; i++) {
      stringSort.insert(tempStrings[i]); 
   } 

   cout << "Initial array: ";
   stringSort.show(25, 10); 

   stringSort.insertionSortI();
   cout << "After iterative Insertion Sort:";
   stringSort.show(25, 10);

   stringSort.shuffle(); 
   cout << "Shuffled: "; 
   stringSort.show(25, 10); 

   stringSort.selectionSortI();
   cout << "After iterative Selection Sort:";
   stringSort.show(25, 10);

   stringSort.shuffle(); 
   cout << "Shuffled: "; 
   stringSort.show(25, 10); 

   stringSort.bubbleSortI();
   cout << "After iterative Bubble Sort:";
   stringSort.show(25, 10); 

   stringSort.shuffle(); 
   cout << "Shuffled: "; 
   stringSort.show(25, 10); 

   stringSort.insertionSortR();
   cout << "After recursive Insertion Sort:";
   stringSort.show(25, 10); 

   stringSort.shuffle(); 
   cout << "Shuffled: "; 
   stringSort.show(25, 10); 

   stringSort.selectionSortR();
   cout << "After recursive Selection Sort:";
   stringSort.show(25, 10); 

   stringSort.shuffle(); 
   cout << "Shuffled: "; 
   stringSort.show(25, 10); 

   stringSort.bubbleSortR();
   cout << "After recursive Bubble Sort:";
   stringSort.show(25, 10); 

   stringSort.shuffle(); 
   cout << "Shuffled: "; 
   stringSort.show(25, 10); 







// making TesterClass tester
   TSorter<TesterClass> s;
   s.makeSpace(numValues); 

   srand(time(NULL)); // use this line for pseudo-random numbers 
   // srand(23);      // use this line for deterministic "random" numbers

	//string tempStrings[] = {"Hello", "Dan", "hello", "apple", "RqWe", "1number", "4numbeR", "DAN", "TIM", "dawg"};

	//double tempDoubles[] = {0.04, 0.03, 1.11, 11.0, 10.5, 0.02, 3.2, 4.2, 5.8, 8.88};

	TesterClass* tempTesters[10];

	for(int i=0; i<10; i++)
		tempTesters[i] = new TesterClass(i);	
	
  
   for (unsigned int i=0; i < 10; i++) {
      s.insert(*(tempTesters[i])); 
   } 

   cout << "Initial array: ";
   s.show(25, 10); 

   s.insertionSortI();
   cout << "After iterative Insertion Sort:";
   s.show(25, 10);

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.selectionSortI();
   cout << "After iterative Selection Sort:";
   s.show(25, 10);

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.bubbleSortI();
   cout << "After iterative Bubble Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.insertionSortR();
   cout << "After recursive Insertion Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.selectionSortR();
   cout << "After recursive Selection Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.bubbleSortR();
   cout << "After recursive Bubble Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10);






}
