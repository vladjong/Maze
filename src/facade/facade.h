#pragma once

#include "../model/cave.h"
#include "../model/maze.h"
#include "../model/pacman.h"

namespace s21 {

class Facade {
 private:
    Cave cave_;
    Maze maze_;
    Pacman pacman_;

 public:
    Cave* cave() { return &cave_; }
    Maze* maze() { return &maze_; }
    Pacman* pacman() { return &pacman_; }
    std::vector<Position> findWay(Position begin, Position end) {
        pacman_.getMaze(&maze_);
        return pacman_.findWay(begin, end);
    }
};

}  // namespace s21
