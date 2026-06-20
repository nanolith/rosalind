/**
 * \file bootstrap/rcc_scanner_create.c
 *
 * \brief Create a scanner instance.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <stdlib.h>
#include <string.h>

#include "parser_internal.h"

/**
 * \brief Create a \ref rcc_scanner instance.
 *
 * \param scanner           Pointer to the scanner pointer to be set to this
 *                          created scanner instance on success.
 * \param input             The input string to scan.
 *
 * \returns a status code indicating success or failure.
 *      - 0 on success.
 *      - a non-zero error code on failure.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_create(rcc_scanner** scanner, const char* input)
{
    int retval;
    rcc_scanner* tmp;

    /* allocate memory for this instance. */
    tmp = (rcc_scanner*)malloc(sizeof(*tmp));
    if (NULL == tmp)
    {
        *scanner = NULL;
        retval = RCC_ERROR_OUT_OF_MEMORY;
        goto done;
    }

    /* initialize tmp. */
    memset(tmp, 0, sizeof(*tmp));
    tmp->original_input = tmp->input = input;
    tmp->index = 0;
    tmp->line = tmp->col = 1;

    /* success. */
    *scanner = tmp;
    retval = 0;
    goto done;

done:
    if (0 != retval)
    {
        *scanner = NULL;
    }

    return retval;
}
