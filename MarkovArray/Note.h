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
public:
    note(int number, int length, int velocity);
private:
    std::vector<int> noteData{0, 0, 0};
    void setNumber(int number);
    void setLength(int length);
    void setVelocity(int velocity);
    void setNote(int number, int length, int velocity);
    
    int getNumber();
    int getLength();
    int getVelocity();
    std::vector<int> getNote();
};