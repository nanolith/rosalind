/**
 * \file bootstrap/rcc_scanner_complete_token_keyword_T_STAR.c
 *
 * \brief Complete a token beginning with T.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/* forward decls. */
static int
rcc_scanner_complete_token_keyword_THEN(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_TO(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_TYPE(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to complete keywords starting with a T.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_THEN
 *      - RCC_TOKEN_TYPE_KEYWORD_TO
 *      - RCC_TOKEN_TYPE_KEYWORD_TYPE
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_T_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* handle THEN token. */
    if ('H' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_THEN(details, scanner);
        goto done;
    }

    /* handle TO token. */
    if ('O' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_TO(details, scanner);
        goto done;
    }

    /* handle TYPE token. */
    if ('Y' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_TYPE(details, scanner);
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
 * \brief Attempt to complete a THEN keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_THEN
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_THEN(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with E to be a keyword. */
    if ('E' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with N to be a keyword. */
    if ('N' != scanner->input[1])
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_THEN);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a TO keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_TO
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_TO(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* if the token continues with an alphanumeric, this is an identifier. */
    if (isalnum(scanner->input[1]))
    {
        goto identifier_fallback;
    }
    else
    {
        retval =
            rcc_scanner_token_details_end(
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_TO);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a TYPE keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_TYPE
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_TYPE(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with P to be a keyword. */
    if ('P' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with E to be a keyword. */
    if ('E' != scanner->input[1])
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_TYPE);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}
