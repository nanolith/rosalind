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
#include <stddef.h>

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
    /** \brief RECORD keyword. */
    RCC_TOKEN_TYPE_KEYWORD_RECORD,
    /** \brief POINTER keyword. */
    RCC_TOKEN_TYPE_KEYWORD_POINTER,
    /** \brief TO keyword. */
    RCC_TOKEN_TYPE_KEYWORD_TO,
    /** \brief OPAQUE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_OPAQUE,
    /** \brief HIDE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_HIDE,
    /** \brief REVEAL keyword. */
    RCC_TOKEN_TYPE_KEYWORD_REVEAL,
    /** \brief FUNCTION keyword. */
    RCC_TOKEN_TYPE_KEYWORD_FUNCTION,
    /** \brief PROCEDURE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_PROCEDURE,
    /** \brief VAR keyword. */
    RCC_TOKEN_TYPE_KEYWORD_VAR,
    /** \brief PRECONDITIONS keyword. */
    RCC_TOKEN_TYPE_KEYWORD_PRECONDITIONS,
    /** \brief POSTCONDITIONS keyword. */
    RCC_TOKEN_TYPE_KEYWORD_POSTCONDITIONS,
    /** \brief INVARIANTS keyword. */
    RCC_TOKEN_TYPE_KEYWORD_INVARIANTS,
    /** \brief INTERFACE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_INTERFACE,
    /** \brief IMPLEMENTS keyword. */
    RCC_TOKEN_TYPE_KEYWORD_IMPLEMENTS,
    /** \brief IMPLEMENT keyword. */
    RCC_TOKEN_TYPE_KEYWORD_IMPLEMENT,

    /** \brief identifier token. */
    RCC_TOKEN_TYPE_IDENTIFIER,

    /** \brief bad input. */
    RCC_TOKEN_TYPE_BAD_INPUT,
};

/**
 * \brief Token details.
 */
typedef struct rcc_token_details rcc_token_details;
struct rcc_token_details
{
    int type;
    size_t begin_index;
    size_t end_index;
    size_t begin_line;
    size_t end_line;
    size_t begin_col;
    size_t end_col;
};

/**
 * \brief rcc_scanner implementation.
 */
typedef struct rcc_scanner rcc_scanner;
struct rcc_scanner
{
    const char* original_input;
    const char* input;
    size_t index;
    size_t line;
    size_t col;
};

/******************************************************************************/
/* Start of constructors.                                                     */
/******************************************************************************/

/**
 * \brief Create a \ref rcc_scanner instance.
 *
 * \param scanner           Pointer to the scanner pointer to be set to this
 *                          created scanner instance on success.
 * \param input             The input string to scan.
 *
 * \returns a status code indicating success or failure.
 *      - 0 on success.
 *      - a non-zero error code on failure.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_create(rcc_scanner** scanner, const char* input);

/**
 * \brief Release a \ref rcc_scanner instance.
 *
 * \param scanner           The scanner to release.
 */
void
rcc_scanner_release(rcc_scanner* scanner);

/******************************************************************************/
/* Start of public methods.                                                   */
/******************************************************************************/

/**
 * \brief Read a token from the scanner instance, populating the provided token
 * structure with details.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_SCANNER_TOKEN_TYPE_EOF at the end of input.
 *      - RCC_SCANNER_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad
 *        input.
 *      - a value belonging to the \ref rcc_scanner_token_type enumeration.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Peek a token from the scanner instance, populating the provided token
 * structure with details.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_SCANNER_TOKEN_TYPE_EOF at the end of input.
 *      - RCC_SCANNER_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad
 *        input.
 *      - a value belonging to the \ref rcc_scanner_token_type enumeration.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_peek_token(
    rcc_token_details* details, rcc_scanner* scanner);

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
