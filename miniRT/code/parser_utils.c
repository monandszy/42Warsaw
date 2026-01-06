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

int	ft_is_decimal(char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

float extract_decimal(char *str)
{
  if (ft_is_decimal(str))
    return (ft_atof(str));
  return (0.0f);
}

// "r,g,b" -> "123,123,123"
int extract_rgb(char *str)
{
  char **parts;
  int rgb[3] = {0};
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

void print_error(char *msg)
{
  write(2, msg, ft_strlen(msg));
}