//
//  setNote.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 11.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include "Note.h"

void note::setNumber(int number)
{
    if(number >= 0 && number < 128)
    {
        note::noteData[0] = number;
    }
    else
    {
        printf("ERROR: Notenumber out of Range");
    }
}

void note::setOnTime(int onTime)
{
    note::noteData[1] = onTime;
}

void note::setVelocity(int velocity)
{
    if(velocity >= 0 && velocity < 128)
    {
        note::noteData[2] = velocity;
    }
    else
    {
        printf("ERROR: Velocity out of Range");
    }
}

void note::setOffTime(int offTime)
{
    note::noteData[3] = offTime;
}

void note::setDuration()
{
    note::noteData[4] = noteData.at(3)-noteData.at(1);
}

void note::setRest(int on)
{
    note::noteData[5] = on;
}

void note::setNote(int number, int duration, int velocity)
{
    note::noteData[0] = number;
    note::noteData[1] = duration;
    note::noteData[2] = velocity;
}