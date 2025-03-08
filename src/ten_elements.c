#include "../include/push_swap.h"

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
int set_targets_nodes_back(t_node *node_b, t_stack *stack_a) {
    if (!node_b || !stack_a) 
        return (false);

    t_node *current_a = stack_a->top;
    t_node *next_larger = NULL;
    bool found_target = false;
    while (current_a) {
        if (current_a->value > node_b->value) {
            if (next_larger == NULL || current_a->value < next_larger->value) {
                next_larger = current_a;
                found_target = true;
            }
        }
        current_a = current_a->next;
    }
    node_b->target = next_larger;
  //  printf("Target for %d is %d\n", node_b->value, next_larger ? next_larger->value : -1);

    return found_target;
}
int get_largest_b(t_stack *stack_b) {
    if (!stack_b || !stack_b->top)
        return -1;

    t_node *current = stack_b->top;
    t_node *largest = current;

    while (current) {
        if (current->value > largest->value)
            largest = current;
        current = current->next;
    }
    
    printf("Largest in B: %d\n", largest->value);
    return largest->value;
}
t_node *get_largest_node_b(t_stack *stack_b) {
    if (!stack_b || !stack_b->top)
        return NULL;

    t_node *current = stack_b->top;
    t_node *largest = current;

    while (current) {
        if (current->value > largest->value)
            largest = current;
        current = current->next;
    }
    
    printf("Largest in B: %d\n", largest->value);
    return largest;
}

void sortback(t_stack *stack_a, t_stack *stack_b)
{
    int i = 0;
    while (stack_b->top)
    {
        if (stack_b->top->value == get_largest_b(stack_b) && i == 0)
        {
            pa(stack_a, stack_b);
            i++;
        }
        set_targets_nodes_back(stack_b->top, stack_a);
       // ft_printf("stack b vlaue is %i\n", stack_b->top->value);
        //printf("stack b target is %i\n", stack_b->top->target->value);

        if (stack_b->top->target == stack_a->top)
        {
            pa(stack_a, stack_b);
        }
        else
        {
            rra(stack_a);
        }
        print_stack(stack_a);
        print_stack(stack_b);
    }
}



bool is_stack_b_sorted(t_stack *stack_b) {
    if (!stack_b || !stack_b->top || stack_b->size < 2)
        return true;  // Empty or single element stack is considered sorted

    t_node *current = stack_b->top;
    while (current && current->next) {
        if (current->value < current->next->value) {
           // printf("Stack B is not inverse sorted\n");
            return false;
        }
        current = current->next;
    }
   // printf("Stack B is inverse sorted\n");
    return true;
}

void sort_b_inverse(t_stack *stack_b)
{
    if (!stack_b || !stack_b->top || stack_b->size < 2)
        return;

    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        t_node *current = stack_b->top;
        
        // Check if we need to swap the top two elements
        if (current && current->next && current->value < current->next->value)
        {
            sb(stack_b);
            sorted = false;
        }
        
        // Check if largest value is at bottom and needs to be rotated to top
        int largest = get_largest_b(stack_b);
        if (stack_b->top->value < largest)
        {
            // Decide between rb and rrb based on position of largest
            int pos = 0;
            current = stack_b->top;
            while (current && current->value != largest)
            {
                pos++;
                current = current->next;
            }
            
            // If largest is closer to top, use rb
            if (pos <= stack_b->size / 2)
            {
                rb(stack_b);
            }
            // If largest is closer to bottom, use rrb
            else
            {
                rrb(stack_b);
            }
            sorted = false;
        }
        
        print_stack(stack_b);
    }
}

// Add this helper function to get the position of a target node
int get_target_position(t_stack *stack_b, t_node *target) {
    if (!stack_b || !target)
        return -1;
    
    int pos = 0;
    t_node *current = stack_b->top;
    
    while (current) {
        if (current == target)
            return pos;
        pos++;
        current = current->next;
    }
    return -1;
}

// Modify the element_sort function
void element_sort(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_a->size > 3)
    {
        if (find_cheap(stack_a, stack_b))
        {
            set_targets_nodes(stack_a->top, stack_b);
            
            // Handle sb case
            if (stack_a->top->target == stack_b->top->next)
            {
                pb(stack_a, stack_b);
                sb(stack_b);
            }
            else if (stack_a->top && stack_a->top->target)
            {
                // Get position of target in stack_b
                int target_pos = get_target_position(stack_b, stack_a->top->target);
                
                // Choose rotation direction based on position
                if (target_pos <= stack_b->size / 2)
                {
                    // Use rb if target is in upper half
                    while(stack_b->top != stack_a->top->target)
                        rb(stack_b);
                }
                else
                {
                    // Use rrb if target is in lower half
                    while(stack_b->top != stack_a->top->target)
                        rrb(stack_b);
                }
                pb(stack_a, stack_b);
            }
            else
            {
                if(set_targets_nodes(stack_a->top, stack_b) == 0)
                {
                    if (!is_stack_b_sorted(stack_b))
                    {
                        sort_b_inverse(stack_b);
                    }
                    pb(stack_a, stack_b);
                    // After push, decide rotation direction
                    int largest_pos = get_target_position(stack_b, get_largest_node_b(stack_b));
                    if (largest_pos <= stack_b->size / 2)
                        rb(stack_b);
                    else
                        rrb(stack_b);
                }               
            }
            print_stack(stack_b);
        }
    }
    if (stack_a->size == 3)
    {
        while(stack_b->top->value < get_largest_b(stack_b))
        rb(stack_b); 
        sorted_a(stack_a);
        return;
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
    tiny_sort(stack_a, stack_b);
    print_stack(stack_a);
    print_stack(stack_b);
    sortback(stack_a, stack_b);


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