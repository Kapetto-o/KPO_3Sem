#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "AsmTemplate.h"

using namespace std;

class Deserializer {
private:
    ifstream file;
    ofstream fileAsm;
    const unsigned char textMarker = 0x01;
    const unsigned char intMarker = 0x02;
    string Text;
    int Integer = 0;

public:
    void DeserializeData();
    void ConvertToAssembler();
};
