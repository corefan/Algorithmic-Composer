//
//  getMidiData.cpp
//  MarkovArray
//
//  Created by Lukas Nowok on 02.01.15.
//  Copyright (c) 2015 hw. All rights reserved.
//

#include "readMidi.h"

std::vector< std::vector<int> > readMidi::getMidiData()
{
    std::vector<int> temp{1, 2, 3, 4, 3, 2, 1};
    std::vector<int> temp2;
    std::vector< std::vector<int> > data;

    data.push_back(temp2);
    data.push_back(temp2);
    data.push_back(temp2);
    
    for (int i = 0; i < temp.size(); i++)
    {
        data[0].push_back(temp[i]);
        data[1].push_back(0);
        data[2].push_back(0);
    }
    
    
    return data;
}