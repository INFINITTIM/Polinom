#include "../PolinomLab/Node.h"
#include "../PolinomLab/List.h"
#include "../PolinomLab/Monom.h"
#include "../PolinomLab/Monom.cpp"
#include "../PolinomLab/Polinom.h"
#include "../PolinomLab/Polinom.cpp"

#include "gtest.h"

TEST(Monom, can_create_empty_monom) {
    ASSERT_NO_THROW(Monom m);
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

TEST(List, can_create_list)
{
    ASSERT_NO_THROW(List<int> m);
}


TEST(List, can_copy_list)
{
    List<int> m1;
    m1.InsFirst(2);
    ASSERT_NO_THROW(List<int> m(m1));
}


TEST(List, correct_copy_list)
{
    List<int> m1;
    m1.InsFirst(2);
    List<int> m(m1);
    EXPECT_EQ(m, m1);
}


TEST(List, compare_lists)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsFirst(4);
    List<int> m;
    m.InsFirst(2);
    m.InsFirst(4);
    EXPECT_TRUE(m == m1);
}

TEST(List, no_compare_lists)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsFirst(4);
    List<int> m;
    m.InsFirst(4);
    m.InsFirst(2);
    EXPECT_NE(m,m1);
}

TEST(List, correct_inslast)
{
    List<int> m1;
    m1.InsLast(1);
    EXPECT_EQ(m1.getCurr(), 1);
}

TEST(List, correct_insfirst)
{
    List<int> m1;
    m1.InsFirst(1);
    m1.InsFirst(3);
    m1.InsLast(2);
    m1.Reset();
    EXPECT_EQ(m1.getCurr(), 3);
}

TEST(List, correct_inscurr)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsCurr(3);
    EXPECT_EQ(m1.getCurr(), 2);
}

TEST(List, correct_dellast)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsCurr(3);
    m1.DelLast();
    m1.Reset();
    EXPECT_EQ(m1.getCurr(), 3);
}

TEST(List, correct_delfirst)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsCurr(3);
    m1.DelFirst();
    EXPECT_EQ(m1.getCurr(), 2);
}

TEST(List, correct_delcurr)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsCurr(3);
    m1.InsLast(4);
    m1.InsLast(5);
    m1.GoNext();
    m1.DelCurr();
    m1.Reset();
    m1.GoNext();
    m1.GoNext();
    EXPECT_EQ(m1.getCurr(), 5);
}

TEST(List, correct_reset)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsCurr(3);
    m1.Reset();
    EXPECT_EQ(m1.getCurr(), 3);

}

TEST(List, correct_getCurr)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsCurr(3);
    m1.InsLast(5);
    m1.GoNext();
    EXPECT_EQ(m1.getCurr(), 5);
}

TEST(List, correct_IsEnd)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsCurr(3);
    m1.InsLast(5);
    m1.GoNext();
    m1.DelLast();
    ASSERT_TRUE(m1.IsEnd());
}

TEST(List, correct_GoNext)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsCurr(3);
    m1.InsLast(5);
    m1.GoNext();
    EXPECT_EQ(m1.getCurr(), 5);
}

TEST(List, correct_clear)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsCurr(3);
    m1.InsLast(5);
    m1.Clear();
    ASSERT_TRUE(m1.IsEmpty());
}

TEST(List, correct_empty)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsCurr(3);
    m1.InsLast(5);
    m1.Clear();
    ASSERT_TRUE(m1.Size() == 0);
}

TEST(List, correct_size)
{
    List<int> m1;
    m1.InsFirst(2);
    m1.InsCurr(3);
    m1.InsLast(5);
    m1.DelCurr();
    ASSERT_TRUE(m1.Size() == 2);
}

TEST(Polinom, can_create_polinom)
{
    ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, can_create_custom_polinom)
{
    Monom a(4.0, 2, 0, 4);
    Monom b(-3.0, 1, 2, 5);
    Monom m[] = { a, b };
    ASSERT_NO_THROW(Polinom p(m, 2));
}

TEST(Polinom, can_copy_polinom)
{
    Polinom p;
    p.AddMonom({ 3,4,3,4 });
    ASSERT_NO_THROW(Polinom p1(p));
}


