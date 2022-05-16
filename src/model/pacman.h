#pragma once

#include <stack>
#include <vector>

#include "matrix.h"
#include "maze.h"

namespace s21 {

struct Position {
    int x;
    int y;
    Position() : x(0), y(0) {}
    Position(int xval, int yval) : x(xval), y(yval) {}
};

class Pacman {
 private:
    Matrix *hWall_ = nullptr;
    Matrix *vWall_ = nullptr;
    int **map_ = nullptr;
    int rows_;
    int cols_;

    void allocateMap();
    void destroyMap();
    int takePossibleSteps(int);

 public:
    Pacman() : rows_(0), cols_(0) {}
    ~Pacman() { destroyMap(); }
    void getMaze(Maze *maze);
    std::vector<Position> findWay(Position begin, Position end);
};

}  // namespace s21
