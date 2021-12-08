#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QDebug>
#include "Societe.h"

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
    void on_add_jarray_clicked();

    void on_deleteButton_clicked();

    void on_DeleteAll_clicked();

    void on_ModifySoc_clicked();

    void on_search_textChanged(const QString &arg1);

    void on_tri_asc_clicked();

    void on_tabSociete_clicked(const QModelIndex &index);

    void on_refreshLogs_clicked();

    void on_sendBtn_clicked();
    void   mailSent(QString status);

      bool digitonlyinput(QString );
      bool characteronlyinput(QString  );

private:
    Ui::MainWindow *ui;
    Societe tmpsoc;
    QStringList files;

};

#endif // MAINWINDOW_H
