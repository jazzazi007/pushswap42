#include "../include/push_swap.h"

void pb(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_a->top || stack_a->size < 2)
        return;
    t_node *new_node = create_node(stack_a->top->value);
    new_node->next = stack_b->top;
    stack_b->top = new_node;
    stack_b->size++;
    
    stack_a->top = stack_a->top->next;
    stack_a->size--;
    ft_printf("pb\n");
}

t_node *create_node(int value)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node) {
        perror("Failed to allocate memory for node");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

t_stack *init_stack() {
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack) {
        perror("Failed to allocate memory for stack");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(t_stack *stack, int value) {
    t_node *new_node = create_node(value);
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

void pop(t_stack* stack)
{
    if (stack->top)
    {
        t_node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->size--;
    }
    else
    ft_printf("Stack is empty\n");
}

void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current) {
        ft_printf("%d -> ", current->value);
        current = current->next;
    }
    ft_printf("NULL\n");
}