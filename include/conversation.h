#ifndef CONVERSATION_H
#define CONVERSATION_H
#include <bits/stdc++.h>
using namespace std;
struct conversation
{
    int from;
    int to;
    string massege;
};
void SHOW_USERS();
void conversation(int user_id ,int who);
void doctor_menu(int doctor_id);
void teacher_menu(int teacher_id);
void student_menu(int student_id);


#endif // CONVERSATION_H
