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
    cmd.setKeyEventFunction([&cmd](){
        std::cout << cmd.getLastKeyPress() << std::endl;
    });
    cmd.setMouseEventFunction([&cmd](){
        std::cout << "Mouse L x:" << cmd.getLastLMousePressX() << " y:" << cmd.getLastLMousePressY() << std::endl;
    });
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