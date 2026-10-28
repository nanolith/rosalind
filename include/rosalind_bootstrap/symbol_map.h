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

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
