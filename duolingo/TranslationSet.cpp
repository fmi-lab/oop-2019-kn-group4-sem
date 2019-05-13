#include "TranslationSet.h"
#include <string>

void TranslationSet::addPhrase(const Phrase& phrase)
{
    for (int i = 0; i < phrases.size(); i++) {
        if (phrase.language == phrases[i].language) {
            phrases[i].text = phrase.text;
            return;
        }
    }
    phrases.push_back(phrase);
}

bool TranslationSet::hasTranslationForLanguage(std::string language) const
{
    for (int i = 0; i < phrases.size(); i++) {
        if (language == phrases[i].language) {
            return true;
        }
    }
    return false;
}
std::string TranslationSet::getTranslationForLanguage(std::string language) const
{
    for (int i = 0; i < phrases.size(); i++) {
        if (language == phrases[i].language) {
            return phrases[i].text;
        }
    }
    return "";
}
