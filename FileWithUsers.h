#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "FileText.h"
#include "User.h"
#include "AuxiliaryMethod.h"
using namespace std;

class FileWithUsers: public FileText
{

public:
    FileWithUsers(string nazwaPlikuZUserami):FileText(nazwaPlikuZUserami){};
    void dopiszUzytkownikaDoPliku(User user);
    vector <User> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(string noweHaslo,int idZalogowanegoUzytkownika);

};
#endif
