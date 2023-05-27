#include "menu.h"

void admin_menu()
{

    cout<<"1 - show registration requests "<<endl;
    cout<<"2 - request accept "<<endl;
    cout<<"3 - Back "<<endl;
    cout<<"Enter Choice :";

    int number ;
    cin >> number;
    if(cin.fail() || number > 3 || number < 1)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"You have to enter integer number from [1 to 3 ] " <<endl;
        cout<<endl;
        admin_menu();
        return;
    }

    if(number == 1)
    {
        show_registration_requests();
    }
    else if(number == 2)
    {
        request_accept();
    }
    else
    {
        start();
    }
    return ;

}
void doctor_menu(int doctor_id)
{
    cout<<"1 - Create course "<<endl;
    cout<<"2 - Invite the teacher to the course " <<endl;
    cout<<"3 - View course "<<endl;
    cout<<"4 - Log out "<<endl;
    cout<<"5 - write a Post for a course "<<endl;
    cout<<"6 - Show post for a course "<<endl;
    cout<<"7 - Add assignment on course "<<endl;
    cout<<"8 - View  assignment of course " <<endl;
    cout<<"9 - Show solution in the course "<<endl;
    cout<<"10 - Give evaluation of the solution and add comment"<<endl;
    cout<<"11 - Show users "<<endl;
    cout<<"12 - conversation "<<endl;
    cout<<"13 - delete assignment "<<endl;
    cout<<"14 - delete course "<<endl;


    cout<<"Enter Choice :";

    int number ;
    cin >> number ;
    if(cin.fail() || number > 14 || number < 1)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"You have to enter integer number from [1 to 11 ] " <<endl;
        cout<<endl;
        doctor_menu(doctor_id);
        return;
    }
    if(number == 1)
    {
        Create_course(doctor_id);
    }
    if(number == 2)
    {
        Invite_the_teacher_to_the_course(doctor_id);
    }
    if(number == 3)
    {
        View_course(doctor_id, 1);
    }
    if(number == 4)
    {
        start();
    }
    if(number == 5)
    {
        Write_a_post_for_a_course(doctor_id, 1);
    }
    if(number == 6)
    {
        Show_post_for_a_course(doctor_id, 1);
    }
    if(number == 7)
    {
        Add_assignment_on_course(doctor_id, 1);
    }
    if(number == 8)
    {
        View_assignment_of_course(doctor_id, 1);
    }
    if(number == 9)
    {
        Show_solution_in_the_course(doctor_id, 1);
    }
    if(number == 10)
    {
        Give_evaluation_of_the_solution_and_add_comment(doctor_id, 1);
    }
    if(number== 11)
    {
        Show_users(doctor_id , 1 );
    }
    if(number == 12)
    {
        conversation(doctor_id, 1);
    }
    if(number == 13)
    {

        VIEW_COURSE();
        cout<<"Please enter course id "<<endl;
        int course_id;
        cin >> course_id;
        delete_an_assignment_from_course(doctor_id ,course_id,1);
    }
    if(number == 14)
    {
        VIEW_COURSE();
        cout<<"Please enter course id "<<endl;
        int course_id;
        cin >> course_id;
        delete_course(doctor_id ,course_id,1);
    }





    return ;
}

void teacher_menu(int teacher_id)
{
    cout<<"1 - View course "<<endl;
    cout<<"2 - Log out "<<endl;
    cout<<"3 - write a Post for a course "<<endl;
    cout<<"4 - Show post for a course "<<endl;
    cout<<"5 - Add assignment on course "<<endl;
    cout<<"6 - View  assignment of course " <<endl;
    cout<<"7 - Show solution in the course "<<endl;
    cout<<"8 - Give evaluation of the solution and add comment"<<endl;
    cout<<"9 - accept invitation " <<endl;
    cout<<"10 - Show users "<<endl;
    cout<<"11 - conversation "<<endl;
    cout<<"12 - delete assignment "<<endl;






    cout<<"Enter Choice :";


    int number ;
    cin >> number ;
    if(cin.fail() || number > 12 || number < 1)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"You have to enter integer number from [1 to 10 ] " <<endl;
        cout<<endl;
        teacher_menu(teacher_id);
        return;
    }
    if(number == 1)
    {
        View_course(teacher_id , 0);
    }
    if(number == 2)
    {
        start();
    }
    if(number == 3)
    {
        Write_a_post_for_a_course(teacher_id, 0);
    }
    if(number == 4)
    {
        Show_post_for_a_course(teacher_id, 0);
    }
    if(number == 5)
    {
        Add_assignment_on_course(teacher_id, 0);
    }
    if(number == 6)
    {
        View_assignment_of_course(teacher_id, 0);
    }
    if(number == 7)
    {
        Show_solution_in_the_course(teacher_id, 0);
    }
    if(number == 8)
    {
        Give_evaluation_of_the_solution_and_add_comment(teacher_id, 0);
    }
    if(number == 9 )
    {
        accept_invitation(teacher_id);
    }
    if(number == 10)
    {
        Show_users(teacher_id , 0 );
    }
    if(number == 11)
    {
        conversation(teacher_id , 0);
    }
    if(number == 12)
    {

        VIEW_COURSE();

        cout<<"Please enter course id "<<endl;
        int course_id;
        cin >> course_id;
        delete_an_assignment_from_course(teacher_id ,course_id,0);

    }
    return ;
}

void student_menu(int student_id)
{
    cout<<"Please make a choice : "<<endl;
    cout<<"1 - Register in Course "<<endl;
    cout<<"2 - view Course "<<endl;
    cout<<"3 - Grades Report "<<endl;
    cout<<"4 - Log out "<<endl;
    cout<<"5 - unregister "<<endl;
    cout<<"6 - set solution on assignment in course "<<endl;
    cout<<"7 - show post for a course "<<endl;
    cout<<"8 - View assignment of course "<<endl;
    cout<<"9 - show users "<<endl;
    cout<<"10 - conversation "<<endl;






    int number ;
    cin >> number ;
    if(cin.fail() || number > 10 || number < 1)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"You have to enter integer number from [1 to 8 ] " <<endl;
        cout<<endl;
        student_menu(student_id);
        return;
    }
    if(number == 1)
    {
        Register_in_course(student_id);
    }
    if(number == 2)
    {
        View_course(student_id , 2);
    }
    if(number == 3)
    {
       Grades_report(student_id);
    }
    if(number == 4)
    {
        start();
    }
    if(number == 5)
    {
        Unregister_from_course(student_id);
    }
    if(number == 6)
    {
        Set_solution_on_assignment_in_course(student_id);
    }
    if(number == 7 )
    {
        Show_post_for_a_course(student_id , 2);
    }
    if(number == 8 )
    {
        View_assignment_of_course(student_id , 2);
    }
    if(number == 9 )
    {
        Show_users(student_id , 2);
    }
    if(number == 10)
    {
        conversation(student_id, 2);
    }
    return;
}


