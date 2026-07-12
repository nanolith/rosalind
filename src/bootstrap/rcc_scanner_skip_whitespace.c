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

    do {
        while (0 != scanner->input[0] && isspace(scanner->input[0]))
        {
            rcc_scanner_next_character(scanner);
        }

        if ('{' != scanner->input[0])
        {
            break;
        }
        else
        {
            while (0 != scanner->input[0] && '}' != scanner->input[0])
            {
                rcc_scanner_next_character(scanner);
            }

            if (0 == scanner->input[0])
            {
                /* on EOF, return an invalid character. */
                return (unsigned char)'{';
            }
            else if ('}' == scanner->input[0])
            {
                rcc_scanner_next_character(scanner);
            }
        }
    } while (0 != scanner->input[0]);

    retval = (unsigned char)scanner->input[0];

    return retval;
}
