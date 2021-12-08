#include "candidat.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>


Candidat::Candidat()
{  cin=0;  anne_dexperience=0; nom=""; prenom="";
            poste=""; adresse_mail=""; adreese="";

}

         Candidat::Candidat(int cin,QString nom ,QString prenom,int anne_dexperience,QString adresse_mail,QString poste,QString adresse)
     {
        this->cin=cin;
             this->anne_dexperience=anne_dexperience;
             this->nom=nom;
             this->prenom=prenom;
             this->adreese=adresse;
             this->adresse_mail=adresse_mail;
             this->poste=poste;

           }


         int Candidat::getcin(){return cin;}
    int Candidat::getanne_dexperience(){return anne_dexperience;}
    QString Candidat::getnom(){return nom;}
        QString Candidat::getprenom(){return prenom;}
        QString Candidat::getadresse_mail(){return adresse_mail;}
        QString Candidat::getposte(){return poste;}
        QString Candidat::getadreese(){return adreese;}

        void Candidat::setcin(int cin){this->cin=cin;}
        void Candidat::setanne_dexperience(int anne_dexperience) {this->anne_dexperience=anne_dexperience;}
        void Candidat::setnom(QString nom){this->nom=nom;}
        void Candidat::setprenom(QString prenom){this->prenom=prenom;}
        void Candidat::setadresse_mail(QString adresse_mail){this->adresse_mail=adresse_mail;}
        void Candidat::setposte(QString poste){this->poste=poste;}
        void Candidat::setadreese(QString adresse){this->adreese=adresse;}

//**************************************************************************
        //***************************************************************************
        bool Candidat::ajouter()
        {
            QString Cin_string= QString::number(cin);
            QString A_string= QString::number(anne_dexperience);

            bool test=false;
            QSqlQuery query;
            query.prepare("INSERT INTO CANDIDAT (CIN, NOM, PRENOM,ANNE_DEXPERIENCE,ADRESSE_MAIL,POSTE,ADRESSE) "
                          "VALUES (:CIN, :NOM, :PRENOM,:ANNE_DEXPERIENCE,:ADRESSE_MAIL,:POSTE,:ADRESSE)");
            query.bindValue(":CIN",Cin_string);
            query.bindValue(":NOM",nom);
            query.bindValue(":PRENOM",prenom);
            query.bindValue(":ANNE_DEXPERIENCE",A_string);
            query.bindValue(":ADRESSE_MAIL",adresse_mail);
                    query.bindValue(":POSTE",poste);
                    query.bindValue(":ADRESSE",adreese);
              query.exec();
              test =true;
            return test ;
        }

        QSqlQueryModel* Candidat::afficher()
        {
             QSqlQueryModel* model=new  QSqlQueryModel();

             model->setQuery("SELECT * FROM CANDIDAT");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("ANNE_DEXPERICENCE"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_MAIL"));
             model->setHeaderData(5, Qt::Horizontal, QObject::tr("POSTE"));
             model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));

            return model;

        }


        bool Candidat::supprimer(int cin)
        {
         QSqlQuery query;
         QString res= QString::number(cin);
         query.prepare("Delete from CANDIDAT where CIN= :CIN");
         query.bindValue(":CIN",res);
         return query.exec();
        }

        bool Candidat::modifier()
        {
            bool test=false;
            QSqlQuery query;

            QString Cin_string= QString::number(cin);
            QString A_string= QString::number(anne_dexperience);

              query.prepare("UPDATE CANDIDAT set CIN=:CIN , NOM=:NOM, ANNE_DEXPERIENCE=:ANNE_DEXPERIENCE , ADRESSE_MAIL=:ADRESSE_MAIL , POSTE=:POSTE , ADRESSE=:ADRESSE   WHERE CIN=:CIN");
              query.bindValue(":CIN",Cin_string);
              query.bindValue(":NOM",nom);
              query.bindValue(":PRENOM",prenom);
              query.bindValue(":ANNE_DEXPERIENCE",A_string);
              query.bindValue(":ADRESSE_MAIL",adresse_mail);
                      query.bindValue(":POSTE",poste);
                      query.bindValue(":ADRESSE",adreese);


             if( query.exec())
                test =true;


            return test ;
        }



        QSqlQueryModel * Candidat::afficher_tri_nom()
        {
            QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from CANDIDAT order by NOM asc ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ANNE_DEXPERICENCE"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_MAIL"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("POSTE"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));



            return model;
        }

        QSqlQueryModel * Candidat::afficher_tri_prenom()
        {
            QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from CANDIDAT order by PRENOM desc ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ANNE_DEXPERICENCE"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_MAIL"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("POSTE"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));

            return model;
        }

        QSqlQueryModel* Candidat::chercher_con(QString text)
        {
        QSqlQuery query;
            QSqlQueryModel* model=new QSqlQueryModel();
           {
             query.prepare("SELECT * FROM CANDIDAT where CIN like '"+text+"'");
             query.exec();
             model->setQuery(query);
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("ANNE_DEXPERICENCE"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_MAIL"));
             model->setHeaderData(5, Qt::Horizontal, QObject::tr("POSTE"));
             model->setHeaderData(6, Qt::Horizontal, QObject::tr("ADRESSE"));
             }

            return model;

        }

        int Candidat::calcul_An(int min, int max){
            QSqlQuery query;

            query.prepare("select *from CANDIDAT where ANNE_DEXPERIENCE between :min and :max");
            query.bindValue(":min",min);
            query.bindValue(":max",max);
            query.exec();

            int total=0;

            while(query.next())
            {
                total++;
            }

            return total;
        }
