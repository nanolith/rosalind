/**
 * \file rosalind_bootstrap/avl_tree.h
 *
 * \brief AVL tree for rcc-stage0.
 *
 * See LICENSE.txt for copyright and license information.
 */

#pragma once

/* C++ compatibility. */
# ifdef   __cplusplus
extern "C" {
# endif /*__cplusplus*/

/**
 * \brief An AVL tree node.
 *
 * Types can derive from this node to be added to an AVL tree.
 */
typedef struct rcc_avl_tree_node rcc_avl_tree_node;
struct rcc_avl_tree_node
{
    rcc_avl_tree_node* parent;
    rcc_avl_tree_node* left;
    rcc_avl_tree_node* right;
    int height;
};

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
