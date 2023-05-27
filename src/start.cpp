#include "start.h"
const string admin_password = "1234";
const string admin_name = "yazan";
const string admin_family = "alshabki";

void Login()
{
    fstream in("user.txt", ios::in | ios::out | ios::app);
    in.clear();

    cout<<"Please enter user name : ";
    string name;
    cin >> name ;

    cout<<"Please enter family : ";
    string family;
    cin >>  family;

    cout<<"Please enter password : ";
    string password;
    cin >> password;

    int id;
    while(in >> id)
    {
        string name2 ,family2 , password2 ,user_name2 , email2 , job2;
        in >>name2>> family2 >> password2 >> user_name2 >> email2 >> job2;
        if(name == name2 && family2 == family && password2 == password)
        {
            cout<<"Welcome " << name << " " << family << " . You are logged in "<<endl;
            if(job2 == "doctor")
            {
                doctor_menu(id);
            }
            else if(job2 == "student")
            {
                student_menu(id);
            }
            else if(job2 == "teacher")
            {
                teacher_menu(id);
            }
            return ;
        }
    }
    cout<<"SORRY : USER NAME IS NOT VALID "<<endl;
    return ;
}
void Sign_up()
{
    cout<<"If you want to back click 0 else click any number" <<endl;

    int me;
    cin >> me;
    if(me != 0)
    {
        fstream add( "admin.txt" , ios::in | ios::out | ios::app );
        add.clear();

        cout<<"Please enter name : ";

        string name ;
        cin >> name ;

        cout<<"Please enter family : ";

        string family ;
        cin >> family ;

        cout<<"Please enter password : ";

        string password ;
        cin >> password ;

        cout<<"Please enter user name : ";

        string user_name ;
        cin >> user_name ;

        point:

        cout<<"Please enter email : ";
        string email ;
        cin >> email ;


        string ok  ="@gmail.com";
        string answer = "";

        if(email.size() < 10 )
        {
            cout << "The account must be valid"<<endl;
            cout<<"Like this style ( x )@gmail.com . ' NOTE ': X CAN BE ANY THING "<<endl;
            goto point;
        }
        for(int i = email.size() -1 ; i >= email.size() - 10 ;i--)
        {
            answer += email[i];
        }
        reverse(answer.begin() , answer.end());
        if(answer != ok)
        {
            cout << "The account must be valid"<<endl;
            cout<<"Like this style ( x ).gmail.com . ' NOTE ': X CAN BE ANY THING "<<endl;

            goto point;
        }
        cout<<"Please enter your job :";
        string job;
        cin >> job;

        ifstream in("request-id.txt");
        in.clear();
        int number_of_request;
        in >> number_of_request;
        int new_number_of_request;
        new_number_of_request = number_of_request + 1;
        in.close();
        add << new_number_of_request << " ";
        add << name <<" ";
        add << family <<" ";
        add << password <<" ";
        add << user_name <<" ";
        add << email <<" ";
        add << job <<"\n";
        add.close();
        cout << " Registered, awaiting admin approval " << endl;

        ofstream out("request-id.txt");
        out.clear();
        out << new_number_of_request;
        out.close();

        start();
    }
    else if(me==0)
    {
        start();
    }
}
void Login_for_admin()
{
    cout<<"Please enter your name :";
    string name ;
    cin >> name ;
    cout<<"Please enter your family :";
    string family ;
    cin >> family ;
    cout<<"Please enter your password :";
    string password;
    cin>>password;
    if(name == admin_name && password == admin_password && family == admin_family)
    {
        cout<<"Hello yazan !"<<endl;
        admin_menu();
    }
    else
    {
        cout<<"You are not the admin !!!!"<<endl;
        start();
    }
    return ;
}
void start()
{

    cout<<"1 - Login"<<endl;
    cout<<"2 - Sign up"<<endl;
    cout<<"3 - login for admin"<<endl;
    cout<<"4 - Shutdown system"<<endl;
    cout<<"Enter Choice :";

    int choice ;
    cin >> choice ;
    if(cin.fail() || choice > 4 || choice < 1)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"You have to enter integer number from [1 to 4 ] " <<endl;
        cout<<endl;
        start();
        return;
    }

    if(choice == 1)
    {
        Login();
    }
    else if(choice == 2)
    {
        Sign_up();
    }
    else if(choice == 3)
    {
        Login_for_admin();
    }
    else
    {
        return;
    }
    return ;
}


