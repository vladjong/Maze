#pragma once

#include <fstream>
#include <iostream>

#include "matrix.h"

namespace s21 {

enum cell { DEAD, ALIVE };

class Cave {
 public:
    void readFile(const std::string &fileName);
    void updateMap();
    Matrix& getMap() {return map_;}
    void generateMap(int chance, int rows, int cols);
    int getRows() { return rows_; }
    int getCols() { return cols_; }
    void setLimits(int birth, int death);
    Matrix& map() { return map_; }

 private:
    Matrix map_;
    int rows_ = 0;
    int cols_ = 0;
    int birthLimit_ = 0;
    int deathLimit_ = 0;

    void allocateMap();
    void parseSize(std::ifstream &myfile);
    void parseMap(std::ifstream &file);
};

}  // namespace s21
