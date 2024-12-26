#include "push_swap.h"

void sa(t_stack *stack_a) {
    if (!stack_a || stack_a->size < 2) {
        return;
    }

    t_node *first = stack_a->top;
    t_node *second = first->next;

    first->next = second->next;
    second->next = first;
    stack_a->top = second;
    printf("sa\n");
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
    printf("sb\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
    printf("ss\n");
}

void pa(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_b->top || stack_b->size < 2)
        return;
    t_node *new_node = create_node(stack_b->top->value);
    new_node->next = stack_a->top;
    stack_a->top = new_node;
    stack_a->size++;
    
    stack_b->top = stack_b->top->next;
    stack_b->size--;
    printf("pa\n");
}

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
    printf("pb\n");
}

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
    printf("ra\n");
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
    printf("rb\n");
}

void rr(t_stack* stack_a, t_stack* stack_b)
{
    ra(stack_a);
    rb(stack_b);
    printf("rr\n");
}

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
    printf("rra\n");   
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
    printf("rrb\n");
}

void rrr(t_stack* stack_a, t_stack* stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    printf("rrr\n");
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
    printf("Stack is empty\n");
}

void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}