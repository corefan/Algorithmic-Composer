//
//  generate2ndMarkovList.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 11.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include "midiProcessing.h"

void midiProcessing::generate2ndMarkovList()
{
    sort2ndTempVector();
    
    for(int i = 0; i < midiProcessing::noteData.size()-2; i++)
    {
        for(int j = 0; j < midiProcessing::markovList2.size(); j++)
        {
            if(midiProcessing::noteData[i].getNumber() == midiProcessing::markovList2[j][0].getNumber() && midiProcessing::noteData[i+1].getNumber() == midiProcessing::markovList2[j][1].getNumber())
            {
                midiProcessing::markovList2[j].push_back(midiProcessing::noteData[i+2]);
                break;
            }
        }
    }
}