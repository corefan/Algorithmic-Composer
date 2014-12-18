//
//  Note.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 18.12.14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <stdio.h>
#include "Note.h"

note::note(int number, int length, int velocity)
{
    note::noteData[0] = number;
    note::noteData[1] = length;
    note::noteData[2] = velocity;
}