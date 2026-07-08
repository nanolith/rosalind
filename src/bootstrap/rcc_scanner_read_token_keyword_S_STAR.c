/**
 * \file bootstrap/rcc_scanner_read_token_keyword_S_STAR.c
 *
 * \brief Read all of the tokens beginning with an S.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/**
 * \brief Attempt to read keywords starting with the letter S.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_S_STAR is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_SHL
 *      - RCC_TOKEN_TYPE_KEYWORD_SHR
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_S_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    /* for this function, the token must begin with an 'S'. */
    if ('S' != *(scanner->input))
    {
        return RCC_TOKEN_TYPE_BAD_INPUT;
    }

    /* start the token. */
    rcc_scanner_token_details_begin(details, scanner);

    /* attempt to complete this token. */
    return rcc_scanner_complete_token_keyword_S_STAR(details, scanner);
}
