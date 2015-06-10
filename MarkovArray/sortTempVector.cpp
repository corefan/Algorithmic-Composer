//
//  sortTempVector.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include "midiProcessing.h"

void midiProcessing::sortTempVector()
{
    int tempLastElement = -1;
    int index = 0;
    std::vector<note> B;
    std::sort(midiProcessing::tempVector.begin(), midiProcessing::tempVector.end());
    
    for(int i = 0; i < midiProcessing::tempVector.size(); i++)
    {
        if(tempLastElement != midiProcessing::tempVector.at(i).getNumber())
        {
            midiProcessing::markovList.push_back(B);
            midiProcessing::markovList[index].push_back(midiProcessing::tempVector[i]);
            index++;
            tempLastElement = midiProcessing::tempVector.at(i).getNumber();
        }
        else if(tempLastElement == midiProcessing::tempVector.at(i).getNumber())
        {
            tempLastElement = midiProcessing::tempVector.at(i).getNumber();
        }
        else
        {
            printf("ERROR: 404");
        }
    }
}