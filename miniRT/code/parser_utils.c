#include "miniRT.h"

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

int	ft_isnumber(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '-')
		i++;
	if (!*str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

size_t split_len(char **spl)
{
  size_t len;

  len = 0;
  while (spl[len])
    len++;
  return (len);
}