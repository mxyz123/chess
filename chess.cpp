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

Chess::Chess(Konsole* k)
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
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(255);
                    this->k->print(" ");
                } 
                else 
                {
                    this->k->setAttribute(0);
                    this->k->print(" ");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            case 11:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(252);
                    this->k->print("p");
                } 
                else 
                {
                    this->k->setAttribute(12);
                    this->k->print("p");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            case 12:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(252);
                    this->k->print("v");
                } 
                else 
                {
                    this->k->setAttribute(12);
                    this->k->print("v");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            case 13:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(252);
                    this->k->print("k");
                } 
                else 
                {
                    this->k->setAttribute(12);
                    this->k->print("k");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            case 14:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(252);
                    this->k->print("s");
                } 
                else 
                {
                    this->k->setAttribute(12);
                    this->k->print("s");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            case 15:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(252);
                    this->k->print("K");
                } 
                else 
                {
                    this->k->setAttribute(12);
                    this->k->print("K");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            case 16:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(252);
                    this->k->print("Q");
                } 
                else 
                {
                    this->k->setAttribute(12);
                    this->k->print("Q");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            case 21:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(250);
                    this->k->print("p");
                } 
                else 
                {
                    this->k->setAttribute(10);
                    this->k->print("p");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            case 22:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(250);
                    this->k->print("v");
                } 
                else 
                {
                    this->k->setAttribute(10);
                    this->k->print("v");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            case 23:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(250);
                    this->k->print("k");
                } 
                else 
                {
                    this->k->setAttribute(10);
                    this->k->print("k");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            case 24:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(250);
                    this->k->print("s");
                } 
                else 
                {
                    this->k->setAttribute(10);
                    this->k->print("s");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            case 25:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(250);
                    this->k->print("K");
                } 
                else 
                {
                    this->k->setAttribute(10);
                    this->k->print("K");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            case 26:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(250);
                    this->k->print("Q");
                } 
                else 
                {
                    this->k->setAttribute(10);
                    this->k->print("Q");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            default:
                this->k->resetAttribute();
                this->k->print("[");
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    this->k->setAttribute(255);
                    this->k->print(" ");
                } 
                else 
                {
                    this->k->setAttribute(0);
                    this->k->print(" ");
                }
                this->k->resetAttribute();
                this->k->print("]");
                break;
            }
        }
        this->k->println("");
    }
    this->k->resetAttribute();
}

int Chess::get(int x, int y)
{
    return this->board[x][y];
}

void Chess::set(int x, int y, int val)
{
    this->board[x][y] = val;
}
