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

/**
 * \brief Release a \ref rcc_ast_import_spec_atom instance.
 *
 * \param atom          The atom to release.
 */
void
rcc_ast_import_spec_atom_release(rcc_ast_import_spec_atom* atom);

/**
 * \brief Create a \ref rcc_ast_import instance.
 *
 * \param import        Pointer to the import pointer to be set with this
 *                      instance on success.
 * \param name          The name of this atom.
 * \param shorthand     The optional shorthand name of this atom.
 * \param loc           The location of this atom.
 *
 * \returns Zero on success and non-zero on failure.
 */
int FN_DECL_MUST_CHECK
rcc_ast_import_create(
    rcc_ast_import** import, const char* name, const char* shorthand,
    const rcc_token_details* loc);

/**
 * \brief Release a \ref rcc_ast_import instance.
 *
 * \param import        The import to release.
 */
void
rcc_ast_import_release(rcc_ast_import* import);

/**
 * \brief Add an import spec atom to the given import.
 *
 * \note This import takes ownership of this atom and will release it when it is
 * released.
 *
 * \param import        The import to which this atom is added.
 * \param atom          The atom to add.
 *
 * \returns Zero on success and non-zero on failure.
 */
int FN_DECL_MUST_CHECK
rcc_ast_import_add_atom(
    rcc_ast_import* import, rcc_ast_import_spec_atom* atom);

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
