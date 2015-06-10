//
//  generate2ndMidiFile.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 07.02.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include "midiProcessing.h"

void midiProcessing::generate2ndMidiFile(const char *filePath, int size)
{
    srand (time(NULL));
    MidiFile outputFile;
    outputFile.absoluteTime();
    outputFile.addTrack(1);
    outputFile.setTicksPerQuarterNote(tpq);
    Array<uchar> midiEvent;
    midiEvent.setSize(3);
    int actionTime = 0;
    std::vector<note> tempLastTwoNotes{markovList2[0][0], markovList2[0][1]};
    std::vector<note> tempNote;
    int tempVectorIndex = 0;
    int tempIndex;
    
    for (int i = 0; i < size; i++)
    {
        tempIndex = (rand() % (markovList2.at(tempVectorIndex).size()-2))+2;
        tempLastTwoNotes[0] = markovList2.at(tempVectorIndex).at(1);
        tempLastTwoNotes[1] = markovList2.at(tempVectorIndex).at(tempIndex);
        
        tempNote = markovList2.at(tempVectorIndex);
        
        for (int j = 0; j < markovList2.size(); j++)
        {
            if (tempLastTwoNotes[0].getNumber() == markovList2.at(j).at(0).getNumber() && tempLastTwoNotes[1].getNumber() == markovList2.at(j).at(1).getNumber())
            {
                tempVectorIndex = j;
                break;
            }
        }
        midiEvent[0] = 0x90;
        midiEvent[1] = tempLastTwoNotes[1].getNumber();
        midiEvent[2] = tempLastTwoNotes[1].getVelocity();
        outputFile.addEvent(1, actionTime, midiEvent);
        
        actionTime += tempLastTwoNotes[1].getRest();
        midiEvent[0] = 0x80;
        outputFile.addEvent(1, tempNote.at(tempIndex).getDuration()+actionTime, midiEvent);
        
    }
    outputFile.sortTracks();
    outputFile.write(filePath);
}