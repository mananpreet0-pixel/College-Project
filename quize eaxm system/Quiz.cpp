#include<iostream>
#include<fstream>
#include "Quiz.h"
#include <vector>
#include <limits>
#include <cctype>
#include <iomanip>

Quiz::Quiz()
{}
void Quiz::shuffleQuestions()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(questions.begin(), questions.end(), g);
}
void Quiz::addQuestion(const Question& q)
{
    questions.emplace_back(q);
}
void Quiz::displayQuestions()
{
    for (int i = 0; i < questions.size(); i++)
    {
        questions[i].display();
        std::cout << std::endl;

    }
}
int Quiz::startQuiz()
{
    shuffleQuestions();

    int score = 0;

    int totalQuestions = std::min(25, static_cast<int>(questions.size()));

    for (int i = 0; i < totalQuestions; i++)
    {
        questions[i].display();

        char answer;

        do
        {
            std::cout << "Enter your answer (A/B/C/D): ";
            std::cin >> answer;

            answer = std::toupper(static_cast<unsigned char>(answer));

            if (answer != 'A' &&
                answer != 'B' &&
                answer != 'C' &&
                answer != 'D')
            {
                std::cout << "Invalid choice! Please enter A, B, C, or D.\n";
            }

        } while (answer != 'A' &&
                 answer != 'B' &&
                 answer != 'C' &&
                 answer != 'D');
        
        if (questions[i].checkAnswer(answer))
        {
            std::cout << "Correct!\n";
            score++;
        }
        else
        {
            std::cout << "Wrong! Correct answer: "
                    << questions[i].getCorrectAnswer() << '\n';
        }
    }
    

    double percentage = (score * 100.0) / totalQuestions;

    std::cout << "Final Score: " << score << "/" << totalQuestions << '\n';
    std::cout << "Percentage: " << std::fixed
            << std::setprecision(2)
            << percentage << "%\n";
    return score;
}
void Quiz::saveToFile()
{
    std::ofstream outFile("Questions.txt");
    if(outFile.is_open())
    {
        for(int i=0;i<questions.size();i++)
        {
            outFile << questions[i].getQuestion() << '\n';
            outFile << questions[i].getOptionA() << '\n';
            outFile << questions[i].getOptionB() << '\n';
            outFile << questions[i].getOptionC() << '\n';
            outFile << questions[i].getOptionD() << '\n';
            outFile << questions[i].getCorrectAnswer() << '\n';
        }
        outFile.close();

    }
    else
    {
        std::cerr <<"Error opening file for writting!" <<std::endl;
    }
}
void Quiz::loadFromFile()
{
    questions.clear();
    std::ifstream inFile("Questions.txt");
    if (!inFile.is_open())
    {
        std::cout << "Error opening file!\n";
        return;
    }
    std::string question;
    std::string optionA;
    std::string optionB;
    std::string optionC;
    std::string optionD;
    char correctAnswer;
    while (getline(inFile, question))
    {
        getline(inFile, optionA);
        getline(inFile, optionB);
        getline(inFile, optionC);
        getline(inFile, optionD);
        inFile >> correctAnswer;
        inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        questions.emplace_back(
        question,
        optionA,
        optionB,
        optionC,
        optionD,
        correctAnswer
        );
    }
    inFile.close();

}
int Quiz::getTotalQuestions() const
{
    return questions.size();
}