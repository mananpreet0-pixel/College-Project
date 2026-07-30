#ifndef QUESTION_H
#define QUESTION_H

#include<string>

class Question
{
    private:
        std::string question;
        std::string optionA;
        std::string optionB;
        std::string optionC;
        std::string optionD;
        char correctAnswer;

    public:
        Question();
        Question(std::string question,std::string optionA,
        std::string optionB,
        std::string optionC,
        std::string optionD,
        char correctAnswer);
        std::string getQuestion();
        std::string getOptionA();
        std::string getOptionB();
        std::string getOptionC();
        std::string getOptionD();
        char getCorrectAnswer();
        void display();
        bool checkAnswer(char StudentAnswer);
        
};
#endif