/**
 * \file bootstrap/rcc_scanner_complete_token_keyword_D_STAR.c
 *
 * \brief Complete a token beginning with D.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/* forward decls. */
static int
rcc_scanner_complete_token_keyword_DIV_(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_DO(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to complete keywords starting with a D.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_DIV
 *      - RCC_TOKEN_TYPE_KEYWORD_DO
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_D_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* handle DIV keyword. */
    if ('I' == *(scanner->input + 1))
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_DIV_(details, scanner);
        goto done;
    }

    /* handle DO keyword. */
    if ('O' == *(scanner->input + 1))
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_DO(details, scanner);
        goto done;
    }

    /* identifier fallback. */
    retval =
        rcc_scanner_complete_token_identifier(
            details, scanner, false);
    goto done;

done:
    return retval;
}

/**
 * \brief Attempt to complete a DIV keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_DIV
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_DIV_(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with V to be a keyword. */
    if ('V' != *(scanner->input + 1))
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* if the token continues with an alphanumeric, this is an identifier. */
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
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a DO keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_DO
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_DO(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* if the token continues with an alphanumeric, this is an identifier. */
    if (isalnum(*(scanner->input + 1)))
    {
        goto identifier_fallback;
    }
    else
    {
        retval =
            rcc_scanner_token_details_end(
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_DO);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}
