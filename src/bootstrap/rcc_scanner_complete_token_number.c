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

/* forward decls. */
static bool is_sigil(int ch, int* base);
static void copy_digits(char* output, const char* input, ptrdiff_t* length);

/**
 * \brief Attempt to complete a number token.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 * \param base              The base for this number.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_NUMBER
 *      - RCC_TOKEN_TYPE_REAL
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_number(
    rcc_token_details* details, rcc_scanner* scanner, int base)
{
    int retval;
    char input[30];

    /* if the current token is minus... */
    if ('-' == scanner->input[0])
    {
        /* ...and the next token is a sigil... */
        if (is_sigil(*(scanner->input + 1), &base))
        {
            /* the base is updated and we continue... */
            rcc_scanner_next_character(scanner);
        }
        /* ...and the next token is NOT a digit... */
        else if (!isdigit(*(scanner->input + 1)))
        {
            /* This is a minus token. */
            retval =
                rcc_scanner_token_details_end(
                    details, scanner, RCC_TOKEN_TYPE_MINUS);
            goto done;
        }
    }

    /* read all characters. */
    while (isalnum(*(scanner->input + 1)))
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
    copy_digits(input, scan_start, &length);

    /* attempt to convert the number to a signed integer. */
    errno = 0;
    details->primitive_val.integerv.val.signedv
        = strtoimax(input, &endptr, base);
    if (*endptr || 0 != errno)
    {
        /* attempt to convert the number to an unsigned integer. */
        errno = 0;
        details->primitive_val.integerv.val.unsignedv =
            strtoumax(input, &endptr, base);
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

/**
 * \brief Return true if the given character is a sigil, and set the base.
 *
 * \param ch            The character to check.
 * \param base          Pointer to the base to update on true.
 *
 * \returns true if the character is a sigil and false otherwise.
 */
static bool is_sigil(int ch, int* base)
{
    switch (ch)
    {
        case '$':
            *base = 16;
            return true;

        default:
            return false;
    }
}

/**
 * \brief Copy digits from input to output, skipping any sigils.
 *
 * \param output                Pointer to the output buffer, to which digitsare
 *                              copied.
 * \param input                 Pointer to the input buffer, from which digits
 *                              are copied.
 * \param length                On input, the length of the input buffer. On
 *                              output, the length of the copied data.
 */
static void copy_digits(char* output, const char* input, ptrdiff_t* length)
{
    ptrdiff_t outidx = 0;
    ptrdiff_t i = 0;

    /* handle unary minus. */
    if (i < *length && '-' == input[i])
    {
        output[outidx++] = input[i++];
    }

    for (; i < *length; ++i)
    {
        if (isalnum(input[i]))
        {
            output[outidx++] = input[i];
        }
    }

    *length = outidx;
}
