//
//  printTrack.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include "midiProcessing.h"

void midiProcessing::printTrack()
{
    for(int i = 0; i < midiProcessing::noteData.size(); i++)
    {
        printf("%d ", midiProcessing::noteData[i].getNumber());
    }
    printf("\n\n");
}