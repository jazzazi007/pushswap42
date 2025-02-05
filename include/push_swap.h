#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "../42_libft/libft.h"
#include "../42_printf/ft_printf.h"


typedef struct s_node {
    int value;
    bool cheapest;
    struct s_node *next;
    struct  s_node *prev;
    struct s_node *target;
} t_node;

typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

void ss(t_stack *stack_a, t_stack *stack_b);
void sb(t_stack *stack_b);
void sa(t_stack *stack_a);
t_node *create_node(int value);
void push(t_stack *stack, int value);
void pop(t_stack* stack);
t_stack *init_stack();
void print_stack(t_stack *stack);
void pa(t_stack *stack_a, t_stack *stack_b);
void pb(t_stack *stack_a, t_stack *stack_b);
void rr(t_stack* stack_a, t_stack* stack_b);
void ra(t_stack* stack_a);
void rb(t_stack* stack_b);
void rra(t_stack* stack_a);
void rrb(t_stack* stack_b);
void rrr(t_stack* stack_a, t_stack* stack_b);

void startpush(t_stack *stack_a, t_stack *stack_b);
bool is_sorted_inv(t_stack *stack);
char **ft_split(char const *s, char c);
int ft_atoi(const char *str);
int set_targets_nodes(t_node *node_a, t_stack *stack_b);
bool find_cheap(t_stack *stack_a, t_stack *stack_b);
//void radix_sort(t_stack *stack_a);
//int get_max(t_stack *stack);
#endif