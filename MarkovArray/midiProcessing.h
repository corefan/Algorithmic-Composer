//
//  midiProcessing.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include "readMidi.h"

class midiProcessing
{
private:
    std::vector< std::vector<note> > markovList;
    std::vector< std::vector<note> > markovList2;
    std::vector< std::vector<note> > tempVector2;
    std::vector<note> tempVector;
    std::vector<note> noteData;
    int tpq;
    
public:
    void printTrack();
    void sortTempVector();
    void sort2ndTempVector();
    void printMarkovList();
    void printMarkovList2();
    void generateMarkovList();
    void generate2ndMarkovList();
    void readInputFile(const char *filePath);
    void generateMidiFile(const char *filePath, int size);
    void generateMidiFileOriginalRhythm(const char *filePath, int size);
    void generate2ndMidiFile(const char *filePath, int size);
    void generate2ndMidiFileOriginalRhythm(const char *filePath, int size);
};