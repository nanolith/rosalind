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
    /** \brief Begin a block. */
    RCC_TOKEN_TYPE_KEYWORD_BEGIN = 1,
    /** \brief End a block. */
    RCC_TOKEN_TYPE_KEYWORD_END,
};

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
