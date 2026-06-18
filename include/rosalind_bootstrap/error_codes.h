/**
 * \file rosalind_bootstrap/error_codes.h
 *
 * \brief Error codes for rcc-stage0.
 *
 * See LICENSE.txt for copyright and license information.
 */

#pragma once

/* C++ compatibility. */
# ifdef   __cplusplus
extern "C" {
# endif /*__cplusplus*/

enum rcc_error_code
{
    /** \brief Out of memory error. */
    RCC_ERROR_OUT_OF_MEMORY = 1,
};

/* C++ compatibility. */
# ifdef   __cplusplus
}
# endif /*__cplusplus*/
