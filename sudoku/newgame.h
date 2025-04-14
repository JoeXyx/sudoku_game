#ifndef NEWGAME_H
#define NEWGAME_H

#include <QWidget>

namespace Ui {
class NewGame;
}

class NewGame : public QWidget
{
    Q_OBJECT

public:
    explicit NewGame(QWidget *parent = nullptr);
    ~NewGame();

    QString difficulty;

signals:
    void sucess(QString difficulty );

private slots:
    void on_okButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::NewGame *ui;
};

#endif // NEWGAME_H
