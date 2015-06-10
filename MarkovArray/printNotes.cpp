//
//  printNotes.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 25.01.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include "readMidi.h"

void readMidi::printNotes(int track)
{
    for(int i = 0; i < readMidi::noteData.at(track).size(); i++)
    {
        printf("Number %d, Velocity %d, OnTime %d, OffTime %d\n", noteData.at(track).at(i).getNumber(), noteData.at(track).at(i).getVelocity(), noteData.at(track).at(i).getOnTime(), noteData.at(track).at(i).getOffTime());
    }
}
