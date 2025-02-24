#include "../include/push_swap.h"
void set_targets(t_stack *stack_a, t_stack *stack_b) 
{
    if (!stack_a || !stack_b) return; // Check for null stacks

    t_node *current_a = stack_a->top; // Start from the top of stack A

    while (current_a) 
    {
        t_node *current_b = stack_b->top; // Start from the top of stack B
        t_node *next_smaller = NULL; // To hold the next smaller node

        // Find the next smaller number in stack B
        while (current_b) 
        {
            if (current_b->value < current_a->value) {
                // If we find a smaller number, we set it as the next_smaller
                if (next_smaller == NULL || current_b->value > next_smaller->value) {
                    next_smaller = current_b; // Update next_smaller to the current node
                } 
            }
            current_b = current_b->next; // Move to the next node in stack B
        }

        // Set the target for the current node in stack A
        current_a->target = next_smaller;
        printf("Target for %d is %d\n", current_a->value, next_smaller ? next_smaller->value : -1);

        // Move to the next node in stack A
        current_a = current_a->next;
    }
}
void sorted_a(t_stack *stack_a)
{
    t_node *first = stack_a->top;
    t_node *second = first->next;
    t_node *third = second->next;
        while (!is_sorted_inv(stack_a)){
            
        if (first->value < second->value && first->value < third->value) 
        {
            ra(stack_a);
            printf("Performing ra\n");
        }
        else if (second->value < first->value && second->value < third->value) 
        {
            rra(stack_a);
            printf("Performing rra\n");
        }
        if (first->value < second->value) 
        {
            sa(stack_a);
            printf("Performing sa\n");
        }}   
}
void sortback(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_b->top)
    {
        if (stack_b->top->target == stack_a->top)
        {
            pa(stack_a, stack_b);
        }
        else
        {
            rra(stack_a);
        }
    }
}
void element_sort(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current = stack_a->top;
    t_node *target = current->target;
    t_node *next = current->next;
    t_node *next_target = next->target;

    while(!is_sorted_inv(stack_a) || !is_sorted_inv(stack_b))
    {
        if (stack_a->size == 3)
        {
            sorted_a(stack_a);
            return;
        }
        else{
        if (find_cheap(stack_a, stack_b))
        {
            set_targets_nodes(stack_a->top, stack_b);
            while(stack_b->top != stack_a->top->target)
            {
                rb(stack_b);
            }
            pb(stack_a, stack_b);
        }
        else
        {
            sa(stack_a);
            while (stack_b->top != stack_a->top->target)
            {
                rrb(stack_b);
            }
            pb(stack_a, stack_b);
        }}


    }
}

void ten_elements(t_stack *stack_a, t_stack *stack_b)
{
 if (!stack_a)
    {
        perror("Stack is empty");
        exit(EXIT_FAILURE);
    }
    startpush(stack_a, stack_b);
    print_stack(stack_a);
    print_stack(stack_b);
    element_sort(stack_a, stack_b);
}

int main(int ac, char **av) {
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();
    
    // Push three elements onto the stack
    if (ac < 2) {
        ft_printf("Usage: %s <number> [number] [number] ...\n", av[0]);
        return 1;
    }
    int i = 1;
    while (av[i]) {
        push(stack_a, atoi(av[i]));
        i++;
    }
    print_stack(stack_a);
    print_stack(stack_b);
    
    ten_elements(stack_a, stack_b);
    return 0;
}