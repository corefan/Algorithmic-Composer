//
//  Note.h
//  MarkovArray
//
//  Created by Lukas Nowok on 11.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#ifndef MarkovArray_Note_h
#define MarkovArray_Note_h

#include <vector>

#endif

class note
{
private:
    std::vector<int> noteData{0, 0, 0};
    
public:
    note();
    note(int number, int length, int velocity);
    
    int key;
    
    void setNumber(int number);
    void setLength(int length);
    void setVelocity(int velocity);
    void setNote(int number, int length, int velocity);
    
    int getNumber();
    int getLength();
    int getVelocity();
    
    std::vector<int> getNote();
    
    
    note(int k) : key(k){}
        
    bool operator < (const note& str) const
    {
        return (key < str.key);
    }
    
};