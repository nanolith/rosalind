/**
 * \file rosalind_bootstrap/function_decl.h
 *
 * \brief Function declaration macros for rcc-stage0.
 *
 * See LICENSE.txt for copyright and license information.
 */

#pragma once

/*
 * With GCC 3.4 and clang, we can force a warning / error if the return value
 * of a function isn't checked.
 */
#if defined(__GNUC__) && defined(__GNUC_MINOR__) && !defined(FN_DECL_MUST_CHECK)
# if (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || (__GNUC__ > 3)
#  define FN_DECL_MUST_CHECK __attribute__((warn_unused_result))
# endif
#endif

/*
 * For other compilers, skip this check.
 */
#ifndef FN_DECL_MUST_CHECK
# define FN_DECL_MUST_CHECK
#endif
