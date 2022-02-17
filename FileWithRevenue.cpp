#include "FileWithRevenue.h"
#include "Markup.h"

bool FileWithRevenue::dopiszAdresataDoPliku(Income income)
{
    CMarkup xml;

    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.loadIncomeId());
    xml.AddElem("UserId", income.loadUserId());
    xml.AddElem("Date", AuxiliaryMethod::conversionDateIntToString(income.loadDate()));
    xml.AddElem("Item", income.loadItem());
    xml.AddElem("Amount", AuxiliaryMethod::conversionFloatToString(income.loadAmount()));
    xml.Save("incomes.xml");
}


vector <Income> FileWithRevenue::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)

{

    Income income;
    vector <Income> incomes;

    CMarkup xml;
    xml.Load( "incomes.xml" );
    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER     plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    while ( xml.FindElem("Income") )
    {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        MCD_STR strUsId = xml.GetData();
        xml.ResetMainPos();

        if(atoi(strUsId.c_str())==idZalogowanegoUzytkownika)
        {

            xml.FindElem( "IncomeId" );
            MCD_STR strInID = xml.GetData();
            income.setIncomeId(atoi(strInID.c_str()));

            xml.FindElem( "UserId" );
            MCD_STR strUsId = xml.GetData();
            income.setUserID(atoi(strUsId.c_str()));

            xml.FindElem( "Date" );
            MCD_STR strDa = xml.GetData();
            income.setDate (AuxiliaryMethod::conversionDateStringToInt(strDa));

            xml.FindElem( "Item" );
            MCD_STR strIt = xml.GetData();
            income.setItem (strIt);

            xml.FindElem( "Amount" );
            MCD_STR strAm = xml.GetData();
            income.setAmount(atof(strAm.c_str()));

            incomes.push_back(income);

            xml.OutOfElem();
        }
        else
            xml.OutOfElem();
    }
    return incomes;
}

int FileWithRevenue::pobierzZPlikuIdOstatniegoAdresata()
{
    int lastIncomeId=0;
    string strLastIncomeId="";
    CMarkup xml;
    xml.Load( "incomes.xml" );
    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER     plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    while ( xml.FindElem("Income") )
    {
        xml.IntoElem();

        xml.FindElem( "IncomeId" );
        MCD_STR strID = xml.GetData();
        strLastIncomeId=strID;

        xml.OutOfElem();
    }
    lastIncomeId=atoi(strLastIncomeId.c_str());

    return lastIncomeId;
}

