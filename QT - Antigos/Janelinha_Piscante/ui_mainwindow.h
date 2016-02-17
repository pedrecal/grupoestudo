/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widHey;
    QPushButton *pushHey;
    QWidget *widDj;
    QPushButton *pushDj;
    QScrollArea *scrollHey;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollDj;
    QWidget *scrollAreaWidgetContents_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(730, 437);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widHey = new QWidget(centralWidget);
        widHey->setObjectName(QStringLiteral("widHey"));
        widHey->setGeometry(QRect(40, 30, 251, 151));
        pushHey = new QPushButton(widHey);
        pushHey->setObjectName(QStringLiteral("pushHey"));
        pushHey->setGeometry(QRect(70, 70, 96, 31));
        widDj = new QWidget(centralWidget);
        widDj->setObjectName(QStringLiteral("widDj"));
        widDj->setGeometry(QRect(40, 210, 251, 151));
        pushDj = new QPushButton(widDj);
        pushDj->setObjectName(QStringLiteral("pushDj"));
        pushDj->setGeometry(QRect(70, 70, 96, 31));
        scrollHey = new QScrollArea(centralWidget);
        scrollHey->setObjectName(QStringLiteral("scrollHey"));
        scrollHey->setGeometry(QRect(410, 20, 241, 161));
        scrollHey->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 239, 159));
        scrollHey->setWidget(scrollAreaWidgetContents);
        scrollDj = new QScrollArea(centralWidget);
        scrollDj->setObjectName(QStringLiteral("scrollDj"));
        scrollDj->setGeometry(QRect(410, 190, 241, 161));
        scrollDj->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 239, 159));
        scrollDj->setWidget(scrollAreaWidgetContents_2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 730, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Janelinha Piscante", 0));
        pushHey->setText(QApplication::translate("MainWindow", "HEY", 0));
        pushDj->setText(QApplication::translate("MainWindow", "DJ", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
