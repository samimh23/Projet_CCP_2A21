#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include "Societe.h"
#include<iostream>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QHorizontalBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "smtp.h"
#include <QStringList>
#include<QFileDialog>
QT_CHARTS_USE_NAMESPACE


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QFile file("C:/Users/don7a/Desktop/New folder/Atelier_Connexion/logs.txt");
              if(!file.open(QFile::WriteOnly | QFile::Text | QFile::Append))
              {
                  QMessageBox::warning(this,"title","file not open");
              }
              QTextStream out(&file);
    ui->tabSociete->setModel(tmpsoc.afficher());//refresh
    QPieSeries *series = new QPieSeries();

        series->append("Sociétés archivé", tmpsoc.nb_archived());
        series->append("Sociétés courantes", tmpsoc.nb_current());


        QPieSlice *slice = series->slices().at(1);
        slice->setExploded();
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkBlue, 2));
        slice->setBrush(Qt::darkMagenta);

        QChart *chart = new QChart(); //create pie
        chart->addSeries(series);
        chart->setTitle("Statistique");
        chart->setBackgroundBrush(Qt::transparent);
        //chart->legend()->hide();
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(600,351);

        QGridLayout layout;
        layout.addWidget(chartView);
        this->ui->graphicsView->setLayout(&layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void piechart(Societe s) {

}
void MainWindow::on_add_jarray_clicked()
{
   int id = ui->id_jarray->text().toInt();
    QString field = ui->field_jarray->text();
    QString nom = ui->ns_jarray->text();
    QString adresse = ui->addy_jarray->text();

    Societe s(id,nom,adresse,field);

    bool ajout= s.ajouter();
//    Smtp* smtp = new Smtp("recruting.help.center@gmail.com", "recruting101", "smtp.gmail.com", 465);
//            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


//            smtp->sendMail("recruting.help.center@gmail.com","yessine.jarray@esprit.tn" , "RECRUTING HELP CENTER VERIFICATION","SOCIETE AJOUTE AVEC SUCCEE");

    QFile file("C:/Users/don7a/Desktop/New folder/Atelier_Connexion/logs.txt");
              if(!file.open(QFile::WriteOnly | QFile::Text | QFile::Append))
              {
                  QMessageBox::warning(this,"title","file not open");
              }
              QTextStream out(&file);
              QDateTime localTime = QDateTime::currentDateTime();
                                         QString time1 = localTime.toString();
                                         out <<"Societe : "+nom+" ajouté à "+time1+" \n";
                                         file.close();
 //Societe tmpsoc;
 ui->tabSociete->setModel(tmpsoc.afficher());//refresh
 QPieSeries *series = new QPieSeries();

     series->append("Sociétés archivé", tmpsoc.nb_archived());
     series->append("Sociétés courantes", tmpsoc.nb_current());


     QPieSlice *slice = series->slices().at(1);
     slice->setExploded();
     slice->setLabelVisible();
     slice->setPen(QPen(Qt::darkBlue, 2));
     slice->setBrush(Qt::darkMagenta);

     QChart *chart = new QChart(); //create pie
     chart->addSeries(series);
     chart->setTitle("Statistique");
     chart->setBackgroundBrush(Qt::transparent);
     //chart->legend()->hide();
     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     chartView->resize(600,351);

     QGridLayout layout;
     layout.addWidget(chartView);
     this->ui->graphicsView->setLayout(&layout);
}

void MainWindow::on_deleteButton_clicked()
{  bool test =false;
    int id = ui->deleteid->text().toInt();
    QString ids = ui->deleteid->text();
  test =  tmpsoc.supprimer(id);
  if (ui->deleteid->text()!="")
  {
      QFile file("C:/Users/don7a/Desktop/New folder/Atelier_Connexion/logs.txt");
            if(!file.open(QFile::WriteOnly | QFile::Text | QFile::Append))
            {
                QMessageBox::warning(this,"title","file not open");
            }
            QTextStream out(&file);
            QDateTime localTime = QDateTime::currentDateTime();
                                       QString time1 = localTime.toString();
                                       out <<"Societe : "+ids+" Supprimé à "+time1+" \n";
                                       file.close();
  }
  ui->deleteid->clear();
  ui->tabSociete->setModel(tmpsoc.afficher());//refresh

     QPieSeries *series = new QPieSeries();

         series->append("Sociétés archivé", tmpsoc.nb_archived());
         series->append("Sociétés courantes", tmpsoc.nb_current());


         QPieSlice *slice = series->slices().at(1);
         slice->setExploded();
         slice->setLabelVisible();
         slice->setPen(QPen(Qt::darkBlue, 2));
         slice->setBrush(Qt::darkMagenta);

         QChart *chart = new QChart(); //create pie
         chart->addSeries(series);
         chart->setTitle("Statistique");
         chart->setBackgroundBrush(Qt::transparent);
         //chart->legend()->hide();
         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->resize(600,351);

         QGridLayout layout;
         layout.addWidget(chartView);
         this->ui->graphicsView->setLayout(&layout);
}

void MainWindow::on_DeleteAll_clicked()
{
    tmpsoc.supprimer_all();
    ui->tabSociete->setModel(tmpsoc.afficher());//refresh
}

void MainWindow::on_ModifySoc_clicked()
{
    if(ui->ModifySoc->isChecked())
      {
          ui->ModifyLabel->setText("Modification : Activer");
      ui->tabSociete->setModel(tmpsoc.afficher_mod());
      }
      else
      {
          ui->ModifyLabel->setText("Modification : Désactiver");
          ui->tabSociete->setModel(tmpsoc.afficher());

      }
    QPieSeries *series = new QPieSeries();

        series->append("Sociétés archivé", tmpsoc.nb_archived());
        series->append("Sociétés courantes", tmpsoc.nb_current());


        QPieSlice *slice = series->slices().at(1);
        slice->setExploded();
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkBlue, 2));
        slice->setBrush(Qt::darkMagenta);

        QChart *chart = new QChart(); //create pie
        chart->addSeries(series);
        chart->setTitle("Statistique");
        chart->setBackgroundBrush(Qt::transparent);
        //chart->legend()->hide();
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(600,351);

        QGridLayout layout;
        layout.addWidget(chartView);
        this->ui->graphicsView->setLayout(&layout);
}

