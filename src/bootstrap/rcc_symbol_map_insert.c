/**
 * \file bootstrap/rcc_symbol_map_insert.c
 *
 * \brief Insert an entry into the symbol map.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/error_codes.h>

#include "symbol_map_internal.h"

/**
 * \brief Insert an entry into the symbol map instance.
 *
 * \note The symbol map takes ownership of this entry on success.
 *
 * \param map           The map instance for this insert operation.
 * \param entry         The entry to insert.
 * \param overwrite     Set to true if any previous entry should be overwritten.
 *
 * \returns 0 on success and non-zero on failure.
 *      - RCC_ERROR_WOULD_OVERWRITE if an entry already exists, and overwrite is
 *        set to false.
 */
int rcc_symbol_map_insert(
    rcc_symbol_map* map, rcc_symbol_entry* entry, bool overwrite)
{
    int retval;
    rcc_avl_tree_node* tmp;

    /* attempt to find a node matching the given key. */
    if (rcc_avl_tree_find(&tmp, map->tree, entry->name))
    {
        if (overwrite)
        {
            retval = rcc_avl_tree_delete(NULL, map->tree, entry->name);
            if (0 != retval)
            {
                return retval;
            }
        }
        else
        {
            return RCC_ERROR_WOULD_OVERWRITE;
        }
    }

    /* attempt to insert the entry. */
    rcc_avl_tree_insert(map->tree, &entry->hdr);

    /* success. */
    return 0;
}
