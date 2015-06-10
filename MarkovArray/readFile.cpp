//
//  readFile.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 15.01.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include "readMidi.h"

void readMidi::readFile(const char *filePath)
{
    std::vector<note> B;
    std::vector<ulong> on(128);
    MidiFile mf;
    mf.read(filePath);
    int tempOnEvent = 0;
    int count = 0;
    
    
    readMidi::tpq = mf.getTicksPerQuarterNote();
    
    for (int i = 0; i < mf.getNumTracks(); i++)
    {
        readMidi::noteData.push_back(B);
        count = 0;
        for (int j = 0; j < mf.getNumEvents(i); j++)
        {
            if(mf.getEvent(i, j).isNoteOn())
            {
                note newNote(mf.getEvent(i, j).data[1], mf.getEvent(i, j).time, mf.getEvent(i, j).data[2], 0);
                readMidi::noteData.at(i).push_back(newNote);
                on.at(mf.getEvent(i, j).data[1]) = readMidi::noteData.at(i).size()-1;
                
                if (count != 0)
                {
                    noteData.at(i).at(count).setRest((noteData.at(i).at(count).getOnTime())-(noteData.at(i).at(count-1).getOnTime()));
                    noteData.at(i).at(count-1).setRest((noteData.at(i).at(count).getOnTime())-(noteData.at(i).at(count-1).getOnTime()));
                }
                tempOnEvent = (noteData.at(i).at(count).getOnTime());
                count += 1;
            }
            else if(mf.getEvent(i, j).isNoteOff())
            {
                readMidi::noteData.at(i).at(on[mf.getEvent(i, j).data[1]]).setOffTime(mf.getEvent(i, j).time);
                readMidi::noteData.at(i).at(on[mf.getEvent(i, j).data[1]]).setDuration();
                on.at(mf.getEvent(i, j).data[1]) = 0;
            }
        }
    }
    if (noteData.at(0).size() == 0)
    {
        printf("Es konnten keine Daten gelesen werden\n");
        exit(2);
    }
    else if (noteData.at(0).size() > 0)
    {
        printf("Daten wurden erfolgreich gelesen\n");
    }
}