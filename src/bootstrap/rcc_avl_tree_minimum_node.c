/**
 * \file bootstrap/rcc_avl_tree_minimum_node.c
 *
 * \brief Given a subtree node, return the minimum node in this subtree.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/avl_tree.h>

/**
 * \brief Given a subtree node, return the minimum node in this subtree.
 *
 * \param tree          The AVL tree for this operation.
 * \param x             The node from which this search should start. Must not
 *                      be NULL.
 *
 * \returns the minimum node in this subtree.
 */
rcc_avl_tree_node* rcc_avl_tree_minimum_node(
    rcc_avl_tree* tree, rcc_avl_tree_node* x)
{
    (void)tree;

    while (NULL != x->left)
    {
        x = x->left;
    }

    return x;
}
