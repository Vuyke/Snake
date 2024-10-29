#include <iostream>
#include <conio.h>
#include <list>
#include <time.h>
#include "constants.h"
#include "console.h"
using namespace std;

pi g(pi cord, pi cur) {
    return (cord + cur + N) % N;
}

void updateDirection(pi poc, pi dir, int upd, int updOld) {
    if(dir == INVALID) return;
    pi a, b, inc;
    if(dir == RIGHT || dir == LEFT) {
        a = g(poc, make_pair(0, BLOCK_SIZE));
        b = poc;
        inc = {1, 0};
        if(dir == LEFT) {
            swap(a, b);
            a = g(a, dir);
            b = g(b, dir);
        }
    }
    else {
        a = g(poc, make_pair(BLOCK_SIZE, 0));
        b = poc;
        inc = {0, 1};
        if(dir == UP) {
            swap(a, b);
            a = g(a, dir);
            b = g(b, dir);
        }
    }
    for0(k, BLOCK_SIZE) {
        mat[a.x][a.y] = upd;
        mat[b.x][b.y] = updOld;
        a = a + inc;
        b = b + inc;
    }
}

void initSpot(int i, int j, int kind) {
    for0(i1, BLOCK_SIZE) {
        for0(j1, BLOCK_SIZE) {
            mat[i + i1][j + j1] = kind;
        }
    }
}

void initApple() {
    pi tren = {-1, -1};
    int cnt = 0;
    for0(i, DIM_N) {
        for0(j, DIM_N) {
            if(mat[i * BLOCK_SIZE][j * BLOCK_SIZE] == EMPTY) {
                cnt++;
                tren = rand() % cnt ? tren : make_pair(i, j);
            }
        }
    }
    initSpot(tren.x * BLOCK_SIZE, tren.y * BLOCK_SIZE, APPLE);
}

pi getSecond() {
    if(snake.size() == 1)
        return INVALID;
    auto it = snake.begin();
    it++;
    return *it;
}

void updateSnake() {
    pi curCord = snake.back();
    pi lastCord = snake.front();
    pi newCur = g(curCord, curDir * BLOCK_SIZE);
    pi delDir = snake.size() == 1 ? curDir : direction(lastCord, getSecond());
    int p = mat[newCur.x][newCur.y];
    if(p == TAIL) {
        poraz = true;
        updateDirection(curCord, curDir, HIT, HEAD);
        screenUpdate();
        return;
    }
    for0(i, BLOCK_SIZE) {
        updateDirection(curCord, curDir, HEAD, TAIL);
        if(p != APPLE) {
            if(snake.size() > 1)
                updateDirection(lastCord, delDir, TAIL, EMPTY);
            else {
                updateDirection(lastCord, delDir, HEAD, EMPTY);
            }
        }
        curCord = curCord + curDir;
        lastCord = lastCord + delDir;
        Sleep(SLEEP2_FRAME);
        screenUpdate();
    }
    snake.push_back(g(snake.back(), curDir * BLOCK_SIZE));
    if(p != APPLE)
        snake.pop_front();
    else {
        initApple();
        broj++;
        if(broj == MAX)
            pobeda = true;
    }
}

int main()
{
    hideCursor();
    setColor(0);
    srand(time(0));
    initSpot(0, 0, HEAD);
    snake.push_back({0, 0});
    curDir = RIGHT;
    initApple();
    ispis();
    while(true) {
        updateSnake();
        if(poraz) {
            cout << "You LOST!" << endl;
            break;
        }
        else if(pobeda) {
            cout << "You WON!" << endl;
            break;
        }
        if((x = move()) != INVALID) {
            if(x != getOther(curDir))
                curDir = x;
        }
        Sleep(SLEEP_FRAME);
    }
    Sleep(5000);
    return 0;
}
