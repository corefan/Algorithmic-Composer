//
//  generateMidiFile.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 29.01.15.
//  Copyright (c) 2015 hw. All rights reserved.
//


#include "midiProcessing.h"

void midiProcessing::generateMidiFile(const char *filePath, int size)
{
    srand (time(NULL));
    MidiFile outputFile;
    outputFile.absoluteTime();
    outputFile.addTrack(1);
    outputFile.setTicksPerQuarterNote(tpq);
    Array<uchar> midiEvent;
    midiEvent.setSize(3);
    int actionTime = 0;
    int tempVectorIndex = 0;
    std::vector<note> tempNote;
    int tempIndex;
    
    for (int i = 0; i < size; i++)
    {
        tempNote = midiProcessing::markovList.at(tempVectorIndex);
        tempIndex = (rand() % (midiProcessing::markovList.at(tempVectorIndex).size()-1)) + 1;
        midiEvent[0] = 0x90;
        midiEvent[1] = tempNote.at(tempIndex).getNumber();
        midiEvent[2] = tempNote.at(tempIndex).getVelocity();
        outputFile.addEvent(1, actionTime, midiEvent);
        midiEvent[0] = 0x80;
        outputFile.addEvent(1, (tempNote.at(tempIndex).getDuration())+actionTime, midiEvent);
        
        actionTime += tempNote.at(tempIndex).getRest();
        
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