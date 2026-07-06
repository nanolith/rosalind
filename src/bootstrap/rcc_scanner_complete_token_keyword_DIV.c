/**
 * \file bootstrap/rcc_scanner_complete_token_keyword_DIV.c
 *
 * \brief Complete a DIV token.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/**
 * \brief Attempt to complete a DIV keyword token.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_DIV or RCC_TOKEN_TYPE_IDENTIFIER on success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_DIV(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    if ('I' != *(scanner->input + 1))
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    if ('V' != *(scanner->input + 1))
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    if (isalnum(*(scanner->input + 1)))
    {
        goto identifier_fallback;
    }
    else
    {
        retval =
            rcc_scanner_token_details_end(
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_DIV);

        rcc_scanner_next_character(scanner);

        return retval;
    }

identifier_fallback:
    return
        rcc_scanner_complete_token_identifier(
            details, scanner, false);
}
