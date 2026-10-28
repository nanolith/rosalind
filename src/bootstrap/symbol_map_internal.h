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

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
