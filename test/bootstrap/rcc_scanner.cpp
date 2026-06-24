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
