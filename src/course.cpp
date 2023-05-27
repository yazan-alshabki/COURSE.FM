#include "course.h"
void Create_course(int doctor_id)
{
    fstream add("course.txt", ios :: in | ios :: out | ios::app);
    add.clear();
    cout<<"Please enter course name :" ;
    string name ;
    cin >> name ;
    cout<<"Please enter course code :" ;
    string code ;
    cin >> code ;
    fstream read("user.txt", ios::app | ios :: out | ios :: in);
    read.clear();

    ifstream in("course-id.txt");
    in.clear();
    int course_id ;
    in >> course_id;
    int new_course_id = course_id + 1;
    in.close();
    add << new_course_id <<" ";
    add << name <<" ";
    add << code <<" ";
    add << doctor_id <<"\n";
    add.close();
    ofstream out("course-id.txt");
    out.clear();
    out << new_course_id;
    out.close();
    doctor_menu(doctor_id);
    return ;
}
void Invite_the_teacher_to_the_course(int doctor_id)
{
    SHOW_USERS();
    fstream invite("invitations.txt", ios :: out | ios :: in | ios :: app );
    invite.clear();
    cout<<"Please enter teacher id :" <<endl;
    int teacher_id;
    cin >> teacher_id;

    VIEW_COURSE();
    cout<<"Please enter course id :" <<endl;
    int  course_id;
    cin >> course_id;

    fstream read("course.txt", ios :: out | ios :: in | ios :: app );
    read.clear();
    int course_id2;
    while(read >> course_id2)
    {
        string name2, code2 ;
        int doctor_id2;
        read >> name2 >> code2 >> doctor_id2 ;
        if(doctor_id2 == doctor_id && course_id2 == course_id)
        {
            goto point;
        }
    }
    read.close();
    cout<<"You can not invite teacher because you are not owner of this course !"<<endl;
    doctor_menu(doctor_id);

point :
    read.close();

    ifstream in("invitations-id.txt");
    in.clear();

    int invitation_id;
    in >> invitation_id;
    int new_invitation_id = invitation_id + 1;
    in.close();

    invite << new_invitation_id << " ";
    invite << doctor_id << " ";
    invite << teacher_id << " ";
    invite << course_id << "\n";
    invite.close();

    ofstream out("invitations-id.txt");
    out.clear();
    out << new_invitation_id ;
    out.close();


    doctor_menu(doctor_id);

    return ;

}
void VIEW_COURSE()
{
    fstream read("course.txt", ios :: in | ios :: out | ios :: app);
    read.clear();
    int course_id;
    while(read >> course_id)
    {
        string course_name, course_code;
        int owner_id;
        read >> course_name >> course_code >> owner_id;
        cout<<"Course id :"<<course_id<<endl;
        cout<<"Course name :"<<course_name<<endl;
        cout<<"Course code :"<<course_code<<endl;
        fstream read2("user.txt", ios :: in | ios :: out | ios :: app);
        read2.clear();
        int id;
        while(read2 >> id)
        {
            string name,family,password, user_name,email, job;
            read2 >> name >> family >> password >> user_name >> email >> job;
            if(id == owner_id)
            {
                cout<<"Owner name :" <<name<<endl;
            }
        }
        read2.close();
        cout<<endl;
    }
    read.close();
    return ;
}

