/* 
 * BinaryHeap.cpp
 *
 * Description: min Binary Heap ADT class.
 *
 * Class Invariant:  Always a min Binary Heap.
 * 
 * Author: Alex Zhu
 * Last Modification: Nov. 2023
 *
 */  

/******* Start of Binary Heap  Public Interface *******/	

   // Description: Returns the number of elements in the Binary Heap.
   // Postcondition: The Binary Heap is unchanged by this operation.
   // Time Efficiency: O(1)
   //unsigned int getElementCount() const;

   // Description: Inserts newElement into the Binary Heap. 
   //              It returns true if successful, otherwise false.      
   // Time Efficiency: O(log2 n)
   //bool insert(ElementType & newElement);
      
   // Description: Removes (but does not return) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(log2 n)
   //void remove();

   // Description: Retrieves (but does not remove) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Postcondition: This Binary Heap is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(1) 
   //ElementType & retrieve() const;
 
/******* End of Binary Heap Public Interface *******/
#include <iostream>
#include "BinaryHeap.h"  // Header file
#include "EmptyDataCollectionException.h"

#ifndef BINARYHEAP_CPP
#define BINARYHEAP_CPP

using std::cout;
using std::endl;

// constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(){
   elements = new ElementType[INITIAL_CAPACITY];
}

// destructor
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap(){
   delete[] elements;
   elements = nullptr;
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  

   if(elementCount == 0) 
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

   elements[0] = elements[elementCount - 1];
   elementCount--;
   
   // No need to call reheapDown() if we have just removed the only element
   if ( elementCount > 0 ) 
      reHeapDown(0);
   
   return;   
}


// Utility method
// Description: Recursively put the array back into a min Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
} 

// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const{
   return elementCount;
}

// Description: Inserts newElement into the Binary Heap. 
//              It returns true if successful, otherwise false.      
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType & newElement){
   if(elementCount == capacity){ // Array is full. Double its size.
      capacity *= 2;
      ElementType* newArray = new ElementType[capacity];
      if(newArray == nullptr){
         return false;
      }
      for(unsigned int i = 0; i<elementCount; i++){
         newArray[i] = elements[i];
      }
      delete[] elements;
      elements = newArray;
   }
   elements[elementCount] = newElement;
   reHeapUp(elementCount);
   elementCount++;
   return true;
}

// Utility method
// Description: Recursively put the array back into a min Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfElement) {
   // Base case: elements[indexOfElement] is the root and has no parent
   if(indexOfElement == 0){
      return;
   }
   unsigned int indexofParent = (indexOfElement-1)/2; //No need to bother with floor since division rounds down with C++ ints
   // Base case: the parent is less than or equal to the child – the rest of the tree is already heapified
   if(elements[indexofParent] <= elements[indexOfElement]){
      return;
   }
   else{
      //swap parent and child
      ElementType temp = elements[indexOfElement];
      elements[indexOfElement] = elements[indexofParent];
      elements[indexofParent] = temp;
      //recursively heap up the same element
      reHeapUp(indexofParent);
   }
}

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType & BinaryHeap<ElementType>::retrieve() const{
   if(elementCount == 0){
      throw EmptyDataCollectionException("retrieve() called with empty binary heap");
   }
   return elements[0];
}
//template class BinaryHeap<Event>;
#endif