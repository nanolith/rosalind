/**
 * \file bootstrap/rcc_symbol_map_release.c
 *
 * \brief Release a symbol map instance.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <stdlib.h>
#include <string.h>

#include "symbol_map_internal.h"

/**
 * \brief Release an \ref rcc_symbol_map instance, calling the user release
 * function on any entries in the map.
 *
 * \param map           The map instance to release.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_symbol_map_release(rcc_symbol_map* map)
{
    int retval = 0;

    if (NULL != map->tree)
    {
        retval = rcc_avl_tree_release(map->tree);
    }

    explicit_bzero(map, sizeof(*map));
    free(map);

    return retval;
}
