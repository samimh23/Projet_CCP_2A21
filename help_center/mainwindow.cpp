#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "candidat.h"
#include <QString>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QtSql/QSqlQuery>
#include "statistiques.h"
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QTextStream>
#include<QWidget>
#include<QtSvg/QSvgRenderer>
#include<QDirModel>
#include"qrcode.h"
#include<fstream>
using qrcodegen::QrCode;
using qrcodegen::QrSegment;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->show_con->setModel(C.afficher());
    connect(ui->sendBtn_2, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn_2, SIGNAL(clicked()), this, SLOT(browse()));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{
    int CIN=ui->li_cin->text().toInt();
    QString NOM=ui->li_nom->text();
    QString PRENOM=ui->li_prenom->text();
    int ANNE_DEXPERIENCE =ui->li_exp->text().toInt();
    QString ADRESSE_MAIL=ui->li_mail->text();
    QString POSTE=ui->li_poste->text();
    QString ADRESSE=ui->li_add->text();


    Candidat C (CIN,NOM,PRENOM,ANNE_DEXPERIENCE,ADRESSE_MAIL,POSTE,ADRESSE);
    bool test=C.ajouter();

            if(test)
                {
                QMessageBox::information(nullptr,QObject::tr("Ok"),
                                     QObject::tr("Ajout effectué\n"
                                                   "Click cancel to exit."),QMessageBox::Cancel);
                  ui->show_con->setModel(C.afficher());

                }
            else
                {
                QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                     QObject::tr("Ajout non effectué\n"
                                                   "Click cancel to exit."),QMessageBox::Cancel);
                }
}


void MainWindow::on_show_con_activated(const QModelIndex &index)
{
    QString val=ui->show_con->model()->data(index).toString();
    QSqlQuery qry ;
       qry.prepare("SELECT * from CANDIDAT  where CIN='"+val+"' ");
       if(qry.exec())
       {
           while(qry.next())
           {


               ui->li_cin->setText(qry.value(0).toString());
               ui->li_nom->setText(qry.value(1).toString());
               ui->li_prenom->setText(qry.value(2).toString());
               ui->li_exp->setText(qry.value(3).toString());
               ui->li_mail->setText(qry.value(1).toString());
               ui->li_poste->setText(qry.value(2).toString());
               ui->li_add->setText(qry.value(3).toString());


           }
       }
       ui->li_cin->setText(ui->show_con->model()->data(ui->show_con->model()->index(index.row(),0)).toString());

}

void MainWindow::on_Supprimer_clicked()
{
    int cin =ui->li_cin->text().toInt();
     bool test=C.supprimer(cin);
   if (test)
   {

       QMessageBox::information(nullptr,QObject::tr("Ok"),
                            QObject::tr("suppression effectué\n"
                                          "Click cancel to exit."),QMessageBox::Cancel);
       ui->show_con->setModel(C.afficher());

       }
   else
       {
       QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                            QObject::tr("suppression non effectué\n"
                                          "Click cancel to exit."),QMessageBox::Cancel);
       }
}

void MainWindow::on_modifier_clicked()
{
    int CIN=ui->li_cin->text().toInt();
    QString NOM=ui->li_nom->text();
    QString PRENOM=ui->li_prenom->text();
    int ANNE_DEXPERIENCE =ui->li_exp->text().toInt();
    QString ADRESSE_MAIL=ui->li_mail->text();
    QString POSTE=ui->li_poste->text();
    QString ADRESSE=ui->li_add->text();



Candidat C (CIN,NOM,PRENOM,ANNE_DEXPERIENCE,ADRESSE_MAIL,POSTE,ADRESSE);


    bool test=C.modifier();
    if(test)

        {
        QMessageBox::information(nullptr,QObject::tr("Ok"),
        QObject::tr("Modification effectuée\n"
                                           "Click cancel to exit."),QMessageBox::Cancel);


        ui->show_con->setModel(C.afficher());

        }
    else
        {
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                             QObject::tr("Modification non effectuée\n"
                                           "Click cancel to exit."),QMessageBox::Cancel);

        }
}

void MainWindow::on_Vider_clicked()
{
    ui->li_cin->setText("");
    ui->li_nom->setText("");
    ui->li_prenom->setText("");
    ui->li_exp->setText("");
    ui->li_add->setText("");
    ui->li_mail->setText("");
    ui->li_poste->setText("");
}


void MainWindow::on_nom_tri_clicked()
{
    ui->show_con->setModel(C.afficher_tri_nom());

}

void MainWindow::on_prenom_tri_clicked()
{
    ui->show_con->setModel(C.afficher_tri_prenom());

}

void MainWindow::on_Chercher_clicked()
{
    QString choix;
            choix=ui->li_cher->text();
            QString li_rechercher=ui->li_cher->text();
            ui->show_con->setModel(C.chercher_con(li_rechercher));
}

void MainWindow::on_stat_clicked()
{
    statistiques *s=new statistiques();
       s->show();
}


void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file_2->setText( fileListString );

}


void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("sami.mahjoub@esprit.tn",ui->mail_pass_2->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("sami.mahjoub@esprit.tn", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText(), files );
    else
        smtp->sendMail("sami.mahjoub@esprit.tn", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText());
}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt_2->clear();
    ui->subject_2->clear();
    ui->file_2->clear();
    ui->msg_2->clear();
    ui->mail_pass_2->clear();
}




void MainWindow::on_qr_clicked()
{
    if(ui->show_con->currentIndex().row()==-1)
                  QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                           QObject::tr("Veuillez Choisir un animal du Tableau.\n"
                                                       "Click Ok to exit."), QMessageBox::Ok);
              else
              {

                   int li_cin=ui->show_con->model()->data(ui->show_con->model()->index(ui->show_con->currentIndex().row(),0)).toInt();

                   const QrCode qr = QrCode::encodeText(std::to_string(li_cin).c_str(), QrCode::Ecc::LOW);
                   std::ofstream myfile;
                   myfile.open ("qrcode.svg") ;
                   myfile << qr.toSvgString(1);
                   myfile.close();
                   QSvgRenderer svgRenderer(QString("qrcode.svg"));
                   QPixmap pix( QSize(90, 90) );
                   QPainter pixPainter( &pix );
                   svgRenderer.render( &pixPainter );
                   ui->qr_9->setPixmap(pix);
              }
}
