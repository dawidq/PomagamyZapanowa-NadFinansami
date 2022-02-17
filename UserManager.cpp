#include "UserManager.h"

void UserManager::rejestracjaUzytkownika()
{
    User user = podajDaneNowegoUzytkownika();

    users.push_back(user);
    fileWithUsers.dopiszUzytkownikaDoPliku(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::podajDaneNowegoUzytkownika()
{
    User user;


    user.ustawId(pobierzIdNowegoUzytkownika());
    string name;
    cout << "Podaj imie: ";
    cin>>name;
    user.setName(name);
    string surname;
    cout << "Podaj nazwisko: ";
    cin>>surname;
    user.setSurname(surname);
    string login;
    do
    {
        cout << "Podaj login: ";
        cin>>login;
        user.ustawLogin(login);
    }
    while (czyIstniejeLogin(user.pobierzLogin()) == true);
    string haslo;
    cout << "Podaj haslo: ";
    cin>>haslo;
    user.ustawHaslo(haslo);

    return user;
}

int UserManager::pobierzIdNowegoUzytkownika()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().pobierzId() + 1;
}
bool UserManager::czyIstniejeLogin(string login)
{
    for (int i=0; i<users.size(); i++)
    {
        if(users[i].pobierzLogin()==login)
        {
            cout<<"istnieje uzytkownik o takim loginie:"<<endl;
            return true;
        }

    }
    return false;
}
void UserManager::wypiszWszystkichUzytkownikow()
{
    for (int i=0; i<users.size(); i++)
    {

        cout<<users[i].pobierzId()<<endl;
        cout<<users[i].pobierzLogin()<<endl;
        cout<<users[i].pobierzHaslo()<<endl;

    }
}
void UserManager::logowanieUzytkownika()
{
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";

    login = AuxiliaryMethod::wczytajLinie();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = AuxiliaryMethod::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    idZalogowanegoUzytkownika= itr -> pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}
void UserManager::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika=0;
}
bool UserManager::czyUzytkownikJestZalogowany()
{
    if(idZalogowanegoUzytkownika>0)
        return true;
    else
        return false;
}

int UserManager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UserManager::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = AuxiliaryMethod::wczytajLinie();


    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            fileWithUsers.zapiszWszystkichUzytkownikowDoPliku(noweHaslo,idZalogowanegoUzytkownika);
            system("pause");
        }
    }

}
