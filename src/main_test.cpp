#include <gtest/gtest.h>

#include <vector>

#include "model/cave.h"
#include "model/matrix.h"
#include "model/maze.h"
#include "model/pacman.h"

TEST(generateMaze, checkSize) {
    s21::Maze maze;
    maze.setSizes(10, 10);
    ASSERT_EQ(maze.getRows(), 10);
    ASSERT_EQ(maze.getColumns(), 10);
}

TEST(generateMaze, checkVerticlal) {
    s21::Maze maze;
    maze.setSizes(10, 10);
    maze.generateMaze();
    auto matrix = maze.getVerticalWalls();
    for (int i = 0; i < maze.getRows(); i++) {
        ASSERT_EQ(matrix(i, maze.getColumns() - 1), true);
    }
}

TEST(generateMaze, checkHorizontal) {
    s21::Maze maze;
    maze.setSizes(10, 10);
    maze.generateMaze();
    auto matrix = maze.getHorizontalWalls();
    for (int i = 0; i < maze.getColumns(); i++) {
        ASSERT_EQ(matrix(maze.getRows() - 1, i), true);
    }
}

TEST(readFromFile, checkMaze) {
    s21::Maze maze;
    maze.setFromFile("datasets/10x10.txt");
}

TEST(findWay10x10, checkPacman) {
    s21::Maze maze;
    maze.setFromFile("datasets/10x10.txt");
    s21::Pacman pacman;
    pacman.getMaze(&maze);
    auto way = pacman.findWay({0, 0}, {5, 5});
    int result[]{5, 5, 5, 4, 6, 4, 6, 3, 5, 3, 4, 3, 4, 4, 3, 4, 3,
                 3, 2, 3, 1, 3, 1, 2, 2, 2, 2, 1, 2, 0, 1, 0, 0, 0};
    for (int i = 0, pos = 0; i < way.size(); i++) {
        ASSERT_EQ(way[i].x, result[pos++]);
        ASSERT_EQ(way[i].y, result[pos++]);
    }
}

TEST(findWay20x20, checkPacman) {
    s21::Maze maze;
    maze.setFromFile("datasets/20x20.txt");
    s21::Pacman pacman;
    pacman.getMaze(&maze);
    auto way = pacman.findWay({10, 15}, {8, 3});
    int result[]{8,  3,  8,  4,  7,  4,  6,  4,  5,  4,  4,  4,  3,  4,  2,  4,  2,  5,  3,  5,  3,
                 6,  2,  6,  1,  6,  1,  5,  1,  4,  1,  3,  1,  2,  2,  2,  3,  2,  3,  1,  2,  1,
                 1,  1,  0,  1,  0,  0,  1,  0,  2,  0,  3,  0,  4,  0,  4,  1,  4,  2,  5,  2,  6,
                 2,  7,  2,  8,  2,  9,  2,  10, 2,  10, 3,  9,  3,  9,  4,  9,  5,  9,  6,  8,  6,
                 7,  6,  6,  6,  5,  6,  4,  6,  4,  7,  5,  7,  5,  8,  5,  9,  5,  10, 6,  10, 6,
                 9,  6,  8,  6,  7,  7,  7,  7,  8,  7,  9,  8,  9,  8,  8,  8,  7,  9,  7,  10, 7,
                 11, 7,  12, 7,  12, 8,  11, 8,  11, 9,  10, 9,  10, 10, 11, 10, 12, 10, 12, 11, 12,
                 12, 12, 13, 11, 13, 10, 13, 10, 14, 11, 14, 12, 14, 12, 15, 11, 15, 10, 15};
    for (int i = 0, pos = 0; i < way.size(); i++) {
        ASSERT_EQ(way[i].x, result[pos++]);
        ASSERT_EQ(way[i].y, result[pos++]);
    }
}

TEST(readFromFile50x50, checkCave) {
    s21::Cave cave;
    cave.readFile("datasets/cave.txt");
    ASSERT_EQ(cave.getRows(), 50);
    ASSERT_EQ(cave.getCols(), 50);
}

TEST(readFromFile10x10, checkCave) {
    s21::Cave cave;
    cave.readFile("datasets/10x10.txt");
    ASSERT_EQ(cave.getRows(), 10);
    ASSERT_EQ(cave.getCols(), 10);
}

TEST(generateCave, checkSize) {
    s21::Cave cave;
    cave.generateMap(30, 17, 6);
    ASSERT_EQ(cave.getRows(), 17);
    ASSERT_EQ(cave.getCols(), 6);
}

TEST(generateCave, update) {
    s21::Cave cave;
    cave.readFile("datasets/10x10.txt");
    bool map[] = {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0,
                  1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1,
                  1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
                  0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1};
    for (int i = 0, pos = 0; i < cave.getRows(); i++)
        for (int j = 0; j < cave.getCols(); j++) 
            ASSERT_EQ(cave.getMap()(i, j), map[pos++]);
    bool result[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                     0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1,
                     0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
                     1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cave.setLimits(3, 4);
    cave.updateMap();
    for (int i = 0, pos = 0; i < cave.getRows(); i++)
        for (int j = 0; j < cave.getCols(); j++) 
            ASSERT_EQ(cave.getMap()(i, j), result[pos++]);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
