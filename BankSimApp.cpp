#include <iostream>
#include <cmath>
#include "PriorityQueue.h"
#include "BinaryHeap.h"
#include "Queue.h"
#include "Event.h"
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;
using std::cin;

void arrivalPrint(unsigned int time){
    cout << "Processing an arrival event at time:";
    unsigned int numDigits = log10(time);
    for(unsigned int i = 0; i < (5-numDigits); i++){
        cout << " ";
    }
    cout << time << endl;
}

void departurePrint(unsigned int time){
    cout << "Processing a departure event at time:";
    unsigned int numDigits = log10(time);
    for(unsigned int i = 0; i < (4-numDigits); i++){
        cout << " ";
    }
    cout << time << endl;
}

void processArrival(Event arrivalEvent, PriorityQueue<Event> &eventPriorityQueue, Queue<Event> &bankLine, bool &tellerAvailable){
    //cout << eventPriorityQueue.peek().getType();
    eventPriorityQueue.dequeue();
    
    if(bankLine.isEmpty() && tellerAvailable){
        unsigned int departureTime = arrivalEvent.getTime() + arrivalEvent.getLength();
        Event newDepartureEvent = Event('D', departureTime, arrivalEvent.getLength());
        eventPriorityQueue.enqueue(newDepartureEvent);
        tellerAvailable = false;
    }
    else{
        bankLine.enqueue(arrivalEvent);
    }
}

void processDeparture(Event departureEvent, PriorityQueue<Event> &eventPriorityQueue, Queue<Event> &bankLine, bool &tellerAvailable, float &cumWaitTime){
    eventPriorityQueue.dequeue();
    if(!bankLine.isEmpty()){
        Event nextCustomer = bankLine.peek();
        cumWaitTime += departureEvent.getTime() - nextCustomer.getTime();
        bankLine.dequeue();
        unsigned int departureTime = departureEvent.getTime() + nextCustomer.getLength();
        Event newDepartureEvent = Event('D', departureTime);
        eventPriorityQueue.enqueue(newDepartureEvent);
    }
    else{
        tellerAvailable = true;
    }
}

void simulate(){
    cout << "Simulation Begins" << endl;
    float cumWaitTime = 0;
    unsigned int peopleprocessed = 0;
    Queue<Event> bankLine;
    PriorityQueue<Event> eventPriorityQueue;
    bool tellerAvailable = true;
    unsigned int arvTime, tsnTime;
    while(cin >> arvTime >> tsnTime){
        Event newArvEvent = Event('A', arvTime, tsnTime);
        eventPriorityQueue.enqueue(newArvEvent);
    }
    while(!eventPriorityQueue.isEmpty()){
        Event newEvent = eventPriorityQueue.peek();
        //unsigned int currentTime = newEvent.getTime();
        if(newEvent.isArrival()){
            arrivalPrint(newEvent.getTime());
            processArrival(newEvent, eventPriorityQueue, bankLine, tellerAvailable);
        }
        else{
            departurePrint(newEvent.getTime());
            processDeparture(newEvent, eventPriorityQueue, bankLine, tellerAvailable, cumWaitTime);
            peopleprocessed++;
        }
    }
    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl << endl;
    float avgWaitTime = cumWaitTime/peopleprocessed;
    cout << "\tTotal number of people processed: " << peopleprocessed << endl;
    cout << "\tAverage amount of time spent waiting: " << avgWaitTime << endl;
}

int main(){
    simulate();
    return 0;
}