/**
 * \file bootstrap/rcc_avl_tree_clear.c
 *
 * \brief Clear an AVL tree instance.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/avl_tree.h>

/**
 * \brief Clear all nodes in an AVL tree, and set the count to 0.
 *
 * \param tree          The tree instance to clear.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_avl_tree_clear(rcc_avl_tree* tree)
{
    int retval = 0;

    /* delete all nodes in the tree if the tree is not empty. */
    if (NULL != tree->root)
    {
        retval = rcc_avl_tree_delete_nodes(tree, tree->root);
    }

    /* now the tree is empty. */
    tree->root = NULL;
    tree->count = 0;

    return retval;
}
