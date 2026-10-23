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

/**
 * \brief Test that we can scan the function contract for the example
 * quadraticRoot function.
 */
TEST(quadraticRoot_example_function_contract)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = R"(
        PRECONDITIONS
        BEGIN
            ASSERT PropertyValidReferenceToREAL(result);
        END
        POSTCONDITIONS
        BEGIN
            ASSERT PropertyVariableModified(result);

            IF quadraticRoot <> TRUE THEN
                ASSERT (result^ = 0);
        END
    )";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* read a PRECONDITIONS keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_PRECONDITIONS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a BEGIN keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_BEGIN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an ASSERT keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_ASSERT
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

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a semicolon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_SEMICOLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an END keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_END
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a POSTCONDITIONS keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_POSTCONDITIONS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a BEGIN keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_BEGIN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an ASSERT keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_ASSERT
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

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a semicolon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_SEMICOLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an IF keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_IF
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a not equal. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_NOT_EQUAL
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a Boolean value. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_BOOLEAN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a THEN keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_THEN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an ASSERT keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_ASSERT
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a caret. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CARET
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an equal. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_EQUAL
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number value. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a semicolon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_SEMICOLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an END keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_END
            == rcc_scanner_read_token(&details, scanner));

    /* read EOF. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_EOF
            == rcc_scanner_read_token(&details, scanner));

    /* clean up. */
    rcc_scanner_release(scanner);
}

/**
 * \brief Test that we can scan the constant expression in the quadraticRoot
 * example.
 */
TEST(quadraticRoot_example_discriminant_constant)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = R"(
        CONST discriminant: REAL := b * b - 4 * a * c;
    )";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* read a CONST keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_CONST
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

    /* the next token should be a minus. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_MINUS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a star. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_STAR
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

    /* read EOF. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_EOF
            == rcc_scanner_read_token(&details, scanner));

    /* clean up. */
    rcc_scanner_release(scanner);
}

/**
 * \brief Test that we can scan the IF statement for the quadraticRoot function
 * example.
 */
TEST(quadraticRoot_example_if_statement)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = R"(
        IF     (a = 0)
            OR (discriminant < 0)
            OR (index > 0 AND discriminant = 0)
            OR (index > 1)
        THEN
        BEGIN
            result^ := 0;
            quadraticRoot := FALSE;
        END
    )";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* read an IF keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_IF
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an equal. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_EQUAL
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an OR keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_OR
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a less-than. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_LESS_THAN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an OR keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_OR
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a greater than. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_GREATER_THAN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an AND keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_AND
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an equal. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_EQUAL
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an OR keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_OR
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a greater-than. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_GREATER_THAN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a THEN keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_THEN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a BEGIN keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_BEGIN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a caret. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CARET
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a assignment. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_ASSIGNMENT
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a semicolon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_SEMICOLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an assignment. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_ASSIGNMENT
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be Boolean value. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_BOOLEAN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a semicolon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_SEMICOLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an END keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_END
            == rcc_scanner_read_token(&details, scanner));

    /* read EOF. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_EOF
            == rcc_scanner_read_token(&details, scanner));

    /* clean up. */
    rcc_scanner_release(scanner);
}

/**
 * \brief Test that we can scan the ELSE statement for the quadraticRoot
 * function example.
 */
TEST(quadraticRoot_example_else_statement)
{
    rcc_scanner* scanner = nullptr;
    rcc_token_details details;
    const char* INPUT = R"(
        ELSE
        BEGIN
            quadraticRoot := TRUE;

            IF index = 0 THEN
                result^ := ((b * -1) + SQRT(discriminant)) / (2 * a)
            ELSE
                result^ := ((b * -1) - SQRT(discriminant)) / (2 * a);
        END;
    )";

    /* Create the scanner instance. */
    TEST_ASSERT(0 == rcc_scanner_create(&scanner, INPUT));

    /* read an ELSE keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_ELSE
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

    /* the next token should be a Boolean value. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_BOOLEAN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a semicolon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_SEMICOLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an IF keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_IF
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an equal. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_EQUAL
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a THEN keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_THEN
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a caret. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CARET
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an assignment. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_ASSIGNMENT
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a star. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_STAR
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a plus. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_PLUS
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

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a slash. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_SLASH
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a star. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_STAR
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an ELSE keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_ELSE
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a caret. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CARET
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an assignment. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_ASSIGNMENT
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a star. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_STAR
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a minus. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_MINUS
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

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a slash. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_SLASH
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an open parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_OPEN_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a number. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_VALUE_NUMBER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a star. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_STAR
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an identifier. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_IDENTIFIER
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a close parenthesis. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_CLOSE_PARENTHESIS
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a semicolon. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_SEMICOLON
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be an END keyword. */
    TEST_ASSERT(
        RCC_TOKEN_TYPE_KEYWORD_END
            == rcc_scanner_read_token(&details, scanner));

    /* the next token should be a semicolon. */
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
