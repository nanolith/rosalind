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

/**
 * \brief Comparison function type for comparing two AVL tree keys.
 *
 * \param context       Context data to be passed to the comparison function.
 * \param lhs           The left-hand key of the comparison.
 * \param rhs           The right-hand key of the comparison.
 *
 * \returns an integer value representing the comparison result.
 *      - &lt; 0 if \p lhs &lt; \p rhs.
 *      - 0 if \p lhs == \p rhs.
 *      - &gt; 0 if \p lhs &gt; \p rhs.
 */
typedef int (*rcc_avl_tree_compare_fn)(
    void* context, const void* lhs, const void* rhs);

/**
 * \brief Given an AVL tree node, return the key for this node.
 *
 * \param context       Context data to be passed to the accessor function.
 * \param node          The node.
 *
 * \returns the key for this node.
 */
typedef const void* (*rcc_avl_tree_key_fn)(void* context, const void* elem);

/**
 * \brief Given an AVL tree node, release it.
 *
 * \param context       Context data to be passed to the release function.
 * \param node          The node to release.
 *
 * \returns 0 on success and non-zero on failure.
 */
typedef int (*rcc_avl_tree_release_fn)(
    void* context, rcc_avl_tree_node* node);

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
