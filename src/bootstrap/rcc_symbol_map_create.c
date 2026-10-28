/**
 * \file bootstrap/rcc_symbol_map_create.c
 *
 * \brief Create a symbol map instance.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/error_codes.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_map_internal.h"

/**
 * \brief Create a new \ref rcc_symbol_map instance.
 *
 * \param map           Pointer to the \ref rcc_symbol_map pointer to set to the
 *                      created instance on success.
 * \param release_fn    Function to release a tree node.
 * \param context       The user context for this map.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_symbol_map_create(
    rcc_symbol_map** map, rcc_symbol_entry_release_fn release_fn,
    void* context)
{
    int retval, release_retval;
    rcc_symbol_map* tmp;

    tmp = (rcc_symbol_map*)malloc(sizeof(*tmp));
    if (NULL == tmp)
    {
        retval = RCC_ERROR_OUT_OF_MEMORY;
        goto done;
    }

    explicit_bzero(tmp, sizeof(*tmp));

    /* create avl tree. */
    retval =
        rcc_avl_tree_create(
            &tmp->tree, (rcc_avl_tree_compare_fn)&rcc_symbol_map_compare,
            (rcc_avl_tree_key_fn)&rcc_symbol_map_key,
            (rcc_avl_tree_release_fn)release_fn, context);
    if (0 != retval)
    {
        goto cleanup_tmp;
    }

    /* success. */
    *map = tmp;
    retval = 0;
    goto done;

cleanup_tmp:
    release_retval = rcc_symbol_map_release(tmp);
    if (0 != release_retval)
    {
        retval = release_retval;
    }

done:
    return retval;
}