TEST(Polinom, correct_copy_polinom)
{
    Polinom p;
    p.AddMonom({ 3,4,3,4 });
    Polinom p1(p);
    EXPECT_EQ(p, p1);
}

TEST(Polinom, correct_assignment_polinom)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3,4,3,4 });
    p1 = p;
    EXPECT_EQ(p, p1);
}

TEST(Polinom, compare_equal_polinom)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3,4,3,4 });
    p1.AddMonom({ 3,4,3,4 });
    ASSERT_TRUE(p == p1);
}

TEST(Polinom, compare_not_equal_polinom)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3,4,3,4 });
    p1.AddMonom({ 5,4,3,4 });
    ASSERT_TRUE(p != p1);
}

TEST(Polinom, can_add_const_with_function_to_not_empty_polinom)
{
    Polinom p;
    p.AddMonom({ 3, 2, 0, 0 });
    p.AddConst(5);
    Monom m[2] = { { 3, 2, 0, 0 }, { 5, 0, 0, 0 } };
    EXPECT_EQ(p, Polinom(m, 2));
}

TEST(Polinom, can_add_const_with_function_to_empty_polinom)
{
    Polinom p;
    p.AddConst(5);
    Monom m[1] = { { 5, 0, 0, 0 } };
    EXPECT_EQ(p, Polinom(m, 1)); 
}

TEST(Polinom, can_add_const_with_function_to_polinom_with_const)
{
    Polinom p;
    p.AddMonom({ 3, 2, 0, 0 });
    p.AddConst(9);
    p.AddConst(5);
    Monom m[2] = { { 3, 2, 0, 0 }, { 14, 0, 0, 0 } };
    EXPECT_EQ(p, Polinom(m, 2));
}

TEST(Polinom, can_add_const_with_operator_plus_to_not_empty_polinom)
{
    Polinom p;
    p.AddMonom({ 3, 2, 0, 0 });
    Polinom p1;
    p1 = p + 5;
    Monom m[2] = { { 3, 2, 0, 0 }, { 5, 0, 0, 0 } };
    EXPECT_EQ(p1, Polinom(m, 2));
}

TEST(Polinom, can_add_const_with_operator_plus_to_empty_polinom)
{
    Polinom p;
    Polinom p1;
    p1 = p + 5;
    Monom m[1] = { { 5, 0, 0, 0 } };
    EXPECT_EQ(p1, Polinom(m, 1));
}

TEST(Polinom, can_add_const_with_operator_plus_to_polinom_with_const)
{
    Polinom p;
    p.AddMonom({ 3, 2, 0, 0 });
    p.AddConst(9);
    Polinom p1;
    p1 = p + 5;
    Monom m[2] = { { 3, 2, 0, 0 }, { 14, 0, 0, 0 } };
    EXPECT_EQ(p1, Polinom(m, 2));
}

TEST(Polinom, can_add_const_with_operator_plus_equal_to_not_empty_polinom)
{
    Polinom p;
    p.AddMonom({ 3, 2, 0, 0 });
    p += 5;
    Monom m[2] = { { 3, 2, 0, 0 }, { 5, 0, 0, 0 } };
    EXPECT_EQ(p, Polinom(m, 2));
}

TEST(Polinom, can_add_const_with_operator_plus_equal_to_empty_polinom)
{
    Polinom p;
    p += 5;
    Monom m[1] = { { 5, 0, 0, 0 } };
    EXPECT_EQ(p, Polinom(m, 1));
}

TEST(Polinom, can_add_const_with_operator_plus_equal_to_polinom_with_const)
{
    Polinom p;
    p.AddMonom({ 3, 2, 0, 0 });
    p.AddConst(9);
    p += 5;
    Monom m[2] = { { 3, 2, 0, 0 }, { 14, 0, 0, 0 } };
    EXPECT_EQ(p, Polinom(m, 2));
}

TEST(Polinom, can_add_monom_with_function_to_empty_polinom)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    Monom m[1] = { { 3, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(m, 1));
}

