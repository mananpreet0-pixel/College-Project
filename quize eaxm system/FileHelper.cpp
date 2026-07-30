#include "FileHelper.h"
#include <limits>
#include <iostream>
#include <cctype>

bool readStudent(std::ifstream& inFile,
                 std::string& username,
                 std::string& password,
                 std::string& name,
                 int& rollNumber,
                 int& score)
{
    if (!std::getline(inFile, username))
        return false;

    std::getline(inFile, password);
    std::getline(inFile, name);

    inFile >> rollNumber;
    inFile >> score;
    inFile.ignore();

    return true;
}

bool isBlank(const std::string& str)
{
    for (char ch : str)
    {
        if (!isspace(static_cast<unsigned char>(ch)))
            return false;
    }
    return true;
}

bool readQuestion(std::ifstream& inFile,
                  std::string& question,
                  std::string& optionA,
                  std::string& optionB,
                  std::string& optionC,
                  std::string& optionD,
                  std::string& answer)
{
    if (!std::getline(inFile, question))
        return false;

    std::getline(inFile, optionA);
    std::getline(inFile, optionB);
    std::getline(inFile, optionC);
    std::getline(inFile, optionD);
    std::getline(inFile, answer);

    return true;
}
bool isStrongPassword(const std::string& password)
{
    if(password.length()<8)
        return false;

    bool upper=false;
    bool lower=false;
    bool digit=false;
    bool special=false;

    for (unsigned char ch : password)
    {
        if (isspace(ch))
            return false;

        if (isupper(ch))
            upper = true;
        else if (islower(ch))
            lower = true;
        else if (isdigit(ch))
            digit = true;
        else
            special = true;
    }

    return upper && lower && digit && special;
}

int getValidInteger(const std::string& message)
{
    int value;

    while (true)
    {
        std::cout << message;

        std::cin >> value;

        if (!std::cin.fail())
        {
            return value;
        }

        std::cout << "Invalid input! Please enter a number.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string toLower(std::string str)
{
    for(char &ch : str)
        ch = std::tolower(static_cast<unsigned char>(ch));

    return str;
}