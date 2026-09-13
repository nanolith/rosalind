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
