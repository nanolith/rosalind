/**
 * \file bootstrap/rcc_scanner_release.c
 *
 * \brief Release a scanner instance.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <stdlib.h>
#include <string.h>

#include "parser_internal.h"

/**
 * \brief Release a \ref rcc_scanner instance.
 *
 * \param scanner           The scanner to release.
 */
void
rcc_scanner_release(rcc_scanner* scanner)
{
    memset(scanner, 0, sizeof(*scanner));
    free(scanner);
}
