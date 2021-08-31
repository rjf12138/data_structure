
#include "queue.h"
#include "gtest/gtest.h"

using namespace ds;

namespace my {
namespace project {
namespace {

class Queue_Test : public ::testing::Test {
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

TEST_F(Queue_Test, QueueBasicTest)
{
    int ret = 0;
    Queue<int> queue;
    ASSERT_EQ(queue.empty(), true);
    ASSERT_EQ(queue.size(), 0);
    ASSERT_EQ(queue.pop(ret), 0);
    ASSERT_EQ(queue.push(2), 1);
}

TEST_F(Queue_Test, QueuePushPopTest)
{
    int ret = 0;
    int count = 100;
    Queue<int> queue;
    for (int i = 0; i < count; ++i) {
        int max_node = rand() % 10000;
        for (int i = 0; i <= max_node; ++i) {
            ASSERT_EQ(queue.push(i), 1);
        }
        ASSERT_EQ(queue.size(), max_node + 1);
        for (int i = 0; i <= max_node; ++i) {
            ASSERT_EQ(queue.pop(ret), 1);
            ASSERT_EQ(ret, i);
        }
        ASSERT_EQ(queue.empty(), true);
    }
    // 带有重复数据
    for (int i = 0; i < count; ++i) {
        int max_node = rand() % 10000;
        for (int i = 0; i <= max_node; ++i) {
            ASSERT_EQ(queue.push(i), 1);
            ASSERT_EQ(queue.push(i), 1);
        }
        ASSERT_EQ(queue.size(), 2 * (max_node + 1));
        for (int i = 0; i <= max_node; ++i) {
            ASSERT_EQ(queue.pop(ret), 1);
            ASSERT_EQ(ret, i);

            ASSERT_EQ(queue.pop(ret), 1);
            ASSERT_EQ(ret, i);
        }
        ASSERT_EQ(queue.empty(), true);
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