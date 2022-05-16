#include "maze.h"

namespace s21 {

bool randomBool() {
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<int> dist(0, 1);
    return static_cast<bool>(dist(engine));
}

void Maze::clearGenerator() {
    sideLine_.clear();
    counter_ = 1;
}

void Maze::fillEmptyValue() {
    for (int i = 0; i < cols_; i++) {
        sideLine_.push_back(kEmpty);
    }
}

void Maze::assignUniqueSet() {
    for (int i = 0; i < cols_; i++) {
        if (sideLine_[i] == kEmpty) {
            sideLine_[i] = counter_;
            counter_++;
        }
    }
}

void Maze::mergeSet(int index, int element) {
    int mutableSet = sideLine_[index + 1];
    for (int j = 0; j < cols_; j++) {
        if (sideLine_[j] == mutableSet) {
            sideLine_[j] = element;
        }
    }
}

void Maze::addingVerticalWalls(int row) {
    for (int i = 0; i < cols_ - 1; i++) {
        bool choise = randomBool();
        if (choise == true || sideLine_[i] == sideLine_[i + 1]) {
            v_walls_(row, i) = true;
        } else {
            mergeSet(i, sideLine_[i]);
        }
    }
    v_walls_(row, cols_ - 1) = true;
}

int Maze::calculateUniqueSet(int element) {
    int countUniqSet = 0;
    for (int i = 0; i < cols_; i++) {
        if (sideLine_[i] == element) {
            countUniqSet++;
        }
    }
    return countUniqSet;
}

void Maze::addingHorizontalWalls(int row) {
    for (int i = 0; i < cols_; i++) {
        bool choise = randomBool();
        if (calculateUniqueSet(sideLine_[i]) != 1 && choise == true) {
            h_walls_(row, i) = true;
        }
    }
}

int Maze::calculateHorizontalWalls(int element, int row) {
    int countHorizontalWalls = 0;
    for (int i = 0; i < cols_; i++) {
        if (sideLine_[i] == element && h_walls_(row, i) == false) {
            countHorizontalWalls++;
        }
    }
    return countHorizontalWalls;
}

void Maze::checkedHorizontalWalls(int row) {
    for (int i = 0; i < cols_; i++) {
        if (calculateHorizontalWalls(sideLine_[i], row) == 0) {
            h_walls_(row, i) = false;
        }
    }
}

void Maze::preparatingNewLine(int row) {
    for (int i = 0; i < cols_; i++) {
        if (h_walls_(row, i) == true) {
            sideLine_[i] = kEmpty;
        }
    }
}

void Maze::checkedEndLine() {
    for (int i = 0; i < cols_ - 1; i++) {
        if (sideLine_[i] != sideLine_[i + 1]) {
            v_walls_(rows_ - 1, i) = false;
            mergeSet(i, sideLine_[i]);
        }
        h_walls_(rows_ - 1, i) = true;
    }
    h_walls_(rows_ - 1, cols_ - 1) = true;
}

void Maze::addingEndLine() {
    assignUniqueSet();
    addingVerticalWalls(rows_ - 1);
    checkedEndLine();
}

void Maze::generateMaze() {
    fillEmptyValue();
    for (int j = 0; j < rows_ - 1; j++) {
        assignUniqueSet();
        addingVerticalWalls(j);
        addingHorizontalWalls(j);
        checkedHorizontalWalls(j);
        preparatingNewLine(j);
    }
    addingEndLine();
    clearGenerator();
}

}  // namespace s21
