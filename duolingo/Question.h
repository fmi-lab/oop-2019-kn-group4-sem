#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question
{
    public:
        Question(std::string nativeLanguage, std::string targetLanguage, int difficulty = 1);
        virtual ~Question();
        virtual std::string askQuestion() const = 0;
        virtual double scoreAnswer(std::string answer) const = 0;
    protected:
        int difficulty;
        std::string nativeLanguage;
        std::string targetLanguage;
    private:
};

#endif // QUESTION_H
