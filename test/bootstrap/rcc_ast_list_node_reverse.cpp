/**
 * \file test/bootstrap/rcc_ast_list_node_reverse.cpp
 *
 * \brief Unit tests for \ref rcc_ast_list_node_reverse.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <minunit/minunit.h>
#include <rosalind_bootstrap/ast.h>

TEST_SUITE(rcc_ast_list_node_reverse);

/**
 * \brief Reversing an empty list is a no-op.
 */
TEST(reverse_empty)
{
    rcc_ast_list_node* empty = nullptr;

    rcc_ast_list_node_reverse(&empty);

    TEST_ASSERT(nullptr == empty);
}

/**
 * \brief Test that we can reverse a singleton list.
 */
TEST(reverse_singleton)
{
    rcc_ast_list_node singleton = { .next = nullptr };
    rcc_ast_list_node* ptr = &singleton;

    rcc_ast_list_node_reverse(&ptr);

    TEST_ASSERT(&singleton == ptr);
}

/**
 * \brief Test that we can reverse an arbitrary list.
 */
TEST(reverse_multi)
{
    rcc_ast_list_node c = { .next = nullptr };
    rcc_ast_list_node b = { .next = &c };
    rcc_ast_list_node a = { .next = &b };
    rcc_ast_list_node* ptr = &a;

    rcc_ast_list_node_reverse(&ptr);

    TEST_ASSERT(&c == ptr);
    TEST_ASSERT(&b == ptr->next);
    TEST_ASSERT(&a == ptr->next->next);
    TEST_ASSERT(nullptr == ptr->next->next->next);
}
