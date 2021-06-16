#pragma once
#include<bits/stdc++.h>
using namespace std;
class Expense
{
    protected:
    double amount;
    public:
    Expense(const double &amount) : amount(amount){}

};
class Equal : public Expense{
    int n;
    public:
    Equal(const double &amount, const int& n) : Expense(amount){
        this->n = n;
    }
    int distributeEqual()
    {
        return amount/n;
    }
};
class Percent : public Expense{
    vector<double> percentages;
    vector<double> percentSplit;
    public:
    Percent(const double &amount, const vector<double>& per) : Expense(amount){
        this->percentages = per;
    }
    vector<double> distribute()
    {
        for(auto per:percentages)
        {
            double val = per*amount/100;
            percentSplit.push_back(val);

        }
        return percentSplit;
    }
};
class Exact : public Expense{
    vector<double> exactValues;
    int totalValue;
    public:
    Exact(const double &amount, const vector<double>& values) : Expense(amount){
        this->exactValues = values;
        this->totalValue = 0;
    }
    bool distribute()
    {
        for(auto per:exactValues)
        {
            totalValue+=per;

        }
        return totalValue==amount;
    }
};