#pragma once

#include <fstream>
#include <iostream>
#include <random>
#include <vector>

#include "matrix.h"

namespace s21 {

constexpr int kEmpty = 0;

class Maze {
 private:
    int rows_{0}, cols_{0};
    Matrix v_walls_, h_walls_;
    std::ifstream file_;
    std::vector<int> sideLine_;
    int counter_{1};

 public:
    void setSizes(int rows, int cols);
    void setFromFile(std::string filename);
    int getRows() { return rows_; }
    int getColumns() { return cols_; }
    Matrix& getVerticalWalls() { return v_walls_; }
    Matrix& getHorizontalWalls() { return h_walls_; }
    void generateMaze();

 private:
    inline void allocateWalls();
    void parseSize();
    void parseWalls(Matrix& matrix);
    void fillEmptyValue();
    void assignUniqueSet();
    void addingVerticalWalls(int row);
    void mergeSet(int index, int element);
    int calculateUniqueSet(int element);
    int calculateHorizontalWalls(int element, int row);
    void checkedHorizontalWalls(int row);
    void addingHorizontalWalls(int row);
    void preparatingNewLine(int row);
    void addingEndLine();
    void checkedEndLine();
    void clearGenerator();
};

}  // namespace s21
