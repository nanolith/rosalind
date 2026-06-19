/**
 * \file bootstrap/rcc_scanner_release.c
 *
 * \brief Release a scanner instance.
 *
 * \copyright 2026 Justin Handville.  Please see license.txt in this
 * distribution for the license terms under which this software is distributed.
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
