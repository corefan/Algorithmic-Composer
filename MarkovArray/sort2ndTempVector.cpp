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
    int tempLastElement;
    int index = 0;
    std::vector<note> B;
    
    midiProcessing::tempVector2.push_back(B);
    
    midiProcessing::tempVector2[0].push_back(midiProcessing::tempVector[0]);
    tempLastElement = midiProcessing::tempVector[0].getNumber();
    
    for(int i = 1; i < midiProcessing::tempVector.size(); i++)
    {
        midiProcessing::tempVector2.push_back(B);
        midiProcessing::tempVector2[i].push_back(midiProcessing::tempVector[i]);
        midiProcessing::tempVector2[i-1].push_back(midiProcessing::tempVector[i]);
        tempLastElement = midiProcessing::tempVector[i].getNumber();
        index++;
    }
    
    //midiProcessing::tempVector2[index].push_back(midiProcessing::tempVector[0]);
    std::sort(midiProcessing::tempVector2.begin(), midiProcessing::tempVector2.end());
    
    int tempLastElement2;
    index = 0;
    
    midiProcessing::markovList2.push_back(B);
    
    if (midiProcessing::tempVector2[0].size() == 2)
    {
        midiProcessing::markovList2[0].push_back(midiProcessing::tempVector2[0][0]);
        midiProcessing::markovList2[0].push_back(midiProcessing::tempVector2[0][1]);
    }
    else if(midiProcessing::tempVector2[0].size() == 1)
    {
        midiProcessing::markovList2[0].push_back(midiProcessing::tempVector2[0][0]);
    }
    else
    {
        printf("ERROR: 503");
    }
    
    tempLastElement = midiProcessing::tempVector2[0][0].getNumber();
    tempLastElement2 = midiProcessing::tempVector2[0][1].getNumber();
    
    for(int i = 1; i < midiProcessing::tempVector2.size(); i++)
    {
        if(tempLastElement == midiProcessing::tempVector2[i][0].getNumber() && tempLastElement2 == midiProcessing::tempVector2[i][1].getNumber())
        {
            if (midiProcessing::tempVector2[i].size() == 2)
            {
                tempLastElement = midiProcessing::tempVector2[i][0].getNumber();
                tempLastElement2 = midiProcessing::tempVector2[i][1].getNumber();
            }
            else if(midiProcessing::tempVector2[i].size() == 1)
            {
                tempLastElement = midiProcessing::tempVector2[i][0].getNumber();
                tempLastElement2 = -1;
            }
            else
            {
                printf("ERROR: 504");
            }
        }
        else if(tempLastElement != midiProcessing::tempVector2[i][0].getNumber() || tempLastElement2 != midiProcessing::tempVector2[i][1].getNumber())
        {
            if (midiProcessing::tempVector2[i].size() == 2)
            {
                midiProcessing::markovList2.push_back(B);
                midiProcessing::markovList2[index+1].push_back(midiProcessing::tempVector2[i][0]);
                midiProcessing::markovList2[index+1].push_back(midiProcessing::tempVector2[i][1]);
                index++;
                
                tempLastElement = midiProcessing::tempVector2[i][0].getNumber();
                tempLastElement2 = midiProcessing::tempVector2[i][1].getNumber();
            }
            else if(midiProcessing::tempVector2[i].size() == 1)
            {
                //midiProcessing::markovList2.push_back(B);
                //midiProcessing::markovList2[index+1].push_back(midiProcessing::tempVector2[i][0]);
                //index++;
                
                tempLastElement = midiProcessing::tempVector2[i][0].getNumber();
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