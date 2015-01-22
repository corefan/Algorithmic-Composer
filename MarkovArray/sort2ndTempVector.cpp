//
//  sort2ndTempVector.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 18.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include "midiProcessing.h"

void midiProcessing::sort2ndTempVector()
{
    int tempLastElement = 0;
    int index = 1;
    std::vector<note> B;
    
    std::sort(midiProcessing::tempVector.begin(), midiProcessing::tempVector.end());
    
    midiProcessing::markovList.push_back(B);
    
    midiProcessing::markovList[0].push_back(midiProcessing::tempVector[0]);
    tempLastElement = midiProcessing::noteData[0].getNumber();
    
    for(int i = 0; i < midiProcessing::tempVector.size(); i++)
    {
        if(tempLastElement != midiProcessing::tempVector[i].getNumber())
        {
            midiProcessing::markovList.push_back(B);
            midiProcessing::markovList[index].push_back(midiProcessing::tempVector[i]);
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