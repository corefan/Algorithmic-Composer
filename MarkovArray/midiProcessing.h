//
//  midiProcessing.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
//#include <vector>
//#include "note.h"
#include "readMidi.h"

class midiProcessing
{
private:
    std::vector<int> trackData{9, 6, 6, 3, 4, 13, 8, 2, 3, 11, 4, 1, 0, 2, 3, 4, 5, 6, 5, 3, 4, 2, 6, 9};
    std::vector< std::vector<note> > markovList;
    std::vector< std::vector<note> > markovList2;
    std::vector< std::vector<note> > tempVector2;
    std::vector<note> tempVector;
    std::vector<note> noteData;
    
public:
    midiProcessing();
    void printTrack();
    void sortTempVector();
    void sort2ndTempVector();
    void printMarkovList();
    void printMarkovList2();
    void generateMarkovList();
    void generate2ndMarkovList();
    void passNoteData();
};