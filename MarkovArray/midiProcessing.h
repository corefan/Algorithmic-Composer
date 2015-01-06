//
//  midiProcessing.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "Note.h"
#include "readMidi.h"

class midiProcessing
{
private:
    std::vector<int> trackData{1, 5, 3, 4};
    std::vector< std::vector<int> > markovList;
    std::vector<int> tempVector;
    std::vector<note> noteData;
    
public:
    midiProcessing();
    void printTrack();
    void sortTempVector();
    void sort2ndTempVector();
    void printMarkovList();
    void generateMarkovList();
    void generate2ndMarkovList();
    void passNoteData();
};