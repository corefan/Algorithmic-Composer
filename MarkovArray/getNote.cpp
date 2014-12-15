//
//  getNote.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 11.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include "Note.h"

int Note::getNumber()
{
    return Note::NoteData[0];
}

int Note::getLength()
{
    return Note::NoteData[0];
}

int Note::getVelocity()
{
    return Note::NoteData[0];
}

std::vector<int> Note::getNote()
{
    return Note::NoteData;
}