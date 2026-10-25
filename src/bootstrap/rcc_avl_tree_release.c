/**
 * \file bootstrap/rcc_avl_tree_release.c
 *
 * \brief Release an AVL tree instance.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/avl_tree.h>
#include <stdlib.h>

/**
 * \brief Release an \ref rcc_avl_tree instance, calling the user release
 * function on any elements in the tree.
 *
 * \param tree          The tree instance to release.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_avl_tree_release(rcc_avl_tree* tree)
{
    int retval = rcc_avl_tree_clear(tree);

    free(tree);

    return retval;
}
