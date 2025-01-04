#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/push_swap.h"
#include <unistd.h>

bool is_sorted(t_stack *stack) {
    if (!stack || stack->size < 2) {
        printf("error sorted\n");
        return true;
    }

    t_node *current = stack->top;
    while (current && current->next) {
        if (current->value > current->next->value) {
            printf("not sorted\n");
            return false;
            
        }
        current = current->next;
    }
    printf("sorted\n");
    return true;
}
bool is_sorted_inv(t_stack *stack) {
    if (!stack || stack->size < 2) {
        printf("error sorted\n");
        return true;
    }

    t_node *current = stack->top;
    while (current && current->next) {
        if (current->value < current->next->value) {
            printf("not sorted\n");
            return false;
            
        }
        current = current->next;
    }
    printf("sorted\n");
    return true;
}
t_node *get_largest(t_stack *stack_a)
{
    t_node *current = stack_a->top;
    t_node *next_ = current->next;
    t_node *largest = current;
    while (current)
    {
        if (current->value > next_->value)
            largest = current;
        current = current->next;
    }
    printf("Largest: %d\n", largest->value);
    return largest;
}
int set_targets_nodes(t_node *node_a, t_stack *stack_b) {
    if (!node_a || !stack_b) return(false); // Check for null stacks

        t_node *current_b = stack_b->top; // Start from the top of stack B
        t_node *next_smaller = NULL; // To hold the next smaller node

        // Find the next smaller number in stack B
        while (current_b) {
            if (current_b->value < node_a->value) {
                // If we find a smaller number, we set it as the next_smaller
                if (next_smaller == NULL || current_b->value > next_smaller->value) {
                    next_smaller = current_b; // Update next_smaller to the current node
                }
                printf("Target for %d is %d\n", node_a->value, next_smaller ? next_smaller->value : -1);

                return true;
            }
            current_b = current_b->next; // Move to the next node in stack B
        }
        return false;
}

void tiny_sort(t_stack *stack_a, t_stack *stack_b) {
    
    if (stack_a->size < 2) return; // No need to sort if less than 2 elements

    if (stack_a->size == 2) {
        if (stack_a->top->value > stack_a->top->next->value) {
            printf("Performing sa\n");
            int temp = stack_a->top->value;
            stack_a->top->value = stack_a->top->next->value;
            stack_a->top->next->value = temp;
        }
    } else if (stack_a->size == 3) {
        if (stack_a->top == NULL || stack_a->top->next == NULL || stack_a->top->next->next == NULL) {
            return; // Safety check
        }
        int first = stack_a->top->value;
        int second = stack_a->top->next->value;
        int third = stack_a->top->next->next->value;
        if (set_targets_nodes(get_largest(stack_a), stack_b))
        {
        while (!is_sorted_inv(stack_a)){
        if (first < second && first < third) 
        {
            ra(stack_a);
            printf("Performing ra\n");
        }
        else if (second < first && second > third) 
        {
            rra(stack_a);
            printf("Performing rra\n");
        }
        if (first < second) 
        {
            sa(stack_a);
            printf("Performing sa\n");
        }}   
        }
        else{
        while (!is_sorted(stack_a)){
        if (first > second && first > third) 
        {
            ra(stack_a);
            printf("Performing ra\n");
        }
        else if (second > first && second > third) 
        {
            rra(stack_a);
            printf("Performing rra\n");
        }
        if (first > second) 
        {
            sa(stack_a);
            printf("Performing sa\n");
        }}
        }
    }
    if (is_sorted_inv(stack_a) && is_sorted_inv(stack_b))
        {
            while (!is_sorted(stack_a) || stack_b->size > 0)
            {
                sleep(2);
            if (set_targets_nodes(stack_a->top, stack_b))
            {
                printf("Performing pa\n");
                pa(stack_a, stack_b);
            }
            else if (stack_a->top->value > stack_a->top->next->value)
            {
                printf("Performing sa\n");
                sa(stack_a);
            }

            else
            {
                printf("Performing rra\n");
                rra(stack_a);
            }
            print_stack(stack_a); // Print stack_a to see its state
            }
            
        }
}
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

void find_cheap(t_stack *stack_a, t_stack *stack_b) {
    if (!stack_a) return; // Check for null stack

    t_node *current_a = stack_a->top; // Start from the top of stack A
    t_node *first_node = current_a; // First node in stack A
    t_node *second_node = current_a->next; // Second node in stack A

    if (!second_node) return; // If there is no second node, exit

    // Calculate moves for the first node
    int moves_first = 0;
    int move_first_inv = 0;
    if (first_node->target) {
        t_node *current_b = stack_b->top; // Start from the top of stack B
        while (current_b) {
            if (current_b == first_node->target) {
                break; // Stop counting when we reach the target node
            }
            moves_first++; // Count this node as needing to be moved
            current_b = current_b->next; // Move to the next node in stack B
        }
        move_first_inv = stack_b->size - moves_first;
    }
    printf("first %d\n", moves_first);
    printf("inv first %d\n", move_first_inv);

    // Calculate moves for the second node
    int moves_second = 0;
    int move_second_inv = 0;
    if (second_node->target) {
        t_node *current_b = stack_b->top; // Start from the top of stack B
        while (current_b) {
            if (current_b == second_node->target) {
                break; // Stop counting when we reach the target node
            }
            moves_second++; // Count this node as needing to be moved
            current_b = current_b->next; // Move to the next node in stack B
        }
        
        move_second_inv = stack_b->size - moves_second;
        moves_second++;
    }
    printf("sec %d\n", moves_second);
    printf("inv second %d\n", move_second_inv);
    if (move_first_inv < moves_first)
        moves_first = move_first_inv;
    if (move_second_inv < moves_second)
        moves_second = move_second_inv;
    // Compare moves and determine the cheapest
    if (moves_first <= moves_second) {
        first_node->cheapest = true; // Mark the first node as cheapest
        second_node->cheapest = false; // Mark the second node as not cheapest
        printf("First\n");
    } else {
        first_node->cheapest = false; // Mark the first node as not cheapest
        second_node->cheapest = true; // Mark the second node as cheapest
        printf("Second\n");
    }
}

void startpush(t_stack *stack_a, t_stack *stack_b)
{
       if (stack_a->size <= 3) {
        printf("stack a size is 3, or less.\n");
        return;
    }
    //push the first 2 elements
    int i = 0;
    while(i<2)
    {
        pb(stack_a, stack_b);
        i++;
    }

}
void sort_stackb(t_stack *stack_b)
{
    if (stack_b->size < 1)
        return;
    t_node *current = stack_b->top;
    t_node *next = current->next;
    if (current->value < next->value)
    {
        sb(stack_b);
    }
}

int main() {
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();
    
    // Push three elements onto the stack
    push(stack_a, 1);
    push(stack_a, 40);
    push(stack_a, 20);
    push(stack_a, 50);
    push(stack_a, 5);
    print_stack(stack_a);
    print_stack(stack_b);
    
    startpush(stack_a, stack_b);
    printf("Initial Stack A:\n");
    print_stack(stack_a);
    print_stack(stack_b);
    sort_stackb(stack_b);
    tiny_sort(stack_a, stack_b);
    if (is_sorted(stack_a))

    printf("Sorted Stack A:\n");
    print_stack(stack_a);
    printf("Sorted Stack B:\n");
    print_stack(stack_b);

    set_targets(stack_a, stack_b);

    // Clean up memory (not shown for simplicity)
    free(stack_a);

    return 0;
}