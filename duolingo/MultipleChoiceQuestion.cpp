#include <string>
#include <vector>
#include "Question.h"
#include "TranslationSet.h"
#include "MultipleChoiceQuestion.h"

MultipleChoiceQuestion::MultipleChoiceQuestion(
    TranslationSet const& target,
    std::vector<TranslationSet> const& possibleAnswers,
    std::string nativeLanguage,
    std::string targetLanguage
): Question(nativeLanguage, targetLanguage), target(target), possibleAnswers(possibleAnswers) { }


std::string MultipleChoiceQuestion::askQuestion() const
{
    std::string question = "Which is the correct translation for: ";
    question += this->target.getTranslationForLanguage(this->nativeLanguage);
    for (int i = 0; i < this->possibleAnswers.size(); i++) {
        question += "\n" + this->possibleAnswers[i].getTranslationForLanguage(this->targetLanguage);
    }
    return question;
}

double MultipleChoiceQuestion::scoreAnswer(std::string answer) const
{
    std::string correctAnswer = this->target.getTranslationForLanguage(this->targetLanguage);
    return correctAnswer == answer ? difficulty : 0;
}
