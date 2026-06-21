/**
 * \file bootstrap/rcc_scanner_skip_whitespace.c
 *
 * \brief Skip whitespace and return the first non-whitespace character.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/**
 * \brief Skip over whitespace, returning the first non-whitespace character.
 *
 * Update the line and column information.
 *
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a non-whitespace character or 0.
 *      - a non-whitespace character.
 *      - 0 if EOF was reached.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_skip_whitespace(rcc_scanner* scanner)
{
    int retval;

    while (*(scanner->input) != 0 && isspace(*(scanner->input)))
    {
        rcc_scanner_next_character(scanner);
    }

    retval = (unsigned char)*(scanner->input);

    return retval;
}
