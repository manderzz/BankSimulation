//
//  Event.cpp
//  Assignment3
//
//  Created by admin on 2017-07-01.
//  Modified by faraz098.
//  Copyright © 2017 Maxim Puchkov, Faraz Fazlalizadeh. All rights reserved.
//

#include "Event.h"

/**
 Default constructor.
 */
Event::Event() { }

/**
 Parameterized constructor.
 
 @param eventType Type of the event (ARRIVAL or DEPARTURE).
 
 @param time Arrival time of this customer.
 
 @param duration Duration of this customer's transaction.
 */
Event::Event(EventType eventType, int time, int duration) : type(eventType), time(time) {
    if (eventType == DEPARTURE) {
        this->duration = 0;
    } else {
        this->duration = duration;
    }
}

/**
 Getter method.
 
 @returns Type of the event.
 */
EventType Event::getType() const {
    return type;
}

/**
 Getter method.
 
 @returns Arrival time of the customer.
 */
int Event::getTime() const {
    return time;
}

/**
 Getter method.
 
 @returns Transaction duration time of the customer.
 */
int Event::getDuration() const {
    return duration;
}

/**
 Setter method.
 
 @param eventType New event type of the event.
 */
void Event::setType(EventType eventType) {
    type = eventType;
}

/**
 Setter method.
 
 @param time New arrival time of the customer.
 */
void Event::setTime(int time) {
    this->time = time;
}

/**
 Setter method.
 
 @param duration New transaction duration time of the customer.
 */
void Event::setDuration(int duration) {
    this->duration = duration;
}

/**
 Overloaded "less than" operator.
 
 @param event Event that is compared to the other event.
 
 @param other Event to be compared to.
 
 @returns True if the arrival time is less than the other's event.
 
 @returns True if it is an arrival event and the other event is a departure
 event and the arrival times are equal.
 
 @returns False otherwise.
 */
bool operator<(Event &event, Event &other) {
    if (event.getTime() == other.getTime()) {
        return (event.getType() < other.getType());
    }
    return (event.getTime() < other.getTime());
}

/**
 Overloaded "greater than" operator.
 
 @param event Event that is compared to the other event.
 
 @param other Event to be compared to.
 
 @returns True if the arrival time is greater than the other's event.
 
 @returns True if it is a departure event and the other event is an arrival
 event and the arrival times are equal.
 
 @returns False otherwise.
 */
bool operator>(Event &event, Event &other) {
    if (event.getTime() == other.getTime()) {
        return (event.getType() > other.getType());
    }
    return (event.getTime() > other.getTime());
}

/**
 Default destructor.
 */
Event::~Event() { }
