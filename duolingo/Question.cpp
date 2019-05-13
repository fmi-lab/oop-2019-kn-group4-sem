#include "Question.h"
#include <string>
Question::Question(std::string nativeLanguage, std::string targetLanguage, int difficulty)
  :nativeLanguage(nativeLanguage), targetLanguage(targetLanguage), difficulty(difficulty) { }

Question::~Question() { }

