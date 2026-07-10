/**
 * \file bootstrap/rcc_scanner_read_token.c
 *
 * \brief Read a token from the scanner instance, skipping whitespace and
 * populating the provided token structure with details.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <ctype.h>

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

        case 'F':
            retval =
                rcc_scanner_complete_token_keyword_F_STAR(details, scanner);
            goto done;

        case 'G':
            retval =
                rcc_scanner_complete_token_keyword_GOTO(details, scanner);
            goto done;

        case 'H':
            retval =
                rcc_scanner_complete_token_keyword_HIDE(details, scanner);
            goto done;

        case 'I':
            retval =
                rcc_scanner_complete_token_keyword_I_STAR(details, scanner);
            goto done;

        case 'M':
            retval =
                rcc_scanner_complete_token_keyword_M_STAR(details, scanner);
            goto done;

        case 'N':
            retval =
                rcc_scanner_complete_token_keyword_N_STAR(details, scanner);
            goto done;

        case 'O':
            retval =
                rcc_scanner_complete_token_keyword_O_STAR(details, scanner);
            goto done;

        case 'P':
            retval =
                rcc_scanner_complete_token_keyword_P_STAR(details, scanner);
            goto done;

        case 'R':
            retval =
                rcc_scanner_complete_token_keyword_R_STAR(details, scanner);
            goto done;

        case 'S':
            retval =
                rcc_scanner_complete_token_keyword_S_STAR(details, scanner);
            goto done;

        case 'T':
            retval =
                rcc_scanner_complete_token_keyword_T_STAR(details, scanner);
            goto done;

        case 'U':
            retval =
                rcc_scanner_complete_token_keyword_UINT(details, scanner);
            goto done;

        case 'V':
            retval =
                rcc_scanner_complete_token_keyword_VAR(details, scanner);
            goto done;

        case 'X':
            retval =
                rcc_scanner_complete_token_keyword_XOR(details, scanner);
            goto done;

        case 'W':
            retval =
                rcc_scanner_complete_token_keyword_W_STAR(details, scanner);
            goto done;
    }

    /* if the first character is alpha, then treat this as an identifier. */
    if (isalpha(ch))
    {
        retval = rcc_scanner_complete_token_identifier(details, scanner, false);
        goto done;
    }

    /* if the first character is a number, then treat this as a number. */
    if (isdigit(ch))
    {
        retval = rcc_scanner_complete_token_number(details, scanner);
        goto done;
    }

    /* if nothing else matches, this is bad input. */
    retval =
        rcc_scanner_token_details_end(
            details, scanner, RCC_TOKEN_TYPE_BAD_INPUT);
    goto done;

done:
    return retval;
}
