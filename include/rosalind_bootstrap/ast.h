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
 * \brief AST list node.
 */
typedef struct rcc_ast_list_node rcc_ast_list_node;
struct rcc_ast_list_node
{
    rcc_ast_list_node* next;
};

/**
 * \brief Import spec atom.
 */
typedef struct rcc_ast_import_spec_atom rcc_ast_import_spec_atom;
struct rcc_ast_import_spec_atom
{
    rcc_ast_list_node hdr;
    char* name;
    rcc_token_details loc;
};

/**
 * \brief Import definition.
 */
typedef struct rcc_ast_import rcc_ast_import;
struct rcc_ast_import
{
    rcc_ast_list_node hdr;
    char* name;
    char* shorthand;
    rcc_token_details loc;
    rcc_ast_import_spec_atom* import_spec_head;
};

/**
 * \brief Module definition.
 */
typedef struct rcc_ast_module rcc_ast_module;
struct rcc_ast_module
{
    char* name;
    rcc_token_details loc;
    rcc_ast_import* import_head;
};

/**
 * \brief Reverse a linked list.
 *
 * \param list          The list to reverse.
 */
void rcc_ast_list_node_reverse(rcc_ast_list_node** list);

/**
 * \brief Create a \ref rcc_ast_import_spec_atom instance.
 *
 * \param atom          Pointer to the atom pointer to be set with this instance
 *                      on success.
 * \param name          The name of this atom.
 * \param loc           The location of this atom.
 *
 * \returns Zero on success and non-zero on failure.
 */
int FN_DECL_MUST_CHECK
rcc_ast_import_spec_atom_create(
    rcc_ast_import_spec_atom** atom, const char* name,
    const rcc_token_details* loc);

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
