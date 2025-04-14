#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"sudokuboard.h"
#include<QRandomGenerator>
#include<QMessageBox>
#include<QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    board = new sudokuboard(this);



    layout = new QVBoxLayout;
    layout->addWidget(board);

    ui->sudokuContainer->setLayout(layout);
    ui->sudokuContainer->setStyleSheet(R"(QWidget#sudokuContainer {

         border-radius: 12px;
        background-color: rgba(52, 73, 94,100);
        border-radius:6
    }
 )");



    // 在 MainWindow 构造函数或初始化时，对于sudukocell改变，添加响应函数，以及连接相应变量
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            connect(board->cells[i][j], &QLineEdit::textChanged, this, [=](const QString &text){
                int value = text.toInt();
                savemove(i, j, value);
            });
            connect(board->cells[i][j], &QLineEdit::selectionChanged, this, [=](){
                currentRow = i;
                currentCol = j;
            });
        }
    }

    timer=new QTimer();
    connect(timer,&QTimer::timeout,this,&MainWindow::updateTimerDisplay);
    elapsedTime=QTime(0,0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getDifficulty()
{
    my_generator=new sudokugenerator();
    qDebug()<<"用户选择难度为："<<newgame.difficulty;
    if (newgame.difficulty == "Easy")
        my_generator->generate(Easy);
    else if (newgame.difficulty == "Medium")
        my_generator->generate(Medium);
    else
        my_generator->generate(Hard);
    int puzzle[9][9];
    my_generator->getPuzzle(puzzle);
    board->loadPuzzle(puzzle);  // 显示题目到界面

    elapsedTime = QTime(0, 0, 0);
    timer->start(1000); // 每秒触发一次 timeout


}

void MainWindow::savemove(int row, int col, int value)
{
    if(!undostack.empty()){
    Move last=undostack.top();
        if(last.row==row&&last.col==col){
        undostack.push(Move{row,col,last.currentValue,value});
        return;
        }
    }
    int oldvalue=0;
    undostack.push( Move{row,col,oldvalue,value});
    board->cells[row][col]->setValue(value);
}

void MainWindow::onCellEdited(int row, int col, int newValue)
{
    savemove(row,col,newValue);
    board->update();
}

void MainWindow::updateCell(int row, int col, int value)
{
    sudokucell* cell = board->cells[row][col];
    cell->blockSignals(true);  // 避免触发 textChanged 导致死循环
    if (value == 0)
        cell->clear();
    else
        cell->setText(QString::number(value));
    cell->blockSignals(false);
}

bool MainWindow::checkgridvaild()
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board->cells[i][j]->getValue()!=0&&board->cells[i][j]->getValue()!=my_generator->grid[i][j])return false;
        }
    }
    return true;
}

void MainWindow::markerror()
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board->cells[i][j]->getValue()!=0&&board->cells[i][j]->getValue()!=my_generator->grid[i][j]){
                board->cells[i][j]->highlightError(true);
                return;
            }
        }
    }
}

void MainWindow::givehint()
{
    QVector<QPair<int, int>> emptyCells;


    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board->cells[row][col]->getValue() == 0) {
                emptyCells.append(qMakePair(row, col));
            }
        }
    }

    if (emptyCells.isEmpty()) return;

    // 随机选一个空格子
    int index = QRandomGenerator::global()->bounded(emptyCells.size());
    int row = emptyCells[index].first;
    int col = emptyCells[index].second;

    int correctValue = my_generator->grid[row][col];
    // grid[row][col] = correctValue;

    board->cells[row][col]->blockSignals(true);
    board->cells[row][col]->setValue(correctValue);
    board->cells[row][col]->blockSignals(false);

    board->cells[row][col]->setStyleSheet("color: green; font-weight: bold;");

    // 可选：保存历史记录以便撤销
    undostack.push({row, col, 0, correctValue});
    while (!redostack.empty()) redostack.pop();
}

