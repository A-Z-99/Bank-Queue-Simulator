
/* 
 * Queue.h
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Alex Zhu
 * Date: Nov. 12 2023
 */

/******* Start of Queue Public Interface *******/
		
   // Class Invariant:  FIFO or LILO order

   // Description: Returns true if this Queue is empty, otherwise false.
   // Postcondition: This Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   ///bool isEmpty() const;///
   
   // Description: Inserts newElement at the "back" of this Queue 
   //              (not necessarily the "back" of this Queue's data structure) 
   //              and returns true if successful, otherwise false.
   // Time Efficiency: O(1)
   ///bool enqueue(<ElementType> & newElement);///
   
   // Description: Removes (but does not return) the element at the "front" of this Queue 
   //              (not necessarily the "front" of this Queue's data structure).
   // Precondition: This Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
   // Time Efficiency: O(1)
   //void dequeue(); 

   // Description: Returns (but does not remove) the element at the "front" of this Queue
   //              (not necessarily the "front" of this Queue's data structure).
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   //<ElementType> & peek() const;
 
/******* End of Queue Public Interface *******/
#include "Event.h"
 
#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {

	
    private:
        static unsigned int const INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
        T* elements;                

        unsigned int elementCount = 0;                  // Number of elements in the Queue - if you need it!
        unsigned int capacity = INITIAL_CAPACITY;       // Actual capacity of the data structure (number of cells in the array)
        unsigned int frontindex = 0;                    // Index of front element (next dequeued/peeked element)
        unsigned int backindex = 0;                     // Index of where the next element will be enqueued                     

/* You can add private methods. */


    public:
 
/* You cannot remove/modify the public methods below. 
   This also applies to their documentation. 
   However, you can add public methods if you need them 
   like "printQueue()", etc.                            */

        // Description: Constructor
        Queue();

        // Description: Destructor
        ~Queue();

        // Description: Inserts newElement at the back of Queue
        // Time Efficiency: O(1)
        bool enqueue(T newElement);

        // Description: Removes the frontmost element
        // Precondition: Queue not empty
        // Time Efficiency: O(1)
        void dequeue();

        // Description: Returns a copy of the frontmost element
        // Precondition: Queue not empty
        // Time Efficiency: O(1)
        T peek() const;

        // Description: Returns true if and only if Queue empty
        // Time Efficiency: O(1)
        bool isEmpty() const;
        
};
#include "Queue.cpp"
#endif

