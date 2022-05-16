#include "pacman.h"

#include <array>

namespace s21 {

void Pacman::getMaze(Maze *maze) {
    hWall_ = &(maze->getHorizontalWalls());
    vWall_ = &(maze->getVerticalWalls());
    rows_ = maze->getRows();
    cols_ = maze->getColumns();
    allocateMap();
}

void Pacman::allocateMap() {
    map_ = new int *[rows_];
    for (int i = 0; i < rows_; i++) {
        map_[i] = new int[cols_];
        for (int j = 0; j < cols_; j++) map_[i][j] = -1;
    }
}

void Pacman::destroyMap() {
    if (map_) {
        for (int i = 0; i < rows_; i++) {
            delete[] map_[i];
        }
        delete[] map_;
        map_ = nullptr;
    }
}

int changeTheCell(int value, int cell) {
    if (cell == -1)
        cell = value;
    else
        cell = std::min(cell, value);
    return cell;
}

int Pacman::takePossibleSteps(int step) {
    int result = 0;
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            if (map_[i][j] == step) {
                result++;
                if (i < rows_ - 1 && !(*hWall_)(i, j)) {
                    map_[i + 1][j] = changeTheCell(step + 1, map_[i + 1][j]);
                }
                if (i > 0 && !(*hWall_)(i - 1, j)) {
                    map_[i - 1][j] = changeTheCell(step + 1, map_[i - 1][j]);
                }
                if (j < cols_ - 1 && !(*vWall_)(i, j)) {
                    map_[i][j + 1] = changeTheCell(step + 1, map_[i][j + 1]);
                }
                if (j > 0 && !(*vWall_)(i, j - 1)) {
                    map_[i][j - 1] = changeTheCell(step + 1, map_[i][j - 1]);
                }
            }
        }
    }
    return result;
}

std::vector<Position> Pacman::findWay(Position begin, Position end) {
    std::vector<Position> path_;
    int y{end.y};
    int x{end.x};
    int count{1};
    int step{0};
    map_[begin.y][begin.x] = 0;
    while (count > 0 && map_[y][x] == -1) count = takePossibleSteps(step++);
    if (map_[y][x] != -1) {
        step = map_[y][x];
        path_.push_back({x, y});
        while (y != begin.y || x != begin.x) {
            if (y < rows_ - 1 && !(*hWall_)(y, x) && map_[y + 1][x] == step - 1)
                y++;
            else if (y > 0 && !(*hWall_)(y - 1, x) && map_[y - 1][x] == step - 1)
                y--;
            else if (x < cols_ - 1 && !(*vWall_)(y, x) && map_[y][x + 1] == step - 1)
                x++;
            else if (x > 0 && !(*vWall_)(y, x - 1) && map_[y][x - 1] == step - 1)
                x--;
            path_.push_back({x, y});
            step--;
        }
    }
    return path_;
}

}  // namespace s21
