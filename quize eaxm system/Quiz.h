#ifndef QUIZ_H
#define QUIZ_H

#include "Question.h"
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class Quiz
{
    private:
        std::vector<Question> questions;

    public:
        Quiz();
       void addQuestion(const Question& q);
       void shuffleQuestions();
       void displayQuestions();
       int startQuiz();
       void saveToFile();
       void loadFromFile();
       int getTotalQuestions() const;
        
};
#endif