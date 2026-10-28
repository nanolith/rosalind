/**
 * \file bootstrap/rcc_symbol_map_compare.c
 *
 * \brief Compare two symbol map entry keys.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <string.h>

#include "symbol_map_internal.h"

/**
 * \brief Comparison function for comparing two symbol map keys.
 *
 * \param context       Unused.
 * \param lhs           The left-hand key of the comparison.
 * \param rhs           The right-hand key of the comparison.
 *
 * \returns an integer value representing the comparison result.
 *      - &lt; 0 if \p lhs &lt; \p rhs.
 *      - 0 if \p lhs == \p rhs.
 *      - &gt; 0 if \p lhs &gt; \p rhs.
 */
int rcc_symbol_map_compare(
    void* context, const char* lhs, const char* rhs)
{
    (void)context;

    return strcmp(lhs, rhs);
}
