/**
 * \file rosalind_bootstrap/ast.h
 *
 * \brief AST for rcc-stage0.
 *
 * See LICENSE.txt for copyright and license information.
 */

#pragma once

#include <rosalind_bootstrap/function_decl.h>
#include <rosalind_bootstrap/token.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* C++ compatibility. */
# ifdef   __cplusplus
extern "C" {
# endif /*__cplusplus*/

/**
 * \brief Module definition.
 */
typedef struct rcc_ast_module rcc_ast_module;
struct rcc_ast_module
{
    char* name;
    rcc_token_details module_loc;
};

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
