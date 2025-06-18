#include "pch.h"
#include "CppUnitTest.h"
#include "../lab81/lab81.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringProcessingTests
{
    TEST_CLASS(StringFunctionTests)
    {
    public:
        TEST_METHOD(TestContainsAllLetters_Iterative_PositiveCase)
        {
            std::string input = "white llama";
            std::string word = "while";
            bool result = containsAllLetters_iterative(input, word);
            Assert::IsTrue(result);
        }

        TEST_METHOD(TestContainsAllLetters_Iterative_NegativeCase)
        {
            std::string input = "hello world";
            std::string word = "while";
            bool result = containsAllLetters_iterative(input, word);
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestContainsAllLetters_Iterative_CaseInsensitive)
        {
            std::string input = "WHITE Llama";
            std::string word = "while";
            bool result = containsAllLetters_iterative(input, word);
            Assert::IsTrue(result);
        }

        TEST_METHOD(TestContainsAllLetters_Iterative_EmptyInput)
        {
            std::string input = "";
            std::string word = "while";
            bool result = containsAllLetters_iterative(input, word);
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestContainsAllLetters_Iterative_EmptyWord)
        {
            std::string input = "some text";
            std::string word = "";
            bool result = containsAllLetters_iterative(input, word);
            Assert::IsTrue(result);  // Empty set is always contained
        }

        TEST_METHOD(TestReplaceWhileWithStars_Iterative_BasicCase)
        {
            std::string input = "replace while with stars";
            std::string expected = "replace *** with stars";
            std::string result = replaceWhileWithStars_iterative(input);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestReplaceWhileWithStars_Iterative_MultipleOccurrences)
        {
            std::string input = "while while while";
            std::string expected = "*** *** ***";
            std::string result = replaceWhileWithStars_iterative(input);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestReplaceWhileWithStars_Iterative_NoWhile)
        {
            std::string input = "no replacement needed";
            std::string expected = "no replacement needed";
            std::string result = replaceWhileWithStars_iterative(input);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestReplaceWhileWithStars_Iterative_WhileAsPartOfWord)
        {
            std::string input = "whilesome text";
            std::string expected = "***some text";
            std::string result = replaceWhileWithStars_iterative(input);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestReplaceWhileWithStars_Iterative_CaseSensitive)
        {
            std::string input = "WHILE While while";
            std::string expected = "WHILE While ***";
            std::string result = replaceWhileWithStars_iterative(input);
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestReplaceWhileWithStars_Iterative_EmptyString)
        {
            std::string input = "";
            std::string expected = "";
            std::string result = replaceWhileWithStars_iterative(input);
            Assert::AreEqual(expected, result);
        }
    };
}