TEST(Polinom, can_add_monom_with_function_to_polinom_in_first)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ 1, 3, 1, 0 });
    Monom m[2] = { { 1, 3, 1, 0 }, { 3, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(m, 2));
}

TEST(Polinom, can_add_monom_with_function_to_polinom_in_last)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    Monom m[2] = { { 3, 2, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(m, 2));
}

TEST(Polinom, can_add_monom_with_function_to_polinom_in_middle)
{
    Polinom p;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    p.AddMonom({ 1, 3, 1, 0 });
    Monom m[3] = { { 3, 5, 1, 0 }, { 1, 3, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(m, 3));
}

TEST(Polinom, can_add_monom_with_function_to_polinom_in_first_and_equal_degree)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ 1, 1, 1, 0 });
    p.AddMonom({ 1, 2, 1, 0 });
    Monom m[2] = { { 4, 2, 1, 0 }, { 1, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(m, 2));
}

TEST(Polinom, can_add_monom_with_function_to_polinom_in_last_and_equal_degree)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    Monom m[2] = { { 3, 2, 1, 0 }, { 268, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(m, 2));
}

TEST(Polinom, can_add_monom_with_function_to_polinom_in_middle_and_equal_degree)
{
    Polinom p;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    p.AddMonom({ 1, 3, 1, 0 });
    p.AddMonom({ 3456, 3, 1, 0 });
    Monom m[3] = { { 3, 5, 1, 0 }, { 3457, 3, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(m, 3));
}


TEST(Polinom, can_add_monom_with_function_to_polinom_in_first_and_equal_degree_and_del_node)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ 1, 1, 1, 0 });
    p.AddMonom({ -3, 2, 1, 0 });
    Monom m[1] = { { 1, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(m, 1));
}

TEST(Polinom, can_add_monom_with_function_to_polinom_in_last_and_equal_degree_and_del_node)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ -134, 1, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    Monom m[1] = { { 3, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(m, 1));
}

TEST(Polinom, can_add_monom_with_function_to_polinom_in_midlle_and_equal_degree_and_del_node)
{
    Polinom p;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    p.AddMonom({ 234567, 3, 1, 0 });
    p.AddMonom({ -234567, 3, 1, 0 });
    Monom m[2] = { { 3, 5, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(m, 2));
}

TEST(Polinom, can_add_monom_with_operator_plus_to_empty_polinom)
{
    Polinom p;
    Monom m(3, 2, 1, 0 );
    Polinom p1;
    p1 = p + m;
    Monom mm[1] = { { 3, 2, 1, 0 } };
    EXPECT_EQ(p1, Polinom(mm, 1));
}

TEST(Polinom, can_add_monom_with_operator_plus_to_polinom_in_first)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    Monom m(1, 3, 1, 0);
    Polinom p1;
    p1 = p + m;
    Monom mm[2] = { { 1, 3, 1, 0 }, { 3, 2, 1, 0 } };
    EXPECT_EQ(p1, Polinom(mm, 2));
}

TEST(Polinom, can_add_monom_with_operator_plus_to_polinom_in_last)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    Monom m( 134, 1, 1, 0 );
    Polinom p1;
    p1 = p + m;
    Monom mm[2] = { { 3, 2, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p1, Polinom(mm, 2));
}

TEST(Polinom, can_add_monom_with_operator_plus_to_polinom_in_middle)
{
    Polinom p;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    Monom m(1, 3, 1, 0);
    Polinom p1;
    p1 = p + m;
    Monom mm[3] = { { 3, 5, 1, 0 }, { 1, 3, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p1, Polinom(mm, 3));
}

TEST(Polinom, can_add_monom_with_operator_plus_to_polinom_in_first_and_equal_degree)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ 1, 1, 1, 0 });
    Monom m(1, 2, 1, 0);
    Polinom p1;
    p1 = p + m;
    Monom mm[2] = { { 4, 2, 1, 0 }, { 1, 1, 1, 0 } };
    EXPECT_EQ(p1, Polinom(mm, 2));
}

TEST(Polinom, can_add_monom_with_operator_plus_to_polinom_in_last_and_equal_degree)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    Monom m( 134, 1, 1, 0 );
    Polinom p1;
    p1 = p + m;
    Monom mm[2] = { { 3, 2, 1, 0 }, { 268, 1, 1, 0 } };
    EXPECT_EQ(p1, Polinom(mm, 2));
}

