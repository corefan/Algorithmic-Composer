//
//  generateMarkovList.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include "midiProcessing.h"

void midiProcessing::generateMarkovList()
{
    if (midiProcessing::noteData.size() > 0)
    {
        sortTempVector();
        for(int i = 0; i < midiProcessing::noteData.size()-1; i++)
        {
            for(int j = 0; j < midiProcessing::markovList.size(); j++)
            {
                if(midiProcessing::noteData.at(i).getNumber() == midiProcessing::markovList.at(j).at(0).getNumber())
                {
                    midiProcessing::markovList.at(j).push_back(midiProcessing::noteData.at(i+1));
                }
            }
        }
        for(int i = 0; i < midiProcessing::noteData.size(); i++)
        {
            for(int j = 0; j < midiProcessing::markovList.size(); j++)
            {
                if(midiProcessing::markovList.at(j).size() == 1)
                {
                    midiProcessing::markovList.at(j).push_back(midiProcessing::noteData.at(0));
                }
            }
        }
    }
}