#pragma once

#include <windows.h>
#include "constants.h"

void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cInfo;
    GetConsoleCursorInfo(hConsole, &cInfo);
    cInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cInfo);
}

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

template <typename T> void bojaIspis(T s, int color) {
    setColor(color);
    std::cout << s;
    setColor(WHITE);
}

pi move() {
    if(kbhit()) {
        int c = getch();
        if(c == 0 || c == 224) {
            switch(getch()) {
                case RIGHT_ARROW:
                    return RIGHT;
                case UP_ARROW:
                    return UP;
                case LEFT_ARROW:
                    return LEFT;
                case DOWN_ARROW:
                    return DOWN;
            }
        }
    }
    return INVALID;
}

void ispis() {
    for0(i, N) {
        if(i % BLOCK_SIZE == 0) {
            for0(j, N + N / BLOCK_SIZE)
                std::cout << "-";
            std::cout << std::endl;
        }
        for0(j, N) {
            bojaIspis(s[mat[i][j]].x, s[mat[i][j]].y);
            if((j + 1) % BLOCK_SIZE == 0)
                std::cout << "|";
        }

        std::cout << std::endl;
    }
}

void screenUpdate() {
    system("cls");
    ispis();
}
