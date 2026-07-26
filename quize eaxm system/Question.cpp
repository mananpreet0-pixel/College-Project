#include "Question.h"
#include <string>
#include <iostream>

Question::Question():question(""),optionA(""),optionB(""),optionC(""),optionD(""),correctAnswer('\0')
{}

Question::Question(std::string question,
        std::string optionA,
        std::string optionB,
        std::string optionC,
        std::string optionD,
        char correctAnswer)
{
    this->question = question;
    this->optionA = optionA;
    this->optionB = optionB;
    this->optionC = optionC;
    this->optionD = optionD;
    this->correctAnswer=correctAnswer;
}
void Question::display()
{
    std::cout << "Question: " << question << '\n';
    std::cout << "A. " << optionA << '\n';
    std::cout << "B. " << optionB << '\n';
    std::cout << "C. " << optionC << '\n';
    std::cout << "D. " << optionD << '\n';
}
bool Question::checkAnswer(char studentAnswer)
{
    return studentAnswer == correctAnswer;
}
std::string Question::getQuestion()
{
    return question;
}
std::string Question::getOptionA()
{
    return optionA;
}
std::string Question::getOptionB()
{
    return optionB;
}
std::string Question::getOptionC()
{
    return optionC;
}
std::string Question::getOptionD()
{
    return optionD;
}
char Question::getCorrectAnswer()
{
    return correctAnswer;
}