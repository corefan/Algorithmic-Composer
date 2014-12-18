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
    std::vector<int> B;
    
    midiProcessing::markovList.push_back(B);
    midiProcessing::markovList[0].push_back(midiProcessing::tempVector[0]);
    tempLastElement = midiProcessing::tempVector[0];
    
    for(int i = 0; i <= midiProcessing::tempVector.size(); i++)
    {
        if(tempLastElement != midiProcessing::tempVector[i])
        {
            midiProcessing::markovList.push_back(B);
            midiProcessing::markovList[index].push_back(midiProcessing::tempVector[i]);
            index++;
            tempLastElement = midiProcessing::tempVector[i];
        }
        else if(tempLastElement == midiProcessing::tempVector[i])
        {
            tempLastElement = midiProcessing::tempVector[i];
        }
        else
        {
            printf("ERROR: 505");
        }
    }
}