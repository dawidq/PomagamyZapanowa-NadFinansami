#include"Finances.h"

void Finances::setIncomeId(int noweId)
{
    if(noweId>=0)
    incomeId=noweId;
}
void Finances::setUserID(int noweIdUzytkownika)
{
    userId=noweIdUzytkownika;
}
void Finances::setDate(string newDate)
{
    date=newDate;
}
void Finances::setItem(string newItem)
{
    item=newItem;
}
void Finances::setAmount(float newAmount)
{
    amount=newAmount;
}

int Finances::loadIncomeId()
{
    return incomeId;
}
int Finances::loadUserId()
{
    return userId;
}
string Finances::loadDate()
{
    return date;
}
string Finances::loadItem()
{
    return item;
}
float Finances::loadAmount()
{
    return amount;
}

