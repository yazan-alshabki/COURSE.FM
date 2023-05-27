#include "admin.h"


void show_registration_requests()
{
    fstream show("admin.txt" ,ios::in | ios::out | ios::app);
    show.clear();
    int  request_id;
    while(show >> request_id)
    {
        string name,family , password , user_name ,email , job;
        show >> name >> family >> password >> user_name >> email >> job;
        cout <<request_id <<" "<< name <<" "<< family <<" "<< user_name <<" "<< email <<" "<< job << endl;
    }
    admin_menu();
    return ;
}
void request_accept()
{
    vector<request> requests;
    fstream read("admin.txt" , ios::in | ios::out | ios::app);
    read.clear();

    cout<<"Please enter request id :";
    int request_number ;
    cin >> request_number ;
    int request_id;
    while(read >> request_id)
    {

        string name ,family ,password ,user_name ,email ,job;
        read >> name >> family >> password >> user_name >> email >> job;
        if(request_id == request_number)
        {
            fstream add("user.txt" , ios::in | ios::out | ios::app);
            add.clear();

            ifstream in("user-id.txt");
            in.clear();

            int user_id;
            in >> user_id;

            int new_user_id = user_id + 1;

            add << new_user_id << " ";
            add << name << " ";
            add << family << " ";
            add << password << " ";
            add << user_name << " ";
            add << email << " ";
            add << job << "\n";

            add.close();
            ofstream out("user-id.txt");
            out.clear();

            out << new_user_id ;
            out.close();

        }
        else
        {
            request request_x;
            request_x.id = request_id ;
            request_x.name = name ;
            request_x.family = family ;
            request_x.password = password ;
            request_x.user_name = user_name ;
            request_x.email = email ;
            request_x.job = job ;
            requests.push_back(request_x);
        }

    }
    read.close();
    ofstream out("admin.txt");
    out.clear();
    for(request i : requests)
    {
        out << i.id << " ";
        out << i.name << " ";
        out << i.family << " ";
        out << i.password << " ";
        out << i.user_name << " ";
        out << i.email << " ";
        out << i.job << "\n";
    }
    out.close();
    admin_menu();
    return ;
}
