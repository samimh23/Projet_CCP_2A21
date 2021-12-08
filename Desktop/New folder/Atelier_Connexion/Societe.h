#ifndef SOCIETE_H
#define SOCIETE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql>


class Societe
{ public:
Societe();
Societe(int,QString,QString,QString);
bool ajouter();
int nb_disp();
QSqlQueryModel * afficher();
bool supprimer_all();
bool supprimer(int);
QSqlTableModel * afficher_mod();
QSqlQueryModel * afficher_rech(QString);
QSqlQueryModel * trie_nom();
int  nb_by_region(QString);
int  nb_archived();
int  nb_current();
private:
    int id;
    QString nom,adresse,field;

    int getid(){return id;}
    QString getnom()    {return nom;}
    QString getadresse(){return adresse;}
    QString getfield()  {return field;}
};
#endif // SOCIETE_H
