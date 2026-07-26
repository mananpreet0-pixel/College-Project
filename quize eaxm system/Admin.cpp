#include<iostream>
#include<fstream>
#include "Admin.h"
#include "Quiz.h"
#include "Student.h"
#include "FileHelper.h"
#include <vector>
#include <cctype>
#include <limits>
#include <string>
#include "FileHelper.h"
#include <vector>
#include <algorithm>
#include <iomanip>


Admin::Admin()
{
   quiz.loadFromFile();
    loadAdmin();

}
void Admin::viewQuestions()
{
    quiz.loadFromFile();

    if (quiz.getTotalQuestions() == 0)
    {
        std::cout << "\nNo questions available.\n";
        return;
    }

    std::cout << "\n========== ALL QUESTIONS ==========\n";
    quiz.displayQuestions();
}
void Admin::addQuestion()
{
    std::string question;
    std::string optionA;
    std::string optionB;
    std::string optionC;
    std::string optionD;
    char correctAnswer;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true)
    {
        std::cout << "Enter Question: ";
        std::getline(std::cin, question);

        if (question.empty() || isBlank(question))
        {
            std::cout << "Question cannot be empty.\n";
            continue;
        }

        if (questionCheck(question))
        {
            std::cout << "Question already exists.\n";
            continue;
        }

        break;
    }

    while (true)
    {
        std::cout << "Enter Option A: ";
        std::getline(std::cin, optionA);

        if (optionA.empty() || isBlank(optionA))
        {
            std::cout << "Option A cannot be empty.\n";
            continue;
        }

        break;
    }

    while (true)
    {
        std::cout << "Enter Option B: ";
        std::getline(std::cin, optionB);

        if (optionB.empty() || isBlank(optionB))
        {
            std::cout << "Option B cannot be empty.\n";
            continue;
        }

        break;
    }

    while (true)
    {
        std::cout << "Enter Option C: ";
        std::getline(std::cin, optionC);

        if (optionC.empty() || isBlank(optionC))
        {
            std::cout << "Option C cannot be empty.\n";
            continue;
        }

        break;
    }

    while (true)
    {
        std::cout << "Enter Option D: ";
        std::getline(std::cin, optionD);

        if (optionD.empty() || isBlank(optionD))
        {
            std::cout << "Option D cannot be empty.\n";
            continue;
        }

        break;
    }

    while (optionA == optionB ||
       optionA == optionC ||
       optionA == optionD ||
       optionB == optionC ||
       optionB == optionD ||
       optionC == optionD)
{
    std::cout << "\nOptions must be different from each other.\n";
    std::cout << "Please re-enter all options.\n\n";

    while (true)
    {
        std::cout << "Enter Option A: ";
        std::getline(std::cin, optionA);

        if (!optionA.empty() && !isBlank(optionA))
            break;

        std::cout << "Option A cannot be empty.\n";
    }

    while (true)
    {
        std::cout << "Enter Option B: ";
        std::getline(std::cin, optionB);

        if (!optionB.empty() && !isBlank(optionB))
            break;

        std::cout << "Option B cannot be empty.\n";
    }

    while (true)
    {
        std::cout << "Enter Option C: ";
        std::getline(std::cin, optionC);

        if (!optionC.empty() && !isBlank(optionC))
            break;

        std::cout << "Option C cannot be empty.\n";
    }

    while (true)
    {
        std::cout << "Enter Option D: ";
        std::getline(std::cin, optionD);

        if (!optionD.empty() && !isBlank(optionD))
            break;

        std::cout << "Option D cannot be empty.\n";
    }
}

    do
    {
        std::cout << "Enter Correct Answer (A/B/C/D): ";
        std::cin >> correctAnswer;

        correctAnswer = std::toupper(static_cast<unsigned char>(correctAnswer));

        if (correctAnswer != 'A' &&
            correctAnswer != 'B' &&
            correctAnswer != 'C' &&
            correctAnswer != 'D')
        {
            std::cout << "Invalid choice! Please enter A, B, C, or D.\n";
        }

    } while (correctAnswer != 'A' &&
             correctAnswer != 'B' &&
             correctAnswer != 'C' &&
             correctAnswer != 'D');

    Question q(question,
               optionA,
               optionB,
               optionC,
               optionD,
               correctAnswer);

    quiz.addQuestion(q);
    quiz.saveToFile();

    std::cout << "\nQuestion added successfully!\n";
}
void Admin::menu()
{
    int choice;

    do
    {
        std::cout << "\n=========================================\n";
        std::cout << "         QUIZ MANAGEMENT SYSTEM\n";
        std::cout << "              ADMIN PANEL\n";
        std::cout << "=========================================\n";

        std::cout << "\n----- Question Management -----\n";
        std::cout << "1. Add Question\n";
        std::cout << "2. View All Questions\n";
        std::cout << "3. Search Question\n";
        std::cout << "4. Edit Question\n";
        std::cout << "5. Delete Question\n";

        std::cout << "\n----- Student Management -----\n";
        std::cout << "6. View All Students\n";
        std::cout << "7. Search Student\n";
        std::cout << "8. Edit Student\n";
        std::cout << "9. Delete Student\n";

        std::cout << "\n----- Reports -----\n";
        std::cout << "10. View Leaderboard\n";

        std::cout << "\n----- Account -----\n";
        std::cout << "11. Edit Admin Profile\n";
        std::cout << "12. Show Statistics\n";
        std::cout << "13. Logout\n";

        std::cout << "\nEnter your choice: ";
        choice = getValidInteger("Enter your choice: ");

        switch (choice)
        {
        case 1:
            addQuestion();
            break;

        case 2:
            viewQuestions();
            break;

        case 3:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::string question;

            std::cout << "Enter question to search: ";
            std::getline(std::cin, question);

            searchQuestion(question);
            break;
        }

        case 4:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::string question;

            std::cout << "Enter question to edit: ";
            std::getline(std::cin, question);

            editQuestion(question);
            break;
        }

        case 5:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::string question;

            std::cout << "Enter question to delete: ";
            std::getline(std::cin, question);

            deleteQuestion(question);
            break;
        }

        case 6:
            viewStudents();
            break;

        case 7:
        {
            int roll;

            std::cout << "Enter Roll Number: ";
            roll = getValidInteger("Enter Roll Number: ");

            searchStudent(roll);
            break;
        }

        case 8:
        {
            int roll;

            std::cout << "Enter Roll Number: ";
            roll = getValidInteger("Enter Roll Number: ");

            editStudent(roll);
            break;
        }

        case 9:
        {
            int roll;

            std::cout << "Enter Roll Number: ";
            roll = getValidInteger("Enter Roll Number: ");

            deleteStudent(roll);
            break;
        }

        case 10:
            leaderboard();
            break;

        case 11:
            editAdminProfile();
            break;

        case 12:
            showStatistics();
            break;
        case 13:
            std::cout << "Logging out...\n";
            return;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }

    } while (choice!=13);
}
bool Admin::loadAdmin()
{
    std::ifstream inFile("admin.txt");

    if(!inFile.is_open())
    {
        std::cout<<"Unable to open admin file.\n";
        return false;
    }

    std::getline(inFile, adminUsername);
    std::getline(inFile, adminPassword);

    inFile.close();

    return true;
}
void Admin::saveAdmin()
{
    std::ofstream outFile("admin.txt");

    if(!outFile.is_open())
    {
        std::cout<<"Unable to open admin file.\n";
        return;
    }

    outFile<<adminUsername<<'\n';
    outFile<<adminPassword<<'\n';

    outFile.close();
}
bool Admin::login()
{
    std::string username;
    std::string password;

    std::cout<<"Username: ";
    std::cin>>username;

    std::cout<<"Password: ";
    std::cin>>password;

    loadAdmin();

    if(username==adminUsername &&
       password==adminPassword)
    {
        return true;
    }

    std::cout<<"Invalid Username or Password.\n";
    return false;
}
void Admin::editAdminProfile()
{
    loadAdmin();

    bool editing=true;

    while(editing)
    {
        std::cout<<"\n========== ADMIN PROFILE ==========\n";
        std::cout<<"1. Username : "<<adminUsername<<'\n';
        std::cout<<"2. Password : ********\n";
        std::cout<<"3. Done\n";

        int choice;

        std::cout<<"Enter choice: ";
        std::cin>>choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        switch(choice)
        {
        case 1:
        {
            std::cout<<"Enter New Username: ";
            std::getline(std::cin,adminUsername);
            break;
        }

        case 2:
        {
            while(true)
            {
                std::cout<<"Enter New Password: ";

                std::getline(std::cin,adminPassword);

                if(isStrongPassword(adminPassword))
                    break;

                std::cout<<"\nWeak Password!\n";
                std::cout<<"Password must contain:\n";
                std::cout<<"- Minimum 8 characters\n";
                std::cout<<"- One uppercase letter\n";
                std::cout<<"- One lowercase letter\n";
                std::cout<<"- One digit\n";
                std::cout<<"- One special character\n\n";
            }

            break;
        }

        case 3:
            editing=false;
            break;

        default:
            std::cout<<"Invalid Choice.\n";
        }
    }

    saveAdmin();

    std::cout<<"\nAdmin Profile Updated Successfully.\n";
}
void Admin::leaderboard()
{
    std::ifstream inFile("students.txt");

    if(!inFile.is_open())
    {
        std::cout << "Unable to open students file.\n";
        return;
    }

    Student student;

    std::vector<StudentRecord> students;

    StudentRecord temp;

    while(readStudent(inFile,
                              temp.username,
                              temp.password,
                              temp.name,
                              temp.rollNumber,
                              temp.score))
    {
        students.push_back(temp);
    }

    inFile.close();

    std::sort(students.begin(), students.end(),
        [](const StudentRecord& a, const StudentRecord& b)
        {
            return a.score > b.score;
        });

    std::cout << "\n========== LEADERBOARD ==========\n\n";

    std::cout
        << std::left
        << std::setw(6)  << "Rank"
        << std::setw(25) << "Name"
        << std::setw(15) << "Roll No"
        << std::setw(10) << "Score"
        << '\n';

    std::cout
        << "-----------------------------------------------------------\n";

    for(size_t i=0;i<students.size();i++)
    {
        std::cout
            << std::setw(6)  << i+1
            << std::setw(25) << students[i].name
            << std::setw(15) << students[i].rollNumber
            << std::setw(10) << students[i].score
            << '\n';
    }
}
bool Admin::questionCheck(std::string& q) 
{
    std::ifstream inFile("Questions.txt");
    std::string question;
    std::string optionA;
    std::string optionB;
    std::string optionC;
    std::string optionD;
    std::string answer;

    while(readQuestion(inFile,
                    question,
                    optionA,
                    optionB,
                    optionC,
                    optionD,
                    answer))
    {
        if(question==q)
            return true;
    }

    return false;
}
void Admin::searchQuestion(const std::string& q)
{
    std::string search = toLower(q);
    std::ifstream inFile("Questions.txt");

    if (!inFile.is_open())
    {
        std::cout << "Unable to open file.\n";
        return;
    }

    std::string question, optionA, optionB, optionC, optionD, answer;

    while (std::getline(inFile, question))
    {
        std::getline(inFile, optionA);
        std::getline(inFile, optionB);
        std::getline(inFile, optionC);
        std::getline(inFile, optionD);
        std::getline(inFile, answer);

        if (toLower(question).find(search) != std::string::npos)
        {
            std::cout << "\nQuestion: " << question << '\n';
            std::cout << "A. " << optionA << '\n';
            std::cout << "B. " << optionB << '\n';
            std::cout << "C. " << optionC << '\n';
            std::cout << "D. " << optionD << '\n';
            std::cout << "Answer: " << answer << '\n';
            return;
        }
    }

    std::cout << "Question not found.\n";
}
void Admin::deleteQuestion(const std::string& q)
{
    std::ifstream inFile("Questions.txt");
    std::ofstream outFile("temp.txt");

    if (!inFile.is_open() || !outFile.is_open())
    {
        std::cout << "Unable to open file.\n";
        return;
    }

    std::string question;
    std::string optionA;
    std::string optionB;
    std::string optionC;
    std::string optionD;
    std::string answer;

    bool found = false;
    bool deleted = false;

    while (readQuestion(inFile,
                        question,
                        optionA,
                        optionB,
                        optionC,
                        optionD,
                        answer))
    {
        if (question == q)
        {
            found = true;

            char confirm;

            do
            {
                std::cout << "\nAre you sure you want to delete this question? (Y/N): ";
                std::cin >> confirm;
                confirm = toupper(confirm);

            } while (confirm != 'Y' && confirm != 'N');

            if (confirm == 'Y')
            {
                deleted = true;
                continue;       // Skip writing this question
            }
        }

        // Write every question except the deleted one
        outFile << question << '\n';
        outFile << optionA << '\n';
        outFile << optionB << '\n';
        outFile << optionC << '\n';
        outFile << optionD << '\n';
        outFile << answer << '\n';
    }

    inFile.close();
    outFile.close();

    remove("Questions.txt");
    rename("temp.txt", "Questions.txt");

    quiz.loadFromFile();

    if (deleted)
        std::cout << "\nQuestion deleted successfully.\n";
    else if (found)
        std::cout << "\nDeletion cancelled.\n";
    else
        std::cout << "\nQuestion not found.\n";
}
void Admin::editQuestion(const std::string& q)
{
    std::ifstream inFile("Questions.txt");
    std::ofstream outFile("temp.txt");

    if (!inFile.is_open() || !outFile.is_open())
    {
        std::cout << "Unable to open file.\n";
        return;
    }

    std::string question;
    std::string optionA;
    std::string optionB;
    std::string optionC;
    std::string optionD;
    std::string answer;

    bool found = false;


    while (readQuestion(inFile,
                        question,
                        optionA,
                        optionB,
                        optionC,
                        optionD,
                        answer))
    {
    std::string oldQuestion = question;
    std::string oldOptionA = optionA;
    std::string oldOptionB = optionB;
    std::string oldOptionC = optionC;
    std::string oldOptionD = optionD;
    std::string oldAnswer = answer;
        if(question == q)
{
    found = true;

    int choice;

    do
    {
        std::cout << "\n========== EDIT QUESTION ==========\n";
        std::cout << "1. Question : " << question << '\n';
        std::cout << "2. Option A : " << optionA << '\n';
        std::cout << "3. Option B : " << optionB << '\n';
        std::cout << "4. Option C : " << optionC << '\n';
        std::cout << "5. Option D : " << optionD << '\n';
        std::cout << "6. Answer   : " << answer << '\n';
        std::cout << "7. Save & Exit\n";

        std::cout << "\nEnter your choice: ";
        choice = getValidInteger("Enter your choice: ");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice)
        {
        case 1:
            std::cout << "Current Question : " << question << '\n';
            std::cout << "Enter New Question: ";
            std::getline(std::cin, question);
            break;

        case 2:
            std::cout << "Current Option A : " << optionA << '\n';
            std::cout << "Enter New Option A: ";
            std::getline(std::cin, optionA);
            break;

        case 3:
            std::cout << "Current Option B : " << optionB << '\n';
            std::cout << "Enter New Option B: ";
            std::getline(std::cin, optionB);
            break;

        case 4:
            std::cout << "Current Option C : " << optionC << '\n';
            std::cout << "Enter New Option C: ";
            std::getline(std::cin, optionC);
            break;

        case 5:
            std::cout << "Current Option D : " << optionD << '\n';
            std::cout << "Enter New Option D: ";
            std::getline(std::cin, optionD);
            break;

        case 6:
        {
            do
            {
                std::cout << "Enter Correct Answer (A/B/C/D): ";
                std::getline(std::cin, answer);

                if(answer.length()==1)
                    answer[0]=toupper(answer[0]);

            }while(answer!="A" &&
                  answer!="B" &&
                  answer!="C" &&
                  answer!="D");

            break;
        }

        case 7:
            char confirm;

            do
            {
                std::cout<<"Save changes? (Y/N): ";
                std::cin>>confirm;
                confirm=toupper(confirm);

            }while(confirm!='Y' && confirm!='N');

            if(confirm=='N')
            {
                question=oldQuestion;
                optionA=oldOptionA;
                optionB=oldOptionB;
                optionC=oldOptionC;
                optionD=oldOptionD;
                answer=oldAnswer;
            }

                break;
            

        default:
            std::cout<<"Invalid Choice!\n";
    }
    

    }while(choice!=7);
}

        outFile << question << '\n';
        outFile << optionA << '\n';
        outFile << optionB << '\n';
        outFile << optionC << '\n';
        outFile << optionD << '\n';
        outFile << answer << '\n';
    }

    inFile.close();
    outFile.close();

    remove("Questions.txt");
    rename("temp.txt", "Questions.txt");

    quiz.loadFromFile();

    if (found)
        std::cout << "\nQuestion updated successfully.\n";
    else
        std::cout << "\nQuestion not found.\n";
}
void Admin::viewStudents()
{
    std::ifstream inFile("students.txt");

    if (!inFile.is_open())
    {
        std::cout << "No students found.\n";
        return;
    }

    std::string username;
    std::string password;
    std::string name;
    int rollNumber;
    int score;

    while (readStudent(inFile,
                                username,
                                password,
                                name,
                                rollNumber,
                                score))
    {
        std::cout << "\n-------------------------\n";
        std::cout << "Name        : " << name << '\n';
        std::cout << "Username    : " << username << '\n';
        std::cout << "Roll Number : " << rollNumber << '\n';
        std::cout << "Score       : " << score << '\n';
    }

    inFile.close();
}
void Admin::searchStudent(int roll)
{
    std::ifstream inFile("students.txt");

    if (!inFile.is_open())
    {
        std::cout << "Unable to open file.\n";
        return;
    }

    std::string username;
    std::string password;
    std::string name;
    int rollNumber;
    int score;

    while (readStudent(inFile,
                       username,
                       password,
                       name,
                       rollNumber,
                       score))
    {
        if (rollNumber == roll)
        {
            std::cout << "\nStudent Found\n";
            std::cout << "Name : " << name << '\n';
            std::cout << "Username : " << username << '\n';
            std::cout << "Roll Number : " << rollNumber << '\n';
            std::cout << "Score : " << score << '\n';
            return;
        }
    }

    std::cout << "Student not found.\n";
}
void Admin::deleteStudent(int roll)
{
    std::ifstream inFile("students.txt");
    std::ofstream outFile("temp.txt");

    if (!inFile.is_open() || !outFile.is_open())
    {
        std::cout << "Unable to open file.\n";
        return;
    }

    std::string username;
    std::string password;
    std::string name;
    int rollNumber;
    int score;

    bool found = false;
    bool deleted = false;

    while (readStudent(inFile,
                       username,
                       password,
                       name,
                       rollNumber,
                       score))
    {
        if (rollNumber == roll)
        {
            found = true;

            char confirm;

            do
            {
                std::cout << "\nAre you sure you want to delete this student? (Y/N): ";
                std::cin >> confirm;
                confirm = toupper(confirm);

            } while (confirm != 'Y' && confirm != 'N');

            if (confirm == 'Y')
            {
                deleted = true;
                continue;      
            }
        }

        outFile << username << '\n';
        outFile << password << '\n';
        outFile << name << '\n';
        outFile << rollNumber << '\n';
        outFile << score << '\n';
    }

    inFile.close();
    outFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (deleted)
        std::cout << "\nStudent deleted successfully.\n";
    else if (found)
        std::cout << "\nDeletion cancelled.\n";
    else
        std::cout << "\nStudent not found.\n";
}
void Admin::editStudent(int roll)
{
    std::ifstream inFile("students.txt");
    std::ofstream outFile("temp.txt");

    if (!inFile.is_open() || !outFile.is_open())
    {
        std::cout << "Unable to open file.\n";
        return;
    }

    Student student;

    std::string username;
    std::string password;
    std::string name;
    int rollNumber;
    int score;

    bool found = false;

    while (readStudent(inFile,
                               username,
                               password,
                               name,
                               rollNumber,
                               score))
    {
        if (rollNumber == roll)
        {
            found = true;

            std::string oldUsername = username;
            std::string oldPassword = password;
            std::string oldName = name;
            int oldRollNumber = rollNumber;
            int oldScore = score;

            int choice;

            do
            {
                std::cout << "\n========== EDIT STUDENT ==========\n";
                std::cout << "1. Username    : " << username << '\n';
                std::cout << "2. Password    : ********\n";
                std::cout << "3. Name        : " << name << '\n';
                std::cout << "4. Roll Number : " << rollNumber << '\n';
                std::cout << "5. Score       : " << score << '\n';
                std::cout << "6. Save & Exit\n";

                std::cout << "\nEnter your choice: ";
                choice = getValidInteger("Enter your choice: ");
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                switch(choice)
                {
                case 1:
                {
                    while(true)
                    {
                        std::cout << "Enter New Username: ";
                        std::getline(std::cin, username);

                        if(username.empty()  || isBlank(username))
                        {
                            std::cout << "Username cannot be empty.\n";
                            continue;
                        }

                        if(student.usernameExists(username) &&
                        username != oldUsername)
                        {
                            std::cout << "Username already exists.\n";
                            continue;
                        }

                        break;
                    }
                    break;
                }

                case 2:
                {
                    while(true)
                    {
                        std::cout << "Enter New Password: ";
                        std::getline(std::cin, password);

                        if(isStrongPassword(password))
                            break;

                        std::cout << "Weak Password!\n";
                    }
                    break;
                }

                case 3:
                {
                    while(true)
                    {
                        std::cout << "Enter New Name: ";
                        std::getline(std::cin, name);

                        if(name.empty() || isBlank(name))
                        {
                            std::cout << "Name cannot be empty.\n";
                            continue;
                        }

                        break;
                    }

                    break;
                }
                case 4:
                {
                    while(true)
                    {
                        std::cout << "Enter New Roll Number: ";
                        rollNumber = getValidInteger("Enter New Roll Number: ");

                        if(rollNumber <= 0)
                        {
                            std::cout << "Invalid Roll Number.\n";
                            continue;
                        }

                        if(student.rollNumberExists(rollNumber) &&
                        rollNumber != oldRollNumber)
                        {
                            std::cout << "Roll Number already exists.\n";
                            continue;
                        }

                        break;
                    }

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                case 5:
                {
                    while(true)
                    {
                        score = getValidInteger("Enter New Score: ");

                        if(score < 0)
                        {
                            std::cout << "Score cannot be negative.\n";
                            continue;
                        }

                        break;
                    }

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                case 6:
                {
                    char confirm;

                    do
                    {
                        std::cout << "\nSave changes? (Y/N): ";
                        std::cin >> confirm;

                        confirm = toupper(confirm);

                    } while(confirm != 'Y' && confirm != 'N');

                    if(confirm == 'N')
                    {
                        username = oldUsername;
                        password = oldPassword;
                        name = oldName;
                        rollNumber = oldRollNumber;
                        score = oldScore;
                    }

                    break;
                }

                default:
                    std::cout << "Invalid Choice!\n";
                }

            } while(choice != 6);
        }

        outFile << username << '\n';
        outFile << password << '\n';
        outFile << name << '\n';
        outFile << rollNumber << '\n';
        outFile << score << '\n';
    }

    inFile.close();
    outFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        std::cout << "\nStudent updated successfully.\n";
    else
        std::cout << "\nStudent not found.\n";
}
void Admin::showStatistics()
{
    std::ifstream studentFile("students.txt");
    std::ifstream questionFile("Questions.txt");

    if (!studentFile.is_open() || !questionFile.is_open())
    {
        std::cout << "Unable to open files.\n";
        return;
    }

    int totalStudents = 0;
    int totalQuestions = 0;
    int highestScore = -1;
    std::string topper = "None";
    int totalScore = 0;

    std::string username;
    std::string password;
    std::string name;
    int rollNumber;
    int score;

    while (readStudent(studentFile,
                       username,
                       password,
                       name,
                       rollNumber,
                       score))
    {
        totalStudents++;
        totalScore += score;

        if (score > highestScore)
        {
            highestScore = score;
            topper = name;
        }
    }

    std::string question;
    std::string optionA;
    std::string optionB;
    std::string optionC;
    std::string optionD;
    std::string answer;

    while (readQuestion(questionFile,
                        question,
                        optionA,
                        optionB,
                        optionC,
                        optionD,
                        answer))
    {
        totalQuestions++;
    }

    double average = 0;

    if (totalStudents > 0)
        average = static_cast<double>(totalScore) / totalStudents;

    std::cout << "\n========== STATISTICS ==========\n\n";

    std::cout << "Total Students : " << totalStudents << '\n';
    std::cout << "Total Questions: " << totalQuestions << '\n';
    std::cout << "Highest Score  : " << highestScore << '\n';
    std::cout << "Topper         : " << topper << '\n';
    std::cout << "Average Score  : " << average << '\n';

    studentFile.close();
    questionFile.close();
}