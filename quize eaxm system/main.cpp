#include <iostream>
#include "Student.h"
#include "Admin.h"

int main()
{
    Admin admin;
    Student student;
    int choice;
    do{
        std::cout << "\n========== QUIZ MANAGEMENT SYSTEM ==========\n";
        std::cout << "1. Admin Login\n";
        std::cout << "2. Student Login\n";
        std::cout << "3. Student Signup\n";
        std::cout << "4. Exit\n";
        std::cout <<"Enter your choice\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            if(admin.login())
            {
                admin.menu();
            }
            break;
        case 2:
            if(student.login())
                {
                    student.menu();
                }
            break;
        case 3:
            student.signUp();
            break;
        case 4:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid input\n";
            break;
        }

    }while(choice != 4);

    return 0;
}
