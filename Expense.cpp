#include"Expense.h"

void Expense::setExpenseId(int noweId)
{
    if(noweId>=0)
    expenseId=noweId;
}
void Expense::setUserID(int noweIdUzytkownika)
{
    userId=noweIdUzytkownika;
}
void Expense::setDate(int newDate)
{
    date=newDate;
}
void Expense::setItem(string newItem)
{
    item=newItem;
}
void Expense::setAmount(float newAmount)
{
    amount=newAmount;
}

int Expense::loadExpenseId()
{
    return expenseId;
}
int Expense::loadUserId()
{
    return userId;
}
int Expense::loadDate()
{
    return date;
}
string Expense::loadItem()
{
    return item;
}
float Expense::loadAmount()
{
    return amount;
}

