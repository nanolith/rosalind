/**
 * \file bootstrap/rcc_scanner_token_details_begin.c
 *
 * \brief Begin the token details for a given token type.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include "parser_internal.h"

/**
 * \brief Begin the input token, populating token details.
 *
 * \param details           The details to populate with the begin token data.
 * \param scanner           The scanner instance.
 */
void rcc_scanner_token_details_begin(
    rcc_token_details* details, rcc_scanner* scanner)
{
    details->type = RCC_TOKEN_TYPE_BAD_INPUT;
    details->begin_index = details->end_index = scanner->index;
    details->begin_line = details->end_line = scanner->line;
    details->begin_col = details->end_col = scanner->col;
}
