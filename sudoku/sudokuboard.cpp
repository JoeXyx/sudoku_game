#include "sudokuboard.h"

sudokuboard::sudokuboard(QWidget *parent)
    : QWidget{parent}
{
    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(0);
    setContentsMargins(5, 5, 5, 5);




    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cells[i][j] = new sudokucell(this);

            gridLayout->addWidget(cells[i][j], i, j);
        }
    }
}

void sudokuboard::loadPuzzle(const int puzzle[9][9])
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(puzzle[i][j]!=0)
                cells[i][j]->setFixedCell(puzzle[i][j]);
            else
                cells[i][j]->setEditable();
        }
    }
}

void sudokuboard::clearBoard()
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(!cells[i][j]->isFixed)cells[i][j]->clear();
        }
    }
}

sudokucell *sudokuboard::cellAt(int row, int col)
{
    return cells[row][col];
}

QVector<QVector<int> > sudokuboard::gettable()
{
    QVector<QVector<int> >temp;
    for(int i=0;i<9;i++){
        QVector<int>temp1;
        for(int j=0;j<9;j++){
            temp1.push_back(cells[i][j]->getValue());
        }
        temp.push_back(temp1);
    }
    return temp;
}
