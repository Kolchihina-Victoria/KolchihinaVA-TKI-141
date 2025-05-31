#include "pch.h"
#include "CppUnitTest.h"
#include "../Library/IntVector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntVectorTests
{
    TEST_CLASS(IntVectorTests)
    {
    public:

        TEST_METHOD(InitializationAndInsertion)
        {
            IntVector vec = { 10, 20 };
            vec << 30;

            Assert::AreEqual((size_t)3, vec.size());
            Assert::AreEqual(10, vec[0]);
            Assert::AreEqual(30, vec[2]);
        }

        TEST_METHOD(Removal)
        {
            IntVector vec = { 1, 2, 3 };
            int removed;
            vec >> removed;

            Assert::AreEqual(3, removed);
            Assert::AreEqual((size_t)2, vec.size());
        }

        TEST_METHOD(EmptyAndFind)
        {
            IntVector vec;
            Assert::IsTrue(vec.empty());

            vec << 5 << 6;
            Assert::IsFalse(vec.empty());
            Assert::AreEqual(1, vec.find(6));
            Assert::AreEqual(-1, vec.find(999));
        }

        TEST_METHOD(OutOfRangeAccess)
        {
            IntVector vec = { 1 };
            try {
                int x = vec[5];
                Assert::Fail(L"Expected out_of_range exception");
            }
            catch (const std::out_of_range&) {
                // Expected
            }
        }
    };
}
