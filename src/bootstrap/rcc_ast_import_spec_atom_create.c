/**
 * \file bootstrap/rcc_scanner_create.c
 *
 * \brief Create a scanner instance.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/ast.h>
#include <rosalind_bootstrap/error_codes.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Create a \ref rcc_ast_import_spec_atom instance.
 *
 * \param atom          Pointer to the atom pointer to be set with this instance
 *                      on success.
 * \param name          The name of this atom.
 * \param loc           The location of this atom.
 *
 * \returns Zero on success and non-zero on failure.
 */
int FN_DECL_MUST_CHECK
rcc_ast_import_spec_atom_create(
    rcc_ast_import_spec_atom** atom, const char* name,
    const rcc_token_details* loc)
{
    int retval;
    rcc_ast_import_spec_atom* tmp;

    /* allocate memory for this instance. */
    tmp = (rcc_ast_import_spec_atom*)malloc(sizeof(*tmp));
    if (NULL == tmp)
    {
        *atom = NULL;
        retval = RCC_ERROR_OUT_OF_MEMORY;
        goto done;
    }

    /* initialize tmp. */
    explicit_bzero(tmp, sizeof(*tmp));
    memcpy(&tmp->loc, loc, sizeof(tmp->loc));

    /* copy name. */
    tmp->name = strdup(name);
    if (NULL == tmp->name)
    {
        retval = RCC_ERROR_OUT_OF_MEMORY;
        goto cleanup_tmp;
    }

    /* success. */
    retval = 0;
    *atom = tmp;
    goto done;

cleanup_tmp:
    rcc_ast_import_spec_atom_release(tmp);

done:
    return retval;
}
