#include <stdio.h>
#include <stdlib.h>

// Stack Node Definition
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// Stack Definition
typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

// Stack Operations
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

// Push from stack_a to stack_b (pb operation)
void pb(t_stack *stack_a, t_stack *stack_b) {
    if (stack_a->top) {
        t_node *temp = stack_a->top;
        stack_a->top = stack_a->top->next;
        temp->next = stack_b->top;
        stack_b->top = temp;
        stack_a->size--;
        stack_b->size++;
        printf("pb\n");
    }
}

// Push from stack_b to stack_a (pa operation)
void pa(t_stack *stack_a, t_stack *stack_b) {
    if (stack_b->top) {
        t_node *temp = stack_b->top;
        stack_b->top = stack_b->top->next;
        temp->next = stack_a->top;
        stack_a->top = temp;
        stack_b->size--;
        stack_a->size++;
        printf("pa\n");
    }
}

// Print the Stack
void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Utility Function to Find Maximum Bits (for Radix Sort)
int calculate_max_bits(t_stack *stack) {
    t_node *current = stack->top;
    int max = current->value;
    while (current) {
        if (current->value > max) {
            max = current->value;
        }
        current = current->next;
    }
    int bits = 0;
    while ((max >> bits) != 0) {
        bits++;
    }
    return bits;
}
int calculate_chunk_size(int stack_size) {
    if (stack_size > 100) return stack_size / 5; // 5 chunks for larger stacks
    if (stack_size > 50) return stack_size / 4;  // 4 chunks for medium stacks
    return stack_size / 2;                       // 2 chunks for smaller stacks
}


// Sorting Algorithms
void tiny_sort(t_stack *stack_a) {
    if (stack_a->size == 2 && stack_a->top->value > stack_a->top->next->value) {
        printf("Performing sa\n");
        int temp = stack_a->top->value;
        stack_a->top->value = stack_a->top->next->value;
        stack_a->top->next->value = temp;
    } else if (stack_a->size == 3) {
        int first = stack_a->top->value;
        int second = stack_a->top->next->value;
        int third = stack_a->top->next->next->value;

        if (first > second && first > third) printf("Performing ra\n");
        else if (second > first && second > third) printf("Performing rra\n");

        if (stack_a->top->value > stack_a->top->next->value) printf("Performing sa\n");
    }
}

void radix_sort(t_stack *stack_a, t_stack *stack_b) {
    int max_bits = calculate_max_bits(stack_a);
    for (int i = 0; i < max_bits; i++) {
        int size = stack_a->size;
        for (int j = 0; j < size; j++) {
            if ((stack_a->top->value >> i) & 1) {
                printf("Performing ra\n");
            } else {
                pb(stack_a, stack_b); // Push to stack_b if bit is 0
            }
        }
        while (stack_b->size > 0) {
            pa(stack_a, stack_b); // Push back to stack_a
        }
    }
}

void chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size) {
    printf("Performing chunk sort with chunk size: %d\n", chunk_size);

    t_node *current;
    for (int i = 0; i < chunk_size && stack_a->size > 0; i++) {
        current = stack_a->top;

        // Move all elements in the chunk to stack_b
        if (current) {
            pb(stack_a, stack_b); // Push the current chunk to stack_b
        }
    }

    // Push the chunk back to stack_a in reverse order
    while (stack_b->size > 0) {
        pa(stack_a, stack_b); // Reinsert from stack_b to stack_a
    }
}


void dynamic_sort(t_stack *stack_a, t_stack *stack_b) {
    while (stack_a->size > 0 || stack_b->size > 0) {
        if (stack_a->size > 100) {
            radix_sort(stack_a, stack_b); // Use radix sort for large stacks
        } else if (stack_a->size > 5) {
            int chunk_size = calculate_chunk_size(stack_a->size); // Dynamic chunk size
            chunk_sort(stack_a, stack_b, chunk_size);
        } else {
            tiny_sort(stack_a); // Use tiny sort for small stacks
            break;
        }
    }
}


// Main Function for Testing
int main() {
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();

    // Test Data: Modify as needed
    int test_data[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(test_data) / sizeof(test_data[0]);

    for (int i = 0; i < size; i++) {
        t_node *new_node = (t_node *)malloc(sizeof(t_node));
        new_node->value = test_data[i];
        new_node->next = stack_a->top;
        stack_a->top = new_node;
        stack_a->size++;
    }

    printf("Initial Stack A:\n");
    print_stack(stack_a);

    dynamic_sort(stack_a, stack_b);

    printf("Final Stack A:\n");
    print_stack(stack_a);

    free(stack_a);
    free(stack_b);

    return 0;
}
