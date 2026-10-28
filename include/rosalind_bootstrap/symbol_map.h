/**
 * \file rosalind_bootstrap/symbol_map.h
 *
 * \brief Symbol map for rcc-stage0.
 *
 * See LICENSE.txt for copyright and license information.
 */

#pragma once

#include <rosalind_bootstrap/avl_tree.h>

/* C++ compatibility. */
# ifdef   __cplusplus
extern "C" {
# endif /*__cplusplus*/

/**
 * \brief A symbol entry.
 *
 * This is the base type from which more complex types can be derived; it just
 * contains a symbol name.
 */
typedef struct rcc_symbol_entry rcc_symbol_entry;
struct rcc_symbol_entry
{
    rcc_avl_tree_node hdr;
    char* name;
};

/**
 * \brief Given a symbol entry, release it.
 *
 * \param context       Context data to be passed to the release function.
 * \param entry         The entry to release.
 *
 * \returns 0 on success and non-zero on failure.
 */
typedef int (*rcc_symbol_entry_release_fn)(
    void* context, rcc_symbol_entry* entry);

/**
 * \brief symbol map.
 */
typedef struct rcc_symbol_map rcc_symbol_map;

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
