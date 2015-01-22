//
//  sortTempVector.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include "midiProcessing.h"

void midiProcessing::sortTempVector()
{
    int tempLastElement;
    int index = 0;
    std::vector<note> B;
    std::sort(midiProcessing::tempVector.begin(), midiProcessing::tempVector.end());
    
    midiProcessing::markovList.push_back(B);
    
    midiProcessing::markovList[0].push_back(midiProcessing::tempVector[0]);
    tempLastElement = midiProcessing::tempVector[0].getNumber();
    
    for(int i = 1; i < midiProcessing::tempVector.size(); i++)
    {
        if(tempLastElement != midiProcessing::tempVector[i].getNumber())
        {
            midiProcessing::markovList.push_back(B);
            midiProcessing::markovList[index+1].push_back(midiProcessing::tempVector[i]);
            index++;
            tempLastElement = midiProcessing::tempVector[i].getNumber();
        }
        else if(tempLastElement == midiProcessing::tempVector[i].getNumber())
        {
            tempLastElement = midiProcessing::tempVector[i].getNumber();
        }
        else
        {
            printf("ERROR: 404");
        }
    }
}