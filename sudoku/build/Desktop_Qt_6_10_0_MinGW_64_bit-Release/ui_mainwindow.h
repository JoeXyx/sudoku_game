/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *sudokuContainer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *newGameButton;
    QPushButton *restartButton;
    QPushButton *pauseButton;
    QPushButton *recoveryButton;
    QPushButton *undoButton;
    QPushButton *hintButton;
    QPushButton *clearButton;
    QPushButton *redoButton;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *helpButton;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *timerLabel;
    QPushButton *exitButton;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *submitButton;
    QPushButton *solveButton;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(454, 404);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/C:/Users/13677/Desktop/79b7-3d2a1863258979bbb1dd6ba371ae1a0e.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 221, 225);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sudokuContainer = new QWidget(centralwidget);
        sudokuContainer->setObjectName("sudokuContainer");
        sudokuContainer->setGeometry(QRect(0, 50, 311, 281));
        sudokuContainer->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(310, 50, 141, 281));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        newGameButton = new QPushButton(widget);
        newGameButton->setObjectName("newGameButton");
        newGameButton->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(26, 188, 156);"));

        verticalLayout->addWidget(newGameButton);

        restartButton = new QPushButton(widget);
        restartButton->setObjectName("restartButton");
        restartButton->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 152, 219);\n"
"font: 12pt \"Microsoft YaHei UI\";"));

        verticalLayout->addWidget(restartButton);

        pauseButton = new QPushButton(widget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setStyleSheet(QString::fromUtf8("background-color: rgb(155, 89, 182);\n"
"font: 12pt \"Microsoft YaHei UI\";"));

        verticalLayout->addWidget(pauseButton);

        recoveryButton = new QPushButton(widget);
        recoveryButton->setObjectName("recoveryButton");
        recoveryButton->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 73, 94);\n"
"font: 12pt \"Microsoft YaHei UI\";"));

        verticalLayout->addWidget(recoveryButton);

        undoButton = new QPushButton(widget);
        undoButton->setObjectName("undoButton");
        undoButton->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 196, 15);\n"
"font: 12pt \"Microsoft YaHei UI\";"));

        verticalLayout->addWidget(undoButton);

        hintButton = new QPushButton(widget);
        hintButton->setObjectName("hintButton");
        hintButton->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 76, 60);\n"
"font: 12pt \"Microsoft YaHei UI\";"));

        verticalLayout->addWidget(hintButton);

        clearButton = new QPushButton(widget);
        clearButton->setObjectName("clearButton");
        clearButton->setStyleSheet(QString::fromUtf8("background-color: rgb(25, 42, 86);\n"
"font: 12pt \"Microsoft YaHei UI\";"));

        verticalLayout->addWidget(clearButton);

        redoButton = new QPushButton(widget);
        redoButton->setObjectName("redoButton");
        redoButton->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 84, 0);\n"
"font: 12pt \"Microsoft YaHei UI\";"));

        verticalLayout->addWidget(redoButton);

        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, 0, 431, 51));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        helpButton = new QPushButton(widget_4);
        helpButton->setObjectName("helpButton");
        helpButton->setMaximumSize(QSize(60, 16777215));
        helpButton->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(255, 184, 184);"));

        horizontalLayout_3->addWidget(helpButton);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setMaximumSize(QSize(50, 16777215));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        horizontalLayout->addWidget(label);

        timerLabel = new QLabel(widget_2);
        timerLabel->setObjectName("timerLabel");
        timerLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        horizontalLayout->addWidget(timerLabel);


        horizontalLayout_3->addWidget(widget_2);

        exitButton = new QPushButton(widget_4);
        exitButton->setObjectName("exitButton");
        exitButton->setMaximumSize(QSize(70, 16777215));
        exitButton->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(61, 61, 61);"));

        horizontalLayout_3->addWidget(exitButton);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 330, 221, 51));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        submitButton = new QPushButton(widget_3);
        submitButton->setObjectName("submitButton");
        submitButton->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(111, 30, 81);"));

        horizontalLayout_2->addWidget(submitButton);

        solveButton = new QPushButton(widget_3);
        solveButton->setObjectName("solveButton");
        solveButton->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(87, 88, 187);"));

        horizontalLayout_2->addWidget(solveButton);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 320, 50, 50));
        label_2->setMinimumSize(QSize(50, 50));
        label_2->setMaximumSize(QSize(50, 50));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/C:/Users/13677/Desktop/79b7-3d2a1863258979bbb1dd6ba371ae1a0e.jpg);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 454, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sudoku_Game", nullptr));
#if QT_CONFIG(tooltip)
        newGameButton->setToolTip(QCoreApplication::translate("MainWindow", "It can start a new game.", nullptr));
#endif // QT_CONFIG(tooltip)
        newGameButton->setText(QCoreApplication::translate("MainWindow", "new game", nullptr));
#if QT_CONFIG(tooltip)
        restartButton->setToolTip(QCoreApplication::translate("MainWindow", "It can restart your game.", nullptr));
#endif // QT_CONFIG(tooltip)
        restartButton->setText(QCoreApplication::translate("MainWindow", "restart", nullptr));
#if QT_CONFIG(tooltip)
        pauseButton->setToolTip(QCoreApplication::translate("MainWindow", "It can stop the time.", nullptr));
#endif // QT_CONFIG(tooltip)
        pauseButton->setText(QCoreApplication::translate("MainWindow", "pause", nullptr));
#if QT_CONFIG(tooltip)
        recoveryButton->setToolTip(QCoreApplication::translate("MainWindow", "It can recover pause.", nullptr));
#endif // QT_CONFIG(tooltip)
        recoveryButton->setText(QCoreApplication::translate("MainWindow", "Pause recovery", nullptr));
#if QT_CONFIG(tooltip)
        undoButton->setToolTip(QCoreApplication::translate("MainWindow", "It can back to yor last step.", nullptr));
#endif // QT_CONFIG(tooltip)
        undoButton->setText(QCoreApplication::translate("MainWindow", "back", nullptr));
#if QT_CONFIG(tooltip)
        hintButton->setToolTip(QCoreApplication::translate("MainWindow", "It can give you some ideas.", nullptr));
#endif // QT_CONFIG(tooltip)
        hintButton->setText(QCoreApplication::translate("MainWindow", "hint", nullptr));
#if QT_CONFIG(tooltip)
        clearButton->setToolTip(QCoreApplication::translate("MainWindow", "It can clear the box you chosen", nullptr));
#endif // QT_CONFIG(tooltip)
        clearButton->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
#if QT_CONFIG(tooltip)
        redoButton->setToolTip(QCoreApplication::translate("MainWindow", "It will help you get back to the previous step.", nullptr));
#endif // QT_CONFIG(tooltip)
        redoButton->setText(QCoreApplication::translate("MainWindow", "redo", nullptr));
        helpButton->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Time:", nullptr));
        timerLabel->setText(QString());
#if QT_CONFIG(tooltip)
        exitButton->setToolTip(QCoreApplication::translate("MainWindow", "It can exit.", nullptr));
#endif // QT_CONFIG(tooltip)
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(tooltip)
        submitButton->setToolTip(QCoreApplication::translate("MainWindow", "Submit your answer", nullptr));
#endif // QT_CONFIG(tooltip)
        submitButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
#if QT_CONFIG(tooltip)
        solveButton->setToolTip(QCoreApplication::translate("MainWindow", "It can solve your problems.", nullptr));
#endif // QT_CONFIG(tooltip)
        solveButton->setText(QCoreApplication::translate("MainWindow", "solve", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
