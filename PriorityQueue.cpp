/* 
 * PriorityQueue.cpp
 *
 * Description: implementation of Queue as an ADT class using a min heap
 * Class Invariant: Priority Queue has highest priority element at the top.
 *
 * Author: Alex Zhu
 * Date: Nov. 12 2023
 */

/******* Start of Priority Queue Public Interface *******/

   // Description: Returns true if this Priority Queue is empty, otherwise false.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   //bool isEmpty() const;

   // Description: Inserts newElement in this Priority Queue and 
   //              returns true if successful, otherwise false.
   // Time Efficiency: O(log2 n)
   //bool enqueue(ElementType & newElement);

   // Description: Removes (but does not return) the element with the next
   //              "highest" priority value from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
   // Time Efficiency: O(log2 n)
   //void dequeue();
   
   // Description: Returns (but does not remove) the element with the next 
   //              "highest" priority from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   //ElementType & peek() const;
   
/*******  End of Priority Queue Public Interface *******/
#include "PriorityQueue.h"
#ifndef PRIORITYQUEUE_CPP
#define PRIORITYQUEUE_CPP

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <typename ElementType>
bool PriorityQueue<ElementType>::isEmpty() const{
    return elements.getElementCount() == 0;
}

// Description: Inserts newElement in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <typename ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement){
    if(elements.insert(newElement)){
        return true;
    }
    return false;
}


// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty. <- Binary Heap will do this!
// Time Efficiency: O(log2 n)
template <typename ElementType>
void PriorityQueue<ElementType>::dequeue(){
    elements.remove();
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty <- Binary Heap will do this!
// Time Efficiency: O(1)
template <typename ElementType>
ElementType & PriorityQueue<ElementType>::peek() const{
    return elements.retrieve();
}
#endif