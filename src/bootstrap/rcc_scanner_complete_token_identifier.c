/**
 * \file bootstrap/rcc_scanner_complete_token_identifier.c
 *
 * \brief Complete an identifier token.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "parser_internal.h"

/**
 * \brief Attempt to complete an identifier token.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 * \param read_start        Set to true if this read starts with the first
 *                          character of the identifier.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_IDENTIFIER on success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_identifier(
    rcc_token_details* details, rcc_scanner* scanner, bool read_start)
{
    int retval, peek;

    peek = *(scanner->input + 1);

    if (read_start)
    {
        if (!isalpha(peek) && '_' != peek)
        {
            return RCC_TOKEN_TYPE_BAD_INPUT;
        }
    }

    while (isalnum(peek) || '_' == peek)
    {
        rcc_scanner_next_character(scanner);
        peek = *(scanner->input + 1);
    }

    retval =
        rcc_scanner_token_details_end(
            details, scanner, RCC_TOKEN_TYPE_IDENTIFIER);

    rcc_scanner_next_character(scanner);

    return retval;
}
