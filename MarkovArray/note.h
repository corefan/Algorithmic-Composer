//
//  Note.h
//  MarkovArray
//
//  Created by Jonas Schüle on 11.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#ifndef MarkovArray_Note_h
#define MarkovArray_Note_h

#include <vector>

#endif

class note
{
private:
    ///notenumber, ontime, velocity, offtime, duration, rest////
    std::vector<int> noteData{0, 0, 0, 0, 0, 0};
    int key;
    
public:
    note();
    note(int number, int onTime, int velocity, int offTime);
    
    void setNumber(int number);
    void setOnTime(int onTime);
    void setOffTime(int offTime);
    void setVelocity(int velocity);
    void setNote(int number, int duration, int velocity);
    void setDuration();
    void setRest(int on);
    
    int getNumber();
    int getOnTime();
    int getVelocity();
    int getOffTime();
    int getDuration();
    int getRest();
    
    std::vector<int> getNote();
    
    note(int k) : key(k){}
    
    bool operator < (const note& str) const
    
    {
        return (key < str.key);
    }
};