//
//  Node.h
//  Assignment3
//
//  Created by admin on 2017-07-01.
//  Modified by faraz098.
//  Copyright © 2017 Maxim Puchkov, Faraz Fazlalizadeh. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <cstdio>

template<class ElementType>
class Node {
    
private:
    
    ElementType item;
    Node<ElementType>* next;
    
public:
    
    /**
     Default constructor.
     */
    Node();
    
    /**
     Constructor with specified item value.
     
     @param item Value of this node's item.
     */
    Node(const ElementType &item);
    
    /**
     Constructor with specified item value and next node.
     
     @param item Value of this node's item.
     
     @param nextNode Next node of the created node.
     */
    Node(const ElementType &item, Node<ElementType> *nextNode);
    
    /**
     Set item of a node.
     
     @param item New value of a node's item.
     */
    void setItem(const ElementType &item);
    
    /**
     Set next node of a node.
     
     @param nextNode Pointer to the next node of a node.
     */
    void setNext(Node<ElementType> *nextNode);
    
    /**
     Getter method.
     
     @returns Node's current item.
     */
    ElementType getItem() const;
    
    /**
     Getter method.
     
     @returns Node's next node.
     */
    Node<ElementType>* getNext() const;
    
};

/**
 Default constructor.
 */
template<class ElementType>
Node<ElementType>::Node() : next(NULL) { }

/**
 Constructor with specified item value.
 
 @param item Value of this node's item.
 */
template<class ElementType>
Node<ElementType>::Node(const ElementType &item) : item(item), next(NULL) { }

/**
 Constructor with specified item value and next node.
 
 @param item Value of this node's item.
 
 @param nextNode Next node of the created node.
 */
template<class ElementType>
Node<ElementType>::Node(const ElementType& item, Node<ElementType> *nextNode) :
item(item), next(nextNode) { }

/**
 Set item of a node.
 
 @param item New value of a node's item.
 */
template<class ElementType>
void Node<ElementType>::setItem(const ElementType &item) {
    this->item = item;
}

/**
 Set next node of a node.
 
 @param nextNode Pointer to the next node of a node.
 */
template<class ElementType>
void Node<ElementType>::setNext(Node<ElementType> *nextNode) {
    next = nextNode;
}

/**
 Getter method.
 
 @returns Node's current item.
 */
template<class ElementType>
ElementType Node<ElementType>::getItem() const {
    return item;
}

/**
 Getter method.
 
 @returns Node's next node.
 */
template<class ElementType>
Node<ElementType>* Node<ElementType>::getNext() const {
    return next;
}

#endif /* Node_h */
