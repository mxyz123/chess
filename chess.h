#pragma once

#include "konsole.h"

class Chess
{
private:
    int board[8][8];
    Konsole* k;
    void printPiece(std::string piece, int x, int y, int color1, int color2);
public:
    Chess(Konsole* k);
    ~Chess();
    void show();
    int get(int x, int y);
    void set(int x, int y, int val);
};