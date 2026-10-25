/**
 * \file rosalind_bootstrap/avl_tree.h
 *
 * \brief AVL tree for rcc-stage0.
 *
 * See LICENSE.txt for copyright and license information.
 */

#pragma once

#include <stddef.h>
#include <stdbool.h>

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

/**
 * \brief AVL tree.
 */
typedef struct rcc_avl_tree rcc_avl_tree;
struct rcc_avl_tree
{
    rcc_avl_tree_compare_fn compare_fn;
    rcc_avl_tree_key_fn key_fn;
    rcc_avl_tree_release_fn release_fn;
    void* context;
    rcc_avl_tree_node* root;
    size_t count;
};

/**
 * \brief Create a new \ref rcc_avl_tree instance.
 *
 * \param tree          Pointer to the \ref rcc_avl_tree pointer to set to the
 *                      created instance on success.
 * \param compare_fn    The comparison function to use to compare keys.
 * \param key_fn        Function to get a key for a given tree node.
 * \param release_fn    Function to release a tree node.
 * \param context       The user context for this tree.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_avl_tree_create(
    rcc_avl_tree** tree, rcc_avl_tree_compare_fn compare_fn,
    rcc_avl_tree_key_fn key_fn, rcc_avl_tree_release_fn release_fn,
    void* context);

/**
 * \brief Release an \ref rcc_avl_tree instance, calling the user release
 * function on any elements in the tree.
 *
 * \param tree          The tree instance to release.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_avl_tree_release(rcc_avl_tree* tree);

/**
 * \brief Clear all nodes in an AVL tree, and set the count to 0.
 *
 * \param tree          The tree instance to clear.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_avl_tree_clear(rcc_avl_tree* tree);

/**
 * \brief Recursively release all nodes under a given node as well as this node
 * in a tree.
 *
 * \param tree          The tree instance for this delete operation.
 * \param node          The node to recursively delete.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_avl_tree_delete_nodes(rcc_avl_tree* tree, rcc_avl_tree_node* node);

/**
 * \brief Insert a node into the AVL tree instance.
 *
 * \note The AVL tree takes ownership of this node.
 *
 * \param tree          The tree instance for this insert operation.
 * \param node          The node to insert.
 */
void rcc_avl_tree_insert(rcc_avl_tree* tree, rcc_avl_tree_node* node);

/**
 * \brief Find a node in the AVL tree matching the given user defined key.
 *
 * \param node          Pointer to the node pointer to set to the found element
 *                      if found.
 * \param tree          The tree instance for this find operation.
 * \param key           The user-defined key for this find operation.
 *
 * \returns true if this element was found and false otherwise.
 */
bool rcc_avl_tree_find(
    rcc_avl_tree_node** node, rcc_avl_tree* tree, const void* key);

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
    rcc_avl_tree_node** node, rcc_avl_tree* tree, const void* key);

/**
 * \brief Swap the contents of two AVL tree instances.
 *
 * \param left          The left AVL tree for the swap.
 * \param right         The right AVL tree for the swap.
 */
void rcc_avl_tree_swap(rcc_avl_tree* left, rcc_avl_tree* right);

/**
 * \brief Given a subtree node, return the minimum node in this subtree.
 *
 * \param tree          The AVL tree for this operation.
 * \param x             The node from which this search should start. Must not
 *                      be NULL.
 *
 * \returns the minimum node in this subtree.
 */
rcc_avl_tree_node* rcc_avl_tree_minimum_node(
    rcc_avl_tree* tree, rcc_avl_tree_node* x);

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
    rcc_avl_tree* tree, rcc_avl_tree_node* x);

/**
 * \brief Return the in-order successor node of the given node, or NULL.
 *
 * \param tree          The AVL tree for this operation.
 * \param x             The node from which this successor is found.
 *
 * \returns the successor node of this node, or NULL if none is found.
 */
rcc_avl_tree_node* rcc_avl_tree_successor_node(
    rcc_avl_tree* tree, rcc_avl_tree_node* x);

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
