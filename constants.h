#pragma once

#include <utility>
#include <string>
#include <vector>
#include <list>

#define for0(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i < n; i++)
#define forr(i, n) for(int i = n - 1; i >= 0; i--)
#define forj(i, n, jmp) for(int i = 0; i < n; i += jmp)
#define x first
#define y second

typedef std::pair<int, int> pi;
typedef std::pair<std::string, int> psi;
typedef std::vector<std::vector<int>> matrix;

template <typename T, typename Q> std::pair<T, Q> operator-(const std::pair<T, Q>& x, const std::pair<T, Q>& y) {
    return {x.x - y.x, x.y - y.y};
}
template <typename T, typename Q> std::pair<T, Q> operator+(const std::pair<T, Q>& x, const std::pair<T, Q>& y) {
    return {x.x + y.x, x.y + y.y};
}
template <typename T, typename Q> std::pair<T, Q> operator+(const std::pair<T, Q>& x, const int& y) {
    return {x.x + y, x.y + y};
}
template <typename T, typename Q> std::pair<T, Q> operator*(const std::pair<T, Q>& x, const int& y) {
    return {x.x * y, x.y * y};
}
template <typename T, typename Q> std::pair<T, Q> operator/(const std::pair<T, Q>& x, const int& y) {
    return {x.x / y, x.y / y};
}
template <typename T, typename Q> std::pair<T, Q> operator%(const std::pair<T, Q>& x, const int& y) {
    return {x.x % y, x.y % y};
}

enum ConVal {
    RIGHT_ARROW = 77,
    UP_ARROW = 72,
    LEFT_ARROW = 75,
    DOWN_ARROW = 80
};
enum Map {
    APPLE = 4,
    HIT = 3,
    HEAD = 2,
    TAIL = 1,
    EMPTY = 0
};

enum Color {
    WHITE = 7,
    LIGHT_AQUA = 11,
    BLUE = 1,
    RED = 4,
    BLACK = 0,
    AQUA = 3,
    LIGHT_RED = 12
};

const int BLOCK_SIZE = 4;
const int SLEEP = 250, SLEEP2 = 300;
const int SLEEP_FRAME = SLEEP / BLOCK_SIZE;
const int SLEEP2_FRAME = SLEEP2 / BLOCK_SIZE;
const int DIM_N = 5;
const int N = BLOCK_SIZE * DIM_N;
const int MAX = 8;
const pi RIGHT = {0, 1}, LEFT = {0, -1}, DOWN = {1, 0}, UP = {-1, 0}, INVALID = {-1, -1};
const pi EDGE_RIGHT = {0, -DIM_N + 1}, EDGE_LEFT = {0, DIM_N - 1}, EDGE_DOWN = {-DIM_N + 1, 0}, EDGE_UP = {DIM_N - 1, 0};
const psi s[5] = {{" ", BLACK}, {"*", LIGHT_AQUA}, {"O", AQUA}, {"X", LIGHT_RED}, {"o", RED}};
int broj = 1;
pi curDir, x;
bool pobeda, poraz;
int mat[N][N];
std::list<pi> snake;

pi getOther(pi dir) {
    if(dir == RIGHT)
        return LEFT;
    if(dir == UP)
        return DOWN;
    if(dir == DOWN)
        return UP;
    if(dir == LEFT)
        return RIGHT;
    return INVALID;
}

pi direction(pi x, pi y) {
    pi res = (y - x) / BLOCK_SIZE;
    if(res == RIGHT || res == EDGE_RIGHT)
        return RIGHT;
    if(res == UP || res == EDGE_UP)
        return UP;
    if(res == LEFT || res == EDGE_LEFT)
        return LEFT;
    if(res == DOWN || res == EDGE_DOWN)
        return DOWN;
    return INVALID;
}
