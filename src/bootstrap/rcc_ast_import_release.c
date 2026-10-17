/**
 * \file bootstrap/rcc_ast_import_release.c
 *
 * \brief Release an import instance.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/ast.h>
#include <stdlib.h>

/**
 * \brief Release a \ref rcc_ast_import instance.
 *
 * \param import        The import to release.
 */
void
rcc_ast_import_release(rcc_ast_import* import)
{
    while (NULL != import->import_spec_head)
    {
        rcc_ast_import_spec_atom* tmp =
            (rcc_ast_import_spec_atom*)import->import_spec_head->hdr.next;
        rcc_ast_import_spec_atom_release(import->import_spec_head);
        import->import_spec_head = tmp;
    }

    if (NULL != import->shorthand && import->name != import->shorthand)
    {
        free(import->shorthand);
    }

    if (NULL != import->name)
    {
        free(import->name);
    }

    free(import);
}
