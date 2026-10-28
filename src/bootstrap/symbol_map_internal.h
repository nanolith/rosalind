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

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
