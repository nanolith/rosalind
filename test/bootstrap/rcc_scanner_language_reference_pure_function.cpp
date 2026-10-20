/**
 * \file test/bootstrap/rcc_scanner_language_reference_pure_function.cpp
 *
 * \brief Unit tests for \ref rcc_scanner and the pure function language
 * reference examples.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <minunit/minunit.h>
#include <rosalind_bootstrap/parser.h>
#include <string.h>

TEST_SUITE(scanner_example_pure_function);

/**
 * \brief Test that we can scan pure function example related tokens.
 */
TEST(pure_function_example_tokens)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = R"(
        PUBLIC square(a: REAL): REAL
        BEGIN
            square := a * a;
        END;
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

    /* the next token should be a REAL keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_REAL
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a BEGIN keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_BEGIN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an assignment. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_ASSIGNMENT
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a star. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_STAR
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a semicolon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_SEMICOLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an END keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_END
            == rcc_scanner_read_token(&details, scanner));

    /* the last token should be a semicolon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_SEMICOLON
            == rcc_scanner_read_token(&details, scanner));

    /* read EOF. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_EOF
            == rcc_scanner_read_token(&details, scanner));

    /* clean up. */
    rcc_scanner_release(scanner);
}
