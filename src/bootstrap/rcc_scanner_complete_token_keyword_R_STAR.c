/**
 * \file bootstrap/rcc_scanner_complete_token_keyword_R_STAR.c
 *
 * \brief Complete a token beginning with R.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/* forward decls. */
static int
rcc_scanner_complete_token_keyword_RECORD(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_REVEAL(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to complete keywords starting with an R.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_RECORD
 *      - RCC_TOKEN_TYPE_KEYWORD_REVEAL
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_R_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with E to be a keyword. */
    if ('E' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* handle RECORD token. */
    if ('C' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_RECORD(details, scanner);
        goto done;
    }

    /* handle REVEAL token. */
    if ('V' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_REVEAL(details, scanner);
        goto done;
    }

    /* this must be an identifier. */
    goto identifier_fallback;

identifier_fallback:
    retval =
        rcc_scanner_complete_token_identifier(
            details, scanner, false);
    goto done;

done:
    return retval;
}

/**
 * \brief Attempt to complete a RECORD keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_RECORD
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_RECORD(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with O to be a keyword. */
    if ('O' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with R to be a keyword. */
    if ('R' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with D to be a keyword. */
    if ('D' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* if the token continues with an alphanumeric, this is an identifier. */
    if (isalnum(scanner->input[1]))
    {
        goto identifier_fallback;
    }
    else
    {
        retval =
            rcc_scanner_token_details_end(
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_RECORD);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a REVEAL keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_REVEAL
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_REVEAL(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with E to be a keyword. */
    if ('E' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with A to be a keyword. */
    if ('A' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with L to be a keyword. */
    if ('L' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* if the token continues with an alphanumeric, this is an identifier. */
    if (isalnum(scanner->input[1]))
    {
        goto identifier_fallback;
    }
    else
    {
        retval =
            rcc_scanner_token_details_end(
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_REVEAL);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}
