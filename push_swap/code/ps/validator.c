
#include "ps.h"

int	validate_argv(char **args)
{
	if (check_numonly(args, 0) || check_maxint(args, 0)
		|| check_duplicates(args, 0, 0))
		return (1);
	return (0);
}

int	check_numonly(char **args, int i)
{
	while (args[i] != NULL)
	{
		if (!ft_isnumber(args[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_duplicates(char **args, int i, int j)
{
	while (args[i])
	{
		while (args[j])
		{
			if (i != j && ft_strncmp(args[i], args[j], ft_strlen(args[i])
					+ 1) == 0)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_maxint(char **args, int i)
{
	size_t	len;

	while (args[i])
	{
		len = ft_strlen(args[i]);
		if (len > 11)
			return (1);
		if (len == 10 || len == 11)
		{
			if (args[i][0] == '-')
			{
				if (ft_strncmp(args[i], "-2147483648", len) > 0)
					return (1);
			}
			else
			{
				if (ft_strncmp(args[i], "2147483647", len) > 0)
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int	ft_isnumber(char *str)
{
	int i;

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