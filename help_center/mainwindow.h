#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "candidat.h"
#include"statistiques.h"
#include "smtp.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ajouter_clicked();

    void on_show_con_activated(const QModelIndex &index);

    void on_Supprimer_clicked();

    void on_modifier_clicked();



    void on_Vider_clicked();



    void on_nom_tri_clicked();

    void on_prenom_tri_clicked();

    void on_Chercher_clicked();

    void on_stat_clicked();

    void sendMail();
    void mailSent(QString);
    void browse();



    void on_qr_clicked();

private:
    Ui::MainWindow *ui;
    QStringList files;
    Candidat C;
};

#endif // MAINWINDOW_H
