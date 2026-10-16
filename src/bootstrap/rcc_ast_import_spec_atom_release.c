/**
 * \file bootstrap/rcc_ast_import_spec_atom_release.c
 *
 * \brief Release an import spec atom instance.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <stdlib.h>
#include <string.h>

#include "parser_internal.h"

/**
 * \brief Release a \ref rcc_ast_import_spec_atom instance.
 *
 * \param atom          The atom to release.
 */
void
rcc_ast_import_spec_atom_release(rcc_ast_import_spec_atom* atom)
{
    if (NULL != atom->name)
    {
        free(atom->name);
    }

    explicit_bzero(atom, sizeof(*atom));
    free(atom);
}
