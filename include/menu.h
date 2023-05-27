#ifndef MENU_H
#define MENU_H
#include <bits/stdc++.h>
using namespace std;


void show_registration_requests();
void request_accept();
void start();
void Create_course(int doctor_id);
void Invite_the_teacher_to_the_course(int doctor_id);
void View_course(int user_id , int who);
void Write_a_post_for_a_course(int user_id ,int who);
void Show_post_for_a_course(int user_id , int who);
void Add_assignment_on_course(int user_id , int who);
void View_assignment_of_course(int user_id , int who);
void Show_solution_in_the_course(int user_id , int who);
void Give_evaluation_of_the_solution_and_add_comment(int user_id , int who);
void accept_invitation(int teacher_id);
void Show_users(int user_id , int who );
void Register_in_course(int student_id);
void student_menu(int student_id);
void Unregister_from_course(int student_id);
void Set_solution_on_assignment_in_course(int student_id);
void Grades_report(int student_id);
void Unregister_from_course(int student_id);
void conversation(int user_id , int who);
void delete_an_assignment_from_course(int user_id ,int course_id , int who);
void delete_assignment_from_course(int user_id ,int course_id , int who);
void delete_solution_from_assignement(int assignment_id);
void delete_course(int user_id ,int course_id ,int who);
void VIEW_COURSE();



















#endif // MENU_H
