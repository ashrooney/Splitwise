#include "Splitwise.hpp"
using namespace std;
int main()
{
    Splitwise sp;
    User a("Ashish",1,"bhattashish192@gmail.com","7675824625");
    User b("Shailja",2,"shailjab@gmail.com","82XXXXXXX");
    User c("Himanshu",3,"hsvdahiya@gmail.com","95XXXXXX");
    User d("Vipin",4,"varun@gmail.com","8997XXXXX");
    sp.addUser(a);
    sp.addUser(b);
    sp.addUser(c);
    sp.addUser(d);
    vector<User> group={a,b,c,d};

    sp.splitBill(a,"Equal",1000, group);
    sp.showUserStatus(a);
    sp.showUserStatus(b);
    sp.showUserStatus(c);
    sp.showUserStatus(d);

    vector<double> percent ={40,20,20,20};
     sp.splitBill(b,"Percent",1200, group, percent);

    sp.showUserStatus(a);
    sp.showUserStatus(b);
    sp.showUserStatus(c);
    sp.showUserStatus(d);
    vector<double> exact{100,400,600,100};
     sp.splitBill(c,"Exact",1200, group, exact);

      sp.showUserStatus(a);
    sp.showUserStatus(b);
    sp.showUserStatus(c);
    sp.showUserStatus(d);
}