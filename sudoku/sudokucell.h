#ifndef SUDOKUCELL_H
#define SUDOKUCELL_H

#include <QWidget>
#include<QLineEdit>

class sudokucell : public QLineEdit
{
    Q_OBJECT
public:
    explicit sudokucell(QWidget *parent = nullptr);
    void setFixedCell(int value); // 设置为题面格子
    void setEditable();           // 设置为可输入格子
    void highlightError(bool on); // 错误提示（红色）
    void resetStyle();            // 恢复默认样式
    int getValue() const;
    void setValue(int value);

    bool isFixed; // 是否为题目格


signals:
};

#endif // SUDOKUCELL_H
