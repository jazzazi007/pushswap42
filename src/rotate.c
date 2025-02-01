#include "../include/push_swap.h"

void ra(t_stack* stack_a)
{
    if (!stack_a || stack_a->size < 2)
        return;
    t_node* top_node = stack_a->top;
    t_node* last_node = stack_a->top;
    while (last_node->next)
        last_node = last_node->next;
    stack_a->top = top_node->next;
    last_node->next = top_node;
    top_node->next = NULL;
    ft_printf("ra\n");
}

void rb(t_stack* stack_b)
{
    if (!stack_b || stack_b->size < 2)
        return;
    t_node* top_node = stack_b->top;
    t_node* last_node = stack_b->top;
    while (last_node->next)
        last_node = last_node->next;
    stack_b->top = top_node->next;
    last_node->next = top_node;
    top_node->next = NULL;
    ft_printf("rb\n");
}

void rr(t_stack* stack_a, t_stack* stack_b)
{
    ra(stack_a);
    rb(stack_b);
    ft_printf("rr\n");
}