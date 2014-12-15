//
//  setNote.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 11.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include "Note.h"

void Note::setNumber(int number)
{
    if(number >= 0 && number < 128)
    {
        Note::NoteData[0] = number;
    }
    else
    {
        printf("ERROR: Number out of Range");
    }
}

void Note::setLength(int length)
{
    Note::NoteData[1] = length;
}

void Note::setVelocity(int velocity)
{
    if(velocity >= 0 && velocity < 128)
    {
        Note::NoteData[2] = velocity;
    }
    else
    {
        printf("ERROR: Velocity out of Range");
    }
}

void Note::setNote(int number, int length, int velocity)
{
    Note::NoteData[0] = number;
    Note::NoteData[1] = length;
    Note::NoteData[2] = velocity;
}