/**
 * \file bootstrap/rcc_symbol_map_delete.c
 *
 * \brief Delete an entry in the symbol map matching the given name.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include "symbol_map_internal.h"

/**
 * \brief Delete an entry in the symbol map matching the given user-defined key.
 *
 * \param entry         Pointer to the entry pointer to be set to the deleted
 *                      entry if found. Set to NULL to call the user release
 *                      method on this deleted entry instead.
 * \param map           The symbol map for this delete operation.
 * \param name          The name of the symbol to delete.
 *
 * \returns 0 on success and non-zero on failure.
 *      - RCC_ERROR_NOT_FOUND if a matching entry was not found.
 */
int rcc_symbol_map_delete(
    rcc_symbol_entry** entry, rcc_symbol_map* map, const char* name)
{
    return rcc_avl_tree_delete((rcc_avl_tree_node**)entry, map->tree, name);
}
