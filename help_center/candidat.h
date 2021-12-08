#ifndef CANDIDAT_H
#define CANDIDAT_H
#include <QString>
#include <QSqlQueryModel>

class Candidat
{
public:
    Candidat();
     Candidat(int,QString,QString,int,QString,QString,QString);
     //geters
     int getcin();
     int getanne_dexperience();
     QString getnom();
     QString getprenom();
     QString getadresse_mail();
     QString getposte();
     QString getadreese();
   //seters
     void setcin(int);
     void setanne_dexperience(int);
     void setnom(QString);
     void setprenom(QString);
     void setadresse_mail(QString);
     void setposte(QString);
     void setadreese(QString);
     bool ajouter();
     QSqlQueryModel * afficher ();
     bool supprimer(int);
     bool modifier ();
     QSqlQueryModel * afficher_tri_nom();
             QSqlQueryModel * afficher_tri_prenom();
        QSqlQueryModel* chercher_con(QString text);
        int calcul_An(int,int);




private:
    int cin,anne_dexperience;
    QString nom,prenom,adresse_mail,poste,adreese;

};

#endif // CANDIDAT_H
