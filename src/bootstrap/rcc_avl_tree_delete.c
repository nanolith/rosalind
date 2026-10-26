/**
 * \file bootstrap/rcc_avl_tree_delete.c
 *
 * \brief Delete a node in an AVL tree.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/avl_tree.h>

/**
 * \brief Delete a node in the AVL tree matching the given user-defined key.
 *
 * \param node          Pointer to the node pointer to be set to the deleted
 *                      node if found. Set to NULL to call the user release
 *                      method on this deleted node instead.
 * \param tree          The AVL tree for this delete operation.
 * \param key           The user-defined key for this delete operation.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_avl_tree_delete(
    rcc_avl_tree_node** node, rcc_avl_tree* tree, const void* key)
{
    rcc_avl_tree_node* tmp = NULL;

    /* attempt to find a node matching the given key. */
    if (!rcc_avl_tree_find(&tmp, tree, key))
    {
        return 0;
    }

    /* remove the node. */
    rcc_avl_tree_remove_node(tree, tmp);

    /* if the node pointer is set, then transfer ownership. */
    if (NULL != node)
    {
        *node = tmp;
        return 0;
    }

    return tree->release_fn(tree->context, tmp);
}
