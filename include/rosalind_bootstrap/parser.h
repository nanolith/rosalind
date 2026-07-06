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
    /** \brief AND keyword. */
    RCC_TOKEN_TYPE_KEYWORD_AND = 1,
    /** \brief BEGIN keyword. */
    RCC_TOKEN_TYPE_KEYWORD_BEGIN,
    /** \brief CONST keyword. */
    RCC_TOKEN_TYPE_KEYWORD_CONST,
    /** \brief END keyword. */
    RCC_TOKEN_TYPE_KEYWORD_END,
    /** \brief FUNCTION keyword. */
    RCC_TOKEN_TYPE_KEYWORD_FUNCTION,
    /** \brief HIDE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_HIDE,
    /** \brief IMPLEMENT keyword. */
    RCC_TOKEN_TYPE_KEYWORD_IMPLEMENT,
    /** \brief IMPLEMENTS keyword. */
    RCC_TOKEN_TYPE_KEYWORD_IMPLEMENTS,
    /** \brief IMPORT keyword. */
    RCC_TOKEN_TYPE_KEYWORD_IMPORT,
    /** \brief INTERFACE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_INTERFACE,
    /** \brief INVARIANTS keyword. */
    RCC_TOKEN_TYPE_KEYWORD_INVARIANTS,
    /** \brief MODULE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_MODULE,
    /** \brief NOT keyword. */
    RCC_TOKEN_TYPE_KEYWORD_NOT,
    /** \brief OPAQUE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_OPAQUE,
    /** \brief OR keyword. */
    RCC_TOKEN_TYPE_KEYWORD_OR,
    /** \brief POINTER keyword. */
    RCC_TOKEN_TYPE_KEYWORD_POINTER,
    /** \brief POSTCONDITIONS keyword. */
    RCC_TOKEN_TYPE_KEYWORD_POSTCONDITIONS,
    /** \brief PRECONDITIONS keyword. */
    RCC_TOKEN_TYPE_KEYWORD_PRECONDITIONS,
    /** \brief PRIVATE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_PRIVATE,
    /** \brief PROCEDURE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_PROCEDURE,
    /** \brief PUBLIC keyword. */
    RCC_TOKEN_TYPE_KEYWORD_PUBLIC,
    /** \brief RECORD keyword. */
    RCC_TOKEN_TYPE_KEYWORD_RECORD,
    /** \brief REVEAL keyword. */
    RCC_TOKEN_TYPE_KEYWORD_REVEAL,
    /** \brief TO keyword. */
    RCC_TOKEN_TYPE_KEYWORD_TO,
    /** \brief TYPE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_TYPE,
    /** \brief VAR keyword. */
    RCC_TOKEN_TYPE_KEYWORD_VAR,
    /** \brief XOR keyword. */
    RCC_TOKEN_TYPE_KEYWORD_XOR,

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

/**
 * \brief Attempt to read an AND keyword token.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_AND is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_AND or RCC_TOKEN_TYPE_IDENTIFIER on success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_AND(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read a BEGIN keyword token.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_BEGIN is used by the scanner
 * proper, and called by this function.
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
rcc_scanner_read_token_keyword_BEGIN(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read a CONST keyword token.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_CONST is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_CONST or RCC_TOKEN_TYPE_IDENTIFIER on success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_CONST(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read a END keyword token.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_END is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_END or RCC_TOKEN_TYPE_IDENTIFIER on success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_END(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read a FUNCTION keyword token.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_FUNCTION is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_FUNCTION or RCC_TOKEN_TYPE_IDENTIFIER on
 *        success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_FUNCTION(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read a HIDE keyword token.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_HIDE is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_HIDE or RCC_TOKEN_TYPE_IDENTIFIER on
 *        success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_HIDE(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read keywords starting with the letter I.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_I_STAR is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPLEMENT
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPLEMENTS
 *      - RCC_TOKEN_TYPE_KEYWORD_IMPORT
 *      - RCC_TOKEN_TYPE_KEYWORD_INTERFACE
 *      - RCC_TOKEN_TYPE_KEYWORD_INVARIANTS
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_I_STAR(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read a MODULE keyword token.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_MODULE is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_MODULE or RCC_TOKEN_TYPE_IDENTIFIER on
 *        success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_MODULE(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read a NOT keyword token.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_NOT is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_NOT or RCC_TOKEN_TYPE_IDENTIFIER on
 *        success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_NOT(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read keywords starting with an O.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_O_STAR is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_OPAQUE
 *      - RCC_TOKEN_TYPE_KEYWORD_OR
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_O_STAR(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read an OPAQUE keyword token.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_OPAQUE is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_OPAQUE or RCC_TOKEN_TYPE_IDENTIFIER on
 *        success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_OPAQUE(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read keywords starting with the letter P.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_P_STAR is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_POINTER
 *      - RCC_TOKEN_TYPE_KEYWORD_POSTCONDITIONS
 *      - RCC_TOKEN_TYPE_KEYWORD_PRECONDITIONS
 *      - RCC_TOKEN_TYPE_KEYWORD_PRIVATE
 *      - RCC_TOKEN_TYPE_KEYWORD_PROCEDURE
 *      - RCC_TOKEN_TYPE_KEYWORD_PUBLIC
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_P_STAR(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read keywords starting with the letter R.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_R_STAR is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_RECORD
 *      - RCC_TOKEN_TYPE_KEYWORD_REVEAL
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_R_STAR(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read keywords starting with the letter T.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_T_STAR is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_TO
 *      - RCC_TOKEN_TYPE_KEYWORD_TYPE
 *      - RCC_TOKEN_TYPE_IDENTIFIER
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_T_STAR(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read a VAR keyword token.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_VAR is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_OPAQUE or RCC_TOKEN_TYPE_IDENTIFIER on
 *        success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_VAR(
    rcc_token_details* details, rcc_scanner* scanner);

/**
 * \brief Attempt to read a XOR keyword token.
 *
 * \note This function exists mainly for verification purposes. The function,
 * \ref rcc_scanner_complete_token_keyword_XOR is used by the scanner
 * proper, and called by this function.
 *
 * \param details           Pointer to the token structure to receive additional
 *                          details.
 * \param scanner           The scanner instance for this operation.
 *
 * \returns a token from the scanner.
 *      - RCC_TOKEN_TYPE_KEYWORD_XOR or RCC_TOKEN_TYPE_IDENTIFIER on
 *        success.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad input.
 */
int FN_DECL_MUST_CHECK
rcc_scanner_read_token_keyword_XOR(
    rcc_token_details* details, rcc_scanner* scanner);

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
