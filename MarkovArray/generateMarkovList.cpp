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
    sortTempVector();
    for(int i = 0; i < midiProcessing::noteData.size()-1; i++)
    {
        for(int j = 0; j < midiProcessing::markovList.size(); j++)
        {
            if(midiProcessing::noteData[i].getNumber() == midiProcessing::markovList[j][0].getNumber())
            {
                midiProcessing::markovList[j].push_back(midiProcessing::noteData[i+1]);
                break;
            }
        }
    }
}