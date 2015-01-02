//
//  setNote.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 11.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
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

void note::setLength(int length)
{
    note::noteData[1] = length;
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

void note::setNote(int number, int length, int velocity)
{
    note::noteData[0] = number;
    note::noteData[1] = length;
    note::noteData[2] = velocity;
}