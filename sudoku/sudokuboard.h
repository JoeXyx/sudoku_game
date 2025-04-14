#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <QWidget>
#include<sudokucell.h>
#include<QGridLayout>

class sudokuboard : public QWidget
{
    Q_OBJECT
public:
    explicit sudokuboard(QWidget *parent = nullptr);
    void loadPuzzle(const int puzzle[9][9]); // 加载新题面
    void clearBoard(); // 清空所有非固定格子
    sudokucell* cellAt(int row, int col); // 获取单元格
    QVector<QVector<int>>gettable();

    QGridLayout* gridLayout;
    sudokucell* cells[9][9];

signals:
};

#endif // SUDOKUBOARD_H
