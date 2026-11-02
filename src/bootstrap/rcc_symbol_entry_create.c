/**
 * \file bootstrap/rcc_symbol_entry_create.c
 *
 * \brief Create a symbol map entry.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/error_codes.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_map_internal.h"

/**
 * \brief Create a new \ref rcc_symbol_entry instance of the given total size.
 *
 * \note This create method should be used by the derived type create method.
 *
 * \param entry         Pointer to the \ref rcc_symbol_entry pointer to set to
 *                      the created instance on success.
 * \param name          The name of this entry.
 * \param size          The total size of the derived entry.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_symbol_entry_create(
    rcc_symbol_entry** entry, const char* name, size_t size)
{
    int retval;
    rcc_symbol_entry* tmp;

    tmp = (rcc_symbol_entry*)malloc(size);
    if (NULL == tmp)
    {
        retval = RCC_ERROR_OUT_OF_MEMORY;
        goto done;
    }

    explicit_bzero(tmp, size);

    tmp->name = strdup(name);
    if (NULL == tmp->name)
    {
        retval = RCC_ERROR_OUT_OF_MEMORY;
        goto cleanup_tmp;
    }

    *entry = tmp;
    retval = 0;
    goto done;

cleanup_tmp:
    rcc_symbol_entry_release(tmp, size);

done:
    return retval;
}
