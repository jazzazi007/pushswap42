
#include "../include/push_swap.h"

void sa(t_stack *stack_a) {
    if (!stack_a || stack_a->size < 2) {
        return;
    }

    t_node *first = stack_a->top;
    t_node *second = first->next;

    first->next = second->next;
    second->next = first;
    stack_a->top = second;
    ft_printf("sa\n");
}

void sb(t_stack *stack_b) 
{
    if (!stack_b || stack_b->size < 2) {
        return;
    }

    t_node *first = stack_b->top;
    t_node *second = first->next;

    first->next = second->next;
    second->next = first;
    stack_b->top = second;
    ft_printf("sb\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
    ft_printf("ss\n");
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_b->top || stack_b->size < 1)
        return;
    t_node *new_node = create_node(stack_b->top->value);
    new_node->next = stack_a->top;
    stack_a->top = new_node;
    stack_a->size++;
    
    stack_b->top = stack_b->top->next;
    stack_b->size--;
    ft_printf("pa\n");
}
