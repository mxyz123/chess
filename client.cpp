#include <iostream>
#include <string>
#include <stdlib.h>
#include "konsole.h"
#include "chess.h"

int main()
{
    system("CLS");
    Konsole cmd = Konsole();
    Chess chess = Chess(&cmd);
    chess.show();
    std::cout << std::endl << "Press ESC to exit..." << std::endl;
    cmd.startListening();
    bool rn = true;
    while (rn) {
        if(cmd.getLastKeyPress() == cmd.KEY_ESC)
        {
            cmd.stopListening();
            rn = false;
        }
    }
    cmd.resetAttribute();
    return 0;
}