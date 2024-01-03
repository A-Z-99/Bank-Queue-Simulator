/* 
 * BinaryHeap.h
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
#include "Event.h"
#include "EmptyDataCollectionException.h"
#ifndef BINARYHEAP_H
#define BINARYHEAP_H

template <typename ElementType>
class BinaryHeap {
    private:
        unsigned int elementCount = 0;
        static unsigned int const INITIAL_CAPACITY = 6;
        unsigned int capacity = INITIAL_CAPACITY;
        ElementType* elements;

        // Utility method
        // Description: Recursively put the array back into a min Binary Heap starting from the root.
        // called when root is removed
        void reHeapDown(unsigned int indexOfRoot);

        // Utility method
        // Description: Recursively put the array back into a min Binary Heap starting from a leaf.
        // called when element is inserted
        void reHeapUp(unsigned int indexOfElement);

    public:
        //constructor
        BinaryHeap();
        //destructor
        ~BinaryHeap();
        
        // Description: Returns the number of elements in the Binary Heap.
        // Postcondition: The Binary Heap is unchanged by this operation.
        // Time Efficiency: O(1)
        unsigned int getElementCount() const;

        // Description: Inserts newElement into the Binary Heap. 
        //              It returns true if successful, otherwise false.      
        // Time Efficiency: O(log2 n)
        bool insert(ElementType & newElement);

        // Description: Removes (but does not return) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
        // Time Efficiency: O(log2 n)
        void remove();

        // Description: Retrieves (but does not remove) the necessary element.
        // Precondition: This Binary Heap is not empty.
        // Postcondition: This Binary Heap is unchanged.
        // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
        // Time Efficiency: O(1) 
        ElementType & retrieve() const;

        


};
#include "BinaryHeap.cpp"
#endif