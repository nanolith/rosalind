/**
 * \file bootstrap/rcc_ast_list_node_reverse.c
 *
 * \brief Reverse an AST list.
 *
 * See LICENSE.txt for copyright and license information.
 */

#include <rosalind_bootstrap/ast.h>

/**
 * \brief Reverse a linked list.
 *
 * \param list          The list to reverse.
 */
void rcc_ast_list_node_reverse(rcc_ast_list_node** list)
{
    rcc_ast_list_node* ret = NULL;
    rcc_ast_list_node* x = *list;

    while (NULL != x)
    {
        rcc_ast_list_node* tmp = x->next;
        x->next = ret;
        ret = x;
        x = tmp;
    }

    *list = x;
}
