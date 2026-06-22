/**
 * \file bootstrap/rcc_scanner_token_details_end.c
 *
 * \brief End the token details for a given token type.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include "parser_internal.h"

/**
 * \brief End the current input token, populating token details.
 *
 * \param details           The details to populate with the end token data.
 * \param scanner           The scanner instance.
 * \param type              The token type.
 *
 * \returns the token type.
 */
int rcc_scanner_token_details_end(
    rcc_token_details* details, rcc_scanner* scanner, int type)
{
    details->type = type;
    details->end_index = scanner->index;
    details->end_line = scanner->line;
    details->end_col = scanner->col;

    return type;
}
