#include "FileWithExpenses.h"
#include "Markup.h"

bool FileWithExpenses::saveExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExists = xml.Load( "expenses.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.loadExpenseId());
    xml.AddElem("UserId", expense.loadUserId());
    xml.AddElem("Date", AuxiliaryMethod::conversionDateIntToString(expense.loadDate()));
    xml.AddElem("Item", expense.loadItem());
    xml.AddElem("Amount", AuxiliaryMethod::conversionFloatToString(expense.loadAmount()));
    xml.Save("expenses.xml");
}


vector <Expense> FileWithExpenses::wczytajAdresatowZalogowanegoUzytkownikaZPlikuu(int idZalogowanegoUzytkownika)

{

    Expense expense;
    vector <Expense> expenses;

    CMarkup xml;
    xml.Load( "expenses.xml" );
    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER     plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    while ( xml.FindElem("Expense") )
    {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        MCD_STR strUsId = xml.GetData();
        xml.ResetMainPos();

        if(atoi(strUsId.c_str())==idZalogowanegoUzytkownika)
        {

            xml.FindElem( "ExpenseId" );
            MCD_STR strInID = xml.GetData();
            expense.setExpenseId(atoi(strInID.c_str()));

            xml.FindElem( "UserId" );
            MCD_STR strUssId = xml.GetData();
            expense.setUserID(atoi(strUssId.c_str()));

            xml.FindElem( "Date" );
            MCD_STR strDa = xml.GetData();
            expense.setDate (AuxiliaryMethod::conversionDateStringToInt(strDa));

            xml.FindElem( "Item" );
            MCD_STR strIt = xml.GetData();
            expense.setItem (strIt);

            xml.FindElem( "Amount" );
            MCD_STR strAm = xml.GetData();
            expense.setAmount(atoi(strAm.c_str()));

            expenses.push_back(expense);

            xml.OutOfElem();
        }
        else
        xml.OutOfElem();

    }
    return expenses;
}

int FileWithExpenses::pobierzZPlikuIdOstatniegoAdresata()
{
    int lastExpenseId=0;
    string strLastExpenseId="";
    CMarkup xml;
    xml.Load( "expenses.xml" );
    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER     plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    while ( xml.FindElem("Expense") )
    {
        xml.IntoElem();

        xml.FindElem( "ExpenseId" );
        MCD_STR strID = xml.GetData();
        strLastExpenseId=strID;

        xml.OutOfElem();
    }
    lastExpenseId=atoi(strLastExpenseId.c_str());

    return lastExpenseId;
}

