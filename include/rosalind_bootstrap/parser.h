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
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* C++ compatibility. */
# ifdef   __cplusplus
extern "C" {
# endif /*__cplusplus*/

enum rcc_token_type
{
    /** \brief EOF. */
    RCC_TOKEN_TYPE_EOF = 0,

    /** \brief AND keyword. */
    RCC_TOKEN_TYPE_KEYWORD_AND,
    /** \brief ARRAY keyword. */
    RCC_TOKEN_TYPE_KEYWORD_ARRAY,
    /** \brief AS keyword. */
    RCC_TOKEN_TYPE_KEYWORD_AS,
    /** \brief BEGIN keyword. */
    RCC_TOKEN_TYPE_KEYWORD_BEGIN,
    /** \brief CASE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_CASE,
    /** \brief CONST keyword. */
    RCC_TOKEN_TYPE_KEYWORD_CONST,
    /** \brief DIV keyword. */
    RCC_TOKEN_TYPE_KEYWORD_DIV,
    /** \brief DO keyword. */
    RCC_TOKEN_TYPE_KEYWORD_DO,
    /** \brief ELSE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_ELSE,
    /** \brief END keyword. */
    RCC_TOKEN_TYPE_KEYWORD_END,
    /** \brief FOR keyword. */
    RCC_TOKEN_TYPE_KEYWORD_FOR,
    /** \brief FUNCTION keyword. */
    RCC_TOKEN_TYPE_KEYWORD_FUNCTION,
    /** \brief GOTO keyword. */
    RCC_TOKEN_TYPE_KEYWORD_GOTO,
    /** \brief HIDE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_HIDE,
    /** \brief IF keyword. */
    RCC_TOKEN_TYPE_KEYWORD_IF,
    /** \brief IMPLEMENT keyword. */
    RCC_TOKEN_TYPE_KEYWORD_IMPLEMENT,
    /** \brief IMPLEMENTS keyword. */
    RCC_TOKEN_TYPE_KEYWORD_IMPLEMENTS,
    /** \brief IMPORT keyword. */
    RCC_TOKEN_TYPE_KEYWORD_IMPORT,
    /** \brief IN keyword. */
    RCC_TOKEN_TYPE_KEYWORD_IN,
    /** \brief INT keyword. */
    RCC_TOKEN_TYPE_KEYWORD_INT,
    /** \brief INTERFACE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_INTERFACE,
    /** \brief INVARIANTS keyword. */
    RCC_TOKEN_TYPE_KEYWORD_INVARIANTS,
    /** \brief MOD keyword. */
    RCC_TOKEN_TYPE_KEYWORD_MOD,
    /** \brief MODULE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_MODULE,
    /** \brief NIL keyword. */
    RCC_TOKEN_TYPE_KEYWORD_NIL,
    /** \brief NOT keyword. */
    RCC_TOKEN_TYPE_KEYWORD_NOT,
    /** \brief OF keyword. */
    RCC_TOKEN_TYPE_KEYWORD_OF,
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
    /** \brief SET keyword. */
    RCC_TOKEN_TYPE_KEYWORD_SET,
    /** \brief SHL keyword. */
    RCC_TOKEN_TYPE_KEYWORD_SHL,
    /** \brief SHR keyword. */
    RCC_TOKEN_TYPE_KEYWORD_SHR,
    /** \brief STRING keyword. */
    RCC_TOKEN_TYPE_KEYWORD_STRING,
    /** \brief THEN keyword. */
    RCC_TOKEN_TYPE_KEYWORD_THEN,
    /** \brief TO keyword. */
    RCC_TOKEN_TYPE_KEYWORD_TO,
    /** \brief TYPE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_TYPE,
    /** \brief UINT keyword. */
    RCC_TOKEN_TYPE_KEYWORD_UINT,
    /** \brief VAR keyword. */
    RCC_TOKEN_TYPE_KEYWORD_VAR,
    /** \brief WHERE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_WHERE,
    /** \brief WHILE keyword. */
    RCC_TOKEN_TYPE_KEYWORD_WHILE,
    /** \brief XOR keyword. */
    RCC_TOKEN_TYPE_KEYWORD_XOR,

    /** \brief identifier token. */
    RCC_TOKEN_TYPE_IDENTIFIER,
    /** \brief number token. */
    RCC_TOKEN_TYPE_NUMBER,
    /** \brief real token. */
    RCC_TOKEN_TYPE_REAL,
    /** \brief plus token. */
    RCC_TOKEN_TYPE_PLUS,
    /** \brief minus token. */
    RCC_TOKEN_TYPE_MINUS,
    /** \brief star token. */
    RCC_TOKEN_TYPE_STAR,
    /** \brief slash token. */
    RCC_TOKEN_TYPE_SLASH,
    /** \brief equal token. */
    RCC_TOKEN_TYPE_EQUAL,
    /** \brief less-than token. */
    RCC_TOKEN_TYPE_LESS_THAN,
    /** \brief greater-than token. */
    RCC_TOKEN_TYPE_GREATER_THAN,
    /** \brief less-than-equal token. */
    RCC_TOKEN_TYPE_LESS_THAN_EQUAL,
    /** \brief greater-than-equal token. */
    RCC_TOKEN_TYPE_GREATER_THAN_EQUAL,
    /** \brief not-equal token. */
    RCC_TOKEN_TYPE_NOT_EQUAL,

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
    union
    {
        struct
        {
            bool is_unsigned;
            union
            {
                intmax_t signedv;
                uintmax_t unsignedv;
            } val;
        } integerv;
        bool booleanv;
        long double realv;
    } primitive_val;
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
 *      - RCC_TOKEN_TYPE_EOF at the end of input.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad
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
 *      - RCC_TOKEN_TYPE_EOF at the end of input.
 *      - RCC_TOKEN_TYPE_BAD_INPUT if the scanner encounters bad
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