TEST(Polinom, can_add_monom_with_operator_plus_to_polinom_in_middle_and_equal_degree)
{
    Polinom p;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    p.AddMonom({ 1, 3, 1, 0 });
    Monom m( 3456, 3, 1, 0 );
    Polinom p1;
    p1 = p + m;
    Monom mm[3] = { { 3, 5, 1, 0}, { 3457, 3, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p1, Polinom(mm, 3));
}


TEST(Polinom, can_add_monom_with_operator_plus_to_polinom_in_first_and_equal_degree_and_del_node)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ 1, 1, 1, 0 });
    Monom m( -3, 2, 1, 0 );
    Polinom p1;
    p1 = p + m;
    Monom mm[1] = { { 1, 1, 1, 0 } };
    EXPECT_EQ(p1, Polinom(mm, 1));
}

TEST(Polinom, can_add_monom_with_operator_plus_to_polinom_in_last_and_equal_degree_and_del_node)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ -134, 1, 1, 0 });
    Monom m( 134, 1, 1, 0 );
    Polinom p1;
    p1 = p + m;
    Monom mm[1] = { { 3, 2, 1, 0 } };
    EXPECT_EQ(p1, Polinom(mm, 1));
}

TEST(Polinom, can_add_monom_with_operator_plus_to_polinom_in_middle_and_equal_degree_and_del_node)
{
    Polinom p;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    p.AddMonom({ 234567, 3, 1, 0 });
    Monom m( -234567, 3, 1, 0 );
    Polinom p1;
    p1 = p + m;
    Monom mm[2] = { { 3, 5, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p1, Polinom(mm, 2));
}

////////////////////////////////

TEST(Polinom, can_add_monom_with_operator_plus_equal_to_empty_polinom)
{
    Polinom p;
    Monom m(3, 2, 1, 0);
    p += m;
    Monom mm[1] = { { 3, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 1));
}

TEST(Polinom, can_add_monom_with_operator_plus_equal_to_polinom_in_first)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    Monom m(1, 3, 1, 0);
    p += m;
    Monom mm[2] = { { 1, 3, 1, 0 }, { 3, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_add_monom_with_operator_plus_equal_to_polinom_in_last)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    Monom m(134, 1, 1, 0);
    p += m;
    Monom mm[2] = { { 3, 2, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_add_monom_with_operator_plus_equal_to_polinom_in_middle)
{
    Polinom p;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    Monom m(1, 3, 1, 0);
    p += m;
    Monom mm[3] = { { 3, 5, 1, 0 }, { 1, 3, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 3));
}

TEST(Polinom, can_add_monom_with_operator_plus_equal_to_polinom_in_first_and_equal_degree)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ 1, 1, 1, 0 });
    Monom m(1, 2, 1, 0);
    p += m;
    Monom mm[2] = { { 4, 2, 1, 0 }, { 1, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_add_monom_with_operator_plus_equal_to_polinom_in_last_and_equal_degree)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    Monom m(134, 1, 1, 0);
    p += m;
    Monom mm[2] = { { 3, 2, 1, 0 }, { 268, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_add_monom_with_operator_plus_equal_to_polinom_in_middle_and_equal_degree)
{
    Polinom p;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    p.AddMonom({ 1, 3, 1, 0 });
    Monom m(3456, 3, 1, 0);
    p += m;
    Monom mm[3] = { { 3, 5, 1, 0}, { 3457, 3, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 3));
}


TEST(Polinom, can_add_monom_with_operator_plus_equal_to_polinom_in_first_and_equal_degree_and_del_node)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ 1, 1, 1, 0 });
    Monom m(-3, 2, 1, 0);
    p += m;
    Monom mm[1] = { { 1, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 1));
}

TEST(Polinom, can_add_monom_with_operator_plus_equal_to_polinom_in_last_and_equal_degree_and_del_node)
{
    Polinom p;
    p.AddMonom({ 3, 2, 1, 0 });
    p.AddMonom({ -134, 1, 1, 0 });
    Monom m(134, 1, 1, 0);
    p += m;
    Monom mm[1] = { { 3, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 1));
}

