#ifndef ADMIN_H
#define ADMIN_H
#include <bits/stdc++.h>
using namespace std;

struct request
{
    int id;
    string name;
    string family;
    string password;
    string user_name;
    string email;
    string job;
};
struct user
{
    int id;
    string name;
    string family;
    string password;
    string user_name;
    string email;
    string job;

};
void admin_menu();
void show_registration_requests();
void request_accept();



#endif // ADMIN_H