void View_course(int user_id,int who)
{
    fstream read("course.txt", ios :: in | ios :: out | ios :: app);
    read.clear();
    int course_id;
    while(read >> course_id)
    {
        string course_name, course_code;
        int owner_id;
        read >> course_name >> course_code >> owner_id;
        cout<<"Course id :"<<course_id<<endl;
        cout<<"Course name :"<<course_name<<endl;
        cout<<"Course code :"<<course_code<<endl;
        fstream read2("user.txt", ios :: in | ios :: out | ios :: app);
        read2.clear();
        int id;
        while(read2 >> id)
        {
            string name,family,password, user_name,email, job;
            read2 >> name >> family >> password >> user_name >> email >> job;
            if(id == owner_id)
            {
                cout<<"Owner name :" <<name<<endl;
            }
        }
        read2.close();
        cout<<endl;
    }
    read.close();

    if(who==1)
    {
        doctor_menu(user_id);
    }
    else if(who==0)
    {
        teacher_menu(user_id);
    }
    else if(who==2)
    {
        student_menu(user_id);
    }

    return ;


}
void Write_a_post_for_a_course(int user_id, int who)
{
    fstream add("post.txt", ios :: app | ios :: in |ios :: out );
    add.clear();

    VIEW_COURSE();
    cout<<"PLease enter course id :";
    int course_id;
    cin >> course_id;

    if(who)
    {
        fstream read("course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();


        int course_id2;
        while(read >> course_id2)
        {
            string name2, code2 ;
            int doctor_id2;
            read >> name2 >> code2 >> doctor_id2 ;
            if(doctor_id2 == user_id && course_id2 == course_id)
            {
                goto point;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        doctor_menu(user_id);
        return ;

    }
    else
    {
        fstream read("teachers-course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int teacher_id;
        while(read >> teacher_id)
        {
            int course_id2;
            read >> course_id2;

            if(teacher_id == user_id && course_id2 == course_id)
            {
                goto point;
            }
        }

        cout<<"You cant do that because you have not this course !"<<endl;
        teacher_menu(user_id);
        return ;


    }
point :
    cout<<"PLease enter course name :";
    string course_name;
    cin >> course_name;

    cout<<"PLease write a post :";
    string post;
    cin.ignore();
    getline(cin,post,'\n');

    ifstream in("post-id.txt");
    in.clear();
    int post_id;
    in >> post_id;
    int new_post_id = post_id + 1;
    in.close();

    add << new_post_id << " ";
    add << course_id << " ";
    add << course_name << " ";
    add << post << "\n";
    add.close();
    ofstream out("post-id.txt");
    in.clear();
    out << new_post_id;
    out.close();

    if(who)doctor_menu(user_id);
    else teacher_menu(user_id);
    return ;

}
void Show_post_for_a_course(int user_id,int who)
{
    fstream read("post.txt", ios :: app | ios :: in |ios :: out );
    read.clear();

    VIEW_COURSE();
    cout<<"Please enter course id :";
    int course_id;
    cin >> course_id;

    if(who==1)
    {
        fstream read2("course.txt", ios :: out | ios :: in | ios :: app );
        read2.clear();

        int course_id2;
        while(read2 >> course_id2)
        {
            string name2, code2 ;
            int doctor_id2;
            read2 >> name2 >> code2 >> doctor_id2 ;
            if(doctor_id2 == user_id && course_id2 == course_id)
            {
                goto point;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        doctor_menu(user_id);
        return ;
    }
    else if(who==0)
    {
        fstream read("teachers-course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int teacher_id;
        while(read >> teacher_id)
        {
            int course_id2;
            read >> course_id2;

            if(teacher_id == user_id && course_id2 == course_id)
            {
                goto point;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        teacher_menu(user_id);
        return ;
    }
    else
    {
        fstream read("register.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int id2;
        while(read >> id2)
        {
            int student_id2,course_id2;
            read >> student_id2 >> course_id2;

            if(student_id2 == user_id && course_id2 == course_id)
            {
                goto point;
            }
        }
        cout<<"You cant do that because you did not register in this course !"<<endl;
        student_menu(user_id);
        return ;

    }
point :


    int post_number=1;
    int id2;
    while(read >> id2)
    {
        int course_id2;
        string course_name, post_text;
        read >> course_id2 >> course_name;
        getline(read, post_text,'\n');
        if(course_id2 == course_id)
        {
            cout<<"course post "<<post_number<<":"<< post_text<<endl;
            post_number++;
        }

    }
    read.close();
    if(who==1)doctor_menu(user_id);
    else if(who==0)teacher_menu(user_id);
    else student_menu(user_id);
    return;

}

void Add_assignment_on_course(int user_id, int who)
{
    fstream add("assignment.txt", ios :: app | ios :: in |ios :: out );
    add.clear();

    VIEW_COURSE();
    cout<<"PLease enter course id :";
    int course_id;
    cin >> course_id;
    if(who)
    {
        fstream read("course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();

        int course_id2;
        while(read >> course_id2)
        {
            string name2, code2 ;
            int doctor_id2;
            read >> name2 >> code2 >> doctor_id2 ;
            if(doctor_id2 == user_id && course_id2 == course_id)
            {
                goto point;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        doctor_menu(user_id);
        return ;
    }
    else
    {
        fstream read("teachers-course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int teacher_id;
        while(read >> teacher_id)
        {
            int course_id2;
            read >> course_id2;

            if(teacher_id == user_id && course_id2 == course_id)
            {
                goto point;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        teacher_menu(user_id);
        return ;
    }


point :


    cout<<"PLease enter course name :";
    string course_name;
    cin >> course_name;

    cout<<"PLease write an assignment :";
    string assignment;
    cin.ignore();
    getline(cin,assignment,'\n');

    ifstream in("assignment-id.txt");
    in.clear();
    int assignment_id;
    in >> assignment_id;
    int new_assignment_id = assignment_id + 1;
    in.close();

    add << new_assignment_id << " ";
    add << course_id << " ";
    add << course_name << " ";
    add << assignment << "\n";
    add.close();
    ofstream out("assignment-id.txt");
    in.clear();
    out << new_assignment_id;
    out.close();
    if(who)doctor_menu(user_id);
    else teacher_menu(user_id);
    return ;
}
void View_assignment_of_course(int user_id,int who)
{
    fstream read("assignment.txt", ios :: app | ios :: in |ios :: out );
    read.clear();
    VIEW_COURSE();
    cout<<"Please enter course id :";
    int course_id;
    cin >> course_id;
    if(who==1)
    {
        fstream read2("course.txt", ios :: out | ios :: in | ios :: app );
        read2.clear();

        int course_id2;
        while(read2 >> course_id2)
        {
            string name2, code2 ;
            int doctor_id2;
            read2 >> name2 >> code2 >> doctor_id2 ;
            if(doctor_id2 == user_id && course_id2 == course_id)
            {
                goto point;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        doctor_menu(user_id);
        return ;
    }
    else if(who==0)
    {
        fstream read("teachers-course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int teacher_id;
        while(read >> teacher_id)
        {
            int course_id2;
            read >> course_id2;

            if(teacher_id == user_id && course_id2 == course_id)
            {
                goto point;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        teacher_menu(user_id);
        return ;
    }
    else
    {
        fstream read("register.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int id2;
        while(read >> id2)
        {
            int student_id2,course_id2;
            read >> student_id2 >> course_id2;

            if(student_id2 == user_id && course_id2 == course_id)
            {
                goto point;
            }
        }
        cout<<"You cant do that because you did not register in this course !"<<endl;
        student_menu(user_id);
        return ;


    }

point :


    int assignment_number=1;
    int id2;
    while(read >> id2)
    {
        int course_id2;
        string course_name, assignment;
        read >> course_id2 >> course_name;
        getline(read, assignment,'\n');
        if(course_id2 == course_id)
        {
            cout<<"course assignment " << assignment_number<<": " <<"id :"<<id2<<" "<< assignment <<endl;
            assignment_number++;
        }

    }
    read.close();


    if(who==1)doctor_menu(user_id);
    else if(who==0)teacher_menu(user_id);
    else student_menu(user_id);
    return;
}
void VIEW_ASSIGNMENT_OF_COURSE(int course_id)
{
    fstream read("assignment.txt", ios :: app | ios :: in |ios :: out );
    read.clear();

    int assignment_number=1;
    int id2;
    while(read >> id2)
    {
        int course_id2;
        string course_name, assignment;
        read >> course_id2 >> course_name;
        getline(read, assignment,'\n');
        if(course_id2 == course_id)
        {
            cout<<"course assignment " << assignment_number<<": " <<"id :"<<id2<<" "<< assignment <<endl;
            assignment_number++;
        }

    }
    read.close();

}
void Show_solution_in_the_course(int user_id, int who)
{
    fstream read("solution.txt", ios :: app | ios :: in |ios :: out );
    read.clear();


    VIEW_COURSE();
    cout<<"Please enter course id :";
    int course_id;
    cin >> course_id;

    VIEW_ASSIGNMENT_OF_COURSE(course_id);
    cout<<"Please enter assignment id :";
    int assignment_id;
    cin >> assignment_id;

    if(who)
    {
        fstream read2("course.txt", ios :: out | ios :: in | ios :: app );
        read2.clear();

        int course_id2;
        while(read2 >> course_id2)
        {
            string name2, code2 ;
            int doctor_id2;
            read2 >> name2 >> code2 >> doctor_id2 ;
            if(doctor_id2 == user_id && course_id2 == course_id)
            {
                goto point;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        doctor_menu(user_id);
        return ;
    }
    else
    {
        fstream read("teachers-course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int teacher_id;
        while(read >> teacher_id)
        {
            int course_id2;
            read >> course_id2;

            if(teacher_id == user_id && course_id2 == course_id)
            {
                goto point;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        teacher_menu(user_id);
        return ;
    }

point :


    int number_of_solution=1;
    int id2;
    while(read >> id2)
    {
        int course_id2, assignment_id2, student_id2;
        string solution;
        read >> course_id2>> assignment_id2 >> student_id2;
        getline(read, solution,'\n');
        if(course_id2 == course_id && assignment_id2 == assignment_id)
        {
            cout<<"course solution " << number_of_solution<<" ";
            cout<<"id :" << id2<<" ";
            cout<<"student id :"<<student_id2 <<" ";
            cout<<"Assignment id :" <<assignment_id2<<" ";
            cout<<" solution : "<<solution<<endl;
            cout<<"Evaluation : ";

            fstream readfile("evaluation.txt", ios::app |ios::out |ios::in);
            readfile.clear();
            int id3;
            while(readfile >> id3)
            {
                int solution_id3,evaluation3, result3;
                string comment;
                readfile >> solution_id3 >> evaluation3 >> result3 ;
                getline(readfile, comment, '\n');
                if(solution_id3 == id2)
                {
                    cout<<evaluation3 << "/" << result3<<endl;
                }
            }
            readfile.close();
            number_of_solution++;
        }
    }
    read.close();
    if(who)doctor_menu(user_id);
    else teacher_menu(user_id);
    return ;
}
void VIEW_SOLUTION_OF_ASSIGNMENT(int assignment_id)
{
    fstream read("solution.txt", ios :: app | ios :: in |ios :: out );
    read.clear();

    int number_of_solution=1;
    int id2;
    while(read >> id2)
    {
        int course_id2, assignment_id2, student_id2;
        string solution;
        read >> course_id2>> assignment_id2 >> student_id2;
        getline(read, solution,'\n');
        if(assignment_id2 == assignment_id)
        {
            cout<<"course solution " << number_of_solution<<" ";
            cout<<"id :" << id2<<" ";
            cout<<"student id :"<<student_id2 <<" ";
            cout<<"Assignment id :" <<assignment_id2<<" ";
            cout<<" solution : "<<solution<<endl;
            cout<<"Evaluation : ";

            fstream readfile("evaluation.txt", ios::app |ios::out |ios::in);
            readfile.clear();
            int id3;
            while(readfile >> id3)
            {
                int solution_id3,evaluation3, result3;
                string comment;
                readfile >> solution_id3 >> evaluation3 >> result3 ;
                getline(readfile, comment, '\n');
                if(solution_id3 == id2)
                {
                    cout<<evaluation3 << "/" << result3<<endl;
                }
            }
            readfile.close();
            number_of_solution++;
        }
    }
    read.close();

}
void Give_evaluation_of_the_solution_and_add_comment(int user_id, int who)
{
    fstream add("evaluation.txt", ios :: app | ios :: in | ios :: out );
    add.clear();
    VIEW_COURSE();
    cout<<"Please enter course id :";
    int course_id;
    cin >> course_id;
    if(who)
    {
        fstream read("course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int course_id2;
        while(read >> course_id2)
        {
            string name2, code2 ;
            int doctor_id2;
            read >> name2 >> code2 >> doctor_id2 ;
            if(doctor_id2 == user_id && course_id2 == course_id)
            {
                goto point1;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        doctor_menu(user_id);
        return ;
    }
    else
    {
        fstream read("teachers-course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int teacher_id;
        while(read >> teacher_id)
        {
            int course_id2;
            read >> course_id2;

            if(teacher_id == user_id && course_id2 == course_id)
            {
                goto point1;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        teacher_menu(user_id);
        return ;
    }
point1 :

    VIEW_ASSIGNMENT_OF_COURSE(course_id);
    cout<<"Please enter assignment id:"<<endl;
    int assignment_id;
    cin>>assignment_id;

    VIEW_SOLUTION_OF_ASSIGNMENT(assignment_id);
    cout<<"PLease enter solution id :";
    int solution_id;
    cin >> solution_id;

    bool solution_evaluated = 0;
    int id2;
    while(add >> id2)
    {
        int solution_id2, evaluation2, result2;
        string comment;
        add >> solution_id2 >> evaluation2 >> result2;
        getline(add, comment,'\n');
        if( solution_id2 == solution_id )
        {
            solution_evaluated=1;
            break;
        }
    }
    if(solution_evaluated)
    {
        add.clear();
        vector<evaluation>evaluations;
        int id2;
        while(add >> id2)
        {
            int solution_id2, evaluation2,result2;
            string comment;
            add >> solution_id2 >> evaluation2 >> result2;
            getline(add, comment,'\n');
            if(solution_id2 == solution_id)
            {
                continue;
            }
            evaluation evaluation_x;
            evaluation_x.id = id2;
            evaluation_x.solution_id = solution_id2;
            evaluation_x.evaluation = evaluation2;
            evaluation_x.result = result2;
            evaluation_x.comment = comment;
            evaluations.push_back(evaluation_x);
        }
        fstream out("evaluation.txt", ios :: out);
        out.clear();
        for(evaluation evaluation_x : evaluations)
        {
            out << evaluation_x.id <<" ";
            out << evaluation_x.solution_id <<" ";
            out << evaluation_x.evaluation <<" ";
            out << evaluation_x.result <<" ";
            out << evaluation_x.comment <<"\n";
        }
        out.close();

    }

    cout<<"Please enter result :";
    int result;
    cin >> result;

    cout<<"Please enter evaluation :";
    int evaluation;
    cin >> evaluation;



point:
    cout<<"Do you want to write a comment ? "<<endl;
    cout<<"1 - YES "<<endl;
    cout<<"2 - NO "<<endl;
    int number ;
    cin >> number ;
    if(cin.fail() || number > 2 || number < 1)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"You have to enter integer number from [1 to 2 ] " <<endl;
        cout<<endl;
        goto point;
    }
    string comment="";
    if(number == 1)
    {
        cout<<"Write a comment : ";
        cin.ignore();
        getline(cin, comment, '\n');
    }
    ifstream in("evaluation-id.txt");
    in.clear();
    int evaluation_id;
    in >> evaluation_id;
    int new_evaluation_id = evaluation_id + 1;
    in.close();

    add.clear();
    add << new_evaluation_id <<" ";
    add << solution_id <<" ";
    add << evaluation <<" ";
    add << result <<" ";
    add << comment <<"\n";
    add.close();

    ofstream out("evaluation-id.txt");
    out.clear();
    out << new_evaluation_id;
    out.close();

    if(who)doctor_menu(user_id);
    else teacher_menu(user_id);
    return ;
}
void accept_invitation(int teacher_id)
{
    fstream read("invitations.txt", ios::in | ios::out |ios::app );
    read.clear();

    vector<invitaion>invitaions;
    int id;
    while(read >> id)
    {
        int sender_id, invited_person_id, course_id;
        read >> sender_id >> invited_person_id >> course_id;
        if(invited_person_id == teacher_id )
        {
            cout<<"sender id : "<<sender_id <<"  course id :" << course_id << endl;
            cout<<"Are you accept this invitation for teach course "<<course_id<<" !"<<endl;
            cout<<"1 - YES "<<endl;
            cout<<"2 - NO "<<endl;
            int number ;
            cin >> number ;
            if(number == 1)
            {
                fstream add("teachers-course.txt", ios::in | ios::out |ios::app );
                add.clear();
                add << teacher_id <<" ";
                add << course_id << "\n";
                add.close();
                continue;
            }
            invitaion invitation_x;
            invitation_x.id = id;
            invitation_x.sender_id = sender_id;
            invitation_x.invited_person_id = invited_person_id;
            invitation_x.course_id = course_id;
            invitaions.push_back(invitation_x);
        }
    }
    read.close();

    fstream out("invitations.txt", ios::out);
    for(invitaion invitation_x: invitaions)
    {

        out <<invitation_x.id <<" ";
        out <<invitation_x.sender_id <<" ";
        out <<invitation_x.invited_person_id <<" ";
        out <<invitation_x.course_id <<"\n";
    }
    out.close();
    teacher_menu(teacher_id);
    return ;
}

void Show_users(int user_id, int who)
{
    fstream read("user.txt", ios::in | ios::out |ios::app );
    read.clear();
    int id;
    while(read >> id)
    {
        string name;
        string family;
        string password;
        string user_name;
        string email;
        string job;

        read >> name;
        read >> family;
        read >> password;
        read >> user_name;
        read >> email;
        read >> job;

        cout<<"id :"<<id << endl;
        cout<<"name :"<< name<< endl;
        cout<<"family :"<< family<< endl;
        cout<<"user_name :"<< user_name<< endl;
        cout<<"job :"<< job<< endl;
        cout<<"\n";



    }
    if(who == 1)doctor_menu(user_id);
    else if(who == 0) teacher_menu(user_id);
    else student_menu(user_id);

    return ;
}

void Register_in_course(int student_id)
{
    fstream add("register.txt", ios :: app | ios :: in | ios :: out);
    add.clear();

    fstream read("course.txt", ios :: app | ios :: in | ios :: out);
    read.clear();

    bool one_time=0;
    int course_id1;
    while(read >> course_id1)
    {
        string course_name1,course_code1;
        int doctor_id1;
        read >> course_name1 >> course_code1 >> doctor_id1;

        fstream read_from_register("register.txt", ios :: app | ios :: in | ios :: out);
        read_from_register.clear();

        int register_id2;
        bool registered=0;
        while(read_from_register >> register_id2)
        {
            int student_id2, course_id2;
            read_from_register >> student_id2 >> course_id2;
            if(course_id2 == course_id1 && student_id2 == student_id)
            {
                registered=1;
                break;
            }
        }
        if(!registered)
        {
            if(one_time==0)
            {
                cout<<"the courses that you did not register "<<endl;
                one_time=1;
            }
            cout<<"id :"<<course_id1<<" "<<"course :"<<course_name1<<" "<<"code :"<<course_code1<<" "<<"doctor who have the course :"<<doctor_id1<<endl;
        }
        read_from_register.close();

    }
    read.close();
    cout<<"Please enter course id : ";
    int course_id;
    cin>>course_id;


    cout<<"You have to paid 5$ : "<<endl;
    cout<<"1 - agree  "<<endl;
    cout<<"2 - refuse  "<<endl;
    cout<<"choice 1 or 2 "<<endl;
    int number ;
    cin >> number;
    if(number == 2)
    {
        cout<<"You Can not register in this course because you do not paid money ! "<<endl;
        student_menu(student_id);
        return;
    }
    else if(number == 1)
    {
        cout << " Registered !!! , good luck man ..." << endl;

        ifstream in("register-id.txt");
        in.clear();

        int register_id;
        in >> register_id;
        int new_register_id = register_id + 1;
        in .close();

        add << new_register_id <<" " ;
        add << student_id << " ";
        add << course_id << "\n";
        add.close();

        ofstream out("register-id.txt");
        out.clear();
        out << new_register_id;
        out.close();
        student_menu(student_id);
        return ;
    }
}
void Set_solution_on_assignment_in_course(int student_id)
{

    fstream add("solution.txt", ios :: app | ios :: in | ios :: out);
    add.clear();
    VIEW_COURSE();
    cout<<"Please enter course id : ";
    int course_id;
    cin >> course_id;

    fstream read("register.txt", ios :: out | ios :: in | ios :: app );
    read.clear();
    int id2;
    while(read >> id2)
    {
        int student_id2,course_id2;
        read >> student_id2 >> course_id2;

        if(student_id2 == student_id2 && course_id2 == course_id)
        {
            goto point;
        }
    }
    read.close();
    cout<<"You cant do that because you did not register in this course !"<<endl;
    student_menu(student_id);
    return ;
point:
    fstream read_from_assignment_file("assignment.txt", ios :: app | ios :: in |ios :: out );
    read_from_assignment_file.clear();

    map<int,int>submited;
    int assignment_number=1;
    int id3;
    while(read_from_assignment_file >> id3)
    {
        int course_id3;
        string course_name3, assignment3;
        read_from_assignment_file >> course_id3 >> course_name3;
        getline(read_from_assignment_file, assignment3,'\n');
        if(course_id3 == course_id)
        {
            cout<<"id : "<<id3<<" course assignment " << assignment_number<<": " << assignment3 <<endl;

            fstream read("solution.txt", ios::in | ios::app | ios::out);
            read.clear();

            int id2;
            while(read >> id2)
            {
                int course_id2, assignment_id2, student_id2;
                string solution;
                read >> course_id2>> assignment_id2 >> student_id2;
                getline(read, solution,'\n');
                if(course_id2 == course_id && assignment_id2 == id3)
                {
                    if(student_id2 == student_id)
                    {
                        submited[id3]++;
                        cout<<"Assignment id :" <<assignment_id2<<" ";
                        cout<<" solution : "<<solution<<endl;
                        cout<<"Evaluation : ";
                        fstream readfile("evaluation.txt", ios::app |ios::out |ios::in);
                        readfile.clear();
                        int id3;
                        while(readfile >> id3)
                        {
                            int solution_id3,evaluation3, result3;
                            string comment;
                            readfile >> solution_id3 >> evaluation3 >> result3 ;
                            getline(readfile, comment, '\n');
                            if(solution_id3 == id2)
                            {
                                cout<<evaluation3 << "/" << result3<<endl;
                            }
                        }
                        readfile.close();
                    }
                }

            }
            if( !submited[id3] )
            {
                cout<<"Assignment id :" <<id3<<" ";
                cout<<"You  did not submit "<<endl;
            }


            read.close();
            assignment_number++;


        }
    }
    read_from_assignment_file.close();

    cout<<"Please assignment id : ";
    int assignment_id;
    cin >> assignment_id;

    if(submited[assignment_id])
    {
        cout<< "You had been submit "<<endl;
        student_menu(student_id);
        return;
    }
    cout<<"Please enter solution :";
    string solution;
    cin.ignore();
    getline(cin, solution, '\n');

    ifstream in("solution-id.txt");
    in.clear();
    int solution_id;
    in >> solution_id;
    int new_solution_id= solution_id +1;
    in.close();
    add << new_solution_id <<" " ;
    add << course_id <<" " ;
    add << assignment_id << " ";
    add << student_id <<" ";
    add << solution << "\n";
    add.close();
    ofstream out("solution-id.txt");
    out.clear();
    out << new_solution_id;
    out.close();
    student_menu(student_id);
    return;
}

void Grades_report(int student_id)
{
    fstream read("solution.txt", ios::app | ios :: in | ios :: out);
    read.clear();

    long long marks=0;
    long long result=0;

    int solution_id2;
    while(read >> solution_id2)
    {
        int course_id2, assignment_id2,student_id2 ;
        string solution ;
        read >> course_id2 >> assignment_id2 >> student_id2 ;
        getline(read, solution, '\n') ;
        if(student_id2 == student_id)
        {
            cout<<"course id :"<<course_id2<<" "<<" assignment id :"<<assignment_id2<<" solution :"<<solution<<" ";
            fstream readfile("evaluation.txt", ios::app |ios::out |ios::in);
            readfile.clear();
            int id3;
            bool NA=0;
            while(readfile >> id3)
            {
                int solution_id3,evaluation3, result3;
                string comment;
                readfile >> solution_id3 >> evaluation3 >> result3 ;
                getline(readfile, comment, '\n');
                if(solution_id3 == solution_id2)
                {
                    NA=1;
                    cout<<"your mark is : "<<evaluation3 <<"/"<<result3<< " "<<comment << endl;
                    marks += evaluation3;
                    result+=result3;
                }
            }
            if(!NA)cout<<"NA"<<endl;
            readfile.close();
        }
    }
    read.close();
    if(result != 0)cout<<"Your final mark is : " <<marks*(100)/result << "%" <<endl;
    else cout<<"You did not submit any solution " <<endl;
    student_menu(student_id);
    return;
}
void Unregister_from_course(int student_id)
{
    fstream read("register.txt", ios::in | ios::app | ios::out);
    read.clear();

    VIEW_COURSE();
    cout<<"PLease enter the id of course which you unregister : ";
    int course_id;
    cin>>course_id;

    vector<register_request>register_list;
    int id2;
    while(read >> id2)
    {
        int student_id2, course_id2;
        read >> student_id2 >> course_id2;
        if(student_id2 == student_id && course_id2 == course_id)
        {
            continue;
        }
        register_request x;
        x.id == id2;
        x.student_id=student_id2;
        x.course_id = course_id2;
        register_list.push_back(x);
    }
    read.close();
    ofstream out("register.txt");
    out.clear();
    for(register_request x : register_list)
    {
        out << x.id<<" ";
        out << x.student_id<<" ";
        out << x.course_id<<"\n";
    }
    out.clear();


    fstream read2("solution.txt", ios::in | ios::app | ios::out);
    read2.clear();

    vector<solution>solutions;
    int id3;
    while(read2 >> id3)
    {
        int course_id3, assignment_id3, student_id3 ;
        read2 >> course_id3 >> assignment_id3 >> student_id3 ;
        string solution3;
        getline(read2, solution3, '\n');
        if(student_id3 == student_id  && course_id3 == course_id)
        {
            continue;
        }

        solution x;
        x.id=id3;
        x.course_id=course_id3;
        x.assignment_id=assignment_id3;
        x.student_id=student_id3;
        x.solution=solution3;
        solutions.push_back(x);
    }
    read2.close();
    ofstream out2("solution.txt");
    out2.clear();
    for(solution x: solutions)
    {
        out2 << x.id <<" " ;
        out2 << x.course_id <<" " ;
        out2 << x.assignment_id <<" " ;
        out2 << x.student_id <<" " ;
        out2 << x.solution <<"\n";
    }
    out2.close();

    student_menu(student_id);
    return;
}
void SHOW_USERS()
{
    fstream read("user.txt", ios::in | ios::out |ios::app );
    read.clear();

    int id;
    while(read >> id)
    {
        string name;
        string family;
        string password;
        string user_name;
        string email;
        string job;

        read >> name;
        read >> family;
        read >> password;
        read >> user_name;
        read >> email;
        read >> job;

        cout<<"id :"<<id << endl;
        cout<<"name :"<< name<< endl;
        cout<<"family :"<< family<< endl;
        cout<<"user_name :"<< user_name<< endl;
        cout<<"job :"<< job<< endl;
        cout<<"\n";
    }
    return ;
}

void delete_solution_from_assignement(int assignment_id)
{
    fstream read("solution.txt", ios::in | ios::out |ios::app );
    read.clear();

    int id2;
    vector<solution>solutions;
    while(read >> id2)
    {
        int course_id2,assignment_id2, student_id2;
        string solution2;
        read >> course_id2 >> assignment_id2 >> student_id2 ;
        getline(read, solution2,'\n');
        if(assignment_id2 == assignment_id)
        {
            continue;
        }
        solution x;
        x.id=id2;
        x.course_id =course_id2;
        x.assignment_id =assignment_id2;
        x.student_id = student_id2;
        x.solution= solution2;
        solutions.push_back(x);
    }
    read.close();
    ofstream out("solution.txt");
    out.clear();
    for(solution x : solutions)
    {
        out<< x.id<< " ";
        out<< x.course_id<< " ";
        out<< x.assignment_id<< " ";
        out<< x.student_id<< " ";
        out<< x.solution<< "\n";
    }
    out.close();
    return;
}

void delete_an_assignment_from_course(int user_id ,int course_id , int who)
{

    if(who)
    {
        fstream read("course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int course_id2;
        while(read >> course_id2)
        {
            string name2, code2 ;
            int doctor_id2;
            read >> name2 >> code2 >> doctor_id2 ;
            if(doctor_id2 == user_id && course_id2 == course_id)
            {
                goto point1;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        doctor_menu(user_id);
        return ;
    }
    else
    {
        fstream read("teachers-course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int teacher_id;
        while(read >> teacher_id)
        {
            int course_id2;
            read >> course_id2;

            if(teacher_id == user_id && course_id2 == course_id)
            {
                goto point1;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        teacher_menu(user_id);
        return ;
    }
point1 :
    fstream read("assignment.txt", ios::in | ios::out |ios::app );
    read.clear();

    VIEW_COURSE();
    VIEW_ASSIGNMENT_OF_COURSE(course_id);
    cout<<"Please enter assignment id :";
    int assignment_id;
    cin >> assignment_id;

    int id2;
    vector<assignment>assignments;
    while(read >> id2)
    {
        int course_id2 ;
        string course_name2, assignment_text2;
        read >> course_id2 >> course_name2 ;
        getline(read, assignment_text2,'\n');
        if(assignment_id == id2)
        {
            delete_solution_from_assignement(id2);
            continue;
        }
        assignment x;
        x.id=id2;
        x.course_id =course_id2;
        x.course_name =course_name2;
        x.assignment_text = assignment_text2;
        assignments.push_back(x);
    }
    read.close();
    ofstream out("assignment.txt");
    out.clear();
    for(assignment x : assignments)
    {
        out<< x.id<< " ";
        out<< x.course_id<< " ";
        out<< x.course_name<< " ";
        out<< x.assignment_text<< "\n";
    }
    out.close();
    if(who==0)
    {
        teacher_menu(user_id);
    }
    else doctor_menu(user_id);

    return;
}

void delete_assignment_from_course(int user_id ,int course_id , int who)
{

    if(who)
    {
        fstream read("course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int course_id2;
        while(read >> course_id2)
        {
            string name2, code2 ;
            int doctor_id2;
            read >> name2 >> code2 >> doctor_id2 ;
            if(doctor_id2 == user_id && course_id2 == course_id)
            {
                goto point1;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        doctor_menu(user_id);
        return ;
    }
    else
    {
        fstream read("teachers-course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int teacher_id;
        while(read >> teacher_id)
        {
            int course_id2;
            read >> course_id2;

            if(teacher_id == user_id && course_id2 == course_id)
            {
                goto point1;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        teacher_menu(user_id);
        return ;
    }
point1 :
    fstream read("assignment.txt", ios::in | ios::out |ios::app );
    read.clear();

    int id2;
    vector<assignment>assignments;
    while(read >> id2)
    {
        int course_id2 ;
        string course_name2, assignment_text2;
        read >> course_id2 >> course_name2 ;
        getline(read, assignment_text2,'\n');
        if(course_id2 == course_id)
        {
            delete_solution_from_assignement(id2);
            continue;
        }
        assignment x;
        x.id=id2;
        x.course_id =course_id2;
        x.course_name =course_name2;
        x.assignment_text = assignment_text2;
        assignments.push_back(x);
    }
    read.close();
    ofstream out("assignment.txt");
    out.clear();
    for(assignment x : assignments)
    {
        out<< x.id<< " ";
        out<< x.course_id<< " ";
        out<< x.course_name<< " ";
        out<< x.assignment_text<< "\n";
    }
    out.close();
    if(who==0)
    {
        teacher_menu(user_id);
    }
    else doctor_menu(user_id);

    return;
}



void delete_course(int user_id ,int course_id ,int who)
{

    if(who)
    {
        fstream read("course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int course_id2;
        while(read >> course_id2)
        {
            string name2, code2 ;
            int doctor_id2;
            read >> name2 >> code2 >> doctor_id2 ;
            if(doctor_id2 == user_id && course_id2 == course_id)
            {
                goto point1;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        doctor_menu(user_id);
        return ;
    }
    else
    {
        fstream read("teachers-course.txt", ios :: out | ios :: in | ios :: app );
        read.clear();
        int teacher_id;
        while(read >> teacher_id)
        {
            int course_id2;
            read >> course_id2;

            if(teacher_id == user_id && course_id2 == course_id)
            {
                goto point1;
            }
        }
        cout<<"You cant do that because you have not this course !"<<endl;
        teacher_menu(user_id);
        return ;
    }
point1 :
    fstream read("course.txt", ios::in | ios::out |ios::app );
    read.clear();

    int id2;
    vector<course>courses;
    while(read >> id2)
    {
        string name2, code2;
        read >> name2 >> code2 ;
        int doctor_id2;
        read >> doctor_id2;
        if(id2 == course_id)
        {
            fstream read3("assignment.txt", ios::in | ios::out |ios::app );
            read3.clear();

            int id3;
            while(read3 >> id3)
            {
                int course_id3 ;
                string course_name3, assignment_text3;
                read3 >> course_id3 >> course_name3 ;
                getline(read3, assignment_text3,'\n');
                if(course_id3 == course_id)
                {
                    delete_solution_from_assignement(id3);
                    delete_assignment_from_course(user_id ,  course_id3 , who);
                }
            }
            read3.close();
            continue;
        }
        course x;
        x.id=id2;
        x.name =name2;
        x.code =code2;
        x.doctor_id = doctor_id2;
        courses.push_back(x);
    }
    read.close();
    ofstream out("course.txt");
    out.clear();
    for(course x : courses)
    {
        out<< x.id<< " ";
        out<< x.name<< " ";
        out<< x.code<< " ";
        out<< x.doctor_id<< "\n";
    }
    out.close();
    if(who==0)
    {
        teacher_menu(user_id);
    }
    else doctor_menu(user_id);

    return;
}







