#include "chess.h"

/*
    0 - volne
    11 | 21 - pesiak
    12 | 22 - veza
    13 | 23 - kon
    14 | 24 - strelec
    15 | 25 - kral
    16 | 26 - kralovna

    11 - 16 -> hrac2
    21 - 26 -> hrac1
*/

void Chess::printPiece(std::string piece, int x, int y, int color1, int color2)
{
    this->k->resetAttribute();
                this->k->print("[");
                if((x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0))
                {
                    this->k->setAttribute(color1);
                    this->k->print(piece);
                } 
                else 
                {
                    this->k->setAttribute(color2);
                    this->k->print(piece);
                }
                this->k->resetAttribute();
                this->k->print("]");
}

Chess::Chess(Konsole *k)
{
    this->k = k;

    this->board[0][0] = 12; //a8
    this->board[0][1] = 13; //b8
    this->board[0][2] = 14; //c8
    this->board[0][3] = 15; //d8
    this->board[0][4] = 16; //e8
    this->board[0][5] = 14; //f8
    this->board[0][6] = 13; //g8
    this->board[0][7] = 12; //h8

    this->board[1][0] = 11; //a7
    this->board[1][1] = 11; //b7
    this->board[1][2] = 11; //c7
    this->board[1][3] = 11; //d7
    this->board[1][4] = 11; //e7
    this->board[1][5] = 11; //f7
    this->board[1][6] = 11; //g7
    this->board[1][7] = 11; //h7

    // a6 .. h3
    for (size_t i = 2; i < 6; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            this->board[i][j] = 0;
        }
        
    }

    this->board[6][0] = 21; //a2
    this->board[6][1] = 21; //b2
    this->board[6][2] = 21; //c2
    this->board[6][3] = 21; //d2
    this->board[6][4] = 21; //e2
    this->board[6][5] = 21; //f2
    this->board[6][6] = 21; //g2
    this->board[6][7] = 21; //h2

    this->board[7][0] = 22; //a1
    this->board[7][1] = 23; //b1
    this->board[7][2] = 24; //c1
    this->board[7][3] = 25; //d1
    this->board[7][4] = 26; //e1
    this->board[7][5] = 24; //f1
    this->board[7][6] = 23; //g1
    this->board[7][7] = 22; //h1
}

Chess::~Chess()
{
}

void Chess::show()
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            switch (this->board[i][j])
            {
            case 0:
                this->printPiece(" ", i, j, 255, 0);
                break;
            case 11:
                this->printPiece("p", i, j, 252, 12);
                break;
            case 12:
                this->printPiece("v", i, j, 252, 12);
                break;
            case 13:
                this->printPiece("k", i, j, 252, 12);
                break;
            case 14:
                this->printPiece("s", i, j, 252, 12);
                break;
            case 15:
                this->printPiece("K", i, j, 252, 12);
                break;
            case 16:
                this->printPiece("Q", i, j, 252, 12);
                break;
            case 21:
                this->printPiece("p", i, j, 250, 10);
                break;
            case 22:
                this->printPiece("v", i, j, 250, 10);
                break;
            case 23:
                this->printPiece("k", i, j, 250, 10);
                break;
            case 24:
                this->printPiece("s", i, j, 250, 10);
                break;
            case 25:
                this->printPiece("K", i, j, 250, 10);
                break;
            case 26:
                this->printPiece("Q", i, j, 250, 10);
                break;
            default:
                this->printPiece(" ", i, j, 250, 10);
                break;
            }
        }
        this->k->println("");
    }
    this->k->resetAttribute();
}

int Chess::get(int x, int y)
{
    return this->board[y][x];
}

void Chess::set(int x, int y, int val)
{
    this->board[y][x] = val;
}
