#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;
class Income
{
    int incomeId;
    int userId;
    int date;
    string item;
    float amount;

public:
    Incomes(int incomeId=0, int userId=0, int date=0, string item="", float amount=0)
    {
        this->incomeId=incomeId;
        this->userId=userId;
        this->date=date;
        this->item=item;
        this->amount=amount;
    }
void setIncomeId(int newIncomeId);
void setUserID(int newUserId);
void setDate(int setDate);
void setItem(string newItem);
void setAmount(float newAmount);

int loadIncomeId();
int loadUserId();
int loadDate();
string loadItem();
float loadAmount();

};
#endif

