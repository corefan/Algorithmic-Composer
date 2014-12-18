//
//  generateMarkovList.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include "midiProcessing.h"

void midiProcessing::generateMarkovList()
{
    for(int i = 0; i < midiProcessing::trackData.size()-1; i++)
    {
        for(int j = 0; j < midiProcessing::markovList.size()-1; j++)
        {
            if(midiProcessing::trackData[i] == midiProcessing::markovList[j][0])
            {
                midiProcessing::markovList[j].push_back(midiProcessing::trackData[i+1]);
                break;
            }
        }
    }
}