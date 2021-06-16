#pragma once
#include<bits/stdc++.h>
#include "User.hpp"
using namespace std;
class UserDatabase
{
    vector<User> users;
     map<pair<string, double>, map<pair<string, double>, double>> oweList;
    //  map<User, double> tryMap;
    //  map<double, User> oweList;
    // UserDatabase() : users(), oweList()
    // {
        
       
    // }
    // UserDatabase();
    public:
    
    static UserDatabase& GetInstance()
    {
        static UserDatabase* memsearch = new UserDatabase;
        return *memsearch;
    }
    void addMember(User user)
    {
        users.push_back(user);
        
    }
    void updateDB(const User &prime, const vector<User> &users, double splitValue)
    {
        auto tempMap = oweList[make_pair(prime.getName(), prime.getID())];
        for(auto user:users)
        {
            if(user.getName() == prime.getName() && user.getID() == prime.getID()) continue;
            // oweList[prime][user] += splitValue;
            tempMap[make_pair(user.getName(), user.getID())] += splitValue; 
            auto tmp = oweList[make_pair(user.getName(), user.getID())];
            tmp[make_pair(prime.getName(), prime.getID())]-=splitValue;

            
            
            oweList[make_pair(user.getName(), user.getID())] = tmp;
        }
        oweList[make_pair(prime.getName(), prime.getID())] = tempMap;
    }

    void updateDB(const User &prime, const vector<User> &users, const vector<double> &distribution)
    {
        auto tempMap = oweList[make_pair(prime.getName(), prime.getID())];
        for(int i = 0; i<distribution.size();i++)
        {
            if(users[i].getName() == prime.getName() && users[i].getID() == prime.getID()) continue;
            tempMap[make_pair(users[i].getName(), users[i].getID())] += distribution[i]; 
            auto tmp = oweList[make_pair(users[i].getName(), users[i].getID())];
            tmp[make_pair(prime.getName(), prime.getID())]-=distribution[i];
            oweList[make_pair(users[i].getName(), users[i].getID())] = tmp;
        }
        
        oweList[make_pair(prime.getName(), prime.getID())] = tempMap;
    }
    void displayOwedAmount(User user)
    {
        for(auto it:oweList[make_pair(user.getName(), user.getID())])
        {
            cout<<user.getName()<<" owes Rs "<<(-1*it.second)<<" to "<<it.first.first<<endl;
        }
    }
};