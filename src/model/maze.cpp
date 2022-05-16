#include "maze.h"

namespace s21 {

void Maze::setSizes(int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    allocateWalls();
}

inline void Maze::allocateWalls() {
    v_walls_ = Matrix(rows_, cols_);
    h_walls_ = Matrix(rows_, cols_);
}

inline void escapeLine(std::ifstream &myfile) {
    std::string line;
    getline(myfile, line);
}

void Maze::setFromFile(std::string filename) {
    file_ = std::ifstream(filename);
    parseSize();
    allocateWalls();
    parseWalls(v_walls_);
    escapeLine(file_);
    parseWalls(h_walls_);
}

void Maze::parseSize() {
    std::string line;
    getline(file_, line);
    size_t sub_pos = 0;
    rows_ = std::stoi(line, &sub_pos);
    cols_ = std::stoi(line.substr(sub_pos + 1), &sub_pos);
    if ((rows_ < 0 || rows_ > 50) && (cols_ < 0 || cols_ > 50)) {
        throw std::invalid_argument("Wrong maze size");
    }
}

void Maze::parseWalls(Matrix &matrix) {
    for (int i = 0; i < rows_; i++) {
        std::string line;
        getline(file_, line);
        for (int j = 0, k = 0; j < cols_; j++, k += 2) {
            matrix(i, j) = checkValue(line.at(k));
        }
    }
}

}  // namespace s21
