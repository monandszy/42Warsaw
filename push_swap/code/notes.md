/* int calculate_b_move_rrr(int target, t_stack *b)
{
  t_dlist *i;
  int b_index;

  b_index = b -> size;
  i -> b -> end;
  while (i)
  {
    if (i -> target > target)
      return (b_index);
    b_index++;
    i = i -> prev;
  }
  return (b_index);
} */

/* // 1 2 3 4 5
//
pb
// 2 3 4 5
// 1
pb rr
// 3 4 5
// 1 2
pb rr
// 4 5
// 1 2 3


// 5 4 3 2 1
//
pb
// 4 3 2 1
// 5
pb
// 3 2 1
// 4 5

// 5 3 4 2 1
//
pb
// 3 4 2 1
// 5
pb (cost of 3 = 0, cost of 4 = 1)
// 4 2 1
// 3 5
rb pb (cost of 4 = 1, cost of 2 = 1, 1 = 1)
// 2 1
// 4 5 3
rrb pb
// 2 3 4 5
// pb
// 1 2 3 4 5

pb */
// 4
// 4 5 3

// COST = current_a_pos_offset + current_b_pos_offset

// for each a
//   check target position
// calculate cost - (rotation cost (combined, a, b)
// future offset from where it is added)
