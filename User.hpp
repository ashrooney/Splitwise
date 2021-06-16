#pragma once
#include "bits/stdc++.h"
using namespace std;
class User
{
    string name;
    int userID;
    string emailID;
    string mobileNo;
    public:
    //This is if one wants to create map of User as the key
    friend bool operator < (const User &a, const User &b){
        return a.getName() < b.getName();
    }
    User()=default;
    User(const string &name, const int &id, const string &email, const string &mobile): name(name), userID(id), emailID(email),mobileNo(mobile) {}
    string getName() const{
        return name;
    }
    int getID() const
    {
        return userID;
    }
    string getEmail() const
    {
        return emailID;
    }    
    string getMobile() const
    {
        return mobileNo;
    }
};