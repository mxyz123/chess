#pragma once

#include <windows.h>
#include <string>
#include <functional>

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
    std::function<void()> keyEventFunction;
    std::function<void()> mouseEventFunction;
public:
    enum KEY_CODE {KEY_ESC = 27};

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
    void setKeyEventFunction(std::function<void()>  fn);
    void setMouseEventFunction(std::function<void()>  fn);
};