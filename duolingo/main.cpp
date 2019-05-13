#include <iostream>
#include "TranslationSet.h"
#include "TranslationQuestion.h"
#include "MultipleChoiceQuestion.h"
#include "Question.h"
using namespace std;

int main()
{
    TranslationSet hello;
    hello.addPhrase(Phrase{"hello", "en"});
    hello.addPhrase(Phrase{"hola", "es"});
    hello.addPhrase(Phrase{"ciao", "it"});

    TranslationSet bye;
    bye.addPhrase(Phrase{"goodbye", "en"});
    bye.addPhrase(Phrase{"adios", "es"});
    bye.addPhrase(Phrase{"ciao", "it"});

    TranslationSet thanks;
    thanks.addPhrase(Phrase{"thank you", "en"});
    thanks.addPhrase(Phrase{"gracias", "es"});

    cout << hello.getTranslationForLanguage("es") << endl;
    cout << bye.getTranslationForLanguage("es") << endl;

    // Question q("en", "es", 3); // not allowed, Question is an abstract class
    TranslationQuestion q1(hello, "en", "es");
    cout << q1.askQuestion() << endl;
    std::string answer;
    std::getline(cin, answer);
    cout << "Your score on q1 is : " << q1.scoreAnswer(answer) << endl;

    MultipleChoiceQuestion q2(hello, {bye, thanks, hello}, "en", "es");
    cout << q2.askQuestion() << endl;
    std::getline(cin, answer);
    cout << "Your score on q2 is : " << q2.scoreAnswer(answer) << endl;

    return 0;
}
