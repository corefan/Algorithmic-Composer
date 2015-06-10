//
//  printMarkovList.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include "midiProcessing.h"

void midiProcessing::printMarkovList()
{
    for(int i = 0; i < midiProcessing::markovList.size(); i++)
    {
        for(int j = 0; j < midiProcessing::markovList.at(i).size(); j++)
        {
            printf("%d ", midiProcessing::markovList.at(i).at(j).getNumber());
        }
        printf("\n");
    }
    printf("\n");
}