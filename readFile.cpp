//
//  readFile.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 15.01.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include <stdio.h>
#include "readMidi.h"

void readMidi::readFile(const char *filePath)
{
    std::vector<note> B;
    MidiFile mf;
    mf.read(filePath);
    
    printf("Reading Succeeded\nFilename: %s \nNumTracks: %d \nNumEvents: %d \n", mf.getFilename(), mf.getNumTracks(), mf.getNumEvents(0));
    
    //(erster Track und) ersten vier Events sind Midiheader?! = Loop vom zweiten zum letzten Track und vom fünften zum vorletzten Event//
    for (int i = 0; i < mf.getNumTracks(); i++)
    {
        readMidi::noteData.push_back(B);
        for (int j = 3; j < mf.getNumEvents(i)-1; j++)
        {
            note newNote(mf.getEvent(i, j).data[1], 10, mf.getEvent(i, j).data[2]);
            readMidi::noteData[i].push_back(newNote);
        }
    }
}