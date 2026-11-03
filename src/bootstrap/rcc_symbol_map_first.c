/**
 * \file bootstrap/rcc_symbol_map_first.c
 *
 * \brief Get the first entry for this symbol map, or NULL if no entries are
 * found.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include "symbol_map_internal.h"

/**
 * \brief Get the first entry for this symbol map, or NULL if no entries are
 * found.
 *
 * \param map           The symbol map for this operation.
 *
 * \returns the first entry or NULL.
 */
rcc_symbol_entry* rcc_symbol_map_first(rcc_symbol_map* map)
{
    if (NULL == map->tree->root)
    {
        return NULL;
    }

    return
        (rcc_symbol_entry*)
            rcc_avl_tree_minimum_node(map->tree, map->tree->root);
}
