#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;
class User
{

int id;
string login;
string haslo;
string name;
string surname;
public:
void ustawId(int noweId);
void ustawLogin(string nowyLogin);
void ustawHaslo(string noweHaslo);
void setName(string newName);
void setSurname(string newPassword);

int pobierzId();
string pobierzLogin();
string pobierzHaslo();
string loadName();
string loadSurname();
};
#endif
