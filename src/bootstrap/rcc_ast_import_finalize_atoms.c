/**
 * \file bootstrap/rcc_ast_import_finalize_atoms.c
 *
 * \brief Finalize the addition of atoms.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/ast.h>


/**
 * \brief Finalize the addition of atoms.
 *
 * \note This function reverses the atom list and should be called only once.
 *
 * \param import        The import atom list to finalize.
 */
void
rcc_ast_import_finalize_atoms(
    rcc_ast_import* import)
{
    rcc_ast_list_node_reverse((rcc_ast_list_node**)&import->import_spec_head);
}
