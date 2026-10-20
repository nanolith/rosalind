/**
 * \file test/bootstrap/rcc_scanner_language_reference_global_variable.cpp
 *
 * \brief Unit tests for \ref rcc_scanner and the global variable language
 * reference examples.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <minunit/minunit.h>
#include <rosalind_bootstrap/parser.h>
#include <string.h>

TEST_SUITE(scanner_example_global_variable);

/**
 * \brief Test that we can scan global variable related tokens.
 */
TEST(global_variable_example_tokens)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = "PRIVATE singletonInitialized : BOOLEAN = FALSE;";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* read a PRIVATE keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_PRIVATE
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a colon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_COLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a BOOLEAN keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_BOOLEAN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an equal. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_EQUAL
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a Boolean value. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_BOOLEAN
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
