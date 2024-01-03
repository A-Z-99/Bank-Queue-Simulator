#include "Queue.h"
#include "testDriver_Q.h"
#include <iostream>
using std::cout;
using std::endl;

//g++ Queue.cpp Event.cpp EmptyDataCollectionException.cpp Queue.h testDriver_Q.cpp -o test

int main () {
    Queue<int> * Q = new Queue<int>();

    // enqueue 1, 2, 3, 4, 5
    for (int i = 1; i <= 5; i++) {
        Q->enqueue(i);
        cout << "enqueue " << i << endl;
    }


    // dequeue 2x elements
    for (int i = 0; i < 2; i++) {
        int y = Q->peek();
        Q->dequeue();
        cout << "peek " << y << endl;
    }


    // enqueue 6, 7, 8, 9, 10
    for (int i = 6; i <= 10; i++) {
        Q->enqueue(i);
        cout << "enqueue " << i << endl;
    }


    // dequeue all elements
    while (!Q->isEmpty()) {
        int y = Q->peek();
        Q->dequeue();
        cout << "peek " << y << endl;
    }
   
    // enqueue 1 to 100
    for (int i = 1; i <= 100; i++) {
        Q->enqueue(i);
        cout << "enqueue " << i << endl;
    }

    // dequeue all elements
    while (!Q->isEmpty()) {
        int y = Q->peek();
        Q->dequeue();
        cout << "peek " << y << endl;
    }
    
    delete Q;
    Q = nullptr;
    return 0;
}