TEST(Polinom, can_add_monom_with_operator_plus_equal_to_polinom_in_middle_and_equal_degree_and_del_node)
{
    Polinom p;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    p.AddMonom({ 234567, 3, 1, 0 });
    Monom m(-234567, 3, 1, 0);
    p += m;
    Monom mm[2] = { { 3, 5, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_add_polinom_with_function_to_empty_polinom)
{
    Polinom p;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    Polinom p1;
    p.AddPolinom(p1);
    Monom mm[2] = { { 3, 5, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_add_empty_polinom_with_function_to_polinom)
{
    Polinom p;
    Polinom p1;
    p1.AddMonom({ 3, 5, 1, 0 });
    p1.AddMonom({ 134, 1, 1, 0 });
    p.AddPolinom(p1);
    Monom mm[2] = { { 3, 5, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_add_polinom_with_function_to_polinom_full_left)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 7, 1, 0 });
    p1.AddMonom({ 3, 6, 1, 0 });
    p.AddPolinom(p1);
    Monom mm[4] = { { 3, 7, 1, 0 }, { 3, 6, 1, 0 }, { 3, 5, 1, 0 }, { 3, 4, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 4));
}

TEST(Polinom, can_add_polinom_with_function_to_polinom_full_right)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 3, 1, 0 });
    p1.AddMonom({ 3, 2, 1, 0 });
    p.AddPolinom(p1);
    Monom mm[4] = { { 3, 5, 1, 0 }, { 3, 4, 1, 0 }, { 3, 3, 1, 0 }, { 3, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 4));
}

TEST(Polinom, can_add_polinom_with_function_to_polinom_more_position_1)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 7, 1, 0 });
    p1.AddMonom({ 3, 2, 1, 0 });
    p.AddPolinom(p1);
    Monom mm[4] = { { 3, 7, 1, 0 }, { 3, 5, 1, 0 }, { 3, 4, 1, 0 }, { 3, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 4));
}

TEST(Polinom, can_add_polinom_with_function_to_polinom_more_position_2)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 1, 1, 0 });
    p.AddPolinom(p1);
    Monom mm[4] = { { 3, 9, 1, 0 }, { 3, 4, 1, 0 }, { 3, 2, 1, 0 }, { 3, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 4));
}

TEST(Polinom, can_add_polinom_with_function_to_polinom_more_position_3)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 2, 1, 0 });
    p.AddPolinom(p1);
    Monom mm[3] = { { 3, 9, 1, 0 }, { 3, 4, 1, 0 }, { 6, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 3));
}

TEST(Polinom, can_add_polinom_with_function_to_polinom_more_position_4)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1.AddMonom({ 3, 9, 1, 0 });
    p1.AddMonom({ 3, 2, 1, 0 });
    p.AddPolinom(p1);
    Monom mm[2] = { { 6, 9, 1, 0 }, { 6, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_add_polinom_with_function_to_polinom_more_position_5)
{
    Polinom p;
    Polinom p1;
    Polinom p_empty;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1.AddMonom({ -3, 9, 1, 0 });
    p1.AddMonom({ -3, 2, 1, 0 });
    p.AddPolinom(p1);
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
}

TEST(Polinom, can_add_polinom_with_operator_plus_to_empty_polinom)
{
    Polinom p;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    Polinom p1;
    Polinom p2;
    p2 = p + p1;
    Monom mm[2] = { { 3, 5, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p2, Polinom(mm, 2));
}

TEST(Polinom, can_add_empty_polinom_with_operator_plus_to_polinom)
{
    Polinom p;
    Polinom p1;
    p1.AddMonom({ 3, 5, 1, 0 });
    p1.AddMonom({ 134, 1, 1, 0 });
    Polinom p2;
    p2 = p + p1;
    Monom mm[2] = { { 3, 5, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p2, Polinom(mm, 2));
}

TEST(Polinom, can_add_polinom_with_operator_plus_to_polinom_full_left)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 7, 1, 0 });
    p1.AddMonom({ 3, 6, 1, 0 });
    Polinom p2;
    p2 = p + p1;
    Monom mm[4] = { { 3, 7, 1, 0 }, { 3, 6, 1, 0 }, { 3, 5, 1, 0 }, { 3, 4, 1, 0 } };
    EXPECT_EQ(p2, Polinom(mm, 4));
}

