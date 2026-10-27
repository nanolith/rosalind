/**
 * \file test/bootstrap/rcc_avl_tree.cpp
 *
 * \brief Unit tests for \ref rcc_avl_tree.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <minunit/minunit.h>
#include <rosalind_bootstrap/avl_tree.h>
#include <stdlib.h>

using namespace std;

TEST_SUITE(rcc_avl_tree);

typedef struct test_context test_context;
struct test_context
{
};

typedef struct test_node test_node;
struct test_node
{
    rcc_avl_tree_node hdr;
    int key;
    char* value;
};

static int test_compare(
    test_context* context, const int* lhs, const int* rhs)
{
    (void)context;
    return *lhs - *rhs;
}

static const void* test_key(
    test_context* context, const test_node* node)
{
    (void)context;

    return &node->key;
}

static int test_node_release(
    test_context* context, test_node* node)
{
    (void)context;

    free(node->value);
    free(node);

    return 0;
}

/**
 * Test that we can create and release an rcc_avl_tree instance.
 */
TEST(create_release)
{
    rcc_avl_tree* tree;

    /* we can create the tree. */
    TEST_ASSERT(
        0
            == rcc_avl_tree_create(
                    &tree, (rcc_avl_tree_compare_fn)&test_compare,
                    (rcc_avl_tree_key_fn)&test_key,
                    (rcc_avl_tree_release_fn)&test_node_release, NULL));

    /* we can release the tree. */
    TEST_ASSERT(0 == rcc_avl_tree_release(tree));
}
