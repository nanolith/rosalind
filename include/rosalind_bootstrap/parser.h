/**
 * \file rosalind_bootstrap/parser.h
 *
 * \brief Parser and AST for rcc-stage0.
 *
 * See LICENSE.txt for copyright and license information.
 */

#pragma once

#include <rosalind_bootstrap/error_codes.h>
#include <rosalind_bootstrap/function_decl.h>

/* C++ compatibility. */
# ifdef   __cplusplus
extern "C" {
# endif /*__cplusplus*/

enum rcc_token_type
{
    /** \brief BEGIN keyword. */
    RCC_TOKEN_TYPE_KEYWORD_BEGIN = 1,
    /** \brief END keyword. */
    RCC_TOKEN_TYPE_KEYWORD_END,
    /** \brief MODULE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_MODULE,
    /** \brief IMPORT keyword. */
    RCC_TOKEN_TYPE_KEYWORD_IMPORT,
    /** \brief PUBLIC keyword. */
    RCC_TOKEN_TYPE_KEYWORD_PUBLIC,
    /** \brief PRIVATE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_PRIVATE,
    /** \brief CONST keyword. */
    RCC_TOKEN_TYPE_KEYWORD_CONST,
    /** \brief TYPE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_TYPE,
};

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
