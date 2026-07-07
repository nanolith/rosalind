/**
 * \file bootstrap/rcc_scanner_complete_token_keyword_F_STAR.c
 *
 * \brief Complete a token beginning with F.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/* forward decls. */
static int
rcc_scanner_complete_token_keyword_FOR(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_FUNCTION_(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to complete keywords starting with an F.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_FOR
 *      - RCC_TOKEN_TYPE_KEYWORD_FUNCTION
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_F_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* handle FOR keyword. */
    if ('O' == *(scanner->input + 1))
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_FOR(details, scanner);
        goto done;
    }

    /* handle FUNCTION keyword. */
    if ('U' == *(scanner->input + 1))
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_FUNCTION_(details, scanner);
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
 * \brief Attempt to complete a FOR keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_FOR
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_FOR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with R to be a keyword. */
    if ('R' != *(scanner->input + 1))
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_FOR);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a FUNCTION keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_FUNCTION
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_FUNCTION_(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with N to be a keyword. */
    if ('N' != *(scanner->input + 1))
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with C to be a keyword. */
    if ('C' != *(scanner->input + 1))
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with T to be a keyword. */
    if ('T' != *(scanner->input + 1))
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with I to be a keyword. */
    if ('I' != *(scanner->input + 1))
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with O to be a keyword. */
    if ('O' != *(scanner->input + 1))
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with N to be a keyword. */
    if ('N' != *(scanner->input + 1))
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_FUNCTION);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}
