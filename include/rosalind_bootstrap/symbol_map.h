/**
 * \file rosalind_bootstrap/symbol_map.h
 *
 * \brief Symbol map for rcc-stage0.
 *
 * See LICENSE.txt for copyright and license information.
 */

#pragma once

#include <rosalind_bootstrap/avl_tree.h>
#include <stdbool.h>

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

/**
 * \brief Clear all nodes in a symbol map, and set the count to 0.
 *
 * \param map           The map instance to clear.
 *
 * \returns 0 on success and non-zero on failure.
 */
int rcc_symbol_map_clear(rcc_symbol_map* map);

/**
 * \brief Insert an entry into the symbol map instance.
 *
 * \note The symbol map takes ownership of this entry on success.
 *
 * \param map           The map instance for this insert operation.
 * \param entry         The entry to insert.
 * \param overwrite     Set to true if any previous entry should be overwritten.
 *
 * \returns 0 on success and non-zero on failure.
 *      - RCC_ERROR_WOULD_OVERWRITE if an entry already exists, and overwrite is
 *        set to false.
 */
int rcc_symbol_map_insert(
    rcc_symbol_map* map, rcc_symbol_entry* entry, bool overwrite);

/**
 * \brief Find an entry in the symbol map matching the given symbol name.
 *
 * \param entry         Pointer to the entry pointer to set to the found entry
 *                      if found.
 * \param map           The symbol map instance for this find operation.
 * \param name          The symbol name to find.
 *
 * \returns true if this entry was found and false otherwise.
 */
bool rcc_symbol_map_find(
    rcc_symbol_entry** entry, rcc_symbol_map* map, const char* name);

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
