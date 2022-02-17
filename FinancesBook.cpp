#include "FinancesBook.h"

void FinancesBook::rejestracjaUzytkownika()
{
    userManager.rejestracjaUzytkownika();
}

void FinancesBook::wypiszWszystkichUzytkownikow()
{
    userManager.wypiszWszystkichUzytkownikow();
}

int FinancesBook::logowanieUzytkownika()
{
    userManager.logowanieUzytkownika();
    if (userManager.czyUzytkownikJestZalogowany())
    {
        financesManager = new FinancesManager(NAZWA_PLIKU_Z_ADRESATAMI,NAZWA_PLIKU_Z_ADRESATAMIII,userManager.pobierzIdZalogowanegoUzytkownika());
    }
}
void FinancesBook::zmianaHaslaZalogowanegoUzytkownika()
{
    userManager.zmianaHaslaZalogowanegoUzytkownika();
}
void FinancesBook::wylogowanieUzytkownika()
{
    userManager.wylogowanieUzytkownika();
    delete financesManager;
    financesManager = NULL;
}
void FinancesBook::addIncome()
{
    if (userManager.czyUzytkownikJestZalogowany())
    {
        financesManager->addIncome();
    }
    else
    {
        cout<< "Przed proba dodania danych zaloguj sie!"<<endl;
        system("pause");
    }
}

    void FinancesBook::addExpense()
{
    if (userManager.czyUzytkownikJestZalogowany())
    {
        financesManager->addExpense();
    }
    else
    {
        cout<< "Przed proba dodania danych zaloguj sie!"<<endl;
        system("pause");
    }
}
void FinancesBook::balanceCurrenMonth()
{
    if(userManager.czyUzytkownikJestZalogowany())
    {
        financesManager->balanceCurrenMonth();
    }
}
void FinancesBook::balancePenultimateMonth()
{
    if(userManager.czyUzytkownikJestZalogowany())
    {
        financesManager->balancePenultimateMonth();
    }
}
void FinancesBook::balanceForChosenDate()
{
    if(userManager.czyUzytkownikJestZalogowany())
    {
        financesManager->balanceForChosenDate();
    }
}
/*balanceForChosenDate
void FinancesBook::wyszukajAdresatowPoImieniu()
{
    if(userManager.czyUzytkownikJestZalogowany())
    {
        financesManager->wyszukajAdresatowPoImieniu();
    }
}
void FinancesBook::wyszukajAdresatowPoNazwisku()
{
    if(userManager.czyUzytkownikJestZalogowany())
    {
        financesManager->wyszukajAdresatowPoNazwisku();
    }
}
void FinancesBook::usunAdresata()
{
    if(userManager.czyUzytkownikJestZalogowany())
    {
        financesManager->usunAdresata();
    }
}
void FinancesBook::edytujAdresata()
{
    if(userManager.czyUzytkownikJestZalogowany())
    {
        financesManager->edytujAdresata();
    }
}
*/
int FinancesBook::pobierzIdZalogowanegoUzytkownika()
{
    return userManager.pobierzIdZalogowanegoUzytkownika();
}
char FinancesBook::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = AuxiliaryMethod::wczytajZnak();

    return wybor;
}

char FinancesBook::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = AuxiliaryMethod::wczytajZnak();

    return wybor;
}
