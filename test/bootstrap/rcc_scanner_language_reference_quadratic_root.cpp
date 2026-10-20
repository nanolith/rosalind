/**
 * \file test/bootstrap/rcc_scanner_language_reference_quadratic_root.cpp
 *
 * \brief Unit tests for \ref rcc_scanner and the impure quadratic root function
 * language reference examples.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <minunit/minunit.h>
#include <rosalind_bootstrap/parser.h>
#include <string.h>

TEST_SUITE(scanner_example_quadratic_root);

/**
 * \brief Test that we can scan the beginning function declaration for the
 * example quadraticRoot function.
 */
TEST(quadraticRoot_example_function_declaration)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = R"(
        PUBLIC quadraticRoot(
            result: POINTER TO REAL, index: INT(8), a: REAL, b: REAL, c: REAL):
                BOOLEAN
    )";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* read a PUBLIC keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_PUBLIC
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a colon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_COLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a POINTER keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_POINTER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a TO keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_TO
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a REAL keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_REAL
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a comma. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_COMMA
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a colon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_COLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an INT keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_INT
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number value. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a comma. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_COMMA
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a colon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_COLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a REAL keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_REAL
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a comma. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_COMMA
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a colon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_COLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a REAL keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_REAL
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a comma. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_COMMA
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a colon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_COLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a REAL keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_REAL
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a colon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_COLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a BOOLEAN keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_BOOLEAN
            == rcc_scanner_read_token(&details, scanner));

    /* read EOF. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_EOF
            == rcc_scanner_read_token(&details, scanner));

    /* clean up. */
    rcc_scanner_release(scanner);
}
