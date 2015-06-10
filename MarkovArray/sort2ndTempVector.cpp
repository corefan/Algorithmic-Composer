//
//  sort2ndTempVector.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 18.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include "midiProcessing.h"

void midiProcessing::sort2ndTempVector()
{
    int tempLastElement;
    int index = 0;
    std::vector<note> B;
    
    midiProcessing::tempVector2.push_back(B);
    
    midiProcessing::tempVector2.at(0).push_back(midiProcessing::tempVector.at(0));
    tempLastElement = midiProcessing::tempVector.at(0).getNumber();
    
    for(int i = 1; i < midiProcessing::tempVector.size(); i++)
    {
        midiProcessing::tempVector2.push_back(B);
        midiProcessing::tempVector2.at(i).push_back(midiProcessing::tempVector.at(i));
        midiProcessing::tempVector2.at(i-1).push_back(midiProcessing::tempVector.at(i));
        tempLastElement = midiProcessing::tempVector.at(i).getNumber();
        index++;
    }
    
    std::sort(midiProcessing::tempVector2.begin(), midiProcessing::tempVector2.end());
    
    tempLastElement = -1;
    int tempLastElement2 = -1;
    index = 0;
    
    for(int i = 0; i < midiProcessing::tempVector2.size(); i++)
    {
        if(tempLastElement == midiProcessing::tempVector2.at(i).at(0).getNumber() && tempLastElement2 == midiProcessing::tempVector2.at(i).at(1).getNumber())
        {
            if (midiProcessing::tempVector2.at(i).size() == 2)
            {
                tempLastElement = midiProcessing::tempVector2.at(i).at(0).getNumber();
                tempLastElement2 = midiProcessing::tempVector2.at(i).at(1).getNumber();
            }
            else if(midiProcessing::tempVector2.at(i).size() == 1)
            {
                tempLastElement = midiProcessing::tempVector2.at(i).at(0).getNumber();
                tempLastElement2 = -1;
            }
            else
            {
                printf("ERROR: 504");
            }
        }
        else if(tempLastElement != midiProcessing::tempVector2.at(i).at(0).getNumber() || tempLastElement2 != midiProcessing::tempVector2.at(i).at(1).getNumber())
        {
            if (midiProcessing::tempVector2.at(i).size() == 2)
            {
                midiProcessing::markovList2.push_back(B);
                midiProcessing::markovList2[index].push_back(midiProcessing::tempVector2.at(i).at(0));
                midiProcessing::markovList2[index].push_back(midiProcessing::tempVector2.at(i).at(1));
                index++;
                
                tempLastElement = midiProcessing::tempVector2.at(i).at(0).getNumber();
                tempLastElement2 = midiProcessing::tempVector2.at(i).at(1).getNumber();
            }
            else if(midiProcessing::tempVector2.at(i).size() == 1)
            {
                tempLastElement = midiProcessing::tempVector2.at(i).at(0).getNumber();
                tempLastElement2 = -1;
            }
            else
            {
                printf("ERROR: 505");
            }
        }
        else
        {
            printf("ERROR: 502");
        }
    }
}