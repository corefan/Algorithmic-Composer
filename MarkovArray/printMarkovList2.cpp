//
//  printMarkovList2.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 22.01.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include <stdio.h>
#include "midiProcessing.h"

void midiProcessing::printMarkovList2()
{
    for(int i = 0; i < midiProcessing::markovList2.size(); i++)
    {
        for(int j = 0; j < midiProcessing::markovList2[i].size(); j++)
        {
            printf("%d ", midiProcessing::markovList2[i][j].getNumber());
        }
        printf("\n");
    }
    printf("\n");
}