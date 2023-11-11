#include "konsole.h"
#include <iostream>
#include <thread>

Konsole::Konsole()
{
    this->output = GetStdHandle(STD_OUTPUT_HANDLE);
    this->input = GetStdHandle(STD_INPUT_HANDLE);
    this->resetAttribute();
    this->listening = false;
    SetConsoleMode(this->input, ENABLE_EXTENDED_FLAGS | ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
}

Konsole::~Konsole()
{
}

void Konsole::setAttribute(int attribute)
{
    this->k = attribute;
}

void Konsole::process()
{
    while(this->listening)
    {
        ReadConsoleInput(this->input, &this->inputRecord, 1, &this->events);

        switch (this->inputRecord.EventType)
        {
        case KEY_EVENT:
            this->lastKeyPress = this->inputRecord.Event.KeyEvent.wVirtualKeyCode;
            std::cout << "Key:" << this->lastKeyPress << std::endl;
            break;
        case MOUSE_EVENT:
            if(this->inputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                this->coord.X = inputRecord.Event.MouseEvent.dwMousePosition.X;
                this->coord.Y = inputRecord.Event.MouseEvent.dwMousePosition.Y;
                std::cout << "Mouse L press x:" << this->coord.X << " y:" << this->coord.Y << std::endl;
            }
            break;
        default:
            break;
        }
        FlushConsoleInputBuffer(this->input);
    }
}

void Konsole::resetAttribute()
{
    this->k = 7;
    SetConsoleTextAttribute(this->output, this->k);
}

void Konsole::startListening()
{
    this->listening = true;
    std::thread t(&Konsole::process, this);
    t.detach();
}

int Konsole::getLastKeyPress()
{
    return this->lastKeyPress;
}

int Konsole::getLastLMousePressX()
{
    return this->coord.X;
}

int Konsole::getLastLMousePressY()
{
    return this->coord.Y;
}

void Konsole::stopListening()
{
    this->listening = false;
}

void Konsole::print(std::string text)
{
    SetConsoleTextAttribute(this->output, this->k);
    std::cout << text;
}

void Konsole::println(std::string text)
{
    SetConsoleTextAttribute(this->output, this->k);
    std::cout << text << std::endl;
}
