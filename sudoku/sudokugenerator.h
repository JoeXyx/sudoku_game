#ifndef SUDOKUGENERATOR_H
#define SUDOKUGENERATOR_H

enum Difficulty {
    Easy,
    Medium,
    Hard
};

class sudokugenerator
{
public:
    sudokugenerator();
    void generate(Difficulty difficulty);
    void getPuzzle( int puzzle[9][9]) ;
    void getSolution( int solution[9][9]) ;

    bool fillGrid();        // 随机填完整的终局
    bool solveGrid(int g[9][9]); // 回溯求解
    bool isSafe(int g[9][9], int row, int col, int num);
    void copyGrid(int src[9][9], int dest[9][9]);
    void removeCells(Difficulty diff); // 挖空函数

    int grid[9][9];         // 最终解
    int puzzle[9][9];       // 带空格的题目
};

#endif // SUDOKUGENERATOR_H
