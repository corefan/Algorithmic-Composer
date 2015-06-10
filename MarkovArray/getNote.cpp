//
//  getNote.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 11.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include "Note.h"

int note::getNumber()
{
    return note::noteData[0];
}

int note::getOnTime()
{
    return note::noteData[1];
}

int note::getVelocity()
{
    return note::noteData[2];
}

int note::getOffTime()
{
    return note::noteData[3];
}

int note::getDuration()
{
    return note::noteData[4];
}

int note::getRest()
{
    return note::noteData[5];
}

std::vector<int> note::getNote()
{
    return note::noteData;
}