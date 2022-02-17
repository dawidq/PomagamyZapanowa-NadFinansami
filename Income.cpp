#include"Income.h"

void Income::setIncomeId(int noweId)
{
    if(noweId>=0)
    incomeId=noweId;
}
void Income::setUserID(int noweIdUzytkownika)
{
    userId=noweIdUzytkownika;
}
void Income::setDate(int newDate)
{
    date=newDate;
}
void Income::setItem(string newItem)
{
    item=newItem;
}
void Income::setAmount(float newAmount)
{
    amount=newAmount;
}

int Income::loadIncomeId()
{
    return incomeId;
}
int Income::loadUserId()
{
    return userId;
}
int Income::loadDate()
{
    return date;
}
string Income::loadItem()
{
    return item;
}
float Income::loadAmount()
{
    return amount;
}