TEST(Polinom, can_add_polinom_with_operator_plus_to_polinom_full_right)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 3, 1, 0 });
    p1.AddMonom({ 3, 2, 1, 0 });
    Polinom p2;
    p2 = p + p1;
    Monom mm[4] = { { 3, 5, 1, 0 }, { 3, 4, 1, 0 }, { 3, 3, 1, 0 }, { 3, 2, 1, 0 } };
    EXPECT_EQ(p2, Polinom(mm, 4));
}

TEST(Polinom, can_add_polinom_with_operator_plus_to_polinom_more_position_1)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 7, 1, 0 });
    p1.AddMonom({ 3, 2, 1, 0 });
    Polinom p2;
    p2 = p + p1;
    Monom mm[4] = { { 3, 7, 1, 0 }, { 3, 5, 1, 0 }, { 3, 4, 1, 0 }, { 3, 2, 1, 0 } };
    EXPECT_EQ(p2, Polinom(mm, 4));
}

TEST(Polinom, can_add_polinom_with_operator_plus_to_polinom_more_position_2)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 1, 1, 0 });
    Polinom p2;
    p2 = p + p1;
    Monom mm[4] = { { 3, 9, 1, 0 }, { 3, 4, 1, 0 }, { 3, 2, 1, 0 }, { 3, 1, 1, 0 } };
    EXPECT_EQ(p2, Polinom(mm, 4));
}

TEST(Polinom, can_add_polinom_with_operator_plus_to_polinom_more_position_3)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 2, 1, 0 });
    Polinom p2;
    p2 = p + p1;
    Monom mm[3] = { { 3, 9, 1, 0 }, { 3, 4, 1, 0 }, { 6, 2, 1, 0 } };
    EXPECT_EQ(p2, Polinom(mm, 3));
}

TEST(Polinom, can_add_polinom_with_operator_plus_to_polinom_more_position_4)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1.AddMonom({ 3, 9, 1, 0 });
    p1.AddMonom({ 3, 2, 1, 0 });
    Polinom p2;
    p2 = p + p1;
    Monom mm[2] = { { 6, 9, 1, 0 }, { 6, 2, 1, 0 } };
    EXPECT_EQ(p2, Polinom(mm, 2));
}

TEST(Polinom, can_add_polinom_with_operator_plus_to_polinom_more_position_5)
{
    Polinom p;
    Polinom p1;
    Polinom p_empty;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1.AddMonom({ -3, 9, 1, 0 });
    p1.AddMonom({ -3, 2, 1, 0 });
    Polinom p2;
    p2 = p + p1;
    Monom mm[10];
    EXPECT_EQ(p2, Polinom(mm, 0));
    EXPECT_EQ(p2, p_empty);
}

TEST(Polinom, can_add_polinom_with_operator_plus_equal_to_empty_polinom)
{
    Polinom p;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 134, 1, 1, 0 });
    Polinom p1;
    p += p1;
    Monom mm[2] = { { 3, 5, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_add_empty_polinom_with_operator_plus_equal_to_polinom)
{
    Polinom p;
    Polinom p1;
    p1.AddMonom({ 3, 5, 1, 0 });
    p1.AddMonom({ 134, 1, 1, 0 });
    p += p1;
    Monom mm[2] = { { 3, 5, 1, 0 }, { 134, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_add_polinom_with_operator_plus_equal_to_polinom_full_left)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 7, 1, 0 });
    p1.AddMonom({ 3, 6, 1, 0 });
    p += p1;
    Monom mm[4] = { { 3, 7, 1, 0 }, { 3, 6, 1, 0 }, { 3, 5, 1, 0 }, { 3, 4, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 4));
}

