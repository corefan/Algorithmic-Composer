//
//  generate2ndMarkovList.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 11.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include "midiProcessing.h"

void midiProcessing::generate2ndMarkovList()
{
    
    if (midiProcessing::noteData.size() > 0)
    {
        sort2ndTempVector();
        for(int i = 0; i < midiProcessing::noteData.size()-2; i++)
        {
            for(int j = 0; j < midiProcessing::markovList2.size(); j++)
            {
                if(midiProcessing::noteData.at(i).getNumber() == midiProcessing::markovList2.at(j).at(0).getNumber() && midiProcessing::noteData.at(i+1).getNumber() == midiProcessing::markovList2.at(j).at(1).getNumber())
                {
                    midiProcessing::markovList2.at(j).push_back(midiProcessing::noteData.at(i+2));
                }
            }
        }
        
        for(int i = 0; i < midiProcessing::noteData.size(); i++)
        {
            for(int j = 0; j < midiProcessing::markovList2.size(); j++)
            {
                if(midiProcessing::markovList2.at(j).size() == 2)
                {
                    midiProcessing::markovList2.at(j).push_back(midiProcessing::noteData.at(0));
                }
            }
        }
    }
}