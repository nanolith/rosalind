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

/**
 * \brief Create a new \ref rcc_symbol_map instance.
 *
 * \param map           Pointer to the \ref rcc_symbol_map pointer to set to the
 *                      created instance on success.
 * \param release_fn    Function to release a tree node.
 * \param context       The user context for this map.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_symbol_map_create(
    rcc_symbol_map** map, rcc_symbol_entry_release_fn release_fn,
    void* context);

/**
 * \brief Release an \ref rcc_symbol_map instance, calling the user release
 * function on any entries in the map.
 *
 * \param map           The map instance to release.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_symbol_map_release(rcc_symbol_map* map);

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
