/**
 * \file bootstrap/rcc_scanner_complete_token_number.c
 *
 * \brief Complete a number token, or upgrade to a real token.
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
 * \brief Attempt to complete a number token.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_NUMBER
 *      - RCC_TOKEN_TYPE_REAL
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_number(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval;
    char input[30];

    /* if the current token is minus... */
    if ('-' == scanner->input[0])
    {
        /* ...and the next token is NOT a digit... */
        if (!isdigit(*(scanner->input + 1)))
        {
            /* This is a minus token. */
            retval =
                rcc_scanner_token_details_end(
                    details, scanner, RCC_TOKEN_TYPE_MINUS);
            goto done;
        }
    }

    /* read all characters. */
    while (isdigit(*(scanner->input + 1)))
    {
        rcc_scanner_next_character(scanner);
    }

    /* end number. */
    retval =
        rcc_scanner_token_details_end(details, scanner, RCC_TOKEN_TYPE_NUMBER);

    /* Get the scanned data. */
    const char* scan_start = scanner->original_input + details->begin_index;
    const char* scan_end = scanner->original_input + details->end_index;
    ptrdiff_t length = scan_end - scan_start + 1;
    char* endptr;
    if ((unsigned)length >= sizeof(input))
    {
        retval = RCC_TOKEN_TYPE_BAD_INPUT;
        goto done;
    }

    /* copy this data to an input buffer. */
    memset(input, 0, sizeof(input));
    memcpy(input, scan_start, length);

    /* attempt to convert the number to a signed integer. */
    errno = 0;
    details->primitive_val.integerv.val.signedv = strtoimax(input, &endptr, 10);
    if (*endptr || 0 != errno)
    {
        /* attempt to convert the number to an unsigned integer. */
        errno = 0;
        details->primitive_val.integerv.val.unsignedv =
            strtoumax(input, &endptr, 10);
        if (*endptr || 0 != errno)
        {
            details->type = retval = RCC_TOKEN_TYPE_BAD_INPUT;
            goto done;
        }
        details->primitive_val.integerv.is_unsigned = true;
    }
    else
    {
        details->primitive_val.integerv.is_unsigned = false;
    }

    goto done;

done:
    return retval;
}
