/**
 * \file bootstrap/rcc_scanner_complete_token_keyword_B_STAR.c
 *
 * \brief Complete a token beginning with B.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/* forward decls. */
static int
rcc_scanner_complete_token_keyword_BEGIN_(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_BOOLEAN_(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to complete keywords starting with a B.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_BEGIN
 *      - RCC_TOKEN_TYPE_KEYWORD_BOOLEAN
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_B_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* handle BEGIN token. */
    if ('E' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_BEGIN_(details, scanner);
        goto done;
    }

    /* handle BOOLEAN token. */
    if ('O' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_BOOLEAN_(details, scanner);
        goto done;
    }

    /* this must be an identifier. */
    goto identifier_fallback;

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);
    goto done;

done:
    return retval;
}

/**
 * \brief Attempt to complete a BEGIN keyword token.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_BEGIN or RCC_TOKEN_TYPE_IDENTIFIER on success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_BEGIN_(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    if ('G' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    if ('I' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    if ('N' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    if (isalnum(scanner->input[1]))
    {
        goto identifier_fallback;
    }
    else
    {
        retval =
            rcc_scanner_token_details_end(
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_BEGIN);

        rcc_scanner_next_character(scanner);

        return retval;
    }

identifier_fallback:
    return
        rcc_scanner_complete_token_identifier(
            details, scanner, false);
}

/**
 * \brief Attempt to complete a BOOLEAN keyword token.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_BOOLEAN or RCC_TOKEN_TYPE_IDENTIFIER on
 *        success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_BOOLEAN_(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    if ('O' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    if ('L' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    if ('E' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    if ('A' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    if ('N' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    if (isalnum(scanner->input[1]))
    {
        goto identifier_fallback;
    }
    else
    {
        retval =
            rcc_scanner_token_details_end(
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_BOOLEAN);

        rcc_scanner_next_character(scanner);

        return retval;
    }

identifier_fallback:
    return
        rcc_scanner_complete_token_identifier(
            details, scanner, false);
}
