#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>

#include "AuxiliaryMethod.h"
#include "User.h"
#include "FileWithUsers.h"
using namespace std;

class UserManager
{
    int idZalogowanegoUzytkownika;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);


public:
    UserManager(string nazwaPlikuZUzytkownikami): fileWithUsers(nazwaPlikuZUzytkownikami){
    idZalogowanegoUzytkownika=0;
    users=fileWithUsers.wczytajUzytkownikowZPliku();
    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();

};
#endif
