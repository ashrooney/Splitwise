#pragma once
#include<bits/stdc++.h>
#include "SplitController.hpp"
#include "UserDatabase.hpp"
using namespace std;
class Splitwise
{
    SplitController *split;

    public:
    Splitwise()
    {
        // split = nullptr;
    }
    void addUser(const User &user)
    {
        UserDatabase::GetInstance().addMember(user);
    }
    void splitBill(const User &prime, const string &splitType, const double &value, const vector<User> &users)
    {
       
        split = new SplitController(users, value);
        // cout<<"Bill is split equally and every one owes"<<split->splitEqual()<<endl;
        UserDatabase::GetInstance().updateDB(prime, users, split->splitEqual());
        
        
    }
    void splitBill(const User &prime, const string &splitType, const double &value, const vector<User> &users, const vector<double> &distribution)
    {
        if(splitType == "Percent")
        {
            split = new SplitController(users, value, distribution);
            UserDatabase::GetInstance().updateDB(prime, users, split->splitPercentage());
        }
        else if(splitType == "Exact")
        {
            split = new SplitController(users, value, distribution);
            if(split->splitExact())
                UserDatabase::GetInstance().updateDB(prime, users, distribution);

        }
    }
    void showUserStatus(const User &user)
    {
        UserDatabase::GetInstance().displayOwedAmount(user);
    }
};