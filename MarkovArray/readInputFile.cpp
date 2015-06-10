//
//  readInputFile.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 02.01.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include "midiProcessing.h"

void midiProcessing::readInputFile(const char *filePath)
{
    int track = 0;
    readMidi rm;
    rm.readFile(filePath);
    rm.getMidiData(midiProcessing::noteData, track);
    rm.getMidiData(midiProcessing::tempVector, track);
    tpq = rm.getTPQ();
}