/**
 * \file bootstrap/rcc_scanner_read_token_keyword_DIV.c
 *
 * \brief Read a DIV token.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/**
 * \brief Attempt to read a DIV keyword token.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_DIV is used by the scanner
 * proper, and called by this function.
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
rcc_scanner_read_token_keyword_DIV(
    rcc_token_details* details, rcc_scanner* scanner)
{
    /* for this function, the token must begin with a 'D'. */
    if ('D' != *(scanner->input))
    {
        return RCC_TOKEN_TYPE_BAD_INPUT;
    }

    /* start the token. */
    rcc_scanner_token_details_begin(details, scanner);

    /* attempt to complete this token. */
    return rcc_scanner_complete_token_keyword_DIV(details, scanner);
}
