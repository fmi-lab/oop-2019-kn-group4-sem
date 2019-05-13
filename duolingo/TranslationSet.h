#ifndef TRANSLATIONSET_H
#define TRANSLATIONSET_H
#include <string>
#include <vector>
struct Phrase {
    std::string text;
    std::string language;
};

class TranslationSet
{
    public:
        void addPhrase(const Phrase& phrase);
        bool hasTranslationForLanguage(std::string language) const;
        std::string getTranslationForLanguage(std::string language) const;
    protected:

    private:
        std::vector<Phrase> phrases;
};

#endif // TRANSLATIONSET_H
