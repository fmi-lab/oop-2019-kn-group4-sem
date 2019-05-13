#include <string>
#include "Question.h"
#include "TranslationSet.h"
#include "TranslationQuestion.h"

TranslationQuestion::TranslationQuestion(const TranslationSet& translation, std::string nativeLanguage, std::string targetLanguage)
  : Question(nativeLanguage, targetLanguage, 2), translation(translation) { }

std::string TranslationQuestion::askQuestion() const
{
    return "Translate: " + this->translation.getTranslationForLanguage(this->nativeLanguage);
}

double TranslationQuestion::scoreAnswer(std::string answer) const
{
    std::string correctAnswer = this->translation.getTranslationForLanguage(this->targetLanguage);
    return correctAnswer == answer ? difficulty : 0;
}
