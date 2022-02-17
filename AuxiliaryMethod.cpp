#include "AuxiliaryMethod.h"

string AuxiliaryMethod::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}
float AuxiliaryMethod::zamienPrzecinekNaKropke(string wartosc)
{

    for(int i=0; i<wartosc.length(); i++)
    {
        if(wartosc[i] == ',')
            wartosc[i] = '.';
    }
float amount = atof(wartosc.c_str());
    return amount;
}

string AuxiliaryMethod::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string AuxiliaryMethod::conversionFloatToString(float liczba)
{
    string s;
    stringstream ss;
    ss.clear();
    ss << liczba;
    ss >> s;
    return s;
}
int AuxiliaryMethod::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;
    return liczbaInt;
}


string AuxiliaryMethod::wczytajLinie()
{
    cin.clear(); cin.sync();
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

char AuxiliaryMethod::wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

int AuxiliaryMethod::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

string AuxiliaryMethod::loadSystemDate()
{
    string date;
    string month;
    string day;
    SYSTEMTIME st;
    GetSystemTime(&st);
    if(st.wMonth<10)
    {
        month=("0"+konwerjsaIntNaString(st.wMonth));
    }
    else
        month=konwerjsaIntNaString(st.wMonth);
    if(st.wDay<10)
    {
        day=("0"+konwerjsaIntNaString(st.wDay));
    }
    else
        day=konwerjsaIntNaString(st.wDay);

    date=(konwerjsaIntNaString(st.wYear)+"-"+month+"-"+day);

    return date;
}
string AuxiliaryMethod::giveDate()
{
    string date;
    string character="-";
    string strMonth="";
    string strDays="";
    string year="";
    int month;
    int days;
    cout<<"Prosze podaj date w formacie rrrr-mm-dd: ";

    do
    {
        cin>>date;
    }
    while(checkDate(date)!=true);

    year=date.substr(0,(date.find(character)));
    date.erase(0,date.find(character)+1);
    month=konwersjaStringNaInt(date.substr(0,(date.find(character))));
    date.erase(0,date.find(character)+1);
    days=konwersjaStringNaInt(date);
    if(month<10)
    {
        strMonth=("0"+konwerjsaIntNaString(month));
    }
    else
        strMonth=konwerjsaIntNaString(month);
    if(days<10)
    {
        strDays=("0"+konwerjsaIntNaString(days));
    }
    else
        strDays=konwerjsaIntNaString(days);

    date=year+"-"+strMonth+"-"+strDays;

    return date;
}

int AuxiliaryMethod::conversionDateStringToInt(string date)
{

    string character="-";
    string strMonth="";
    string strDays="";
    string year="";
    int month;
    int days;
    string newDate="";

    year=date.substr(0,(date.find(character)));
    date.erase(0,date.find(character)+1);
    month=konwersjaStringNaInt(date.substr(0,(date.find(character))));
    date.erase(0,date.find(character)+1);
    days=konwersjaStringNaInt(date);
    if(month<10)
    {
        strMonth=("0"+konwerjsaIntNaString(month));
    }
    else
        strMonth=konwerjsaIntNaString(month);
    if(days<10)
    {
        strDays=("0"+konwerjsaIntNaString(days));
    }
    else
        strDays=konwerjsaIntNaString(days);

    newDate=(year+strMonth+strDays);

    return konwersjaStringNaInt(newDate);
}

string AuxiliaryMethod::conversionDateIntToString(int dateInt)
{

    string dateString="";
    string date;
    dateString=konwerjsaIntNaString(dateInt);
    date=dateString.insert(4,"-");
    date=dateString.insert(7,"-");

    return date;
}

bool AuxiliaryMethod::checkDate(string date)
{
    int month=0;
    int days=0;
    int year=0;
    string character="-";
    year=konwersjaStringNaInt(date.substr(0,(date.find(character))));
    date.erase(0,date.find(character)+1);
    month=konwersjaStringNaInt(date.substr(0,(date.find(character))));
    date.erase(0,date.find(character)+1);
    days=konwersjaStringNaInt(date);
    SYSTEMTIME st;
    GetSystemTime(&st);
    if (year>=2000&&year<st.wYear&&month<13)
    {
        if ((month ==4 || month ==6 || month ==9 || month == 11)&&(days <= 30))
        {
            return true;
        }
        else if (month == 02&&days<30)
        {
            if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))&&(days <= 29))
            {
                return true;
            }
            else if (days <= 28)
            {
                return true;
            }
            else
            {
                cout<<"Niepoprawny dzien! Jezeli jest to rok przestepny ten miesiac liczy 29 dni, w innym wypadku 28!"<<endl;
                return false;
            }
        }
        else if((month !=4 || month !=6 || month !=9 || month != 11|| month != 2)&&(days <= 31))
        {
            return true;
        }
        else
        {
            cout<<"Niepoprawny dzien! Upewnij sie czy dany miesiac ma tyle dni!"<<endl;
            return false;
        }
    }
    else if (year==st.wYear&&month<=st.wMonth)
    {
        if ((month ==4 || month ==6 || month ==9 || month == 11)&&(days <= 30))
        {
            return true;
        }
        else if (month == 02&&days<30)
        {
            if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))&&(days <= 29))
            {
                return true;
            }
            else if (days <= 28)
            {
                return true;
            }
            else
            {
                cout<<"Niepoprawny dzien! Jezeli jest to rok przestepny, ten miesiac liczy 29 dni, w innym wypadku 28!"<<endl;
                return false;
            }
        }
        else if((month !=4 || month !=6 || month !=9 || month != 11|| month != 2)&&(days <= 31))
        {
            return true;
        }
        else
        {
            cout<<"Niepoprawny dzien! Upewnij sie czy dany miesiac ma tyle dni!"<<endl;
            return false;
        }
    }
    else
    {
        cout<<"Niepoprawna data! Wpisz date ponownie!"<<endl;
        return false;
    }
}




