#include "miniRT.h"

// A 0.2 255,255,255
int process_Ambient(t_parser_data *pd, char **parts, t_entry *entry)
{
  t_ambient *ambient;
  double range;
  int rgb;

  entry->type = AMBIENT;
  if (split_len(parts) != 3)
    return (error(pd, "Error: Ambient invalid len\n"));
  
  range = extract_decimal(pd, parts[1]);
  rgb = extract_rgb(pd, parts[2]);

  ambient = (t_ambient *) malloc(sizeof(ambient));
  if (!ambient)
    return (error(pd, "Error: Ambient malloc failed\n"), 1);
  ambient->range = range;
  ambient->rgb = rgb;
  entry->obj = ambient;
  return (0);
}

// C -50.0,0,20 0,0,1 70
int process_Camera(t_parser_data *pd, char **parts, t_entry *entry)
{
  t_camera *camera;
  error(pd, "Error: Camera not implemented\n");

  entry->type = CAMERA;
  (void) camera;
  (void) parts;
  (void) entry;
  return (0);
}
  
int process_Light(t_parser_data *pd, char **parts, t_entry *entry)
{
  entry->type = LIGHT;
  error(pd, "Error: Light not implemented\n");
  (void) parts;
  (void) entry;
  return (0);
}
  
int process_sphere(t_parser_data *pd, char **parts, t_entry *entry)
{
  entry->type = SPHERE;
  error(pd, "Error: Sphere not implemented\n");
  (void) parts;
  (void) entry;
  return (0);
}
  
int process_plane(t_parser_data *pd, char **parts, t_entry *entry)
{
  entry->type = PLANE;
  error(pd, "Error: Plane not implemented\n");
  (void) parts;
  (void) entry;
  return (0);
}
  
int process_cylinder(t_parser_data *pd, char **parts, t_entry *entry)
{
  entry->type = CYLINDER;
  error(pd, "Error: Cylinder not implemented\n");
  (void) parts;
  (void) entry;
  return (0);
}
