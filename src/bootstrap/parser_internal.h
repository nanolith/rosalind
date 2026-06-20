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

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
