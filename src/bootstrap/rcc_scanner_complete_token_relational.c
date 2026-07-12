/**
 * \file bootstrap/rcc_scanner_complete_token_relational.c
 *
 * \brief Complete a relational token, or downgrade to a simple token.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include "parser_internal.h"

/**
 * \brief Attempt to complete a relational token.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_ASSIGNMENT
 *      - RCC_TOKEN_TYPE_COLON
 *      - RCC_TOKEN_TYPE_GREATER_THAN
 *      - RCC_TOKEN_TYPE_GREATER_THAN_EQUAL
 *      - RCC_TOKEN_TYPE_LESS_THAN
 *      - RCC_TOKEN_TYPE_LESS_THAN_EQUAL
 *      - RCC_TOKEN_TYPE_NOT_EQUAL
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_relational(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;

    /* Is the next character an equal sign? */
    if ('=' == scanner->input[1])
    {
        switch (scanner->input[0])
        {
            case '<':
                rcc_scanner_next_character(scanner);
                retval =
                    rcc_scanner_token_details_end(
                        details, scanner, RCC_TOKEN_TYPE_LESS_THAN_EQUAL);
                goto done;

            case '>':
                rcc_scanner_next_character(scanner);
                retval =
                    rcc_scanner_token_details_end(
                        details, scanner, RCC_TOKEN_TYPE_GREATER_THAN_EQUAL);
                goto done;
        }
    }
    else if ('>' == scanner->input[1])
    {
        switch (scanner->input[0])
        {
            case '<':
                rcc_scanner_next_character(scanner);
                retval =
                    rcc_scanner_token_details_end(
                        details, scanner, RCC_TOKEN_TYPE_NOT_EQUAL);
                goto done;
        }
    }
    else
    {
        switch (scanner->input[0])
        {
            case '<':
                retval =
                    rcc_scanner_token_details_end(
                        details, scanner, RCC_TOKEN_TYPE_LESS_THAN);
                goto done;
        }
    }

    /* if nothing else matches, this is bad input. */
    retval =
        rcc_scanner_token_details_end(
            details, scanner, RCC_TOKEN_TYPE_BAD_INPUT);
    goto done;

done:
    return retval;
}
