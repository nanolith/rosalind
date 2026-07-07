/**
 * \file bootstrap/rcc_scanner_complete_token_keyword_C_STAR.c
 *
 * \brief Complete a token beginning with C.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/* forward decls. */
static int
rcc_scanner_complete_token_keyword_CASE(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_CONST_(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to complete keywords starting with a C.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_CASE
 *      - RCC_TOKEN_TYPE_KEYWORD_CONST
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_C_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* handle CASE token. */
    if ('A' == *(scanner->input + 1))
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_CASE(details, scanner);
        goto done;
    }

    /* handle CONST token. */
    if ('O' == *(scanner->input + 1))
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_CONST_(details, scanner);
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
 * \brief Attempt to complete a CASE keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_CASE
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_CASE(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with S to be a keyword. */
    if ('S' != *(scanner->input + 1))
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with E to be a keyword. */
    if ('E' != *(scanner->input + 1))
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_CASE);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a CONST keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_CONST
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_CONST_(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with N to be a keyword. */
    if ('N' != *(scanner->input + 1))
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with S to be a keyword. */
    if ('S' != *(scanner->input + 1))
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

    /* if the token continues with an alphanumeric, this is an identifier. */
    if (isalnum(*(scanner->input + 1)))
    {
        goto identifier_fallback;
    }
    else
    {
        retval =
            rcc_scanner_token_details_end(
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_CONST);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}
