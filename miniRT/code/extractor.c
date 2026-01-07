#include "miniRT.h"

float extract_decimal(t_parser_data *pd, char *str)
{
  float res;

  if (ft_is_decimal(str))
    res = ft_atof(str);
  else
  {
    error(pd);
    res = 0.0;
  }
  return (res);
}

// "r,g,b"
int extract_rgb(t_parser_data *pd, char *str)
{
  char **parts;
  int i;

  parts = ft_split(str, ',');
  if (!parts)
    return (error(pd));
  if (split_len(parts) != 3)  
    return (free_split(parts), error(pd));
  i = 0;
  while (i < 3)
  {
    if (!ft_isnumber(parts[i]))
      return (free_split(parts), error(pd));
    i++;
  }
  free_split(parts);
  return (get_color(ft_atoi(parts[0]), ft_atoi(parts[1]), ft_atoi(parts[2])));
}

// "x,y,z"
void extract_coord(t_parser_data *pd, char *str, t_coord *coord)
{
  char **parts;
  int i;

  parts = ft_split(str, ',');
  if (!parts)
    return (error(pd), (void) 0);
  if (split_len(parts) != 3)  
    return (free_split(parts), error(pd), (void) 0);
  i = 0;
  while (i < 3)
  {
    if (!ft_is_decimal(parts[i]))
      return (free_split(parts), error(pd), (void) 0);
    i++;
  }
  coord->x = ft_atof(parts[0]);
  coord->y = ft_atof(parts[1]);
  coord->z = ft_atof(parts[2]);
  free_split(parts);
}