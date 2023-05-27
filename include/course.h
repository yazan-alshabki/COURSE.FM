#ifndef COURSE_H
#define COURSE_H
#include <bits/stdc++.h>
using namespace std;

struct post
{
    int id;
    int course_id;
    string course_name;
    string post_text;
};
struct course
{
    int id ;
    string name;
    string code ;
    int doctor_id;
};
struct invitaion
{
    int id ;
    int sender_id;
    int invited_person_id;
    int course_id;
};
struct assignment
{
    int id ;
    int course_id;
    string course_name;
    string assignment_text;
};
struct solution
{
    int id ;
    int course_id;
    int assignment_id;
    int student_id;
    string solution;
};
struct evaluation
{
    int id ;
    int solution_id;
    int evaluation;
    int result;
    string comment;
};
struct teachers_course
{
    int teacher_id;
    int course_id;
};
struct register_request
{
    int id ;
    int student_id;
    int course_id;
};
void Create_course(int doctor_id);
void doctor_menu(int doctor_id);
void Invite_the_teacher_to_the_course(int doctor_id);
void View_course(int user_id , int who);
void Write_a_post_for_a_course(int user_id ,int who);
void Show_post_for_a_course(int user_id , int who);
void Add_assignment_on_course(int user_id , int who);
void View_assignment_of_course(int user_id , int who);
void Show_solution_in_the_course(int user_id , int who);
void Give_evaluation_of_the_solution_and_add_comment(int user_id , int who);
void teacher_menu(int teacher_id);
void accept_invitation(int teacher_id);
void Show_users(int user_id , int who );
void Register_in_course(int student_id);
void student_menu(int student_id);
void Unregister_from_course(int student_id);
void Set_solution_on_assignment_in_course(int student_id);
void Grades_report(int student_id);
void Unregister_from_course(int student_id);
void SHOW_USERS();
void delete_an_assignment_from_course(int user_id ,int course_id , int who);
void delete_assignment_from_course(int user_id ,int course_id , int who);
void delete_solution_from_assignement(int assignment_id);
void delete_course(int user_id ,int course_id ,int who);
void VIEW_COURSE();
void VIEW_ASSIGNMENT_OF_COURSE(int course_id);

















#endif // COURSE_H
