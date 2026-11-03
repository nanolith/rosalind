/**
 * \file bootstrap/rcc_symbol_map_count.c
 *
 * \brief Get the number of entries for this symbol map.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include "symbol_map_internal.h"

/**
 * \brief Get the number of entries for this symbol map.
 *
 * \param map           The symbol map for this operation.
 *
 * \returns the number of entries for this symbol map.
 */
size_t rcc_symbol_map_count(const rcc_symbol_map* map)
{
    return map->tree->count;
}
