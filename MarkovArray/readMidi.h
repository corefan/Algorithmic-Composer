//
//  readMidi.h
//  MarkovArray
//
//  Created by Lukas Nowok on 02.01.15.
//  Copyright (c) 2015 hw. All rights reserved.
//
/*MidiDaten in zweidimensionalem Vector
 [noteNumber......]
 [velocity........]
 [length..........]
 
 !Test Class!
 
 */

#ifndef MarkovArray_readMidi_h
#define MarkovArray_readMidi_h

# include <vector>

#endif

class readMidi
{
private:
    std::vector< std::vector<int> > midiData;
public:
    void readFile();
    std::vector< std::vector<int> > getMidiData();
};