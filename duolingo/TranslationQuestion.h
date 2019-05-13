#ifndef TRANSLATIONQUESTION_H
#define TRANSLATIONQUESTION_H

#include <string>
#include "Question.h"
#include "TranslationSet.h"

class TranslationQuestion : public Question
{
    public:
        TranslationQuestion(const TranslationSet& translation, std::string nativeLanguage, std::string targetLanguage);
        std::string askQuestion() const;
        double scoreAnswer(std::string answer) const;

    protected:

    private:
        TranslationSet translation;
};

#endif // TRANSLATIONQUESTION_H
