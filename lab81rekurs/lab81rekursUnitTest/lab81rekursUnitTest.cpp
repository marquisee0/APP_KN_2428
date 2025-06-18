#include "pch.h"
#include "CppUnitTest.h"
#include "../lab81rekurs/lab81rekurs.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringProcessingTests
{
    TEST_CLASS(RecursiveStringFunctionTests)
    {
    public:
        // Tests for containsAllLetters_recursive
        TEST_METHOD(TestContainsAllLetters_Recursive_PositiveCase)
        {
            std::string input = "white llama";
            std::string word = "while";
            bool result = containsAllLetters_recursive(input, word);
            Assert::IsTrue(result);
        }

        TEST_METHOD(TestContainsAllLetters_Recursive_NegativeCase)
        {
            std::string input = "hello world";
            std::string word = "while";
            bool result = containsAllLetters_recursive(input, word);
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestContainsAllLetters_Recursive_CaseInsensitive)
        {
            std::string input = "WHITE Llama";
            std::string word = "while";
            bool result = containsAllLetters_recursive(input, word);
            Assert::IsTrue(result);
        }

        TEST_METHOD(TestContainsAllLetters_Recursive_EmptyInput)
        {
            std::string input = "";
            std::string word = "while";
            bool result = containsAllLetters_recursive(input, word);
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestContainsAllLetters_Recursive_EmptyWord)
        {
            std::string input = "some text";
            std::string word = "";
            bool result = containsAllLetters_recursive(input, word);
            Assert::IsTrue(result);  // Empty set is always contained
        }

        TEST_METHOD(TestContainsAllLetters_Recursive_DuplicateLetters)
        {
            std::string input = "whhiillee";
            std::string word = "while";
            bool result = containsAllLetters_recursive(input, word);
            Assert::IsTrue(result);
        }

        // Tests for replaceWhileWithStars_recursive
        TEST_METHOD(TestReplaceWhileWithStars_Recursive_BasicCase)
        {
            std::string input = "replace while with stars";
            std::string expected = "replace *** with stars";
            std::string result = replaceWhileWithStars_recursive(input, "while");
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestReplaceWhileWithStars_Recursive_MultipleOccurrences)
        {
            std::string input = "while while while";
            std::string expected = "*** *** ***";
            std::string result = replaceWhileWithStars_recursive(input, "while");
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestReplaceWhileWithStars_Recursive_NoWhile)
        {
            std::string input = "no replacement needed";
            std::string expected = "no replacement needed";
            std::string result = replaceWhileWithStars_recursive(input, "while");
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestReplaceWhileWithStars_Recursive_WhileAsPartOfWord)
        {
            std::string input = "whilesome text";
            std::string expected = "***some text";
            std::string result = replaceWhileWithStars_recursive(input, "while");
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestReplaceWhileWithStars_Recursive_CaseSensitive)
        {
            std::string input = "WHILE While while";
            std::string expected = "WHILE While ***";
            std::string result = replaceWhileWithStars_recursive(input, "while");
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestReplaceWhileWithStars_Recursive_EmptyString)
        {
            std::string input = "";
            std::string expected = "";
            std::string result = replaceWhileWithStars_recursive(input, "while");
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestReplaceWhileWithStars_Recursive_CustomTarget)
        {
            std::string input = "replace test with stars";
            std::string expected = "replace *** with stars";
            std::string result = replaceWhileWithStars_recursive(input, "test");
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestReplaceWhileWithStars_Recursive_OverlappingMatches)
        {
            std::string input = "whilewhile";
            std::string expected = "******";
            std::string result = replaceWhileWithStars_recursive(input, "while");
            Assert::AreEqual(expected, result);
        }
    };
}