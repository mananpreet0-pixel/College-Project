#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <fstream>
#include <string>

bool isBlank(const std::string& str);
bool readStudent(std::ifstream& inFile,
                 std::string& username,
                 std::string& password,
                 std::string& name,
                 int& rollNumber,
                 int& score);

bool readQuestion(std::ifstream& inFile,
                  std::string& question,
                  std::string& optionA,
                  std::string& optionB,
                  std::string& optionC,
                  std::string& optionD,
                  std::string& answer);
bool isStrongPassword(const std::string& password);

int getValidInteger(const std::string& message);

std::string toLower(std::string str);

struct StudentRecord
{
    std::string username;
    std::string password;
    std::string name;
    int rollNumber;
    int score;
};

#endif