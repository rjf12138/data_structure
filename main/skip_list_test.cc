
#include "skip_list.h"
#include "gtest/gtest.h"

using namespace ds;

namespace my {
namespace project {
namespace {

class SkipList_Test : public ::testing::Test {
protected:
    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
};

TEST_F(SkipList_Test, SkipListBasicTest)
{
    SkipList<ssize_t, ssize_t> skip_list;
    ASSERT_EQ(skip_list.erase(0), skip_list.end());
    ASSERT_EQ(skip_list.empty(), true);
    ASSERT_EQ(skip_list.size(), 0);
    ASSERT_NE(skip_list.put(100, 1), skip_list.end());

    auto iter = skip_list.get(100);
    ASSERT_EQ(iter.key(), 100);
    ASSERT_EQ(iter.value(), 1);

    ASSERT_EQ(skip_list.get(1000), skip_list.end());
}

TEST_F(SkipList_Test, TraverseSkipList)
{
    SkipList<ssize_t, ssize_t> skip_list;
    for (ssize_t i = 99; i > -100; --i) {
        skip_list.put(i, 1);
    }

    for (auto iter = skip_list.begin(); iter != skip_list.end(); ++iter) {
        fprintf(stderr, "%ld ", iter.key());
    }
    fprintf(stderr, "\n");
}

TEST_F(SkipList_Test, SkipListInsertRemoveTest)
{
    SkipList<int, int> int_skip_list;
    for (int i = -9999; i <= 9999; ++i) {
        ASSERT_NE(int_skip_list.put(i, i + 1), int_skip_list.end());
    }

    for (int i = -19999; i <= 19999; ++i) {
        if (i < -9999) {
            ASSERT_EQ(int_skip_list.get(i), int_skip_list.end());
            continue;
        }

        if (i > 9999) {
            ASSERT_EQ(int_skip_list.get(i), int_skip_list.end());
            continue;
        }

        auto iter = int_skip_list.get(i);
        ASSERT_EQ(iter.key(), i);
        ASSERT_EQ(iter.value(), i + 1);
    }

    for (int i = -19999; i <= 19999; ++i) {
        if (i < -9999) {
            ASSERT_EQ(int_skip_list.erase(i), int_skip_list.end());
            continue;
        }

        if (i > 9999) {
            ASSERT_EQ(int_skip_list.erase(i), int_skip_list.end());
            continue;
        }

        auto iter = int_skip_list.erase(i);
        ASSERT_NE(iter, int_skip_list.end());
    }

    ASSERT_EQ(int_skip_list.size(), 0);

    for (int i = -19999; i <= 19999; ++i) {
        ASSERT_EQ(int_skip_list.get(i), int_skip_list.end());
    }
}

}
}
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}