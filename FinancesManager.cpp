#include "FinancesManager.h"
void FinancesManager::addIncome()
{
    Income income;


    income = addNewIncome();

    incomes.push_back(income);


    if(fileWithRevenue.dopiszAdresataDoPliku(income))
        cout<<"Nowy przychod zostal dodany."<<endl;
    else
        cout<<"Nie udalo sie dodac przychodu do pliku."<<endl;
    system("pause");
}

Income FinancesManager::addNewIncome()
{
    Income income;
    string item, amountString;
    int date;
    float amount;
    char wybor;

    income.setIncomeId((fileWithRevenue.pobierzZPlikuIdOstatniegoAdresata()+1));
    income.setUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    cout << "Jezeli dodanie nowego przychodu dotyczy dnia dzisiejszego   ->  wybierz: 1" << endl;
    cout << "Jezeli dodanie nowego przychodu dotyczy innego dnia         ->  wybierz: 2" << endl;

    wybor = AuxiliaryMethod::wczytajZnak();
    switch (wybor)
    {
    case '1':
        date = AuxiliaryMethod::conversionDateStringToInt(AuxiliaryMethod::loadSystemDate());
        break;
    case '2':
        date = AuxiliaryMethod::conversionDateStringToInt(AuxiliaryMethod::giveDate());
        break;
    }

    cout << "Podaj czego dotyczy przychod: ";

    item =AuxiliaryMethod::wczytajLinie();


    cout << "Podaj wartosc przychodu: ";
    amountString = AuxiliaryMethod::wczytajLinie();
    amount=AuxiliaryMethod::zamienPrzecinekNaKropke(amountString);

    income.setDate(date);
    income.setItem(item);
    income.setAmount(amount);
    return income;
}

void FinancesManager::addExpense()
{
    Expense expense;

    expense = addNewExpense();

    expenses.push_back(expense);
    if(fileWithExpenses.saveExpenseToFile(expense))
        cout<<"Nowy wydatek zostal dopisany do pliku!"<<endl;
    else
        cout<<"Nie udalo sie dodac danych do pliku!"<<endl;
    system("pause");
}


