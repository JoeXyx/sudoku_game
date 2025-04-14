#include "newgame.h"
#include "ui_newgame.h"

NewGame::NewGame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NewGame)
{
    ui->setupUi(this);
}

NewGame::~NewGame()
{
    delete ui;
}

void NewGame::on_okButton_clicked()
{
    emit sucess(difficulty);
    close();
}


void NewGame::on_comboBox_currentTextChanged(const QString &arg1)
{
    //将当前选项名赋值给变量str，输出当前选项名
   difficulty = ui->comboBox->currentText();
    qDebug() <<"Text:"<< difficulty;
}

