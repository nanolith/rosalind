/**
 * \file test/bootstrap/rcc_scanner_language_reference_module.cpp
 *
 * \brief Unit tests for \ref rcc_scanner and the module language reference
 * examples.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <minunit/minunit.h>
#include <rosalind_bootstrap/parser.h>
#include <string.h>

TEST_SUITE(scanner_example_module);

/**
 * \brief Test that we can scan module related tokens.
 */
TEST(MODULE_example_tokens)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = "MODULE Foo.Bar.Baz;";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* read a MODULE keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_MODULE
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a dot. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_DOT
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a dot. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_DOT
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
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

/**
 * \brief Test that we can scan import related tokens.
 */
TEST(IMPORT_example_tokens)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = "IMPORT System.File AS F (createFile, closeFile);";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* read an IMPORT keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_IMPORT
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a dot. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_DOT
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an AS keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_AS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parethesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a comma. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_COMMA
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parethesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
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
