//
//  midiProcessing.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include "midiProcessing.h"

midiProcessing::midiProcessing()
{
    midiProcessing::tempVector = midiProcessing::trackData;
    std::sort(midiProcessing::tempVector.begin(), midiProcessing::tempVector.end());
}