#pragma once

#include <windows.h>
#include <string>

class Konsole
{
private:
    HANDLE output;
    HANDLE input;
    INPUT_RECORD inputRecord;
    DWORD events;
    COORD coord;
    int k;
    bool listening;
    void process();
    int lastKeyPress;
public:
    const int KEY_ESC = 27;

    Konsole();
    ~Konsole();
    void setAttribute(int attribute);
    void print(std::string text);
    void println(std::string text);
    void resetAttribute();
    void startListening();
    void stopListening();
    int getLastKeyPress();
    int getLastLMousePressX();
    int getLastLMousePressY();
};