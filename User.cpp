#include"User.h"

void User::ustawId(int noweId)
{
    if(noweId>=0)
    id=noweId;
}
void User::ustawLogin(string nowyLogin)
{
    login=nowyLogin;
}
void User::ustawHaslo(string noweHaslo)
{
    haslo=noweHaslo;
}
void User::setName(string newName)
{
    name=newName;
}
void User::setSurname(string newSurname)
{
    surname=newSurname;
}
int User::pobierzId()
{
    return id;
}
string User::pobierzLogin()
{
    return login;
}
string User::pobierzHaslo()
{
    return haslo;
}
string User::loadName()
{
    return name;
}
string User::loadSurname()
{
    return surname;
}
