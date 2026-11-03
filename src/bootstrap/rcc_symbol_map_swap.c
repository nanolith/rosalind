/**
 * \file bootstrap/rcc_symbol_map_swap.c
 *
 * \brief Swap the contents of two symbol maps.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include "symbol_map_internal.h"

/**
 * \brief Swap the contents of two symbol map instances.
 *
 * \param left          The left symbol map for the swap.
 * \param right         The right symbol map for the swap.
 */
void rcc_symbol_map_swap(rcc_symbol_map* left, rcc_symbol_map* right)
{
    rcc_avl_tree_swap(left->tree, right->tree);
}
