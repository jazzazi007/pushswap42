#include "push_swap.h"

/*void insertion_stack(t_stack* stack) { 
    if (!stack || stack->size < 2) 
        return; // No need to sort if the stack is empty or has one element }


t_node *sorted = NULL; // This will be the new sorted stack
t_node *current = stack->top; // Start from the top of the original stack

while (current != NULL) {
    t_node *next = current->next; // Store next node to process
    // Insert current node in sorted order
    if (sorted == NULL || sorted->value >= current->value) {
        current->next = sorted; // Insert at the beginning
        sorted = current; // Update sorted stack
    } else {
        t_node *temp = sorted;
        // Find the position to insert
        while (temp->next != NULL && temp->next->value < current->value) {
            temp = temp->next;
        }
        current->next = temp->next; // Insert in the middle or end
        temp->next = current;
    }
    current = next; // Move to the next node
}

stack->top = sorted; // Update the original stack to point to the sorted stack
}*/

/*void insertion_stack(t_stack* stack_a, t_stack* stack_b)
{
    int size_a = stack_a->size;
    int size_b = stack_b->size;
    int midpoint = (size_a / 2);
    int i = 0;

    
    t_node* mid = stack_a->top;

    while(i++ < midpoint)
        mid = mid->next;
    i = 0;
    
    while(i++ < size_a/2)
    {
    t_node* current = stack_a->top;
    if (current == NULL) {
        printf("Reached the end of stack_a before expected.\n");
        break; // Exit the loop if current is NULL
    }
    if (mid != NULL && mid->value > current->value) {
        pb(stack_a, stack_b);
    } else if (mid != NULL && mid->value < current->value){
        ra(stack_a);
    }else
        printf("skipped");
            
    }


    print_stack(stack_b);
    print_stack(stack_a);
}*/
void insertion_stack(t_stack* stack_a, t_stack* stack_b)
{
    int size_a = stack_a->size;

    while (size_a > 2) { // Continue until only 2 elements are left in stack_a
        // Calculate the midpoint based on the current size of stack_a
        int midpoint = (size_a / 2);
        t_node* mid = stack_a->top;

        // Move 'mid' pointer to the midpoint
        int j = 0;
        while (j < midpoint && mid != NULL) {
            mid = mid->next;
            j++;
        }

        // Process elements in stack_a
        t_node* current = stack_a->top; // Always start from the top of stack_a
        int i = 0; // Counter for processed elements

        while (i < size_a) {
            if (current == NULL) {
                printf("Reached the end of stack_a before expected.\n");
                break; // Exit the loop if current is NULL
            }

            // Debug print to show current and mid values
            printf("Current value: %d, Mid value: %d\n", current->value, mid ? mid->value : -1);

            // Compare current value with mid value
            if (mid != NULL && mid->value > current->value) {
                pb(stack_a, stack_b); // Push to stack_b
                printf("Pushed %d to stack_b\n", current->value);
                // After pushing, we need to update current to the next node
                current = stack_a->top; // Reset current to the top of stack_a
                size_a = stack_a->size; // Update size_a after push
                continue; // Skip the increment of i since we changed the stack
            } else if (mid != NULL && mid->value < current->value) {
                ra(stack_a); // Rotate stack_a
                printf("Rotated stack_a\n");
                // After rotating, we need to reset current to the top of stack_a
                current = stack_a->top; // Reset current to the top of stack_a
            } else {
                printf("skipped\n");
                // If neither condition is met, advance current
                current = current->next; // Move to the next node in stack_a
            }

            i++; // Increment the processed count
        }

        // Update size_a for the next iteration
        size_a = stack_a->size; // Recalculate the size of stack_a
    }

    // Optionally sort stack_b here if needed
    // sort_stack_b(stack_b); // Implement this function as needed

    print_stack(stack_b);
    print_stack(stack_a);
}

int main(int ac, char **av) {

    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();


    char **result = ft_split(av[1], ' ');
    int i = 0;
    int len = 0;
    int *num;
    if (ac == 2){
    while (result[len]) {
        len++;
        }
    num = (int *)malloc(sizeof(int) * (len+1));
    if (!num)
    return (1);
    while (result[i]){
    num[i] = ft_atoi(result[i]);
    printf("%i: %i\n", i+1, num[i]);
    free(result[i]);
    push(stack_a, num[i]);
    i++;
    }
    free(result);
    num[i] = '\0';



    /*push(stack_a, 12);
    push(stack_a, 11);
    push(stack_a, 13);
    push(stack_a, 5);
    push(stack_a, 20);
    push(stack_a, 6); */

    printf("Befor:\n");
    print_stack(stack_a);
    insertion_stack(stack_a, stack_b);
    // Calling insertion sort on array arr

    return 0;
}}

/*

int main() {
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();

    // Example values to sort
    push(stack_a, 170);
    push(stack_a, 45);
    push(stack_a, 75);
    push(stack_a, 90);
    push(stack_a, 802);
    push(stack_a, 24);
    push(stack_a, 2);
    push(stack_a, 66);

    printf("Before sorting:\n");
    print_stack(stack_a);

    radix_sort(stack_a);

    printf("After sorting:\n");
    print_stack(stack_a);

    // Clean up memory (not shown here for simplicity)

    return 0;
}
*/