#include <QDebug>
#include "connexion.h"
#include <QMessageBox>
#include <iostream>
#include "Societe.h"
Societe::Societe(){
    id=0;
    nom="3ezdin";
    adresse="aze";
    field ="info";


}
Societe::Societe(int id, QString nom, QString adresse,QString field ) {
     this->id = id;
     this->nom = nom;
     this->adresse = adresse;
     this->field = field;
}

bool Societe::ajouter()
{

    QSqlQuery query;
  //  QString res= QString::number(id);
    query.prepare("INSERT INTO SOCIETE (ID, NOM, ADRESSE, FIELD)"
                        "VALUES (:id, :nom, :adresse, :field)");


    //QString strx4 = QString::number(id);


    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":field", field);
    // query.bindValue(":num",num);


    return query.exec();

}

int Societe:: nb_disp()
{
    QSqlQuery query;
    query.prepare("select count(*) from SOCIETE ;");
    query.exec();
    query.next();

       return query.value(0).toInt();
}


QSqlQueryModel * Societe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from SOCIETE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("FIELD"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("REGION"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("REQ_NUM"));
    return model;
}

bool Societe::supprimer_all()
{
QSqlQuery query;
query.prepare("Delete from Societe ");
return query.exec();
}

bool Societe::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from SOCIETE where id = :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlTableModel * Societe::afficher_mod()
{QSqlTableModel * model= new QSqlTableModel();
    model->setTable("SOCIETE");
model->select();
    return model;
}

QSqlQueryModel * Societe::afficher_rech(QString nom)
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from SOCIETE where nom like '"+nom+"%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("FIELD"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("REGION"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("REQ_NUM"));

    return model;
}


QSqlQueryModel * Societe::trie_nom()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from SOCIETE order by nom asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("FIELD"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("REGION"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("REQ_NUM"));
    return model;
}

int Societe:: nb_by_region(QString region)
{
    QSqlQuery query;
    query.prepare("select count(*) from SOCIETE where region ='"+region+"';");
    query.exec();
    query.next();

       return query.value(0).toInt();
}

int Societe:: nb_archived()
{
    QSqlQuery query;
    query.prepare("select count(*) from SOCIETE where archive = 1;");
    query.exec();
    query.next();

       return query.value(0).toInt();
}

int Societe:: nb_current()
{
    QSqlQuery query;
   query.prepare("select count(*) from SOCIETE where archive = 0;");
    query.exec();
    query.next();

       return query.value(0).toInt();
}
