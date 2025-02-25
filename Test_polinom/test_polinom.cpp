#include "../PolinomLab/List.h"
#include "../PolinomLab/Monom.h"
#include "../PolinomLab/Monom.cpp"
#include "../PolinomLab/Polinom.h"
#include "../PolinomLab/Polinom.cpp"

#include "gtest.h"

TEST(Monom, can_create_empty_monom) {
    ASSERT_NO_THROW(Monom m());
}

TEST(Monom, can_create_custom_monom) {
    ASSERT_NO_THROW(Monom m(2.3, 3, 4, 4));
}

TEST(Monom, correct_LE_monom) {
    Monom m1(2.3, 3, 4, 4);
    Monom m2(2.3, 4, 4, 4);
    Monom m3(2.3, 4, 4, 4);

    EXPECT_LE(m1, m2);
    EXPECT_LT(m1, m2);
    EXPECT_EQ(m2, m3);
}

TEST(Monom, correct_GE_monom) {
    Monom m1(2.3, 4, 4, 5);
    Monom m2(2.3, 4, 4, 4);
    Monom m3(2.3, 4, 4, 4);

    EXPECT_GE(m1, m2);
    EXPECT_GT(m1, m2);
    EXPECT_EQ(m2, m3);
}

TEST(Monom, correct_GT_monom) {
    Monom m1(2.3, 4, 4, 5);
    Monom m2(2.3, 4, 4, 4);

    EXPECT_GT(m1, m2);
}

TEST(Monom, correct_LT_monom) {
    Monom m1(2.3, 4, 1, 4);
    Monom m2(6, 4, 9, 4);

    EXPECT_LT(m1, m2);
}

TEST(Monom, correct_EQ_monom) {
    Monom m1(6, 4, 9, 4);
    Monom m2(6, 4, 9, 4);

    EXPECT_EQ(m1, m2);
}

TEST(Monom, correct_NE_monom) {
    Monom m1(6, 4, 9, 4);
    Monom m2(6, 1, 9, 4);

    EXPECT_NE(m1, m2);
}

