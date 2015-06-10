//
//  Note.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 18.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include "Note.h"

note::note(int number, int onTime, int velocity, int offTime)
{
    note::noteData[0] = number;
    note::key = number;
    note::noteData[1] = onTime;
    note::noteData[2] = velocity;
    note::noteData[3] = offTime;
    note::noteData[4] = offTime-onTime;
}

