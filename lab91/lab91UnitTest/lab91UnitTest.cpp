#include "pch.h"
#include "CppUnitTest.h"
#include "../lab91/lab91.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StudentTests
{
    TEST_CLASS(SpecialityTests)
    {
    public:
        TEST_METHOD(SpecialityToString_CS_ReturnsCorrectString)
        {
            Assert::AreEqual(std::string("Computer Science"), specialityToString(CS));
        }

        TEST_METHOD(SpecialityToString_IT_ReturnsCorrectString)
        {
            Assert::AreEqual(std::string("Informatics"), specialityToString(IT));
        }

        TEST_METHOD(SpecialityToString_Unknown_ReturnsUnknown)
        {
            Assert::AreEqual(std::string("Unknown"), specialityToString(static_cast<Speciality>(99)));
        }
    };

    TEST_CLASS(StudentATests)
    {
    public:
        TEST_METHOD(CalculateAveragesA_WithStudents_CalculatesCorrectly)
        {
            std::vector<StudentA> students = {
                {"Smith", 1, CS, 5, 4, 5},
                {"Johnson", 2, IT, 3, 4, 5},
                {"Williams", 3, ME, 4, 3, 4}
            };

            double avgPhys, avgMath, avgInfo;
            calculateAveragesA(students, avgPhys, avgMath, avgInfo);

            Assert::AreEqual(4.0, avgPhys, 0.001);
            Assert::AreEqual(3.666, avgMath, 0.001);
            Assert::AreEqual(4.666, avgInfo, 0.001);
        }

        TEST_METHOD(CountGoodStudentsA_WithMixedGrades_ReturnsCorrectCount)
        {
            std::vector<StudentA> students = {
                {"Smith", 1, CS, 5, 4, 5},
                {"Johnson", 2, IT, 3, 4, 5},
                {"Williams", 3, ME, 4, 3, 4}
            };

            int good = countGoodStudentsA(students);
            Assert::AreEqual(2, good);
        }
    };

    TEST_CLASS(StudentBTests)
    {
    public:
        TEST_METHOD(CalculateAveragesB_WithStudents_CalculatesCorrectly)
        {
            StudentB s1 = { "Smith", 1, CS, 5, 4 };
            s1.third.programming = 5;

            StudentB s2 = { "Johnson", 2, IT, 3, 4 };
            s2.third.numericalMethods = 5;

            StudentB s3 = { "Williams", 3, ME, 4, 3 };
            s3.third.pedagogy = 4;

            std::vector<StudentB> students = { s1, s2, s3 };

            double avgPhys, avgMath;
            calculateAveragesB(students, avgPhys, avgMath);

            Assert::AreEqual(4.0, avgPhys, 0.001);
            Assert::AreEqual(3.666, avgMath, 0.001);
        }

        TEST_METHOD(CountGoodStudentsB_WithMixedGrades_ReturnsCorrectCount)
        {
            StudentB s1 = { "Smith", 1, CS, 5, 4 };
            s1.third.programming = 5;

            StudentB s2 = { "Johnson", 2, IT, 3, 4 };
            s2.third.numericalMethods = 5;

            StudentB s3 = { "Williams", 3, ME, 4, 3 };
            s3.third.pedagogy = 4;

            std::vector<StudentB> students = { s1, s2, s3 };

            int good = countGoodStudentsB(students);
            Assert::AreEqual(2, good);
        }
    };
}