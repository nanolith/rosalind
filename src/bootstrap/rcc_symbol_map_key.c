/**
 * \file bootstrap/rcc_symbol_map_key.c
 *
 * \brief Return the key for a symbol map entry.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include "symbol_map_internal.h"

/**
 * \brief Given a symbol entry, return the key.
 *
 * \param context       Unused.
 * \param entry         The entry.
 *
 * \returns the key for this entry.
 */
const char* rcc_symbol_map_key(void* context, const rcc_symbol_entry* entry)
{
    (void)context;

    return entry->name;
}
