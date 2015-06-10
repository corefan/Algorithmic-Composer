//
//  main.cpp
//  MarkovArray
//
//  Created by Jonas Schüle on 09/12/14.
//  Copyright (c) 2014 hw. All rights reserved.
//

#include <iostream>
#include <string>
#include "midiProcessing.h"
#include <unistd.h>


int main()
{
    std::string inputFile;
    std::string outputFile;
    std::string desktopPath = "/Desktop/";
    std::string username = getlogin();
    std::string orgRhy;
    int size;
    int order = 0;
    bool b = false;
    midiProcessing mp;
    
    printf("Willkomen zum Algorithmic Composer!\n\n");
    printf("Gib den Pfad zu einer MIDI-Datei an (Drag & Drop):\n");
    
    std::cin >> inputFile;
    const char *c = inputFile.c_str();
    
    mp.readInputFile(c);
    
    while (b == false)
    {
        
        printf("Gib an: 1 (Markov-Kette 1. Ordnung) oder 2 (2. Ordnung):\n");
        std::cin >> order;
        
        if (order == 1)
        {
            mp.generateMarkovList();
            b = true;
        }
        else if (order == 2)
        {
            mp.generate2ndMarkovList();
            b = true;
        }
        else
        {
            printf("Eingabe fehlerhaft\n");
            exit(1);
        }
    }
    
    printf("Dateiname angeben:\n");
    std::cin >> outputFile;
    
    outputFile = "/Users/"+username+desktopPath+outputFile+".mid";
    const char *d = outputFile.c_str();
    
    printf("Anzahl der Noten angeben (1-50000):\n");
    
    std::cin >> size;
    
    if (size < 0 || size > 50000)
    {
        printf("Außerhalb des zulässigen Bereichs\n");
        exit(2);
    }
    
    printf("Originalen Rhythmus verwenden? (Ja/Nein)\n");
    
    std::cin >> orgRhy;
    
    if (orgRhy == "Nein" || orgRhy == "nein" || orgRhy == "n" || orgRhy == "no")
    {
        if (order == 1)
        {
            printf("lädt....\n");
            mp.generateMidiFile(d, size);
        }
        else if (order == 2)
        {
            printf("lädt....\n");
            mp.generate2ndMidiFile(d, size);
        }
        else
        {
            printf("Bitte geben Sie Ja oder Nein ein\n");
            exit(3);
        }
    }
    else if (orgRhy == "Ja" || orgRhy == "ja" || orgRhy == "j" || orgRhy == "yes" || orgRhy == "Yes" || orgRhy == "y")
    {
        if (order == 1)
        {
            printf("lädt....\n");
            mp.generateMidiFileOriginalRhythm(d, size);
        }
        else if (order == 2)
        {
            printf("lädt....\n");
            mp.generate2ndMidiFileOriginalRhythm(d, size);
        }
        else
        {
            printf("Bitte geben Sie Ja oder Nein ein\n");
            exit(4);
        }
    }
    else
    {
        printf("Eingabe fehlerhaft\n");
        exit(5);
    }
    
    printf("\nIhre MIDI-Datei wurde erfolgreich erstellt :)\n");
    std::cout << "Pfad: " << outputFile << std::endl;
    printf("\n");
    
}