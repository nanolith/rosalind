/**
 * \file bootstrap/symbol_map_internal.h
 *
 * \brief Internals for rcc-stage0 symbol map.
 *
 * See LICENSE.txt for copyright and license information.
 */

#pragma once

#include <rosalind_bootstrap/symbol_map.h>

/* C++ compatibility. */
# ifdef   __cplusplus
extern "C" {
# endif /*__cplusplus*/

struct rcc_symbol_map
{
    rcc_avl_tree* tree;
};

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
    void* context, const char* lhs, const char* rhs);

/**
 * \brief Given a symbol entry, return the key.
 *
 * \param context       Unused.
 * \param entry         The entry.
 *
 * \returns the key for this entry.
 */
const char* rcc_symbol_map_key(void* context, const rcc_symbol_entry* entry);

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
