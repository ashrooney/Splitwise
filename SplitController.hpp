#pragma once
#include "User.hpp"
#include "Expense.hpp"

class SplitController
{
    vector<User> users;
    // string expenseType;
    double amount ;
    vector<double> distribution;
    public:
    SplitController(const vector<User> &users,  const double &amount)
    {
        this->users=users;
        // this->expenseType=expenseType;
        this->amount = amount;
    }
    SplitController(const vector<User> &users,  const double &amount, const vector<double> &distribution)
    {
        this->users=users;
        // this->expenseType=expenseType;
        this->amount = amount;
        this->distribution = distribution;
    }

    double splitEqual()
    {
        
        Equal *eq = new Equal(amount, users.size());
        return eq->distributeEqual();
        
    }
    vector<double> splitPercentage()
    {
        Percent *per = new Percent(amount, distribution);
        return per->distribute();
    }

    bool splitExact()
    {
        Exact *ex = new Exact(amount, distribution);
        if(!ex->distribute())
            return false;
        return true;
    }

};