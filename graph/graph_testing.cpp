#include <string>
#include "graph.h"
#include <gtest/gtest.h>

TEST(correctness, correctness_constructor_Test)
{
    Graph<int> a;
}

TEST(correctness, load_save_test)
{
    Graph<int> a, b;
    a.loadFromFile("test.txt");
    a.saveToFile("text1.txt");
    b.loadFromFile("text1.txt");
    EXPECT_EQ(a.getNodesCount(), b.getNodesCount());
}

TEST(correctness, addNode_count_test)
{
    Graph<int> a;
    a.addNode();
    EXPECT_EQ(a.getNodesCount(), 1);
}

TEST(correctness, addNode_test)
{
    Graph<int> a;
    int k = a.addNode();
    a[k] = 2;
    EXPECT_EQ(a[0], 2);
}

TEST(correctness, addEdge_move_test)
{
    Graph<int> a;
    unsigned first = a.addNode();
    unsigned second = a.addNode();
    a.addEdge(first, second);
    unsigned moveTo = a.move(first, std::make_pair(first, second));
    EXPECT_EQ(second, moveTo);
}

Graph<int> a;
void zeronizeNode(Graph<int>::NodeHandle const & h) {
    a[h] = 0;
}

void zeronizeEdge(Graph<int>::EdgeHandle const & h) {
    a[h.first] = 0;
    a[h.second] = 0;
}

TEST(correctness, forEachNode_test)
{
    for (int i = 0; i < 100; i++) {
        a.addNode();
        a[i] = i;
    }
    a.forEachNode(zeronizeNode);
    int sum = 0;
    for (int i = 0; i < 100; i++)
        sum += a[i];
    EXPECT_EQ(sum, 0);
}

TEST(correctness, forEachEdge_test)
{
    for (int i = 0; i < 99; i++) {
        a[i] = i;
        a.addEdge(i, i + 1);
    }
    a.forEachEdge(zeronizeEdge);
    int sum = 0;
    for (int i = 0; i < 100; i++)
        sum += a[i];
    EXPECT_EQ(sum, 0);
}

Graph<int> b;
void decrement(Graph<int>::NodeHandle const & h) {
    b[h]--;
}
TEST(correctness, dfs_max_test)
{
    for (int i = 0; i < 1000; i++) {
        unsigned index = b.addNode();
        b[index] = 1;
    }
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++) {
            if (i == j) continue;
            b.addEdge(i, j);
        }

    b.dfs(0, 1, decrement);

    int sum = 0;
    for (int i = 0; i < 1000; i++)
        sum += b[i];

    EXPECT_EQ(sum, 0);
}


