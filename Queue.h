//
//  Queue.h
//  Assignment3
//
//  Created by admin on 2017-07-01.
//  Modified by faraz098.
//  Copyright © 2017 Maxim Puchkov, Faraz Fazlalizadeh. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <cstdio>

#include "Node.h"
#include "Event.h"
#include "EmptyDataCollectionException.h"

template<class ElementType>
class Queue {
    
private:
    
    Node<ElementType> *rear;
    Node<ElementType> *front;
    int elementCount;
    
public:
    
    Queue();
    
    // Let's put our constructor(s) and destructor (if any) ***here***.
    
    /******* Public Interface - START - *******/
    
    // Description: Returns the number of elements in the Queue.
    // (This method eases testing.)
    // Time Efficiency: O(1)
    int getElementCount() const;
    
    // Description: Returns "true" is this Queue is empty, otherwise "false".
    // Time Efficiency: O(1)
    bool isEmpty() const;
    
    // Description: Adds newElement to the "back" of this Queue
    //              (not necessarily the "back" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Time Efficiency: O(1)
    bool enqueue(const ElementType& newElement);
    
    // Description: Removes the element at the "front" of this Queue
    //              (not necessarily the "front" of its data structure) and
    //              returns "true" if successful, otherwise "false".
    // Precondition: This Queue is not empty.
    // Time Efficiency: O(1)
    bool dequeue();
    
    // Description: Returns (a copy of) the element located at the "front" of this Queue.
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType peek() const throw(EmptyDataCollectionException);
    
    /******* Public Interface - END - *******/
    
    // Let's feel free to add other private helper methods to our Queue class.
    
};

template<class ElementType>
Queue<ElementType>::Queue() : rear(NULL), front(NULL), elementCount(0) { }

// Description: Returns the number of elements in the Queue.
// (This method eases testing.)
// Time Efficiency: O(1)
template<class ElementType>
int Queue<ElementType>::getElementCount() const {
    return elementCount;
}

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::isEmpty() const {
    return (elementCount == 0);
}

// Description: Adds newElement to the "back" of this Queue
//              (not necessarily the "back" of its data structure) and
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::enqueue(const ElementType& data) {
    Node<ElementType> *temp = new Node<ElementType>;
    temp->setItem(data);
    temp->setNext(NULL);
    if (front == NULL) {
        front = temp;
    } else {
        rear->setNext(temp);
    }
    rear = temp;
    elementCount++;
    return true;
}

// Description: Removes the element at the "front" of this Queue
//              (not necessarily the "front" of its data structure) and
//              returns "true" if successful, otherwise "false".
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::dequeue() {
    Node<ElementType> *temp = new Node<ElementType>;
    if (front == NULL) {
        return false;
    } else {
        temp = front;
        front = front->getNext();
        delete temp;
    }
    elementCount--;
    return true;
}

// Description: Returns (a copy of) the element located at the "front" of this Queue.
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template<class ElementType>
ElementType Queue<ElementType>::peek() const throw(EmptyDataCollectionException) {
    if (isEmpty()) {
        throw EmptyDataCollectionException("Collection is empty.");
    }
    // Event event = front->getItem();
    ElementType element = front->getItem();
    return element;
}

#endif /* Queue_h */