void MainWindow::on_search_textChanged(const QString &arg1)
{
    QString nom = ui->search->text();
    ui->tabSociete->setModel(tmpsoc.afficher_rech(nom));
}

void MainWindow::on_tri_asc_clicked()
{
   ui->tabSociete->setModel(tmpsoc.trie_nom());
}

void MainWindow::on_tabSociete_clicked(const QModelIndex &index)
{
    QString val2= ui->tabSociete->model()->data(index).toString();
    QSqlQuery query2;
    query2.prepare("select id from SOCIETE where id='"+val2+"' ");
    if(query2.exec())
    {
        while(query2.next())
        {

            ui->deleteid->setText(query2.value(0).toString());

        }

    }
}

void MainWindow::on_refreshLogs_clicked()
{
    QFile file("C:/Users/don7a/Desktop/New folder/Atelier_Connexion/logs.txt");
              if(!file.open(QFile::ReadOnly | QFile::Text))
              {
                  QMessageBox::warning(this,"title","file not open");
              }
              QTextStream in(&file);
              QString text =in.readAll();
              ui->logs1->setPlainText(text);
              file.close();
}




//mailling

void   MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Mail envoyé!\n\n" ) );
    ui->rcpt->clear();
    ui->sujet->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}




void MainWindow::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp("yassine.jarray.14@gmail.com",ui->mail_pass->text(), "Smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
//(const QString &from, const QString &to, const QString &subject, const QString &body)
    if( !files.isEmpty() )
        smtp->sendMail("yassine.jarray.14@gmail.com", ui->rcpt->text() ,ui->sujet->text(), ui->msg->toPlainText(), files );
    else
        smtp->sendMail("yassine.jarray.14@gmail.com", ui->rcpt->text() ,ui->sujet->text(),ui->msg->toPlainText());

}
