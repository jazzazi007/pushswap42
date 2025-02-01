
#include "../include/push_swap.h"

void rra(t_stack* stack_a)
{
    if (!stack_a || stack_a->size < 2) {
        return;
    }
    if (stack_a->size == 2) {
        t_node *first = stack_a->top;
        t_node *second = first->next;
        second->next = first;
        first->next = NULL;   
        stack_a->top = second; 
        return;
    }
    t_node *last_node = stack_a->top;
    t_node *second_last_node = NULL;
    while (last_node->next) {
        second_last_node = last_node; 
        last_node = last_node->next;   
    }
    second_last_node->next = NULL; 
    last_node->next = stack_a->top; 
    stack_a->top = last_node;     
    ft_printf("rra\n");   
}

void rrb(t_stack* stack_b)
{
    if(!stack_b || stack_b->size <2)
        return;
    if (stack_b->size == 2)
    {
        t_node *first = stack_b->top;
        t_node *second = first->next;
        second->next = first;
        first->next = NULL;
        stack_b->top = second;
        return;
    }
    t_node *last_node = stack_b->top;
    t_node *second_last_node = NULL;
    while (last_node->next)
    {
        second_last_node = last_node;
        last_node = last_node->next;
    }
    second_last_node->next = NULL;
    last_node->next = stack_b->top;
    stack_b->top = last_node;
    ft_printf("rrb\n");
}

void rrr(t_stack* stack_a, t_stack* stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    ft_printf("rrr\n");
}