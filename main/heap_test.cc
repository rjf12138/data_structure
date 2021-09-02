
#include "heap.h"
#include "gtest/gtest.h"

using namespace ds;

namespace my {
namespace project {
namespace {

class Heap_Test : public ::testing::Test {
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

TEST_F(Heap_Test, MinHeapBasicTest)
{
    int ret = 0;
    MinHeap<int> heap;
    ASSERT_EQ(heap.empty(), true);
    ASSERT_EQ(heap.size(), 0);
    ASSERT_EQ(heap.pop(ret), 0);
    ASSERT_EQ(heap.push(2), 1);
}

TEST_F(Heap_Test, MinHeapPushPopTest)
{
    int ret = 0;
    int count = 100;
    MinHeap<int> heap;
    for (int i = 0; i < count; ++i) {
        int max_node = rand() % 10000;
        for (int i = max_node; i >= 0; --i) {
            ASSERT_EQ(heap.push(i), 1);
        }
        ASSERT_EQ(heap.size(), max_node + 1);

        try {
            heap[heap.size()];
        } catch (std::runtime_error &e) {
            //std::cerr << "runtime error test1: " << e.what() << std::endl;
        }

        for (int i = 0; i < heap.size(); ++i) {
            heap[i];
        }

        for (int i = 0; i <= max_node; ++i) {
            ASSERT_EQ(heap.pop(ret), 1);
            ASSERT_EQ(ret, i);
        }
        ASSERT_EQ(heap.empty(), true);

        try {
            heap[0];
        } catch (std::runtime_error &e) {
            //std::cerr << "runtime error test2: " << e.what() << std::endl;
        }

    }
    // 带有重复数据
    for (int i = 0; i < count; ++i) {
        int max_node = rand() % 10000;
        for (int i = max_node; i >= 0; --i) {
            ASSERT_EQ(heap.push(i), 1);
            ASSERT_EQ(heap.push(i), 1);
        }
        ASSERT_EQ(heap.size(), 2 * (max_node + 1));
        for (int i = 0; i <= max_node; ++i) {
            ASSERT_EQ(heap.pop(ret), 1);
            ASSERT_EQ(ret, i);

            ASSERT_EQ(heap.pop(ret), 1);
            ASSERT_EQ(ret, i);
        }
        ASSERT_EQ(heap.empty(), true);
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