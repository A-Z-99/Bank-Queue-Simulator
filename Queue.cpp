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

#include "Queue.h"
#include "EmptyDataCollectionException.h"

#ifndef QUEUE_CPP
#define QUEUE_CPP

template <typename T>
// Description: Constructor
Queue<T>::Queue() {
    elements = new T[INITIAL_CAPACITY];
}

template <typename T>
Queue<T>::~Queue(){
    delete[] elements;
}

// Description: Inserts newElement at the back of Queue
// Time Efficiency: O(1)
template <typename T>
bool Queue<T>::enqueue(T newElement) {
    //expand Queue size if full
    if (elementCount == capacity){
        capacity *= 2;
        T* newArray = new T[capacity];
        if(newArray == nullptr){
            return false;
        }
        //copy items over
        if (frontindex < backindex){
            for(unsigned int i = frontindex; i < backindex; i++){
                newArray[i] = elements[i];
            }
        }
        else{
        //Note: alternative approach could be to reset element alignment so frontindex=0 and backindex=elementcount
            //move items between front to capacity-1 to the equivalant offset from new capacity in newArray
            for (unsigned int i = frontindex; i < capacity/2; i++){
                newArray[capacity-(capacity/2-i)] = elements[i];
            }
            frontindex = capacity-(capacity/2-frontindex);
            //move items from start of array to backindex to same positions in newArray
            for (unsigned int i = 0; i < backindex; i++){
                newArray[i] = elements[i];
            }
        }
        //delete old array
        delete[] elements;
        //assign new array
        elements = newArray;
    }
    elementCount++;
    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;    
    return true;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Exception: Throws EmptyDataCollectionException if this Queue is empty.  
// Time Efficiency: O(1)
template <typename T>
void Queue<T>::dequeue() {
    if(elementCount == 0){
        throw EmptyDataCollectionException("The queue is empty");
    }
    //Shrink Queue if elementCount <= capacity/4.
    //Use <= instead of < because we will dequeue the element after so that elementCount < capacity/4
    if (elementCount <= capacity/4 && capacity/2 >= INITIAL_CAPACITY){
        capacity /= 2;
        T* newArray = new T[capacity];
        if (frontindex <= backindex){
            for(unsigned int i = 0; i < (backindex-frontindex); i++){
                newArray[i] = elements[frontindex+i];
            }
            //update the back index and front index
            backindex = backindex-frontindex;
            frontindex = 0;
            /* This previous code caused issues since resizing the array could put front and/or back index outside of the array capacity
            for(unsigned int i = frontindex; i < backindex; i++){
                newArray[i] = elements[i];
            }
            */
        }
        else {
            //Note: approach used is to reset element alignment so frontindex=0 and backindex=elementcount
            //move items between front to capacity-1 to the front of the newArray
           for (unsigned int i = frontindex; i < capacity*2; i++){
                newArray[i-frontindex] = elements[i];
            }
            //move items between 0 to backindex to the position adjacent to the front element block 
            for (unsigned int i = 0; i < backindex; i++){
                newArray[i+capacity*2-frontindex] = elements[i];
            }
            backindex = backindex-frontindex;
            frontindex = 0;
            /*alternative approach is implemented below:
            //move items between front to capacity-1 to the equivalant offset from new capacity in newArray
            for (unsigned int i = frontindex; i < capacity*2; i++){
                newArray[capacity-(capacity*2-i)] = elements[i];
            }
            frontindex = capacity-(capacity*2-frontindex);
            //move items from start of array to backindex to same positions in newArray
            for (unsigned int i = 0; i < backindex; i++){
                newArray[i] = elements[i];
            }
            */
        }
        //delete old array
        delete[] elements;
        //assign new array
        elements = newArray;
    }
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
    return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
template <typename T>
T Queue<T>::peek() const {
    return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
template <typename T>
bool Queue<T>::isEmpty() const {
    return elementCount == 0;
}
#endif