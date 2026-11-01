/**
 * \file bootstrap/rcc_symbol_entry_release.c
 *
 * \brief Release a symbol map entry.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/error_codes.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_map_internal.h"

/**
 * \brief Release the \ref rcc_symbol_entry part of the derived instance.
 *
 * \note This release method should be called as the last step of the release
 * mechanism for the derived type; it will reclaim memory for the derived type.
 *
 * \param entry         The entry to release.
 * \param size          The total size of the derived entry, for cleanup.
 */
void rcc_symbol_entry_release(
    rcc_symbol_entry* entry, size_t size)
{
    if (NULL != entry->name)
    {
        free(entry->name);
    }

    explicit_bzero(entry, size);
    free(entry);
}
