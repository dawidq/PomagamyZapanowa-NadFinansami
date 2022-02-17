#include "FileWithUsers.h"
#include "Markup.h"

void FileWithUsers::dopiszUzytkownikaDoPliku(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.pobierzId());
    xml.AddElem("Login", user.pobierzLogin());
    xml.AddElem("Password", user.pobierzHaslo());
    xml.AddElem("Name", user.loadName());
    xml.AddElem("Surname", user.loadSurname());
    xml.Save("users.xml");
}

vector <User> FileWithUsers::wczytajUzytkownikowZPliku()
{

    User user;
    vector <User> users;

    CMarkup xml;
    xml.Load( "users.xml" );
    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER     plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    while ( xml.FindElem("User") )
    {
        xml.IntoElem();

        xml.FindElem( "UserId" );
        MCD_STR strID = xml.GetData();
        user.ustawId(atoi(strID.c_str()));

        xml.FindElem( "Login" );
        MCD_STR strLO = xml.GetData();
        user.ustawLogin (strLO);

        xml.FindElem( "Password" );
        MCD_STR strPA = xml.GetData();
        user.ustawHaslo (strPA);

        users.push_back(user);

        xml.OutOfElem();
    }

    return users;
}

void FileWithUsers::zapiszWszystkichUzytkownikowDoPliku(string noweHaslo,int idZalogowanegoUzytkownika)
{

    CMarkup xml;
    xml.Load( "users.xml" );//C:\Users\Dejw\Desktop\PROGRAMYC++\xml
    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER

    while ( xml.FindElem("User") )
    {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        MCD_STR strID = xml.GetData();

        if(atoi(strID.c_str())==idZalogowanegoUzytkownika)
        {
            xml.FindElem( "Password" );
            xml.RemoveElem();
            xml.AddElem("Password", noweHaslo);
        }
        xml.Save( "users.xml" );

        xml.OutOfElem();

    }
}
