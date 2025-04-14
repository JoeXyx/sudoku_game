/********************************************************************************
** Form generated from reading UI file 'newgame.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAME_H
#define UI_NEWGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewGame
{
public:
    QPushButton *okButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *NewGame)
    {
        if (NewGame->objectName().isEmpty())
            NewGame->setObjectName("NewGame");
        NewGame->resize(366, 233);
        okButton = new QPushButton(NewGame);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(140, 160, 56, 18));
        widget = new QWidget(NewGame);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 90, 231, 61));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);


        retranslateUi(NewGame);

        QMetaObject::connectSlotsByName(NewGame);
    } // setupUi

    void retranslateUi(QWidget *NewGame)
    {
        NewGame->setWindowTitle(QCoreApplication::translate("NewGame", "Form", nullptr));
        okButton->setText(QCoreApplication::translate("NewGame", "OK", nullptr));
        label->setText(QCoreApplication::translate("NewGame", "Choose difficulty\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("NewGame", "Easy", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("NewGame", "Medium", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("NewGame", "Hard", nullptr));

    } // retranslateUi

};

namespace Ui {
    class NewGame: public Ui_NewGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAME_H
