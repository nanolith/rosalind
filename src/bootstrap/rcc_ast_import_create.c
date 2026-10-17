/**
 * \file bootstrap/rcc_ast_import_create.c
 *
 * \brief Create an import instance.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/ast.h>
#include <rosalind_bootstrap/error_codes.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Create a \ref rcc_ast_import instance.
 *
 * \param import        Pointer to the import pointer to be set with this
 *                      instance on success.
 * \param name          The name of this atom.
 * \param shorthand     The optional shorthand name of this atom.
 * \param loc           The location of this atom.
 *
 * \returns Zero on success and non-zero on failure.
 */
int FN_DECL_MUST_CHECK
rcc_ast_import_create(
    rcc_ast_import** import, const char* name, const char* shorthand,
    const rcc_token_details* loc)
{
    int retval;
    rcc_ast_import* tmp;

    /* allocate memory for this instance. */
    tmp = (rcc_ast_import*)malloc(sizeof(*tmp));
    if (NULL == tmp)
    {
        *import = NULL;
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

    /* copy shorthand if set. */
    if (NULL != shorthand)
    {
        tmp->shorthand = strdup(shorthand);
        if (NULL == tmp->shorthand)
        {
            retval = RCC_ERROR_OUT_OF_MEMORY;
            goto cleanup_tmp;
        }
    }
    else
    {
        tmp->shorthand = tmp->name;
    }

    /* success. */
    retval = 0;
    *import = tmp;
    goto done;

cleanup_tmp:
    rcc_ast_import_release(tmp);

done:
    return retval;
}
