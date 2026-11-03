/**
 * \file bootstrap/rcc_symbol_map_next.c
 *
 * \brief Get the next entry for this symbol map, or NULL if no more entries are
 * found.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include "symbol_map_internal.h"

/**
 * \brief Get the next entry for this symbol map, or NULL if no entries are
 * found.
 *
 * \param map           The symbol map for this operation.
 * \param curr          The current entry.
 *
 * \returns the next entry or NULL.
 */
rcc_symbol_entry* rcc_symbol_map_next(
    rcc_symbol_map* map, rcc_symbol_entry* curr)
{
    if (NULL == curr)
    {
        return NULL;
    }

    return
        (rcc_symbol_entry*)rcc_avl_tree_successor_node(map->tree, &curr->hdr);
}
