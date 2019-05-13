#ifndef MULTIPLECHOICEQUESTION_H
#define MULTIPLECHOICEQUESTION_H

#include <string>
#include <vector>
#include "Question.h"
#include "TranslationSet.h"

class MultipleChoiceQuestion : public Question
{
    public:
        MultipleChoiceQuestion(TranslationSet const& target,
                               std::vector<TranslationSet> const& possibleAnswers,
                               std::string nativeLanguage,
                               std::string targetLanguage);

        std::string askQuestion() const;
        double scoreAnswer(std::string answer) const;
    protected:

    private:
        TranslationSet target;
        std::vector<TranslationSet> possibleAnswers;
};

#endif // MULTIPLECHOICEQUESTION_H
