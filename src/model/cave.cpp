#include "cave.h"

#include <random>

namespace s21 {

void Cave::allocateMap() { map_ = Matrix(rows_, cols_); }

void Cave::readFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file) {
        throw std::invalid_argument("No file");
    }
    parseSize(file);
    allocateMap();
    parseMap(file);
}

void Cave::parseSize(std::ifstream &file) {
    std::string line;
    getline(file, line);
    size_t subPosition = 0;
    rows_ = std::stoi(line, &subPosition);
    cols_ = std::stoi(line.substr(subPosition + 1), &subPosition);
    if (rows_ > 50 || cols_ > 50) {
        throw std::invalid_argument("Incorrect size");
    }
}

void Cave::parseMap(std::ifstream &file) {
    for (int i = 0; i < rows_; i++) {
        std::string line;
        getline(file, line);
        for (int j = 0, k = 0; j < cols_; j++, k += 2) {
            map_(i, j) = checkValue(line.at(k));
        }
    }
}

int findNeighbours(Matrix &map, int rowPos, int colPos) {
    int count = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) continue;
            int cur_i = rowPos + i;
            int cur_j = colPos + j;
            if (cur_i < 0 || cur_j < 0 || cur_i >= map.getRows() || cur_j >= map.getCols())
                count++;
            else
                count += map(rowPos + i, colPos + j);
        }
    }
    return count;
}

void Cave::updateMap() {
    Matrix oldMap(map_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            int neighbors = findNeighbours(oldMap, i, j);
            if (map_(i, j) == DEAD && neighbors > birthLimit_) map_(i, j) = ALIVE;
            if (map_(i, j) == ALIVE && neighbors < deathLimit_) map_(i, j) = DEAD;
        }
    }
}

void Cave::generateMap(int chance, int rows, int cols) {
    rows_ = rows;
    cols_ = cols;

    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    if (rows_ > 50 || cols_ > 50) {
        throw std::invalid_argument("Incorrect size");
    }
    allocateMap();
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            map_(i, j) = (dist(engine) <= chance);
        }
    }
}

void Cave::setLimits(int birth, int death) {
    birthLimit_ = birth;
    deathLimit_ = death;
}

}  // namespace s21
