/**
 * \file bootstrap/rcc_scanner_complete_token_keyword_P_STAR.c
 *
 * \brief Complete a token beginning with P.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/* forward decls. */
static int
rcc_scanner_complete_token_keyword_PO_STAR(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_POINTER(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_POSTCONDITIONS(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_PR_STAR(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_PRECONDITIONS(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_PRIVATE(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_PROCEDURE(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_PUBLIC(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to complete keywords starting with a P.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_POINTER
 *      - RCC_TOKEN_TYPE_KEYWORD_POSTCONDITIONS
 *      - RCC_TOKEN_TYPE_KEYWORD_PRECONDITIONS
 *      - RCC_TOKEN_TYPE_KEYWORD_PRIVATE
 *      - RCC_TOKEN_TYPE_KEYWORD_PROCEDURE
 *      - RCC_TOKEN_TYPE_KEYWORD_PUBLIC
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_P_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* handle PO* tokens. */
    if ('O' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_PO_STAR(details, scanner);
        goto done;
    }

    /* handle PR* tokens. */
    if ('R' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_PR_STAR(details, scanner);
        goto done;
    }

    /* handle PUBLIC token. */
    if ('U' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_PUBLIC(details, scanner);
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
 * \brief Attempt to complete keywords starting with PO.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_POINTER
 *      - RCC_TOKEN_TYPE_KEYWORD_POSTCONDITIONS
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_PO_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* if the next letter is I, attempt to read a POINTER keyword. */
    if ('I' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_POINTER(details, scanner);
        goto done;
    }

    /* if the next letter is S, attempt to read a POSTCONDITIONS keyword. */
    if ('S' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval =
            rcc_scanner_complete_token_keyword_POSTCONDITIONS(details, scanner);
        goto done;
    }

    /* fall back to an identifier. */
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);
    goto done;

done:
    return retval;
}

/**
 * \brief Attempt to complete a POINTER keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_POINTER
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_POINTER(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with N to be a keyword. */
    if ('N' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with T to be a keyword. */
    if ('T' != scanner->input[1])
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

    /* the next letter must start with R to be a keyword. */
    if ('R' != scanner->input[1])
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_POINTER);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a POSTCONDITIONS keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_POSTCONDITIONS
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_POSTCONDITIONS(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with T to be a keyword. */
    if ('T' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with C to be a keyword. */
    if ('C' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with O to be a keyword. */
    if ('O' != scanner->input[1])
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

    /* the next letter must start with D to be a keyword. */
    if ('D' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with I to be a keyword. */
    if ('I' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with T to be a keyword. */
    if ('T' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with I to be a keyword. */
    if ('I' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with O to be a keyword. */
    if ('O' != scanner->input[1])
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

    /* the next letter must start with S to be a keyword. */
    if ('S' != scanner->input[1])
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_POSTCONDITIONS);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete keywords starting with PR.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_PRECONDITIONS
 *      - RCC_TOKEN_TYPE_KEYWORD_PRIVATE
 *      - RCC_TOKEN_TYPE_KEYWORD_PROCEDURE
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_PR_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* if the next letter is E, attempt to read a PRECONDITIONS keyword. */
    if ('E' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval =
            rcc_scanner_complete_token_keyword_PRECONDITIONS(details, scanner);
        goto done;
    }

    /* if the next letter is I, attempt to read a PRIVATE keyword. */
    if ('I' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_PRIVATE(details, scanner);
        goto done;
    }

    /* if the next letter is O, attempt to read a PROCEDURE keyword. */
    if ('O' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_PROCEDURE(details, scanner);
        goto done;
    }

    /* fall back to an identifier. */
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);
    goto done;

done:
    return retval;
}

/**
 * \brief Attempt to complete a PRECONDITIONS keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_PRECONDITIONS
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_PRECONDITIONS(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with C to be a keyword. */
    if ('C' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with O to be a keyword. */
    if ('O' != scanner->input[1])
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

    /* the next letter must start with D to be a keyword. */
    if ('D' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with I to be a keyword. */
    if ('I' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with T to be a keyword. */
    if ('T' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with I to be a keyword. */
    if ('I' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with O to be a keyword. */
    if ('O' != scanner->input[1])
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

    /* the next letter must start with S to be a keyword. */
    if ('S' != scanner->input[1])
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_PRECONDITIONS);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a PRIVATE keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_PRIVATE
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_PRIVATE(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with V to be a keyword. */
    if ('V' != scanner->input[1])
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

    /* the next letter must start with T to be a keyword. */
    if ('T' != scanner->input[1])
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_PRIVATE);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a PROCEDURE keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_PROCEDURE
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_PROCEDURE(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with C to be a keyword. */
    if ('C' != scanner->input[1])
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

    /* the next letter must start with D to be a keyword. */
    if ('D' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with U to be a keyword. */
    if ('U' != scanner->input[1])
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_PROCEDURE);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a PUBLIC keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_PUBLIC
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_PUBLIC(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with B to be a keyword. */
    if ('B' != scanner->input[1])
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

    /* the next letter must start with I to be a keyword. */
    if ('I' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with C to be a keyword. */
    if ('C' != scanner->input[1])
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_PUBLIC);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}
