//
//  getNote.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 11.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include "Note.h"

int note::getNumber()
{
    return note::noteData[0];
}

int note::getLength()
{
    return note::noteData[0];
}

int note::getVelocity()
{
    return note::noteData[0];
}

std::vector<int> note::getNote()
{
    return note::noteData;
}