/**
 * \file bootstrap/parser_internal.h
 *
 * \brief Internals for rcc-stage0 parser.
 *
 * See LICENSE.txt for copyright and license information.
 */

#pragma once

#include <rosalind_bootstrap/parser.h>

/* C++ compatibility. */
# ifdef   __cplusplus
extern "C" {
# endif /*__cplusplus*/

/******************************************************************************/
/* Start of private methods.                                                  */
/******************************************************************************/

/**
 * \brief Skip to the next character.
 *
 * \param scanner           The scanner instance for this operation.
 */
void rcc_scanner_next_character(rcc_scanner* scanner);

/**
 * \brief Skip over whitespace, returning the first non-whitespace character.
 *
 * Update the line and column information.
 *
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a non-whitespace character or 0.
 *      - a non-whitespace character.
 *      - 0 if EOF was reached.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_skip_whitespace(rcc_scanner* scanner);

/**
 * \brief Begin the input token, populating token details.
 *
 * \param details           The details to populate with the begin token data.
 * \param scanner           The scanner instance.
 */
void rcc_scanner_token_details_begin(
    rcc_token_details* details, rcc_scanner* scanner);

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
    rcc_token_details* details, rcc_scanner* scanner, int type);

/**
 * \brief Attempt to complete a BEGIN keyword token.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_BEGIN or RCC_TOKEN_TYPE_IDENTIFIER on success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_complete_token_keyword_BEGIN(
    rcc_token_details* details, rcc_scanner* scanner);

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
