
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
    ASSERT_EQ(heap.remove(0), 0);
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

TEST_F(Heap_Test, MinHeapRemoveTest)
{
    int ret = 0;
    int count = 100;
    MinHeap<int> heap;
    for (int i = 0; i < count; ++i) {
        int max_node = rand() % 1000 + 1;
        for (int j = max_node; j >= 0; --j) { // 添加的值是独一无二的
            ASSERT_EQ(heap.push(j), 1);
        }

        int tmp = heap[0];
        int size = heap.size();
        ASSERT_EQ(heap.remove(0), 1); // 删除第一个元素
        ASSERT_EQ(size, heap.size() + 1); // 元素数量是否改变
        for (int j = 0; j < heap.size(); ++j) { // tmp的值是否还存在与heap中
            ASSERT_NE(heap[j], tmp);
        }

        size = heap.size();
        tmp = heap[heap.size() / 2 - 1]; // 获取中间位置元素
        ASSERT_EQ(heap.remove(heap.size() / 2 - 1), 1); // 删除中间位置元素
        ASSERT_EQ(size, heap.size() + 1);
        for (int j = 0; j < heap.size(); ++j) {
            ASSERT_NE(heap[j], tmp);
        }

        tmp = heap[heap.size() - 1]; // 获取最后位置元素
        size = heap.size();
        ASSERT_EQ(heap.remove(heap.size() - 1), 1); // 删除中间位置元素
        ASSERT_EQ(size, heap.size() + 1);
        for (int j = 0; j < heap.size(); ++j) {
            ASSERT_NE(heap[j], tmp);
        }

        int last;
        for (int j = 0; j < max_node; ++j) {
            heap.pop(ret);
            if (j != 0) { // 测试删除后堆中元素是否结构不变
                ASSERT_GT(ret, last);
            }
            last = ret;

            if (heap.size() == 0) {
                break;
            }
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