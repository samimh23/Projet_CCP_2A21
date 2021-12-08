/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pb_ajouter;
    QLineEdit *le_cin;
    QPushButton *pb_modifier;
    QLabel *label_8;
    QLineEdit *salaire;
    QPushButton *pb_supprimer;
    QTableView *tab_staff;
    QLineEdit *lineEdit_rech;
    QPushButton *pb_rechercher;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label_4;
    QLineEdit *le_prenom;
    QLineEdit *le_nom;
    QPushButton *pb_excel;
    QPushButton *pb_pdf;
    QWidget *tab_4;
    QCustomPlot *plot;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1212, 932);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 70, 981, 561));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 170, 56, 16));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 110, 56, 16));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 50, 56, 16));
        pb_ajouter = new QPushButton(tab);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(60, 300, 93, 28));
        le_cin = new QLineEdit(tab);
        le_cin->setObjectName(QStringLiteral("le_cin"));
        le_cin->setGeometry(QRect(140, 50, 113, 22));
        pb_modifier = new QPushButton(tab);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(170, 300, 93, 28));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(70, 220, 56, 16));
        salaire = new QLineEdit(tab);
        salaire->setObjectName(QStringLiteral("salaire"));
        salaire->setGeometry(QRect(140, 220, 113, 22));
        pb_supprimer = new QPushButton(tab);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(280, 300, 93, 28));
        tab_staff = new QTableView(tab);
        tab_staff->setObjectName(QStringLiteral("tab_staff"));
        tab_staff->setGeometry(QRect(440, 70, 471, 271));
        lineEdit_rech = new QLineEdit(tab);
        lineEdit_rech->setObjectName(QStringLiteral("lineEdit_rech"));
        lineEdit_rech->setGeometry(QRect(560, 40, 113, 22));
        pb_rechercher = new QPushButton(tab);
        pb_rechercher->setObjectName(QStringLiteral("pb_rechercher"));
        pb_rechercher->setGeometry(QRect(690, 35, 93, 28));
        radioButton = new QRadioButton(tab);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(530, 350, 97, 20));
        radioButton_2 = new QRadioButton(tab);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(640, 350, 97, 20));
        radioButton_3 = new QRadioButton(tab);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(770, 350, 97, 20));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(450, 350, 56, 16));
        le_prenom = new QLineEdit(tab);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(140, 170, 113, 22));
        le_nom = new QLineEdit(tab);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(140, 110, 113, 22));
        pb_excel = new QPushButton(tab);
        pb_excel->setObjectName(QStringLiteral("pb_excel"));
        pb_excel->setGeometry(QRect(690, 410, 93, 28));
        pb_pdf = new QPushButton(tab);
        pb_pdf->setObjectName(QStringLiteral("pb_pdf"));
        pb_pdf->setGeometry(QRect(520, 410, 93, 28));
        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        plot = new QCustomPlot(tab_4);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setGeometry(QRect(30, 20, 621, 351));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1212, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Pr\303\251nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Salaire", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pb_rechercher->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Rechercher</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pb_rechercher->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "NOM", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "PRENOM", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "SALAIRE", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Tri :", Q_NULLPTR));
        pb_excel->setText(QApplication::translate("MainWindow", "Excel", Q_NULLPTR));
        pb_pdf->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "ajouter un staff", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
