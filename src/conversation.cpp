#include "conversation.h"

void conversation(int user_id, int who)
{

point:
    fstream read("conversation.txt",ios::in | ios::app | ios::out);
    read.clear();

    SHOW_USERS();

    cout<<"Please enter user id who you want to speak :";
    int id ;
    cin >> id;

    string name="";

    fstream read2("user.txt",ios::in | ios::app | ios::out);
    read2.clear();
    int users_id;
    bool ok=0;
    while(read2 >> users_id)
    {
        string users_name,users_family,users_password,users_user_name,users_email,users_job;
        read2 >> users_name >> users_family >> users_password >> users_user_name >> users_email >> users_job;
        if(users_id == id)
        {
            ok=1;
            name = users_user_name;
            break;
        }
    }
    read2.close();
    if(!ok)
    {
        cout<<"id is not correct !"<<endl;
        goto point;
    }
    int from;
    while(read >> from )
    {
        int to ;
        string massege;
        read >> to;
        getline(read, massege, '\n');
        if(from == user_id && to == id)
        {
            cout<<"ME : "<<massege<<endl;
        }
        if(to == user_id && from == id)
        {
            cout<<name<<" : "<<massege<<endl;
        }
    }
    read.close();
    fstream read3("conversation.txt",ios::in | ios::app | ios::out);
    read3.clear();

point2:
    while(true)
    {

        cout<<"Enter choice :"<<endl;
        cout<<"1 - send massage "<<endl;
        cout<<"2 - back "<<endl;
        int choice;
        cin >> choice;
        if(choice==1)
        {
            cout<<"enter massage "<<endl;
            string massege;
            cin.ignore();
            getline(cin, massege,'\n');
            read3 << user_id <<" ";
            read3 << id <<" ";
            read3 << massege <<"\n";
        }
        else break;
    }
    read3.close();
    if(who == 1)
    {
        doctor_menu(user_id);
    }
    if(who == 0)
    {
        teacher_menu(user_id);
    }
    if(who == 2)
    {
        student_menu(user_id);
    }
    return;



}
