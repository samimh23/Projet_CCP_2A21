#include "connexion.h"

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{
bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("jarray");//inserer nom de l'utilisateur
    db.setPassword("jarray");//inserer mot de passe de cet utilisateur



if (db.open())
    test = true;

return test;

}
void Connexion::fermerConnexion()
{db.close();}
