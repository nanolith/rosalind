/**
 * \file bootstrap/rcc_scanner_complete_token_keyword_E_STAR.c
 *
 * \brief Complete a token beginning with E.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/* forward decls. */
static int
rcc_scanner_complete_token_keyword_ELSE(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_END_(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to complete keywords starting with an E.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_ELSE
 *      - RCC_TOKEN_TYPE_KEYWORD_END
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_E_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* handle ELSE token. */
    if ('L' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_ELSE(details, scanner);
        goto done;
    }

    /* handle END token. */
    if ('N' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_END_(details, scanner);
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
 * \brief Attempt to complete an ELSE keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_ELSE
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_ELSE(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with S to be a keyword. */
    if ('S' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with a E to be a keyword. */
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_ELSE);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete an END keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_END
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_END_(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with D to be a keyword. */
    if ('D' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* if the next letter is an alphanumeric or number, then fall back to an
     * identifier. */
    if (isalnum(scanner->input[1]))
    {
        goto identifier_fallback;
    }
    else
    {
        retval =
            rcc_scanner_token_details_end(
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_END);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}
