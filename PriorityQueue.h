//
//  PriorityQueue.h
//  Assignment3
//
//  Created by admin on 2017-07-01.
//  Modified by faraz098.
//  Copyright © 2017 Maxim Puchkov, Faraz Fazlalizadeh. All rights reserved.
//

#ifndef PriorityQueue_h
#define PriorityQueue_h

#include "Queue.h"
#include "Event.h"

template <class ElementType>
class PriorityQueue {
    
private:
    
    int elementCount;
    ElementType array[100];
    
public:
    
    // Let's put our constructor(s) and destructor (if any) ***here***.
    
    /**
     Default constructor.
     */
    PriorityQueue();
    
    /**
     Convert Queue class to PriorityQueue class.
     
     @param queue Queue to be converted.
     */
    PriorityQueue(Queue<ElementType> &queue);
    
    /******* Public Interface - START - *******/
    
    // Description: Returns the number of elements in the Priority Queue.
    // (This method eases testing.)
    // Time Efficiency: O(1)
    int getElementCount() const;
    
    // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;
    
    // Description: Inserts newElement in sort order.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is sorted.
    // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
    // Time Efficiency: O(n)
    bool enqueue(const ElementType& newElement);
    
    // Description: Removes the element with the "highest" priority.
    //              It returns "true" if successful, otherwise "false".
    // Precondition: This Priority Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();
    
    // Description: Returns (a copy of) the element with the "highest" priority.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    ElementType peek() const throw(EmptyDataCollectionException);
    
    /******* Public Interface - END - *******/
    
    // Let's feel free to add other private helper methods to our Priority Queue class.
    
}; // end PriorityQueue

/**
 Default constructor.
 */
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue() : elementCount(0) { }

/**
 Convert Queue class to PriorityQueue class.
 
 @param queue Queue to be converted.
 */
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(Queue<ElementType> &queue) : elementCount(0) {
    while (!queue.isEmpty()) {
        try {
            ElementType element = queue.peek();
            this->enqueue(element);
            queue.dequeue();
        } catch (EmptyDataCollectionException &error) {
            // The data collection is empty. Stop processing the queue and break
            // the loop.
            //
            // Display a warning message if required:
            //      cout << "The data collection is empty.\n";
            break;
        }
    }
}

// Description: Returns the number of elements in the Priority Queue.
// (This method eases testing.)
// Time Efficiency: O(1)
template <class ElementType>
int PriorityQueue<ElementType>::getElementCount() const {
    return elementCount;
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return (elementCount == 0);
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
// Time Efficiency: O(n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType& newElement) {
    if (getElementCount() >= 100) {
        return false;
    }
    
    int location = getElementCount();
    for (int i = 0; i < getElementCount(); i++) {
        Event event = newElement;
        if (event > array[i]) {
            location = i;
            break;
        }
    }
    
    elementCount++;
    for (int i = getElementCount(); i > location; i--) {
        array[i] = array[i - 1];
    }
    array[location] = newElement;
    return true;
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::dequeue() {
    if (isEmpty()) {
        return false;
    }
    Event event(ARRIVAL, 0, 0);
    array[elementCount - 1] = event;
    elementCount--;
    return true;
}

// Description: Returns (a copy of) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const throw(EmptyDataCollectionException) {
    if (isEmpty()) {
        throw EmptyDataCollectionException("Collection is empty.");
    }
    return array[elementCount - 1];
}

#endif /* PriorityQueue_h */
