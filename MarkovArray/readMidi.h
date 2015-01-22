//
//  readMidi.h
//  MarkovArray
//
//  Created by Lukas Nowok on 02.01.15.
//  Copyright (c) 2015 hw. All rights reserved.
//
/*
 MidiDaten in zweidimensionalem Vector
 [noteNumber......]
 [velocity........]
 [length..........]
 */

#ifndef MarkovArray_readMidi_h
#define MarkovArray_readMidi_h

//#include <vector>
#include "MidiFile.h"
#include "note.h"

#endif

class readMidi
{
private:
    std::vector< std::vector<note> > noteData;
    
public:
    readMidi();
    void readFile(const char *filePath);
    std::vector< std::vector<note> > getMidiData();
};