/**
 * \file bootstrap/rcc_scanner_next_character.c
 *
 * \brief Skip to the next character.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include "parser_internal.h"

/**
 * \brief Skip to the next character.
 *
 * \param scanner           The scanner instance for this operation.
 */
void rcc_scanner_next_character(rcc_scanner* scanner)
{
    if ('\n' == scanner->input[0])
    {
        scanner->col = 1;
        scanner->line += 1;
    }
    else
    {
        scanner->col += 1;
    }

    scanner->input += 1;
    scanner->index += 1;
}