/*TEST(TQueue, can_create_queue_with_positive_size) {
    ASSERT_NO_THROW(Monom m());
}

TEST(TQueue, throws_when_create_queue_with_negative_size) {
    ASSERT_ANY_THROW(TQueue<int> queue(-5));
}

TEST(TQueue, can_create_copied_queue) {
    TQueue<int> m(5);
    ASSERT_NO_THROW(TQueue<int> m1(m));
}

TEST(TQueue, copied_queue_is_equal_to_source_one) {
    TQueue<int> m(5);
    TQueue<int> m1(m);
    EXPECT_EQ(m, m1);
}

TEST(TQueue, empty_queue) {
    TQueue<int> m(5);
    EXPECT_EQ(m.isEmpty(), true);
}

TEST(TQueue, no_empty_queue) {
    TQueue<int> m(5);
    m.push(1);
    EXPECT_EQ(m.isEmpty(), false);
}

TEST(TQueue, full_queue) {
    TQueue<int> m(2);
    m.push(5);
    m.push(2);
    EXPECT_EQ(m.isFull(), true);
}

TEST(TQueue, no_full_queue) {
    TQueue<int> m(5);
    m.push(5);
    m.push(10);
    EXPECT_EQ(m.isFull(), false);
}

TEST(TQueue, front_function) {
    TQueue<int> m(3);
    m.push(2);
    m.push(3);
    EXPECT_EQ(m.front(), 2);
}

TEST(TQueue, back_function) {
    TQueue<int> m(3);
    m.push(2);
    m.push(3);
    EXPECT_EQ(m.back(),3);
}

TEST(TQueue, clear_stack) {
    TQueue<int>m(2);
    m.push(5);
    m.push(2);
    m.clear();
    EXPECT_EQ(m.isEmpty(), true);
}

TEST(TQueue, push_function) {
    TQueue<int> m(2);
    m.push(2);
    m.push(3);
    EXPECT_EQ(m.back(), 3);
}

TEST(TQueue, pop_function) {
    TQueue<int> m(2);
    m.push(2);
    m.push(3);
    m.pop();
    EXPECT_EQ(m.front(), 3);
}

TEST(TQueue, pop_from_empty_queue_throws_exception) {
    TQueue<int> m(3);
    ASSERT_ANY_THROW(m.pop());  
}

TEST(TQueue, push_to_full_queue_throws_exception) {
    TQueue<int> m(2);
    m.push(1);
    m.push(2);
    ASSERT_ANY_THROW(m.push(3));
}

TEST(TQueue, compare_queues) {
    TQueue<int> m(2);
    m.push(1);
    m.push(2);
    TQueue<int> m1(m);
    EXPECT_EQ(m, m1);
}

TEST(TQueue, compare_queue_different_head) {
    TQueue<int> m(5);
    TQueue<int> m1(m);
    m.push(5);
    m.push(10);
    m1.push(10);
    m1.push(5);
    m1.push(10);
    m1.pop();
    EXPECT_EQ(m, m1);
}

TEST(TQueue, no_compare_queue) {
    TQueue<int> m(2);
    TQueue<int> m1(m);
    m.push(5);
    m.push(10);
    m1.push(10);
    m1.push(5);
    EXPECT_NE(m, m1);
}

// ------------------------------------------------------------------------------------------------------- // 

TEST(LQueue, can_create_queue) {
    ASSERT_NO_THROW(LQueue<int> q);
}

TEST(LQueue, empty_queue) {
    LQueue<int> q;
    EXPECT_TRUE(q.isEmpty());
}

TEST(LQueue, no_empty_queue) {
    LQueue<int> q;
    q.push(1);
    EXPECT_FALSE(q.isEmpty());
}

TEST(LQueue, can_push_queue) {
    LQueue<int> q;
    q.push(2);
    q.push(3);
    EXPECT_EQ(q.back(), 3);
}

TEST(LQueue, can_pop_queue) {
    LQueue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    EXPECT_EQ(q.front(), 3);
}

TEST(LQueue, can_get_front) {
    LQueue<int> q;
    q.push(1);
    q.push(2);

    EXPECT_EQ(q.front(), 1);
}

TEST(LQueue, can_get_back) {
    LQueue<int> q;
    q.push(1);
    q.push(2);

    EXPECT_EQ(q.back(), 2);
}

TEST(LQueue, can_clear_queue) {
    LQueue<int> q;
    q.push(1);
    q.push(2);
    q.clear();
    EXPECT_TRUE(q.isEmpty());
}

TEST(LQueue, can_check_size) {
    LQueue<int> q;
    EXPECT_EQ(q.size(), 0);
    q.push(1);
    EXPECT_EQ(q.size(), 1);
    q.push(2);
    EXPECT_EQ(q.size(), 2);
    q.pop();
    EXPECT_EQ(q.size(), 1);
}

TEST(LQueue, compare_queues) {
    LQueue<int> q1;
    LQueue<int> q2;

    q1.push(1);
    q1.push(2);

    q2.push(1);
    q2.push(2);

    EXPECT_TRUE(q1 == q2);
}

TEST(LQueue,  no_compare_queues) {
    LQueue<int> q1;
    LQueue<int> q2;

    q1.push(1);
    q1.push(2);

    q2.push(1);
    q2.push(2);
    q2.push(3);

    EXPECT_TRUE(q1 != q2);
}

TEST(LQueue, can_throw_on_empty_pop) {
    LQueue<int> q;

    EXPECT_THROW(q.pop(), int); 
}

TEST(LQueue, can_throw_on_empty_front) {
    LQueue<int> q;

    EXPECT_THROW(q.front(), int); 
}

TEST(LQueue, can_throw_on_empty_back) {
    LQueue<int> q;

    EXPECT_THROW(q.back(), int);
}

TEST(LQueue, can_copy_queue) {
    LQueue<int> q1;
    q1.push(1);
    q1.push(2);
    LQueue<int> q2(q1);
    EXPECT_TRUE(q1 == q2);
}

TEST(LQueue, can_assign_queue) {
    LQueue<int> q1;
    q1.push(1);
    q1.push(2);
    LQueue<int> q2;
    q2 = q1;
    EXPECT_TRUE(q1 == q2);
}*/