QVector<QVector<int> > MainWindow::getanswer()
{
    QVector<QVector<int>>temp;
    for(int i=0;i<9;i++){
        QVector<int>temp1;
        for(int j=0;j<9;j++){
            temp1.push_back(my_generator->grid[i][j]);
        }
        temp.push_back(temp1);
    }
    return temp;
}

void MainWindow::updateTimerDisplay()
{
    elapsedTime = elapsedTime.addSecs(1);
    ui->timerLabel->setText(elapsedTime.toString("hh:mm:ss"));
}



void MainWindow::on_restartButton_clicked()
{
    // qDebug()<<getanswer();
    board->clearBoard();
    elapsedTime = QTime(0, 0, 0);
    timer->start(1000); // 每秒触发一次 timeout
    board->update();
}


void MainWindow::on_clearButton_clicked()
{
    qDebug()<<currentRow<<" "<<currentCol;
    if(currentRow<0||currentCol<0)return;
    if(0==board->cells[currentRow][currentRow]->getValue()){qDebug()<<"wrong";return;}
    board->cells[currentRow][currentCol]->blockSignals(true);  // 防止触发 textChanged
    board->cells[currentRow][currentCol]->clear();
    board->cells[currentRow][currentCol]->blockSignals(false);
    undostack.push({currentRow, currentCol, board->cells[currentRow][currentRow]->getValue(), 0});
    while (!redostack.empty()) redostack.pop();
}


void MainWindow::on_newGameButton_clicked()
{
    board->clearBoard();
    connect(&newgame, &NewGame::sucess, this, &MainWindow::getDifficulty);
    newgame.show();
}


void MainWindow::on_undoButton_clicked()
{
    if (undostack.empty()) return;

    Move move = undostack.top();
    undostack.pop();

    // 把当前状态压进 redo 栈
    Move redoMove = {move.row, move.col, move.currentValue, move.previousValue};
    redostack.push(redoMove);

    // 更新状态
    board->cells[move.row][move.col] ->setValue(move.previousValue) ;
    updateCell(move.row, move.col, move.previousValue);
    board->update();
}


void MainWindow::on_exitButton_clicked()
{
    delete board;
    delete my_generator;
    exit(0);
}


void MainWindow::on_redoButton_clicked()
{
    if (redostack.empty()) {qDebug()<<"wrong";return;}

    Move move = redostack.top();
    redostack.pop();

    // 把当前状态压回 undo 栈
    Move undoMove = {move.row, move.col, move.previousValue, move.currentValue};
    undostack.push(undoMove);
    qDebug()<<move.previousValue;

    // 更新状态
    board->cells[move.row][move.col] ->setValue(move.previousValue) ;
    updateCell(move.row, move.col, move.previousValue);
   board-> update();
}


void MainWindow::on_hintButton_clicked()
{
    if(!checkgridvaild()){
        markerror();
    }
    else givehint();
    board->update();
}


void MainWindow::on_submitButton_clicked()
{
    bool judge=true;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board->cells[i][j]->getValue()!=my_generator->grid[i][j])judge=false;
        }
    }
    if(judge)QMessageBox::information(this,"提示","恭喜过关！加油挑战更高难度吧");
    else{
        QMessageBox::information(this,"提示","您的题解存在问题，再检查检查吧！");
    }
}


void MainWindow::on_pauseButton_clicked()
{
    timer->stop();
    board->update();
}


void MainWindow::on_recoveryButton_clicked()
{
    timer->start(1000);
}


void MainWindow::on_solveButton_clicked()
{
    int inputgrid[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            QString text=board->cells[i][j]->text();
            inputgrid[i][j]=text.isEmpty()?0:text.toInt();
        }
    }

    if(my_generator->solveGrid(inputgrid)){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                board->cells[i][j]->setText(QString::number(inputgrid[i][j]));
            }
        }
        board->update();
        QMessageBox::information(this,"提示","您的问题已解决！");
    }
    else QMessageBox::information(this,"提示","您的问题无解！");
}

