/**
 * \file bootstrap/rcc_avl_tree_delete_nodes.c
 *
 * \brief Recusively delete all nodes under a given node as well as this node.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/avl_tree.h>

/**
 * \brief Recursively release all nodes under a given node as well as this node
 * in a tree.
 *
 * \param tree          The tree instance for this delete operation.
 * \param node          The node to recursively delete.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_avl_tree_delete_nodes(rcc_avl_tree* tree, rcc_avl_tree_node* node)
{
    int retval = 0;
    int release_retval;

    /* recursively delete the left branch. */
    if (NULL != node->left)
    {
        release_retval = rcc_avl_tree_delete_nodes(tree, node->left);
        if (0 != release_retval)
        {
            retval = release_retval;
        }
    }

    /* recursively delete the right branch. */
    if (NULL != node->right)
    {
        release_retval = rcc_avl_tree_delete_nodes(tree, node->right);
        if (0 != release_retval)
        {
            retval = release_retval;
        }
    }

    /* release this node. */
    release_retval = tree->release_fn(tree->context, node);
    if (0 != release_retval)
    {
        retval = release_retval;
    }

    /* decode the result. */
    return retval;
}
