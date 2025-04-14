#include "sudokucell.h"
#include<QRegularExpression>
#include<QRegularExpressionValidator>
sudokucell::sudokucell(QWidget *parent)
    : QLineEdit(parent),isFixed(false)
{
    setAlignment(Qt::AlignCenter);//设置控件或视图内部的内容的对齐方式
    setMaxLength(1);
    QFont font;
    font.setPointSize(18);
    setFont(font);

    // 仅允许输入1~9
    QRegularExpression regExp("[1-9]");
    setValidator(new QRegularExpressionValidator(regExp, this));
}

void sudokucell::setFixedCell(int value)// 设置为题面格子
{
    isFixed=true;//是题目格子
    setText(QString::number(value));
    setReadOnly(true);
    setStyleSheet("color: gray; background-color: #f0f0f0;");
}

void sudokucell::setEditable()// 设置为可输入格子
{
    isFixed=false;
    setText("");
    setReadOnly(false);
    setStyleSheet("color: black;");
}

void sudokucell::highlightError(bool on)// 错误提示（红色）
{
    if (on)
        setStyleSheet("color: red; font-weight: bold;");
    else
        resetStyle();
}

void sudokucell::resetStyle()
{
    if (isFixed)
        setStyleSheet("color: gray; background-color: #f0f0f0;");
    else
        setStyleSheet("color: black;");
}

int sudokucell::getValue() const
{
    return text().isEmpty()?0:text().toInt();
}

void sudokucell::setValue(int value)
{
    if(0==value)clear();
    else setText(QString::number(value));
}


