//
//  readMidi.h
//  MarkovArray
//
//  Created by Jonas Schüle on 02.01.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#ifndef MarkovArray_readMidi_h
#define MarkovArray_readMidi_h

#include <stdio.h>
#include "MidiFile.h"
#include "note.h"

#endif

class readMidi
{
private:
    std::vector< std::vector<note> > noteData;
    int tpq;
    
public:
    void readFile(const char *filePath);
    void getMidiData(std::vector<note> &noteVector, int track);
    void printNotes(int track);
    int getTPQ();
};