TEST(Polinom, can_add_polinom_with_operator_plus_equal_to_polinom_full_right)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 3, 1, 0 });
    p1.AddMonom({ 3, 2, 1, 0 });
    p += p1;
    Monom mm[4] = { { 3, 5, 1, 0 }, { 3, 4, 1, 0 }, { 3, 3, 1, 0 }, { 3, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 4));
}

TEST(Polinom, can_add_polinom_with_operator_plus_equal_to_polinom_more_position_1)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 5, 1, 0 });
    p.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 7, 1, 0 });
    p1.AddMonom({ 3, 2, 1, 0 });
    p += p1;
    Monom mm[4] = { { 3, 7, 1, 0 }, { 3, 5, 1, 0 }, { 3, 4, 1, 0 }, { 3, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 4));
}

TEST(Polinom, can_add_polinom_with_operator_plus_equal_to_polinom_more_position_2)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 1, 1, 0 });
    p += p1;
    Monom mm[4] = { { 3, 9, 1, 0 }, { 3, 4, 1, 0 }, { 3, 2, 1, 0 }, { 3, 1, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 4));
}

TEST(Polinom, can_add_polinom_with_operator_plus_equal_to_polinom_more_position_3)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1.AddMonom({ 3, 4, 1, 0 });
    p1.AddMonom({ 3, 2, 1, 0 });
    p += p1;
    Monom mm[3] = { { 3, 9, 1, 0 }, { 3, 4, 1, 0 }, { 6, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 3));
}

