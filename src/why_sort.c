#include "../include/push_swap.h"

void why_sort(t_stack *stack_a, t_stack *stack_b)
{
    //TO DO
        //set tartget of nodes in stack_a
        // targets of top and next

        // then find the cheapest node from both of them
        // if the   cheapest of node top > cheapest of node next : pb in stack_a 
            //but other moves are also possible in stack_b wether rb or rrb
        // else sa then pb
        // after the pb, we will not do the full sort in stacck_b, it is enough to be on the top of the stack
        // then we will start another evaluation of find the cheapest node in stack_a
        // the idea is to move the lowest amount of moves in stack_b

        // rule of sorting at stack_a
        // we can do a small sort in stack_a in the bottom of the stack
        // the rule is to make a small sort to decrease the number of moves on stack_b
        // what is the concept to do this?
}