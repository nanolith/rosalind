/**
 * \file test/bootstrap/rcc_scanner.cpp
 *
 * \brief Unit tests for \ref rcc_scanner.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <minunit/minunit.h>
#include <rosalind_bootstrap/parser.h>

#include "bootstrap/parser_internal.h"

TEST_SUITE(rcc_scanner);

/**
 * \brief Test that we can read a BEGIN token.
 */
TEST(BEGIN_happy_path)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = "BEGIN \t ";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* attempt to read the BEGIN token. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_BEGIN
            == rcc_scanner_read_token_keyword_BEGIN(&details, scanner));

    TEST_EXPECT(RCC_TOKEN_TYPE_KEYWORD_BEGIN == details.type);
    TEST_EXPECT(0 == details.begin_index);
    TEST_EXPECT(4 == details.end_index);
    TEST_EXPECT(1 == details.begin_line);
    TEST_EXPECT(1 == details.end_line);
    TEST_EXPECT(1 == details.begin_col);
    TEST_EXPECT(5 == details.end_col);

    /* clean up. */
    rcc_scanner_release(scanner);
}

/**
 * \brief Test that BEGIN complete falls back to identifier.
 */
TEST(BEGIN_identifier_fallback)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = "BEGINA \t ";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* attempt to read an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token_keyword_BEGIN(&details, scanner));

    TEST_EXPECT(RCC_TOKEN_TYPE_IDENTIFIER == details.type);
    TEST_EXPECT(0 == details.begin_index);
    TEST_EXPECT(5 == details.end_index);
    TEST_EXPECT(1 == details.begin_line);
    TEST_EXPECT(1 == details.end_line);
    TEST_EXPECT(1 == details.begin_col);
    TEST_EXPECT(6 == details.end_col);

    /* clean up. */
    rcc_scanner_release(scanner);
}

/**
 * \brief Test that we can read an CONST token.
 */
TEST(CONST_happy_path)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = "CONST \t ";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* attempt to read the CONST token. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_CONST
            == rcc_scanner_read_token_keyword_CONST(&details, scanner));

    TEST_EXPECT(RCC_TOKEN_TYPE_KEYWORD_CONST == details.type);
    TEST_EXPECT(0 == details.begin_index);
    TEST_EXPECT(4 == details.end_index);
    TEST_EXPECT(1 == details.begin_line);
    TEST_EXPECT(1 == details.end_line);
    TEST_EXPECT(1 == details.begin_col);
    TEST_EXPECT(5 == details.end_col);

    /* clean up. */
    rcc_scanner_release(scanner);
}

/**
 * \brief Test that CONST complete falls back to identifier.
 */
TEST(CONST_identifier_fallback)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = "CONSTANT \t ";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* attempt to read an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token_keyword_CONST(&details, scanner));

    TEST_EXPECT(RCC_TOKEN_TYPE_IDENTIFIER == details.type);
    TEST_EXPECT(0 == details.begin_index);
    TEST_EXPECT(7 == details.end_index);
    TEST_EXPECT(1 == details.begin_line);
    TEST_EXPECT(1 == details.end_line);
    TEST_EXPECT(1 == details.begin_col);
    TEST_EXPECT(8 == details.end_col);

    /* clean up. */
    rcc_scanner_release(scanner);
}

/**
 * \brief Test that we can read an END token.
 */
TEST(END_happy_path)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = "END \t ";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* attempt to read the END token. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_END
            == rcc_scanner_read_token_keyword_END(&details, scanner));

    TEST_EXPECT(RCC_TOKEN_TYPE_KEYWORD_END == details.type);
    TEST_EXPECT(0 == details.begin_index);
    TEST_EXPECT(2 == details.end_index);
    TEST_EXPECT(1 == details.begin_line);
    TEST_EXPECT(1 == details.end_line);
    TEST_EXPECT(1 == details.begin_col);
    TEST_EXPECT(3 == details.end_col);

    /* clean up. */
    rcc_scanner_release(scanner);
}

/**
 * \brief Test that END complete falls back to identifier.
 */
TEST(END_identifier_fallback)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = "ENDIAN \t ";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* attempt to read an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token_keyword_END(&details, scanner));

    TEST_EXPECT(RCC_TOKEN_TYPE_IDENTIFIER == details.type);
    TEST_EXPECT(0 == details.begin_index);
    TEST_EXPECT(5 == details.end_index);
    TEST_EXPECT(1 == details.begin_line);
    TEST_EXPECT(1 == details.end_line);
    TEST_EXPECT(1 == details.begin_col);
    TEST_EXPECT(6 == details.end_col);

    /* clean up. */
    rcc_scanner_release(scanner);
}

/**
 * \brief Test that we can read a FUNCTION token.
 */
TEST(FUNCTION_happy_path)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = "FUNCTION \t ";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* attempt to read the FUNCTION token. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_FUNCTION
            == rcc_scanner_read_token_keyword_FUNCTION(&details, scanner));

    TEST_EXPECT(RCC_TOKEN_TYPE_KEYWORD_FUNCTION == details.type);
    TEST_EXPECT(0 == details.begin_index);
    TEST_EXPECT(7 == details.end_index);
    TEST_EXPECT(1 == details.begin_line);
    TEST_EXPECT(1 == details.end_line);
    TEST_EXPECT(1 == details.begin_col);
    TEST_EXPECT(8 == details.end_col);

    /* clean up. */
    rcc_scanner_release(scanner);
}
