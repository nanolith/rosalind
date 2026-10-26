/**
 * \file bootstrap/rcc_avl_tree_maximum_node.c
 *
 * \brief Given a subtree node, return the maximum node in this subtree.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/avl_tree.h>

/**
 * \brief Given a subtree node, return the maximum node in this subtree.
 *
 * \param tree          The AVL tree for this operation.
 * \param x             The node from which this search should start. Must not
 *                      be NULL.
 *
 * \returns the maximum node in this subtree.
 */
rcc_avl_tree_node* rcc_avl_tree_maximum_node(
    rcc_avl_tree* tree, rcc_avl_tree_node* x)
{
    (void)tree;

    while (NULL != x->right)
    {
        x = x->right;
    }

    return x;
}
