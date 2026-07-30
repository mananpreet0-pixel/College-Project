#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Quiz.h"
#include<string>

class Student: public User
{
    private:
        std::string name;
        int score;
        int rollNumber;
    public:
        Student();
        Student(std::string name,
        int roll_number);
        void saveStudent();
        bool loadStudent(std::string username, std::string password);
        void display();
        void takeQuiz(Quiz& quiz);
        void viewScore();
        void signUp();
        bool login() override;
        void menu();
        void updateStudent();
        bool usernameExists(std::string username);
        bool rollNumberExists(int rollNumber);
        void saveQuizHistory(int totalQuestions);
        void viewQuizHistory(); 
        void editProfile();
        void exportResult(int totalQuestions);
};
#endif