/**
 * \file bootstrap/rcc_avl_tree_create.c
 *
 * \brief Create an empty AVL tree instance.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/avl_tree.h>
#include <rosalind_bootstrap/error_codes.h>
#include <stdlib.h>
#include <string.h>

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
    void* context)
{
    rcc_avl_tree* tmp;

    /* allocate memory for this instance. */
    tmp = (rcc_avl_tree*)malloc(sizeof(*tmp));
    if (NULL == tmp)
    {
        return RCC_ERROR_OUT_OF_MEMORY;
    }

    /* populate values. */
    explicit_bzero(tmp, sizeof(*tmp));
    tmp->compare_fn = compare_fn;
    tmp->key_fn = key_fn;
    tmp->release_fn = release_fn;
    tmp->context = context;

    /* success. */
    *tree = tmp;
    return 0;
}
