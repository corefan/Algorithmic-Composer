//
//  parseNoteData.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 02.01.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include <stdio.h>
#include "midiProcessing.h"

void midiProcessing::passNoteData()
{
    for (int i = 0; i < midiProcessing::trackData.size(); i++)
    {
        note newNote(midiProcessing::trackData[i], 0, 0);
        midiProcessing::noteData.push_back(newNote);
        midiProcessing::tempVector.push_back(newNote);
    }
}