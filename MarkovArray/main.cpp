//
//  main.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <iostream>
#include "midiProcessing.h"
//#include "readMidi.h"

int main()
{
    const char *afile = "/Users/Lukas/Documents/MD/5.Semester/Medienprogrammierung/test.mid";
    readMidi rm;
    
    
    midiProcessing mp;
    mp.printTrack();
    mp.generateMarkovList();
    mp.printMarkovList();
    
    midiProcessing mps;
    mps.generate2ndMarkovList();
    mps.printMarkovList2();
    
};