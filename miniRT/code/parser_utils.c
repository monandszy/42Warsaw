#include "miniRT.h"

float	ft_atof(char *str)
{
	int		i;
	float	sign;
	float	result;
	float	power;

	i = 0;
	sign = 1.0;
	result = 0.0;
	power = 1.0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1.0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i++] - '0');
		power *= 10.0;
	}
	return (sign * result / power);
}

size_t split_len(char **spl)
{
  size_t len;

  len = 0;
  while (spl[len])
    len++;
  return (len);
}

float extract_decimal(char *str)
{
  float res;

  res = ft_atof(str);
  return (res);
}

// "r,g,b"
int extract_rgb(char *str)
{
  char **parts;
  int rgb[3];
  int i;
  size_t len;

  rgb[0] = 0;
  rgb[1] = 0;
  rgb[2] = 0;
  parts = ft_split(str, ',');
  if (!parts)
    return (get_color(rgb[0], rgb[1], rgb[2]));
  len = split_len(parts);
  i = 0;
  while (len--)
  {
    rgb[i] = ft_atoi((parts[i]));
    i++;
  }
  return (get_color(rgb[0], rgb[1], rgb[2]));
}

// "r,g,b"
void extract_coord(char *str, t_coord *coord)
{
  char **parts;
  int xyz[3];
  size_t len;
  int i;
  
  xyz[0] = 0;
  xyz[1] = 0;
  xyz[2] = 0;
  parts = ft_split(str, ',');
  if (!parts)
    return ;
  len = split_len(parts);
  i = 0;
  while (len--)
  {
    xyz[i] = ft_atof((parts[i]));
    i++;
  }
}