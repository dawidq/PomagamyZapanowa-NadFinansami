#include <iostream>
#include "FinancesBook.h"

using namespace std;

int main()
{

    char wybor;

    FinancesBook financesBook("users.xml","incomes.xml","expenses.xml");
    //financesBook.wypiszWszystkichUzytkownikow();
    //system("Pause");

    while (true)
    {
        if (financesBook.pobierzIdZalogowanegoUzytkownika()==0)
        {
            cin.sync();
            wybor = financesBook.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                financesBook.rejestracjaUzytkownika();
                break;
            case '2':
                financesBook.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
      else
       {

            wybor = financesBook.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                financesBook.addIncome();
                break;
            case '2':
                financesBook.addExpense();
                break;
            case '3':
                financesBook.balanceCurrenMonth();
                break;
            case '4':
               financesBook.balancePenultimateMonth();
                break;
            case '5':
               financesBook.balanceForChosenDate();
                break;

            case '7':
                financesBook.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                 financesBook.wylogowanieUzytkownika();
                break;
            }
        }
}

    return 0;
}

