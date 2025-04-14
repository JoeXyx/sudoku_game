#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"sudokuboard.h"
#include"newgame.h"
#include"sudokugenerator.h"
#include<QStack>
#include<QTime>
#include<QTimer>

struct Move{
    int row;
    int col;
    int previousValue;  // 修改前的值
    int currentValue;   // 修改后的值
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void getDifficulty();
    void savemove(int row,int col,int value);
    void updateboard();
    void onCellEdited(int row, int col, int newValue);
    void updateCell(int row, int col, int value);
    bool checkgridvaild();
    void markerror();
    void givehint();
    QVector<QVector<int>>getanswer();
    void updateTimerDisplay();

    sudokuboard* board;
    NewGame newgame;
    sudokugenerator * my_generator;
    QStack<Move> undostack;
    QStack<Move> redostack;
    int currentRow = -1;
    int currentCol = -1;
    QTimer *timer;
    QTime elapsedTime;
    QVBoxLayout* layout;


private slots:
    void on_restartButton_clicked();

    void on_clearButton_clicked();

    void on_newGameButton_clicked();

    void on_undoButton_clicked();

    void on_exitButton_clicked();

    void on_redoButton_clicked();

    void on_hintButton_clicked();

    void on_submitButton_clicked();

    void on_pauseButton_clicked();

    void on_recoveryButton_clicked();

    void on_solveButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
