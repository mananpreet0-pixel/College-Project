#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Quiz.h"

class Admin: public User
{
    private:
        Quiz quiz;
        
        std::string adminUsername;
        std::string adminPassword;
    
    public:
        Admin();
        void addQuestion();
        void deleteQuestion(const std::string& q);
        void editQuestion(const std::string& q);
        void searchQuestion(const std::string& q);
        void viewQuestions();
        bool login() override;
        void menu();
        bool questionCheck(std::string& q);
        void viewStudents();
        void searchStudent(int rollNumber);
        void deleteStudent(int rollNumber);
        void editStudent(int rollNumber);
        void leaderboard();
        void saveAdmin();
        bool loadAdmin();
        void editAdminProfile();
        void showStatistics();
        
};

#endif