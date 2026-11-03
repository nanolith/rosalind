/**
 * \file bootstrap/rcc_symbol_map_find.c
 *
 * \brief Find an entry in the symbol map.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include "symbol_map_internal.h"

/**
 * \brief Find an entry in the symbol map matching the given symbol name.
 *
 * \param entry         Pointer to the entry pointer to set to the found entry
 *                      if found.
 * \param map           The symbol map instance for this find operation.
 * \param name          The symbol name to find.
 *
 * \returns true if this entry was found and false otherwise.
 */
bool rcc_symbol_map_find(
    rcc_symbol_entry** entry, rcc_symbol_map* map, const char* name)
{
    return rcc_avl_tree_find((rcc_avl_tree_node**)entry, map->tree, name);
}
