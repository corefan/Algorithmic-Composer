//
//  midiProcessing.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include <vector>

class midiProcessing
{
private:
    std::vector<int> trackData{1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector< std::vector<int> > markovList;
    std::vector<int> tempVector;
public:
    midiProcessing();
    void generateList();
    void printTrack();
    void sortTempVector();
    void printMarkovList();
    void generateMarkovList();
    void generate2ndMarkovList();
};