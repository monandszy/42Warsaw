#include "miniRT.h"

int process_object(t_parser_data *pd, char *obj, t_entry *entry)
{
  char **parts;
  char *specifier;
  int code;

  parts = ft_split(obj, ' ');
  if (!parts || !parts[0])
    return (error(pd, "Error: Split failed or empty specifier\n"));

  pd->parts = parts;
  specifier = parts[0];
  if (ft_strncmp(specifier, "A", 2) == 0)
    code = process_Ambient(pd, parts + 1, entry);
  else if (ft_strncmp(specifier, "C", 2) == 0)
    code = process_Camera(pd, parts + 1, entry);
  else if (ft_strncmp(specifier, "L", 2) == 0)
    code = process_Light(pd, parts + 1, entry);
  else if (ft_strncmp(specifier, "sp", 3) == 0)
    code = process_sphere(pd, parts + 1, entry);
  else if (ft_strncmp(specifier, "pl", 3) == 0)
    code = process_plane(pd, parts + 1, entry);
  else if (ft_strncmp(specifier, "cy", 3) == 0)
    code = process_cylinder(pd, parts + 1, entry);
  else
    code = error(pd, "Error: Unknown object type\n");
  free_split(parts);
  pd->parts = NULL;
  return (code);
}

void init_counters(t_data *d, t_entry *entries, size_t len)
{
  size_t i;

  i = 0;
  while (i < len)
  {
    if (entries[i].obj)
    {
      if (entries[i].type == AMBIENT)
        d->count_ambient++;
      else if (entries[i].type == CAMERA)
        d->count_camera++;
      else if (entries[i].type == LIGHT)
        d->count_light++;
      else if (entries[i].type == SPHERE)
        d->count_sphere++;
      else if (entries[i].type == PLANE)
        d->count_plane++;
      else if (entries[i].type == CYLINDER)
        d->count_cylinder++;
    }
    i++;
  }
}

int parse_file(t_data *d, char *file)
{
  static t_parser_data pd;
  char **objects;
  t_entry *entries;
  size_t len;
  size_t i;

  pd.file_content = file;
  objects = ft_split(file, '\n');
  if (!objects)
    return (error(&pd, "Error: Split objects failed\n"));
  pd.objects = objects;

  len = split_len(objects);
  entries = (t_entry *) malloc(sizeof(t_entry) * (len + 1));
  if (!entries)
    return (error(&pd, "Error: Malloc entries failed\n"));
  ft_bzero(entries, sizeof(t_entry) * (len + 1));
  pd.entries = entries;

  i = 0;
  while(i < len)
  {
    if (process_object(&pd, objects[i], &entries[i]))
      return (error(&pd, "Error: Process object failed\n"));
    i++;
  }
  init_counters(d, entries, len);
  if (d->count_ambient != 1 || d->count_camera != 1 || d->count_light != 1)
    return (error(&pd, "Error: Invalid count of Ambient or Camera or Light\n"));
  free_split(objects);
  d->entries = entries;
  d->elen = len;
  return (0);
}