Expense FinancesManager::addNewExpense()
{
    Expense expense;
    string item, amountString;
    int date;
    float amount;
    char wybor;

    expense.setExpenseId((fileWithExpenses.pobierzZPlikuIdOstatniegoAdresata()+1));
    expense.setUserID(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    cout << "Jezeli dodanie nowego wydatku dotyczy dnia dzisiejszego   ->  wybierz: 1" << endl;
    cout << "Jezeli dodanie nowego wydatku dotyczy innego dnia         ->  wybierz: 2" << endl;

    wybor = AuxiliaryMethod::wczytajZnak();
    switch (wybor)
    {
    case '1':
        date = AuxiliaryMethod::conversionDateStringToInt(AuxiliaryMethod::loadSystemDate());
        break;
    case '2':
        date = AuxiliaryMethod::conversionDateStringToInt(AuxiliaryMethod::giveDate());
        break;
    }

    cout << "Podaj czego dotyczy wydatek: ";

    item =AuxiliaryMethod::wczytajLinie();


    cout << "Podaj wartosc wydatku: ";
    amountString = AuxiliaryMethod::wczytajLinie();
    amount=AuxiliaryMethod::zamienPrzecinekNaKropke(amountString);

    expense.setDate(date);
    expense.setItem(item);
    expense.setAmount(amount);


    return expense;
}

void FinancesManager::sortingIncomes()
{
    struct less_than_date
    {
        inline bool operator() ( Income& struct1, Income& struct2)
        {
            return (struct1.loadDate() < struct2.loadDate());
        }
    };

    std::sort(incomes.begin(), incomes.end(), less_than_date());
}
void FinancesManager::sortingExpenses()
{
    struct less_than_date
    {
        inline bool operator() ( Expense& struct1, Expense& struct2)
        {
            return (struct1.loadDate() < struct2.loadDate());
        }
    };

    std::sort(expenses.begin(), expenses.end(), less_than_date());
}
float FinancesManager::showIncomesCurrentMonth()
{
    float suma=0;
    SYSTEMTIME st;
    GetSystemTime(&st);
    cout<<endl<<">>> PRZYCHODY <<<"<<endl<<endl;
    for (int i=0; i<incomes.size(); i++)
    {
        if(incomes[i].loadDate()>st.wYear*10000+st.wMonth*100)
        {
            //cout<<incomes[i].loadIncomeId()<<endl;
            //cout<<incomes[i].loadUserId()<<endl;
            cout<<AuxiliaryMethod::conversionDateIntToString(incomes[i].loadDate())<<endl;
            cout<<incomes[i].loadItem()<<endl;
            cout<<incomes[i].loadAmount()<<endl<<endl;
            suma+=incomes[i].loadAmount();
        }

    }

    return suma;
}
float FinancesManager::showExpensesCurrentMonth()
{
    float suma=0;
    SYSTEMTIME st;
    GetSystemTime(&st);
        cout<<endl<<">>> WYDATKI <<<"<<endl<<endl;
    for (int i=0; i<expenses.size(); i++)
    {
        if(expenses[i].loadDate()>st.wYear*10000+st.wMonth*100)
        {
            //cout<<expenses[i].loadExpenseId()<<endl;
            //cout<<expenses[i].loadUserId()<<endl;
            cout<<AuxiliaryMethod::conversionDateIntToString(expenses[i].loadDate())<<endl;
            cout<<expenses[i].loadItem()<<endl;
            cout<<expenses[i].loadAmount()<<endl<<endl;
            suma+=expenses[i].loadAmount();
        }
    }

    return suma;
}
float FinancesManager::showIncomesPenultimateMonth()
{
    float suma=0;
    SYSTEMTIME st;
    GetSystemTime(&st);
    cout<<endl<<">>> PRZYCHODY <<<"<<endl<<endl;
    for (int i=0; i<incomes.size(); i++)
    {
        if((incomes[i].loadDate()>st.wYear*10000+(st.wMonth-1)*100)&&(incomes[i].loadDate()<st.wYear*10000+(st.wMonth)*100))
        {
            //cout<<incomes[i].loadIncomeId()<<endl;
            //cout<<incomes[i].loadUserId()<<endl;
            cout<<AuxiliaryMethod::conversionDateIntToString(incomes[i].loadDate())<<endl;
            cout<<incomes[i].loadItem()<<endl;
            cout<<incomes[i].loadAmount()<<endl<<endl;
            suma+=incomes[i].loadAmount();
        }

    }

    return suma;
}
float FinancesManager::showExpensesPenultimateMonth()
{
    float suma=0;
    SYSTEMTIME st;
    GetSystemTime(&st);
        cout<<endl<<">>> WYDATKI <<<"<<endl<<endl;
    for (int i=0; i<expenses.size(); i++)
    {
        if((expenses[i].loadDate()>st.wYear*10000+(st.wMonth-1)*100)&&(expenses[i].loadDate()<st.wYear*10000+(st.wMonth)*100))
        {
            //cout<<expenses[i].loadExpenseId()<<endl;
            //cout<<expenses[i].loadUserId()<<endl;
            cout<<AuxiliaryMethod::conversionDateIntToString(expenses[i].loadDate())<<endl;
            cout<<expenses[i].loadItem()<<endl;
            cout<<expenses[i].loadAmount()<<endl<<endl;
            suma+=expenses[i].loadAmount();
        }
    }

    return suma;
}
float FinancesManager::showIncomesForChosenDate(int date1, int date2)
{
    float suma=0;

    cout<<endl<<">>> PRZYCHODY <<<"<<endl<<endl;

    for (int i=0; i<incomes.size(); i++)
    {
        if((incomes[i].loadDate()>=date1)&&(incomes[i].loadDate()<=date2))
        {
            //cout<<incomes[i].loadIncomeId()<<endl;
            //cout<<incomes[i].loadUserId()<<endl;
            cout<<AuxiliaryMethod::conversionDateIntToString(incomes[i].loadDate())<<endl;
            cout<<incomes[i].loadItem()<<endl;
            cout<<incomes[i].loadAmount()<<endl<<endl;
            suma+=incomes[i].loadAmount();
        }

    }

    return suma;
}
float FinancesManager::showExpensesForChosenDate(int date1, int date2)
{
    float suma=0;

    cout<<endl<<">>> WYDATKI <<<"<<endl<<endl;

    for (int i=0; i<expenses.size(); i++)
    {
        if((expenses[i].loadDate()>=date1)&&(expenses[i].loadDate()<=date2))
        {
            //cout<<expenses[i].loadIncomeId()<<endl;
            //cout<<expenses[i].loadUserId()<<endl;
            cout<<AuxiliaryMethod::conversionDateIntToString(expenses[i].loadDate())<<endl;
            cout<<expenses[i].loadItem()<<endl;
            cout<<expenses[i].loadAmount()<<endl<<endl;
            suma+=expenses[i].loadAmount();
        }

    }

    return suma;
}
void FinancesManager::balanceCurrenMonth()
{
    float balance=0;
    float sumInc=0;
    float sumExp=0;
    sortingIncomes();
    sumInc=showIncomesCurrentMonth();
    sortingExpenses();
    sumExp=showExpensesCurrentMonth();
    cout<<"SUMA PRZYCHODOW: "<<sumInc<<endl;
    cout<<"SUMA WYDATKOW: "<<sumExp<<endl;
    balance=sumInc-sumExp;
    cout<<"BILANS PRZYCHODOW I WYDATKOW WYNOSI:>>> "<<balance<<" <<<"<<endl;
    system("pause");
}
void FinancesManager::balancePenultimateMonth()
{
    float balance=0;
    float sumInc=0;
    float sumExp=0;
    sortingIncomes();
    sumInc=showIncomesPenultimateMonth();
    sortingExpenses();
    sumExp=showExpensesPenultimateMonth();
    cout<<"SUMA PRZYCHODOW: "<<sumInc<<endl;
    cout<<"SUMA WYDATKOW: "<<sumExp<<endl;
    balance=sumInc-sumExp;
    cout<<"BILANS PRZYCHODOW I WYDATKOW WYNOSI:>>> "<<balance<<" <<<"<<endl;
    system("pause");
}
void FinancesManager::balanceForChosenDate()
{
    float balance=0;
    float sumInc=0;
    float sumExp=0;
    sortingIncomes();
    int date1=0;
    int date2=0;

    cout<<"Podaj zakres z jakiego chcesz zobaczyc bilans (w formacie rrrr-mm-dd):"<<endl;
    cout<<"Podaj poczatek:"<<endl;
    date1=AuxiliaryMethod::conversionDateStringToInt(AuxiliaryMethod::giveDate());

    cout<<"Podaj koniec:"<<endl;
    date2=AuxiliaryMethod::conversionDateStringToInt(AuxiliaryMethod::giveDate());

    sumInc=showIncomesForChosenDate(date1, date2);
    sortingExpenses();
    sumExp=showExpensesForChosenDate(date1, date2);
    cout<<"SUMA PRZYCHODOW: "<<sumInc<<endl;
    cout<<"SUMA WYDATKOW: "<<sumExp<<endl;
    balance=sumInc-sumExp;
    cout<<"BILANS PRZYCHODOW I WYDATKOW WYNOSI:>>> "<<balance<<" <<<"<<endl;
    system("pause");
}
char FinancesManager::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = AuxiliaryMethod::wczytajZnak();

    return wybor;
}
