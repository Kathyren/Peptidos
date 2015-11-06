/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *cmdEntrenar;
    QLineEdit *txtArchivoEntrenamiento;
    QLabel *label;
    QLineEdit *txtArchivoPrueba;
    QLabel *label_2;
    QPushButton *cmdPruebas;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(718, 211);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cmdEntrenar = new QPushButton(centralWidget);
        cmdEntrenar->setObjectName(QStringLiteral("cmdEntrenar"));
        cmdEntrenar->setGeometry(QRect(180, 110, 121, 21));
        txtArchivoEntrenamiento = new QLineEdit(centralWidget);
        txtArchivoEntrenamiento->setObjectName(QStringLiteral("txtArchivoEntrenamiento"));
        txtArchivoEntrenamiento->setGeometry(QRect(160, 20, 541, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 151, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        txtArchivoPrueba = new QLineEdit(centralWidget);
        txtArchivoPrueba->setObjectName(QStringLiteral("txtArchivoPrueba"));
        txtArchivoPrueba->setGeometry(QRect(160, 50, 541, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 151, 21));
        label_2->setFont(font);
        cmdPruebas = new QPushButton(centralWidget);
        cmdPruebas->setObjectName(QStringLiteral("cmdPruebas"));
        cmdPruebas->setGeometry(QRect(480, 110, 121, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 718, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        cmdEntrenar->setText(QApplication::translate("MainWindow", "Entrenar", 0));
        txtArchivoEntrenamiento->setText(QApplication::translate("MainWindow", "C:\\Users\\Enrique\\Desktop\\Entrenamiento.txt", 0));
        label->setText(QApplication::translate("MainWindow", "Datos de Entrenamiento", 0));
        label_2->setText(QApplication::translate("MainWindow", "Datos de Prueba", 0));
        cmdPruebas->setText(QApplication::translate("MainWindow", "Pruebas", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
