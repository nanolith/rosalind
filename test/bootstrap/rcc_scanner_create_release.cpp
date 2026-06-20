/**
 * \file test/bootstrap/rcc_scanner_create_release.cpp
 *
 * \brief Unit tests for \ref rcc_scanner_create and \ref rcc_scanner_release.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <minunit/minunit.h>
#include <rosalind_bootstrap/parser.h>

TEST_SUITE(rcc_scanner_create_release);

/**
 * \brief Test that we can create and release an \ref rcc_scanner instance.
 */
TEST(scanner_create_release)
{
    rcc_scanner* scanner = nullptr;
    const char* INPUT = "test input";

    /* Test that we can create a scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* The scanner instance should not be NULL. */
    TEST_ASSERT(nullptr != scanner);
    /* both original_input and input should be set to our input. */
    TEST_EXPECT(INPUT == scanner->original_input);
    TEST_EXPECT(INPUT == scanner->input);
    /* index starts at 0. */
    TEST_EXPECT(0 == scanner->index);
    /* line starts at 1. */
    TEST_EXPECT(1 == scanner->line);
    /* col starts at 1. */
    TEST_EXPECT(1 == scanner->col);
}
