/**
 * \file bootstrap/rcc_avl_tree_swap.c
 *
 * \brief Swap the contents of two trees.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/avl_tree.h>
#include <string.h>

/**
 * \brief Swap the contents of two AVL tree instances.
 *
 * \param left          The left AVL tree for the swap.
 * \param right         The right AVL tree for the swap.
 */
void rcc_avl_tree_swap(rcc_avl_tree* left, rcc_avl_tree* right)
{
    rcc_avl_tree tmp;

    memcpy(&tmp, left, sizeof(tmp));
    memcpy(left, right, sizeof(tmp));
    memcpy(right, &tmp, sizeof(tmp));
}
