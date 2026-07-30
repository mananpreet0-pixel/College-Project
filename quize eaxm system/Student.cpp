    #include "Student.h"
    #include "Quiz.h"
    #include<iostream>
    #include <fstream>
    #include <string>
    #include <limits>
    #include <cstdio>
    #include <ctime>
    #include <iomanip>
    #include "FileHelper.h"

    Student::Student():name(""),score(0),rollNumber(0)
    {}

    Student::Student(std::string name,int rollNumber)
    {
        this->name = name;
        this->rollNumber = rollNumber;
        score = 0;
    }
    void Student::takeQuiz(Quiz& quiz)
    {
        score = quiz.startQuiz();
        updateStudent();

        int totalQuestions = std::min(25, quiz.getTotalQuestions());

        saveQuizHistory(totalQuestions);
        exportResult(totalQuestions);
    }
    void Student::viewScore()
    {
        std::cout << "Score: " << score << std::endl;
    }
    void Student::display()
    {
        std::cout<<"Name: "<<name<<std::endl;
        std::cout<<"roll Number: "<<rollNumber<<std::endl;
        std::cout << "Score: " << score << std::endl;
    }
    void Student::saveStudent()
    {
        std::ofstream outFile("students.txt", std::ios::app);

        if(outFile.is_open())
    {
        outFile << username << '\n';
        outFile << userpassword << '\n';
        outFile << name << '\n';
        outFile << rollNumber << '\n';
        outFile << score << '\n';

        outFile.close();
    }
    else
    {
        std::cout << "Error opening file!\n";
    }
    }
    bool Student::loadStudent(std::string username, std::string password)
    {
        std::ifstream inFile("students.txt");
        if (!inFile.is_open())
        {
            std::cout << "Error opening file!\n";
            return false;
        }   
        std::string fileUsername;
        std::string filePassword;
        std::string fileName;
        int fileRollNumber;
        int fileScore;
        while (readStudent(inFile, fileUsername, filePassword,
                   fileName, fileRollNumber, fileScore))
            {
                if (username == fileUsername)
                {
                    if (password == filePassword)
                    {
                        this->username = fileUsername;
                        this->userpassword = filePassword;
                        this->name = fileName;
                        this->rollNumber = fileRollNumber;
                        this->score = fileScore;

                        return true;
                    }
                    else
                    {
                        std::cout << "Invalid password!\n";
                        return false;
                    }
                }
            }

std::cout << "Username not found!\n";
return false;
    }
    void Student::signUp()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (true)
        {
            std::cout << "Enter Username: ";
            std::getline(std::cin, username);

            if (username.empty() || isBlank(username))
            {
                std::cout << "Username cannot be empty.\n";
                continue;
            }

            if (usernameExists(username))
            {
                std::cout << "Username already exists.\n";
                continue;
            }

            break;
        }       

        while(true)
        {
            std::cout<<"Enter Password: ";
            std::getline(std::cin,userpassword);

            if(isStrongPassword(userpassword))
                break;

            std::cout<<"Weak Password!\n";
            std::cout<<"Password must contain:\n";
            std::cout<<"- At least 8 characters\n";
            std::cout<<"- One uppercase letter\n";
            std::cout<<"- One lowercase letter\n";
            std::cout<<"- One digit\n";
            std::cout<<"- One special character\n";
        }
        std::cout << "Enter Name: ";
        while (true)
        {
            std::cout << "Enter Name: ";
            std::getline(std::cin, name);

            if (name.empty() || isBlank(name))
            {
                std::cout << "Name cannot be empty.\n";
                continue;
            }

            break;
        }

    while (true)
        {
            rollNumber = getValidInteger("Enter Roll Number: ");

            if (rollNumber <= 0)
            {
                std::cout << "Invalid Roll Number.\n";
                continue;
            }

            if (rollNumberExists(rollNumber))
            {
                std::cout << "Account already exists for this Roll Number.\n";
                continue;
            }

            break;
        }
        

        score = 0;

        saveStudent();

        std::cout << "Signup Successful!\n";
    }
    bool Student::login()
    {
        std::string username;
        std::string password;

        std::cout << "Username: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;

        return loadStudent(username, password);         
    }
    void Student::menu()
    {
        Quiz quiz;
        quiz.loadFromFile();
        int choice;
        do{
            std::cout << "\n========== STUDENT MENU ==========\n";
            std::cout << "1. Take Quiz\n";
            std::cout << "2. View Score\n";
            std::cout << "3. View Quiz History\n";
            std::cout << "4. Logout\n";
            choice = getValidInteger("Enter your choice: ");    
            switch (choice)
            {
            case 1:
                {
                    score = quiz.startQuiz();
                    updateStudent();
                    saveQuizHistory(quiz.getTotalQuestions());
                    exportResult(quiz.getTotalQuestions());
                    break;
                }
            case 2:
                viewScore();
                break;
            case 3:
                {
                    viewQuizHistory();
                    break;
                }
            case 4:
                std::cout << "Logging out...\n";
                return;
            default:
                std::cout << "Invalid input\n";
                break;
            }

        }while(choice != 4);
    }
    void Student::editProfile()
    {
        std::string oldUsername = username;
        int oldRoll = rollNumber;

        int choice;

        do
        {
            std::cout << "\n====== EDIT PROFILE ======\n";
            std::cout << "1. Username : " << username << '\n';
            std::cout << "2. Password : ********\n";
            std::cout << "3. Name     : " << name << '\n';
            std::cout << "4. Roll No  : " << rollNumber << '\n';
            std::cout << "5. Save & Exit\n";

            std::cout << "Choice: ";
            std::cin >> choice;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch(choice)
            {
            case 1:
            {
                while(true)
                {
                    std::string newUsername;

                    std::cout << "New Username: ";
                    std::getline(std::cin,newUsername);

                    if(newUsername.empty())
                    {
                        std::cout<<"Username cannot be empty.\n";
                        continue;
                    }

                    if(usernameExists(newUsername) &&
                    newUsername != oldUsername)
                    {
                        std::cout<<"Username already exists.\n";
                        continue;
                    }

                    username = newUsername;
                    break;
                }
                break;
            }

            case 2:
            {
                while(true)
                {
                    std::string newPassword;

                    std::cout<<"New Password: ";
                    std::getline(std::cin,newPassword);

                    if(!isStrongPassword(newPassword))
                    {
                        std::cout<<"Weak Password.\n";
                        continue;
                    }

                    userpassword = newPassword;
                    break;
                }

                break;
            }

            case 3:
            {
                std::cout<<"New Name: ";
                std::getline(std::cin,name);
                break;
            }

            case 4:
            {
                while(true)
                {
                    int roll;

                    std::cout<<"New Roll Number: ";
                    std::cin>>roll;

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    if(roll<=0)
                    {
                        std::cout<<"Invalid Roll Number.\n";
                        continue;
                    }

                    if(rollNumberExists(roll) &&
                    roll != oldRoll)
                    {
                        std::cout<<"Roll Number already exists.\n";
                        continue;
                    }

                    rollNumber = roll;
                    break;
                }

                break;
            }

            case 5:
                updateStudent();
                std::cout<<"Profile Updated Successfully.\n";
                return;

            default:
                std::cout<<"Invalid Choice.\n";
            }

        }while(true);
    }
    void Student::updateStudent()
    {
        std::string fileUsername;
        std::string filePassword;
        std::string fileName;
        int fileScore;
        int  fileRollNumber;
        std::ifstream inFile("students.txt");
        if(!inFile.is_open())
        {
            std::cout << "Error opening file!\n";
            return;
        }
        std::ofstream outFile("temp.txt");
        if(!outFile.is_open())
        {
            std::cout << "Error opening file!\n";
            return;
        }

        while (readStudent(inFile, fileUsername, filePassword,
                    fileName, fileRollNumber, fileScore))
        {
            if (fileUsername == this->username && filePassword == this->userpassword)
            {
                outFile << fileUsername << '\n';
                outFile << filePassword << '\n';
                outFile << fileName << '\n';
                outFile << fileRollNumber << '\n';
                outFile << this->score << '\n';
            }
            else
            {
                outFile << fileUsername << '\n';
                outFile << filePassword << '\n';
                outFile << fileName << '\n';
                outFile << fileRollNumber << '\n';
                outFile << fileScore << '\n';
            }
        }
        inFile.close();
        outFile.close();
        remove("students.txt");
        rename("temp.txt", "students.txt");
    }
    bool Student::usernameExists(std::string username)
    {
        std::ifstream inFile("students.txt");
        if(!inFile.is_open())
        {
            return false;
        }
        std::string fileUsername;
        std::string filePassword;
        std::string fileName;
        int fileRollNumber;
        int fileScore;
        
        while (readStudent(inFile, fileUsername, filePassword,
                    fileName, fileRollNumber, fileScore))
        {
            if (fileUsername == username)
                return true;
        }

        return false;   
    }
    bool Student::rollNumberExists(int rollNumber)
    {
        std::ifstream inFile("students.txt");
        if(!inFile.is_open())
        {
            return false;
        }
        std::string fileUsername;
        std::string filePassword;
        std::string fileName;
        int fileRollNumber;
        int fileScore;
        
        while (readStudent(inFile, fileUsername, filePassword,
                    fileName, fileRollNumber, fileScore))
        {
            if (fileRollNumber == rollNumber)
                return true;
        }  
        
        return false;
    }
    void Student::saveQuizHistory(int totalQuestions)
    {
        std::ofstream outFile("QuizHistory.txt", std::ios::app);

        if (!outFile)
            return;

        time_t now = time(nullptr);
        tm* local = localtime(&now);

        outFile << username << '\n';
        outFile << name << '\n';
        outFile << score << "/" << totalQuestions << '\n';
        outFile << std::put_time(local, "%d-%m-%Y %H:%M:%S") << '\n';
        outFile << "-------------------------\n";
    }
    void Student::viewQuizHistory()
    {
        bool found = false;
        std::ifstream inFile("QuizHistory.txt");

        if (!inFile.is_open())
        {
            std::cout << "No quiz history found.\n";
            return;
        }

        std::string fileUsername;
        std::string fileName;
        std::string fileResult;   // "8/10"
        std::string fileDate;
        std::string line;

        while (std::getline(inFile, fileUsername))
        {
            std::getline(inFile, fileName);
            std::getline(inFile, fileResult);   
            std::getline(inFile, fileDate);
            std::getline(inFile, line);       

            if (fileUsername == this->username)
            {
                found = true;

                std::cout << "\n=============================\n";
                std::cout << "Name : " << fileName << '\n';
                std::cout << "Score: " << fileResult << '\n';
                std::cout << "Date : " << fileDate << '\n';
            }
        }

        if (!found)
            std::cout << "No quiz history found.\n";

        inFile.close();
    }
    void Student::exportResult(int totalQuestions)
    {
        std::ofstream outFile("Result_" + std::to_string(rollNumber) + ".txt");

        if(!outFile.is_open())
        {
            std::cout << "Unable to create result file.\n";
            return;
        }

        outFile << "========== QUIZ RESULT ==========\n\n";
        outFile << "Name        : " << name << '\n';
        outFile << "Roll Number : " << rollNumber << '\n';
        outFile << "Score       : " << score << "/" << totalQuestions << '\n';

        if(score >= totalQuestions/2)
            outFile << "\nStatus : PASS\n";
        else
            outFile << "\nStatus : FAIL\n";

        outFile.close();

        std::cout << "Result exported successfully.\n";
    }