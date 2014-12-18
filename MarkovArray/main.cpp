//
//  main.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <iostream>
#include "midiProcessing.h"

///adfoherjdjdjdjdjdjieieiejfiernagh///

int main() {
    midiProcessing mp;
    mp.printTrack();
    mp.sortTempVector();
    mp.generateMarkovList();
    mp.printMarkovList();
};