#ifndef FINANCES_H
#define FINANCES_H

#include <iostream>

using namespace std;
class Finances
{
    int incomeId;
    int userId;
    string date;
    string item;
    float amount;

public:
    Finances(int incomeId=0, int userId=0, string date="", string item="", float amount=0)
    {
        this->incomeId=incomeId;
        this->userId=userId;
        this->date=date;
        this->item=item;
        this->amount=amount;
    }
void setIncomeId(int newIncomeId);
void setUserID(int newUserId);
void setDate(string setDate);
void setItem(string newItem);
void setAmount(float newAmount);

int loadIncomeId();
int loadUserId();
string loadDate();
string loadItem();
float loadAmount();

};
#endif

