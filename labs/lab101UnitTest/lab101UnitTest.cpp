#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <set>
#include <algorithm>
#include "../labs/lab101.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileContentTests
{
    TEST_CLASS(FileContentTests)
    {
    public:
        void CreateTestFile(const std::string& filename, const std::string& content)
        {
            std::ofstream file(filename);
            file << content;
            file.close();
        }

        TEST_METHOD(ReadFileContent_ValidFile_ReturnsContent)
        {
            const std::string testFilename = "testfile.txt";
            const std::string expectedContent = "This is a test file content.";
            CreateTestFile(testFilename, expectedContent);

            std::string actualContent = readFileContent(testFilename);

            Assert::AreEqual(expectedContent, actualContent);
        }

        TEST_METHOD(ContainsAllLetters_TextContainsAllLetters_ReturnsTrue)
        {

            std::string text = "The quick brown fox jumps over the lazy dog";
            std::string word = "while";

            bool result = containsAllLetters(text, word);

            Assert::IsTrue(result);
        }

        TEST_METHOD(ContainsAllLetters_EmptyWord_ReturnsTrue)
        {

            std::string text = "Any text";
            std::string word = "";

            bool result = containsAllLetters(text, word);

            Assert::IsTrue(result);
        }

        TEST_METHOD(ProcessFile_FileContainsLetters_OutputsCorrectMessage)
        {
            const std::string testFilename = "test_contains.txt";
            CreateTestFile(testFilename, "This text contains all letters needed for 'while'");

            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

            processFile(testFilename);

            std::cout.rdbuf(old);

            std::string output = buffer.str();
            Assert::IsTrue(output.find("contains") != std::string::npos);
        }

        TEST_METHOD(ProcessFile_FileMissingLetters_OutputsCorrectMessage)
        {
            const std::string testFilename = "test_missing.txt";
            CreateTestFile(testFilename, "This text is missing some letters");

            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

            processFile(testFilename);

            std::cout.rdbuf(old);

            std::string output = buffer.str();
            Assert::IsTrue(output.find("DOSE NOT") != std::string::npos);
        }
    };
}