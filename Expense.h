#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;
class Expense
{
    int expenseId;
    int userId;
    int date;
    string item;
    float amount;

public:
    Incomes(int incomeId=0, int userId=0, int date=0, string item="", float amount=0)
    {
        this->expenseId=expenseId;
        this->userId=userId;
        this->date=date;
        this->item=item;
        this->amount=amount;
    }
void setExpenseId(int newExpenseId);
void setUserID(int newUserId);
void setDate(int setDate);
void setItem(string newItem);
void setAmount(float newAmount);

int loadExpenseId();
int loadUserId();
int loadDate();
string loadItem();
float loadAmount();

};
#endif

