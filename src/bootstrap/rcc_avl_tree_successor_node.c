/**
 * \file bootstrap/rcc_avl_tree_successor_node.c
 *
 * \brief Return the in-order successor node of the given node, or NULL.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/avl_tree.h>

/**
 * \brief Return the in-order successor node of the given node, or NULL.
 *
 * \param tree          The AVL tree for this operation.
 * \param x             The node from which this successor is found.
 *
 * \returns the successor node of this node, or NULL if none is found.
 */
rcc_avl_tree_node* rcc_avl_tree_successor_node(
    rcc_avl_tree* tree, rcc_avl_tree_node* x)
{
    if (NULL != x->right)
    {
        return rcc_avl_tree_minimum_node(tree, x->right);
    }

    rcc_avl_tree_node* y = x->parent;

    while (NULL != y && x == y->right)
    {
        x = y;
        y = y->parent;
    }

    return y;
}
