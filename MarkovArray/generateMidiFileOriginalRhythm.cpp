//
//  generateMidiFileOriginalRhythm.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 07.02.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include "midiProcessing.h"

void midiProcessing::generateMidiFileOriginalRhythm(const char *filePath, int size)
{
    srand (time(NULL));
    MidiFile outputFile;
    outputFile.absoluteTime();
    outputFile.addTrack(1);
    outputFile.setTicksPerQuarterNote(tpq);
    Array<uchar> midiEvent;
    midiEvent.setSize(3);
    int tempVectorIndex = 0;
    int maxTime = midiProcessing::noteData.at(midiProcessing::noteData.size()-1).getOffTime();
    std::vector<note> tempNote;
    int tempIndex;
    int round;
    
    for (int i = 0; i < size; i++)
    {
        round = static_cast<int>(i/midiProcessing::noteData.size());
        tempNote = midiProcessing::markovList.at(tempVectorIndex);
        tempIndex = (rand() % (midiProcessing::markovList.at(tempVectorIndex).size()-1)) + 1;
        midiEvent[0] = 0x90;
        midiEvent[1] = tempNote.at(tempIndex).getNumber();
        midiEvent[2] = midiProcessing::noteData.at(i%midiProcessing::noteData.size()).getVelocity();
        outputFile.addEvent(1, (midiProcessing::noteData.at(i%midiProcessing::noteData.size()).getOnTime())+(maxTime*(round)), midiEvent);
        midiEvent[0] = 0x80;
        outputFile.addEvent(1, (midiProcessing::noteData.at(i%midiProcessing::noteData.size()).getOffTime())+(maxTime*(round)), midiEvent);
        
        for (int j = 0; j < midiProcessing::markovList.size(); j++)
        {
            if (midiProcessing::markovList.at(j).at(0).getNumber() == tempNote.at(tempIndex).getNumber())
            {
                tempVectorIndex = j;
                break;
            }
        }
    }
    outputFile.sortTracks();
    outputFile.write(filePath);
}