TEST(Polinom, can_add_polinom_with_operator_plus_equal_to_polinom_more_position_4)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1.AddMonom({ 3, 9, 1, 0 });
    p1.AddMonom({ 3, 2, 1, 0 });
    p += p1;
    Monom mm[2] = { { 6, 9, 1, 0 }, { 6, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_add_polinom_with_operator_plus_equal_to_polinom_more_position_5)
{
    Polinom p;
    Polinom p1;
    Polinom p_empty;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1.AddMonom({ -3, 9, 1, 0 });
    p1.AddMonom({ -3, 2, 1, 0 });
    p += p1;
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
}

TEST(Polinom, can_mult_const_with_function_to_polinom)
{
    Polinom p;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p.MultConst(4);
    Monom mm[2] = { { 12, 9, 1, 0 }, { 12, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_mult_const_null_with_function_to_polinom)
{
    Polinom p;
    Polinom p_empty;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p.MultConst(0);
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
}

TEST(Polinom, can_mult_const_with_function_to_empty_polinom)
{
    Polinom p;
    Polinom p_empty;
    p.MultConst(5);
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
}

TEST(Polinom, can_mult_const_with_operator_mult_to_polinom)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1 = p * 4;
    Monom mm[2] = { { 12, 9, 1, 0 }, { 12, 2, 1, 0 } };
    EXPECT_EQ(p1, Polinom(mm, 2));
}

TEST(Polinom, can_mult_const_null_with_operator_mult_to_polinom)
{
    Polinom p;
    Polinom p1;
    Polinom p_empty;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p1 = p * 0;
    Monom mm[10];
    EXPECT_EQ(p1, Polinom(mm, 0));
    EXPECT_EQ(p1, p_empty);
}

TEST(Polinom, can_mult_const_with_operator_mult_to_empty_polinom)
{
    Polinom p;
    Polinom p1;
    Polinom p_empty;
    p1 = p * 5;
    Monom mm[10];
    EXPECT_EQ(p1, Polinom(mm, 0));
    EXPECT_EQ(p1, p_empty);
}

TEST(Polinom, can_mult_const_with_operator_mult_equal_to_polinom)
{
    Polinom p;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p *= 4;
    Monom mm[2] = { { 12, 9, 1, 0 }, { 12, 2, 1, 0 } };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_mult_const_null_with_operator_mult_equal_to_polinom)
{
    Polinom p;
    Polinom p_empty;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p *= 0;
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
}

TEST(Polinom, can_mult_const_with_operator_mult_equal_to_empty_polinom)
{
    Polinom p;
    Polinom p_empty;
    p *= 5;
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
}

TEST(Polinom, can_mult_null_monom_with_function_to_polinom)
{
    Polinom p;
    Polinom p_empty;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p.MultMonom({ 0, 0, 0, 0 });
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
}

TEST(Polinom, can_mult_monom_with_function_to_polinom)
{
    Polinom p;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    p.MultMonom({ 5, 4, 3, 2 });
    Monom mm[2] = { { 15, 13, 4, 2}, { 15, 6, 4, 2} };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_mult_monom_with_function_to_empty_polinom)
{
    Polinom p;
    Polinom p_empty;
    p.MultMonom({ 5, 4, 3, 2 });
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
}

TEST(Polinom, can_mult_null_monom_with_operator_mult_to_polinom)
{
    Polinom p;
    Polinom p1;
    Polinom p_empty;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    Monom m(0, 0, 0, 0);
    p1 = p * m;
    Monom mm[10];
    EXPECT_EQ(p1, Polinom(mm, 0));
    EXPECT_EQ(p1, p_empty);
}

TEST(Polinom, can_mult_monom_with_operator_mult_to_polinom)
{
    Polinom p;
    Polinom p1;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    Monom m( 5, 4, 3, 2 );
    p1 = p * m;
    Monom mm[2] = { { 15, 13, 4, 2}, { 15, 6, 4, 2} };
    EXPECT_EQ(p1, Polinom(mm, 2));
}

TEST(Polinom, can_mult_monom_with_operator_mult_to_empty_polinom)
{
    Polinom p;
    Polinom p1;
    Polinom p_empty;
    Monom m(5, 4, 3, 2 );
    p1 = p * m;
    Monom mm[10];
    EXPECT_EQ(p1, Polinom(mm, 0));
    EXPECT_EQ(p1, p_empty);
}

TEST(Polinom, can_mult_null_monom_with_operator_mult_equal_to_polinom)
{
    Polinom p;
    Polinom p_empty;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    Monom m(0, 0, 0, 0);
    p *= m;
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
}

TEST(Polinom, can_mult_monom_with_operator_mult_equal_to_polinom)
{
    Polinom p;
    p.AddMonom({ 3, 9, 1, 0 });
    p.AddMonom({ 3, 2, 1, 0 });
    Monom m(5, 4, 3, 2);
    p *= m;
    Monom mm[2] = { { 15, 13, 4, 2}, { 15, 6, 4, 2} };
    EXPECT_EQ(p, Polinom(mm, 2));
}

TEST(Polinom, can_mult_monom_with_operator_mult_equal_to_empty_polinom)
{
    Polinom p;
    Polinom p_empty;
    Monom m(5, 4, 3, 2);
    p *= m;
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
}

TEST(Polinom, can_mult_polinom_with_function_to_polinom)
{
    Polinom p;
    p.AddMonom({ 2,5,1,6 });
    p.AddMonom({ 5,1,1,3 });
    Monom mm[2] = { { 3, 2, 2, 4 }, { 2, 2, 2, 2 } };
    Polinom p1(mm, 2);
    p.MultPolinom(p1);
    Monom mmm[4] = { { 6, 7, 3, 10 }, { 4, 7, 3, 8 }, { 15, 3, 3, 7 }, { 10, 3, 3, 5 } };
    EXPECT_EQ(p, Polinom(mmm, 4));
}

TEST(Polinom, can_mult_empty_polinom_with_function_to_polinom)
{
    Polinom p;
    Polinom p1;
    Polinom p_empty;
    p.AddMonom({ 2,5,1,6 });
    p.AddMonom({ 5,1,1,3 });
    p.MultPolinom(p1);
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
}

TEST(Polinom, can_mult_polinom_with_function_to_empty_polinom)
{
    Polinom p;
    Polinom p1;
    Polinom p_empty;
    p1.AddMonom({ 2,5,1,6 });
    p1.AddMonom({ 5,1,1,3 });
    p.MultPolinom(p1);
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
}

TEST(Polinom, can_mult_empty_polinom_with_function_to_empty_polinom)
{
    Polinom p;
    Polinom p1;
    Polinom p_empty;
    p.MultPolinom(p1);
    Monom mm[10];
    EXPECT_EQ(p, Polinom(mm, 0));
    EXPECT_EQ(p, p_empty);
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