#include "doctest.h"
#include "../TranslationSet.h"
#include <string>
TranslationSet buildHelloSet() {
    TranslationSet hello;
    hello.addPhrase(Phrase{"hello", "en"});
    hello.addPhrase(Phrase{"hola", "es"});
    hello.addPhrase(Phrase{"ciao", "it"});
    return hello;
}
TEST_SUITE("hasTranslationForLanguage") {
    TEST_CASE(" finds translation for language") {
        TranslationSet hello = buildHelloSet();
        bool hasEn = hello.hasTranslationForLanguage("en");
        CHECK(hasEn);
    }

    TEST_CASE("hasTranslationForLanguage recognizes languages that are not available") {
        TranslationSet hello = buildHelloSet();
        bool hasCn = hello.hasTranslationForLanguage("cn");
        CHECK_FALSE(hasCn);
    }

    TEST_CASE("hasTranslationForLanguage works for empty TranslastionSet") {
        TranslationSet empty;
        bool hasEn = empty.hasTranslationForLanguage("en");
        CHECK_FALSE(hasEn);
    }
}
TEST_SUITE("setTranslation") {
    TEST_CASE("works for existing phrases") {
        TranslationSet hello = buildHelloSet();
        hello.setTranslationForLanguage("en", "hi");
        std::string enHello = hello.getTranslationForLanguage("en");
        CHECK(enHello == "hi");
    }
    TEST_CASE("works for phrases not yet in the set") {
        TranslationSet hello = buildHelloSet();
        hello.setTranslationForLanguage("bg", "zdrasti");
        std::string bgHello = hello.getTranslationForLanguage("bg");
        CHECK(bgHello == "zdrasti");
    }
    TEST_CASE("accepts multiple updates") {
        TranslationSet hello = buildHelloSet();
        hello.setTranslationForLanguage("en", "hi");
        hello.setTranslationForLanguage("en", "hi there!");
        std::string enHello = hello.getTranslationForLanguage("en");
        CHECK(enHello == "hi there!");
    }

    TEST_CASE("trims spaces") {
        TranslationSet empty;
        empty.setTranslationForLanguage("en", "   hi ");
        std::string en = empty.getTranslationForLanguage("en");
        CHECK(en == "hi");
    }

    TEST_CASE("does not accept empty string as translation") {
        TranslationSet hello = buildHelloSet();
        hello.setTranslationForLanguage("bg", "");
        bool hasBg = hello.hasTranslationForLanguage("bg");
        CHECK_FALSE(hasBg);
    }

    TEST_CASE("does not accept empty string as language") {
        TranslationSet hello = buildHelloSet();
        hello.setTranslationForLanguage("", "test");
        bool hasEmptyLang = hello.hasTranslationForLanguage("");
        CHECK_FALSE(hasEmptyLang);
    }
}
