#include "connection.h"
#include<QDebug>

//test git
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("jarray");//inserer nom de l'utilisateur
db.setPassword("jarray");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
