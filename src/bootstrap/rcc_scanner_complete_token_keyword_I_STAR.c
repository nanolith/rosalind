/**
 * \file bootstrap/rcc_scanner_complete_token_keyword_I_STAR.c
 *
 * \brief Complete a token beginning with I.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

#include "parser_internal.h"

/* forward decls. */
static int
rcc_scanner_complete_token_keyword_IF(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_IM_STAR(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_IMPORT(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_IMPL_STAR(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_IMPLEMENTS(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_IN_STAR(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_INT_STAR(
    rcc_token_details* details, rcc_scanner* scanner);
static int
rcc_scanner_complete_token_keyword_INVARIANTS(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to complete keywords starting with an I.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_IF
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPLEMENT
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPLEMENTS
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPORT
 *      - RCC_TOKEN_TYPE_KEYWORD_IN
 *      - RCC_TOKEN_TYPE_KEYWORD_INT
 *      - RCC_TOKEN_TYPE_KEYWORD_INTERFACE
 *      - RCC_TOKEN_TYPE_KEYWORD_INVARIANTS
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_I_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* handle IF token. */
    if ('F' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_IF(details, scanner);
        goto done;
    }

    /* handle IM* tokens. */
    if ('M' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_IM_STAR(details, scanner);
        goto done;
    }

    /* handle IN* tokens. */
    if ('N' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_IN_STAR(details, scanner);
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
 * \brief Attempt to complete an IF keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_IF
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_IF(
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_IF);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete keywords starting with IM.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPLEMENT
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPLEMENTS
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPORT
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_IM_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with P to be a keyword. */
    if ('P' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* if the next letter is O, attempt to read an IMPORT. */
    if ('O' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_IMPORT(details, scanner);
        goto done;
    }

    /* if the next letter is L, attempt to read IMPL* keywords. */
    if ('L' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_IMPL_STAR(details, scanner);
        goto done;
    }

    /* fall back to an identifier. */
    goto identifier_fallback;

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete an IMPORT keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPORT
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_IMPORT(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with R to be a keyword. */
    if ('R' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with a T to be a keyword. */
    if ('T' != scanner->input[1])
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_IMPORT);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete a keyword starting with IMPL.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPLEMENT
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPLEMENTS
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_IMPL_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with E to be a keyword. */
    if ('E' != scanner->input[1])
    {
        goto identifier_fallback;
    }
    rcc_scanner_next_character(scanner);

    /* the next letter must start with M to be a keyword. */
    if ('M' != scanner->input[1])
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

    /* if the next letter is an S, then go down the IMPLEMENTS path. */
    if ('S' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval =
            rcc_scanner_complete_token_keyword_IMPLEMENTS(details, scanner);
        goto done;
    }

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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_IMPLEMENT);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete an IMPLEMENTS keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPLEMENTS
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_IMPLEMENTS(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_IMPLEMENTS);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete keywords starting with an IN.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_INTERFACE
 *      - RCC_TOKEN_TYPE_KEYWORD_INVARIANTS
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_IN_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* If the next letter is a T, try to complete INTERFACE. */
    if ('T' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval = rcc_scanner_complete_token_keyword_INT_STAR(details, scanner);
        goto done;
    }

    /* If the next letter is a V, try to complete INVARIANTS. */
    if ('V' == scanner->input[1])
    {
        rcc_scanner_next_character(scanner);
        retval =
            rcc_scanner_complete_token_keyword_INVARIANTS(details, scanner);
        goto done;
    }

    /* if the next letter is an alphanumeric or number, then fall back to an
     * identifier. */
    if (isalnum(scanner->input[1]))
    {
        /* identifier fallback. */
        retval = rcc_scanner_complete_token_identifier(details, scanner, false);
        goto done;
    }
    else
    {
        retval =
            rcc_scanner_token_details_end(
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_IN);
        rcc_scanner_next_character(scanner);
        goto done;
    }

done:
    return retval;
}

/**
 * \brief Attempt to complete an INTERFACE keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_INTERFACE
 *      - RCC_TOKEN_TYPE_INT
 *      - RCC_TOKEN_TYPE_INTERFACE
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_INT_STAR(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* A non-alpha / number means this is an INT. */
    if (!isalnum(scanner->input[1]))
    {
        retval =
            rcc_scanner_token_details_end(
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_INT);
        rcc_scanner_next_character(scanner);
        goto done;
    }

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

    /* the next letter must start with F to be a keyword. */
    if ('F' != scanner->input[1])
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

    /* if the token continues with an alphanumeric, this is an identifier. */
    if (isalnum(scanner->input[1]))
    {
        goto identifier_fallback;
    }
    else
    {
        retval =
            rcc_scanner_token_details_end(
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_INTERFACE);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}

/**
 * \brief Attempt to complete an INVARIANTS keyword.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_INVARIANTS
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
static int
rcc_scanner_complete_token_keyword_INVARIANTS(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* the next letter must start with A to be a keyword. */
    if ('A' != scanner->input[1])
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

    /* the next letter must start with I to be a keyword. */
    if ('I' != scanner->input[1])
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
                details, scanner, RCC_TOKEN_TYPE_KEYWORD_INVARIANTS);
        rcc_scanner_next_character(scanner);
        goto done;
    }

identifier_fallback:
    retval = rcc_scanner_complete_token_identifier(details, scanner, false);

done:
    return retval;
}
