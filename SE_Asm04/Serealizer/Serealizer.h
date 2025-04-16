#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Serializer {
private:
    ofstream file;
    const unsigned char textMarker = 0x01;
    const unsigned char intMarker = 0x02;
    const unsigned char maxTextLength = 127;
    string Text;
    int Integer;

public:
    Serializer(const string& text, int integer) {
        if (text.size() > maxTextLength) {
            throw invalid_argument("Text length exceeds 127 characters.");
        }
        this->Text = text;
        this->Integer = integer;
    }

    void SerializeData();
};
