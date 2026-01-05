#include "Point.hpp"
#include "Fixed.hpp"

Fixed ft_abs(Fixed a)
{
  if (a < 0)
  {
    a = a * Fixed(-1);
  }
  return (a);
}

int get_side(Point o, Point w, Point p) {

  Fixed delta_ow_y = ft_abs(o.getY() - w.getY());
  Fixed delta_ow_x = ft_abs(o.getX() - w.getX());

  Fixed delta_op_y = ft_abs(o.getY() - p.getY());
  Fixed delta_op_x = ft_abs(o.getX() - p.getX());

  Fixed result = (delta_op_y * delta_ow_x) - (delta_op_x * delta_ow_y);

  if (result < Fixed(0))
    return (-1);
  else if (result == Fixed(0))
    return (0);
  else
    return (1);
}

bool bsp(
  Point const a,
  Point const b,
  Point const c,
  Point const target
) {

  int s1 = get_side(a, b, target);
  int s2 = get_side(a, b, c);

  if (s1 != 0 && s1 == s2)
  {
    s1 = get_side(a, c, target);
    s2 = get_side(a, c, b);
    if (s1 != 0 && s1 == s2)
    {
      s1 = get_side(b, c, target);
      s2 = get_side(b, c, a);
      if (s1 != 0 && s1 == s2)
      {
        return true;
      }
    }
  }
  return false;
}