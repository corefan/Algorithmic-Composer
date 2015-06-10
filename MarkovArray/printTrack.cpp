//
//  printTrack.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include "midiProcessing.h"

void midiProcessing::printTrack()
{
    for(int i = 0; i < midiProcessing::noteData.size(); i++)
    {
        printf("%d %d %d %d\n", midiProcessing::noteData.at(i).getNumber(), midiProcessing::noteData.at(i).getVelocity(), midiProcessing::noteData.at(i).getOnTime(), midiProcessing::noteData.at(i).getOffTime());
    }
    printf("\n\n");
}