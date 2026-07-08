/**
 * \file bootstrap/rcc_scanner_complete_token_keyword_S_STAR.c
 *
 * \brief Complete a token beginning with S.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/* forward decls. */
static int
rcc_scanner_complete_token_keyword_SET(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_SHL(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_SHR(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to complete keywords starting with an S.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_SET
 *      - RCC_TOKEN_TYPE_KEYWORD_SHL
 *      - RCC_TOKEN_TYPE_KEYWORD_SHR
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_S_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* handle SET keyword. */
    if ('E' == *(scanner->input + 1))
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_SET(details, scanner);
        goto done;
    }

    /* the next letter must start with H to be a keyword. */
    if ('H' != *(scanner->input + 1))
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* handle SHL keyword. */
    if ('L' == *(scanner->input + 1))
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_SHL(details, scanner);
        goto done;
    }

    /* handle SHR keyword. */
    if ('R' == *(scanner->input + 1))
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_SHR(details, scanner);
        goto done;
    }

    /* fall back to identifier. */
    goto identifier_fallback;

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a SET keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_SET
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_SET(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_SET);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a SHL keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_SHL
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_SHL(
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_SHL);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a SHR keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_SHR
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_SHR(
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_SHR);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}
