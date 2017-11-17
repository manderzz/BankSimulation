//
//  Event.h
//  Assignment3
//
//  Created by admin on 2017-07-01.
//  Modified by faraz098.
//  Copyright © 2017 Maxim Puchkov, Faraz Fazlalizadeh. All rights reserved.
//

#ifndef Event_h
#define Event_h

enum EventType {
    ARRIVAL,
    DEPARTURE
};

class Event {
    
private:
    
    EventType type;
    int time;
    int duration;
    
public:
    
    /**
     Default constructor.
     */
    Event();
    
    /**
     Parameterized constructor.
     
     @param eventType Type of the event (ARRIVAL or DEPARTURE).
     
     @param time Arrival time of this customer.
     
     @param duration Duration of this customer's transaction.
     */
    Event(EventType eventType, int time, int duration);
    
    /**
     Getter method.
     
     @returns Type of the event.
     */
    EventType getType() const;
    
    /**
     Getter method.
     
     @returns Arrival time of the customer.
     */
    int getTime() const;
    
    /**
     Getter method.
     
     @returns Transaction duration time of the customer.
     */
    int getDuration() const;
    
    /**
     Setter method.
     
     @param eventType New event type of the event.
     */
    void setType(EventType eventType);
    
    /**
     Setter method.
     
     @param time New arrival time of the customer.
     */
    void setTime(int time);
    
    /**
     Setter method.
     
     @param duration New transaction duration time of the customer.
     */
    void setDuration(int duration);
    
    /**
     Overloaded "less-then" operator.
     
     @param event Event that is compared to the other event.
     
     @param other Event to be compared to.
     
     @returns True if the arrival time is less than the other's event.
     
     @returns True if it an arrival event and the other event is a departure
     event and the arrival times are equal.
     
     @returns False otherwise.
     */
    friend bool operator<(Event &event, Event &other);
    
    /**
     Overloaded "greater-then" operator.
     
     @param event Event that is compared to the other event.
     
     @param other Event to be compared to.
     
     @returns True if the arrival time is greater than the other's event.
     
     @returns True if it an departure event and the other event is a arrival
     event and the arrival times are equal.
     
     @returns False otherwise.
     */
    friend bool operator>(Event &event, Event &other);
    
    /**
     Default destructor.
     */
    ~Event();
    
};

#endif /* Event_h */
