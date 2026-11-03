/**
 * \file bootstrap/rcc_symbol_map_clear.c
 *
 * \brief Clear a symbol map.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include "symbol_map_internal.h"

/**
 * \brief Clear all nodes in a symbol map, and set the count to 0.
 *
 * \param map           The map instance to clear.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_symbol_map_clear(rcc_symbol_map* map)
{
    return rcc_avl_tree_clear(map->tree);
}
