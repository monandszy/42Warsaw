int find_pos_of_smallest(t_stack *stack)
{
    t_dlist *current;
    int     min_index = 2147483647; // INT_MAX
    int     min_pos = 0;
    int     current_pos = 0;

    current = stack->start;
    while(current)
    {
        int current_index = *(int *) (current->content);
        if (current_index < min_index)
        {
            min_index = current_index;
            min_pos = current_pos;
        }
        current = current->next;
        current_pos++;
    }
    return (min_pos);
}


int find_insert_pos_in_a(t_stack *a, int b_sorted_index)
{
    t_dlist *current_a;
    int     current_pos;
    int     best_match_pos;
    int     best_match_index;

    current_a = a->start;
    current_pos = 0;
    best_match_pos = -1;
    // Initialize with a very large value to find the minimum index that's larger.
    best_match_index = 2147483647; // Or INT_MAX from <limits.h>

    // Find the element in A that is the smallest but still larger than the element from B.
    while (current_a)
    {
        int a_sorted_index = *(int *) (current_a->content);
        if (a_sorted_index > b_sorted_index && a_sorted_index < best_match_index)
        {
            best_match_index = a_sorted_index;
            best_match_pos = current_pos;
        }
        current_a = current_a->next;
        current_pos++;
    }

    // Edge case: If we didn't find a larger element (meaning the B element is larger than all
    // elements in A), then it should be placed on top of the smallest element in A.
    if (best_match_pos == -1)
    {
        // This now requires finding the position of the smallest element, not the largest.
        best_match_pos = find_pos_of_smallest(a);
    }

    // The position returned is the target that needs to be at the top of A *before* the push.
    // The cost calculation in the main loop will correctly use this position to determine
    // the number of ra/rra moves.
    return (best_match_pos);
}

void    push_back_to_a(t_dlist **steps, t_stack *a, t_stack *b)
{
    while ((int) b->e_count > 0)
    {
        int         best_cost = -1;
        int         final_moves_a = 0;
        int         final_moves_b = 0;

        // 1. Analyze every element in B to find the cheapest one to move.
        t_dlist *current_b = b->start;
        int     current_pos_b = 0;
        while (current_b)
        {
            // Cost to get this B element to the top of stack B
            int cost_b = (current_pos_b <= (int) b->e_count / 2) ? current_pos_b : ((int) b->e_count - current_pos_b) * -1; // Positive for rb, negative for rrb

            // Find where this element should go in stack A
            int target_pos_a = find_insert_pos_in_a(a, *(int *)current_b->content);

            // Cost to get stack A ready for the push
            int cost_a = (target_pos_a <= (int) a->e_count / 2) ? target_pos_a : ((int) a->e_count - target_pos_a) * -1; // Positive for ra, negative for rra

            // Calculate combined cost
            int total_cost;
            if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
            {
                // Rotations are in the same direction (ra/rb or rra/rrb), use rr/rrr
                total_cost = (ft_abs(cost_a) > ft_abs(cost_b)) ? ft_abs(cost_a) : ft_abs(cost_b);
            }
            else
            {
                // Rotations are in opposite directions, just add them up
                total_cost = ft_abs(cost_a) + ft_abs(cost_b);
            }

            // 2. If this is the cheapest move found so far, save it.
            if (best_cost == -1 || total_cost < best_cost)
            {
                best_cost = total_cost;
                final_moves_a = cost_a;
                final_moves_b = cost_b;
            }

            current_b = current_b->next;
            current_pos_b++;
        }

        // 3. Execute the cheapest move.
        // First, do combined rotations (rr or rrr)
        while (final_moves_a > 0 && final_moves_b > 0) { *steps = rr(*steps, a, b); final_moves_a--; final_moves_b--; }
        while (final_moves_a < 0 && final_moves_b < 0) { *steps = rrr(*steps, a, b); final_moves_a++; final_moves_b++; }

        // Then, do remaining individual rotations for A
        while (final_moves_a > 0) { *steps = ra(*steps, a); final_moves_a--; }
        while (final_moves_a < 0) { *steps = rra(*steps, a); final_moves_a++; }

        // Then, do remaining individual rotations for B
        while (final_moves_b > 0) { *steps = rb(*steps, b); final_moves_b--; }
        while (final_moves_b < 0) { *steps = rrb(*steps, b); final_moves_b++; }

        // 4. Finally, push the element.
        *steps = pa(*steps, a, b);
    }
}