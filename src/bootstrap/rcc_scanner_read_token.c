/**
 * \file bootstrap/rcc_scanner_read_token.c
 *
 * \brief Read a token from the scanner instance, skipping whitespace and
 * populating the provided token structure with details.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include "parser_internal.h"

/**
 * \brief Read a token from the scanner instance, populating the provided token
 * structure with details.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_EOF at the end of input.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad
 *        input.
 *      - a value belonging to the \ref rcc_scanner_token_type enumeration.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token(
    rcc_token_details* details, rcc_scanner* scanner)
{
    int retval, ch;

    /* read the first non-whitespace character. */
    ch = rcc_scanner_skip_whitespace(scanner);
    rcc_scanner_token_details_begin(details, scanner);

    switch (ch)
    {
        case 0:
            retval =
                rcc_scanner_token_details_end(
                    details, scanner, RCC_TOKEN_TYPE_EOF);
            goto done;

        case 'A':
            retval =
                rcc_scanner_complete_token_keyword_A_STAR(details, scanner);
            goto done;

        case 'B':
            retval = rcc_scanner_complete_token_keyword_BEGIN(details, scanner);
            goto done;

        case 'C':
            retval =
                rcc_scanner_complete_token_keyword_C_STAR(details, scanner);
            goto done;

        case 'D':
            retval =
                rcc_scanner_complete_token_keyword_D_STAR(details, scanner);
            goto done;

        case 'E':
            retval =
                rcc_scanner_complete_token_keyword_E_STAR(details, scanner);
            goto done;

        default:
            retval =
                rcc_scanner_token_details_end(
                    details, scanner, RCC_TOKEN_TYPE_BAD_INPUT);
            break;
    }

done:
    return retval;
}
