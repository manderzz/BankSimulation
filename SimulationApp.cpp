//
//  SimulationApp.cpp
//  Assignment3
//
//  Created by admin on 2017-07-01.
//  Modified by faraz098.
//  Copyright © 2017 Maxim Puchkov, Faraz Fazlalizadeh. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <sstream>

#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"

// MARK: -

/**
 Event-driven simulation of a bank. Reads required data from the command line.
 
 @code
 uname@hostname: ~$ ./sApp < simulationShuffled1.in
 @endcode
 */
class Simulation {
    
private:
    
    PriorityQueue<Event> priorityQueue;
    
    bool tellerAvailable;
    
    int currentTime;
    
    int totalNumberOfCustomers;
    
    int totalWaitTime;
    
    /**
     Processes an event of type ARRIVAL. Dequeue this event from the priority
     queue. Direct a customer to the teller if available; add a customer to the
     bank line otherwise.
     
     @param event Event to be processed.
     
     @param bankLine The main line of the bank. If teller is not available,
                     add customers to the line.
     */
    void processArrival(const Event &event, Queue<Event> &bankLine);
    
    /**
     Processes an event of type DEPARTURE. Dequeue this event from the priority
     queue. Allow next customer to be processed. If no other customers are
     waiting in line, make the teller available.
     
     @param event Event to be processed.
     
     @param bankLine The main line of the bank. Next customer in line will be
                     the next customer to be processed.
     */
    void processDeparture(const Event &event, Queue<Event> &bankLine);
    
public:
    
    /**
     Default constructor for the Simulation class.
     */
    Simulation();
    
    /**
     Getter method.
     
     @returns priorityQueue property of the class.
     */
    PriorityQueue<Event> getPriorityQueue();
    
    /**
     Read a file and generate events with the data provided.
     
     @note File should contain at least two positive random integer numbers.
     */
    void readFile();
    
    /**
     Run the simulation and process all of the events from the priority queue.
     */
    void run();
    
    /**
     Display statistics (number of customers, average wait time) after the
     simulation has been completed.
     */
    void displayStatistics();
    
};

// MARK: - Simulation Class Implementation

/**
 Default constructor for the Simulation class.
 */
Simulation::Simulation() : totalWaitTime(0) {
   readFile();
}

/**
 Getter method.
 
 @returns priorityQueue property of the class.
 */
PriorityQueue<Event> Simulation::getPriorityQueue() {
    return this->priorityQueue;
}

/**
 Read a file and generate events with the data provided.
 
 @note File should contain at least two positive random integer numbers.
 */
void Simulation::readFile() {
    string line = "";
    while (getline(cin, line)) {
        stringstream ss(line);
        string timeString;
        string durationString;
        getline(ss, timeString, ' ');
        getline(ss, durationString, ' ');
        int time = atoi(timeString.c_str());
        int duration = atoi(durationString.c_str());
        Event event(ARRIVAL, time, duration);
        priorityQueue.enqueue(event);
    }
    totalNumberOfCustomers = priorityQueue.getElementCount();
}

/**
 Run the simulation and process all of the events from the priority queue.
 */
void Simulation::run() {
    cout << "Simulation Begins\n";
    
    Queue<Event> bankLine;
    tellerAvailable = true;
    
    while (!priorityQueue.isEmpty()) {
        try {
            Event event = priorityQueue.peek();
            currentTime = event.getTime();
            if (event.getType() == 0) {
                processArrival(event, bankLine);
            } else {
                processDeparture(event, bankLine);
            }
        } catch (EmptyDataCollectionException &error) {
            // The data collection is empty. Stop processing the queue and break
            // the loop.
            //
            // Display a warning message if required:
            //      cout << "The data collection is empty.\n";
            break;
        }
    }
    
    cout << "Simulation Ends\n";
    displayStatistics();
}


/**
 Processes an event of type ARRIVAL. Dequeue this event from the priority
 queue. Direct a customer to the teller if available; add a customer to the
 bank line otherwise.
 
 @param event Event to be processed.
 
 @param bankLine The main line of the bank. If teller is not available, add
 customers to the line.
 */
void Simulation::processArrival(const Event &event, Queue<Event> &bankLine) {
    priorityQueue.dequeue();
    
    if (bankLine.isEmpty() && tellerAvailable) {
        int departureTime = currentTime + event.getDuration();
        Event departureEvent(DEPARTURE, departureTime, 0);
        priorityQueue.enqueue(departureEvent);
        tellerAvailable = false;
    } else {
        bankLine.enqueue(event);
    }
    
    cout << "Processing an arrival event at time:\t" << event.getTime() << "\n";
}

/**
 Processes an event of type DEPARTURE. Dequeue this event from the priority
 queue. Allow next customer to be processed. If no other customers are
 waiting in line, make the teller available.
 
 @param event Event to be processed.
 
 @param bankLine The main line of the bank. Next customer in line will be the
 next customer to be processed.
 */
void Simulation::processDeparture(const Event &event, Queue<Event> &bankLine) {
    priorityQueue.dequeue();
    
    if (!bankLine.isEmpty()) {
        try {
            Event customer = bankLine.peek();
            totalWaitTime += currentTime - customer.getTime();
            bankLine.dequeue();
            int departureTime = currentTime + customer.getDuration();
            Event departureEvent(DEPARTURE, departureTime, 0);
            priorityQueue.enqueue(departureEvent);
        } catch (EmptyDataCollectionException &error) {
            // The data collection is empty.
            //
            // Display a warning message if required:
            //      cout << "The data collection is empty.\n";
            // Nothing to be done otherwise.
        }
    } else {
        tellerAvailable = true;
    }
    
    cout << "Processing a departure event at time:\t" << event.getTime() << "\n";
}

/**
 Display statistics (number of customers, average wait time) after the
 simulation has been completed.
 */
void Simulation::displayStatistics() {
    double averageWaitTime = static_cast<double>(totalWaitTime) / totalNumberOfCustomers;
    cout << "\nFinal Statistics\n"
    << "\tTotal number of people processed: " << totalNumberOfCustomers << "\n"
    << "\tAverage amount of time spent waiting: " << averageWaitTime
    << "\n\n";
}

// MARK: -

int main() {
    Simulation simulation;
    simulation.run();
    return 0;
}
