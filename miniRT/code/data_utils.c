#include "miniRT.h"

t_ambient *getAmbient(t_entry *entries)
{
	int	i;

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

	i = 0;
	while (entries[i].obj)
	{
		if (entries[i].type == LIGHT)
			return ((t_light *)entries[i].obj);
		i++;
	}
	return (NULL);
}

t_sphere *getSphere(t_entry *entries, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (entries[i].obj)
	{
		if (entries[i].type == SPHERE)
		{
			if (count == n)
				return ((t_sphere *) entries[i].obj);
			count++;
		}
		i++;
	}
	return (NULL);
}

t_plane *getPlane(t_entry *entries, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (entries[i].obj)
	{
		if (entries[i].type == PLANE)
		{
			if (count == n)
				return ((t_plane *) entries[i].obj);
			count++;
		}
		i++;
	}
	return (NULL);
}

t_cylinder *getCylinder(t_entry *entries, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (entries[i].obj)
	{
		if (entries[i].type == CYLINDER)
		{
			if (count == n)
				return ((t_cylinder *) entries[i].obj);
			count++;
		}
		i++;
	}
	return (NULL);
}
