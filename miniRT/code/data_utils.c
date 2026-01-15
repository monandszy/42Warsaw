#include "miniRT.h"

t_ambient *getAmbient(t_entry *entries)
{
	int	i;

	if (!entries)
		return (NULL);
	i = 0;
	while (entries[i].obj)
	{
		if (entries[i].type == AMBIENT)
			return ((t_ambient *)entries[i].obj);
		i++;
	}
	return (NULL);
}

t_camera *getCamera(t_entry *entries)
{
	int	i;

	if (!entries)
		return (NULL);
	i = 0;
	while (entries[i].obj)
	{
		if (entries[i].type == CAMERA)
			return ((t_camera *)entries[i].obj);
		i++;
	}
	return (NULL);
}

t_light *getLight(t_entry *entries)
{
	int	i;

	if (!entries)
		return (NULL);
	i = 0;
	while (entries[i].obj)
	{
		if (entries[i].type == LIGHT)
			return ((t_light *)entries[i].obj);
		i++;
	}
	return (NULL);
}

void *getObject(t_entry *entries, t_type type, int n)
{
	int	i;
	int	count;

	if (!entries)
		return (NULL);
	i = 0;
	count = 0;
	while (entries[i].obj)
	{
		if (entries[i].type == type)
		{
			if (count == n)
				return (entries[i].obj);
			count++;
		}
		i++;
	}
	return (NULL);
}
