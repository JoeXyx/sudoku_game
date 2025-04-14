#include "sudokugenerator.h"
#include<QVector>
#include <ctime>

sudokugenerator::sudokugenerator() {
    std::srand(std::time(0));
}

void sudokugenerator::generate(Difficulty difficulty)
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            grid[i][j]=0;
        }
    }

    fillGrid();                  // 填充完整答案
    copyGrid(grid, puzzle);      // 复制出题
    removeCells(difficulty);     // 挖空处理
}

void sudokugenerator::getPuzzle( int out[9][9])
{
    copyGrid(puzzle,out);
}

void sudokugenerator::getSolution(int out[9][9])
{
    copyGrid(grid,out);
}

bool sudokugenerator::fillGrid()
{
    for (int row = 0; row < 9; ++row)
        for (int col = 0; col < 9; ++col)
            if (grid[row][col] == 0) {
               QVector<int> nums = {1,2,3,4,5,6,7,8,9};
                std::random_shuffle(nums.begin(), nums.end());
                for (int num : nums) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (fillGrid())
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
    return true;
}

bool sudokugenerator::solveGrid(int g[9][9])
{
    for (int row = 0; row < 9; ++row)
        for (int col = 0; col < 9; ++col)
            if (g[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(g, row, col, num)) {
                        g[row][col] = num;
                        if (solveGrid(g))
                            return true;
                        g[row][col] = 0;
                    }
                }
                return false;
            }
    return true;
}

bool sudokugenerator::isSafe(int g[9][9], int row, int col, int num)
{
    //同行同列不能有相同数字
    for (int i = 0; i < 9; ++i) {
        if (g[row][i] == num || g[i][col] == num)
            return false;
    }
    //3*3不能有重复数字
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (g[startRow + i][startCol + j] == num)
                return false;
    return true;
}

void sudokugenerator::copyGrid(int src[9][9], int dest[9][9])
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            dest[i][j]=src[i][j];
        }
    }
}

void sudokugenerator::removeCells(Difficulty diff)
{
    int toRemove = (diff == Easy) ? 35 : (diff == Medium) ? 45 : 55;
    while (toRemove > 0) {
        int row = std::rand() % 9;
        int col = std::rand() % 9;
        if (puzzle[row][col] != 0) {
            puzzle[row][col] = 0;
            --toRemove;
        }
    }
}

