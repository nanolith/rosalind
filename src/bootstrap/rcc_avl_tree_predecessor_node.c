/**
 * \file bootstrap/rcc_avl_tree_predecessor_node.c
 *
 * \brief Return the in-order predecessor node of the given node, or NULL.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/avl_tree.h>

/**
 * \brief Return the in-order predecessor node of the given node, or NULL.
 *
 * \param tree          The AVL tree for this operation.
 * \param x             The node from which this predecessor is found.
 *
 * \returns the predecessor node of this node, or NULL if none is found.
 */
rcc_avl_tree_node* rcc_avl_tree_predecessor_node(
    rcc_avl_tree* tree, rcc_avl_tree_node* x)
{
    if (NULL != x->left)
    {
        return rcc_avl_tree_maximum_node(tree, x->left);
    }

    rcc_avl_tree_node* y = x->parent;

    while (NULL != y && x == y->left)
    {
        x = y;
        y = y->parent;
    }

    return y;
}
