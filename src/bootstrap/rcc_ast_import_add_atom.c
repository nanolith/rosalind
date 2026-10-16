/**
 * \file bootstrap/rcc_ast_import_add_atom.c
 *
 * \brief Add an import spec atom to an import.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/ast.h>

/**
 * \brief Add an import spec atom to the given import.
 *
 * \note This import takes ownership of this atom and will release it when it is
 * released.
 *
 * \param import        The import to which this atom is added.
 * \param atom          The atom to add.
 */
void
rcc_ast_import_add_atom(
    rcc_ast_import* import, rcc_ast_import_spec_atom* atom)
{
    atom->hdr.next = (rcc_ast_list_node*)import->import_spec_head;
    import->import_spec_head = atom;
}
