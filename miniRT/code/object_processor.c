#include "miniRT.h"

// A 0.2 255,255,255
int process_Ambient(t_parser_data *pd, char **parts, t_entry *entry)
{
  t_ambient *ambient;
  double range;
  int rgb;

  entry->type = AMBIENT;
  if (split_len(parts) != 2)
    return (error(pd, "Error: Ambient invalid len\n"));
  
  range = extract_decimal(pd, parts[0]);
  rgb = extract_rgb(pd, parts[1]);

  ambient = (t_ambient *) malloc(sizeof(ambient));
  if (!ambient)
    return (error(pd, "Error: Ambient malloc failed\n"), 1);
  ambient->range = range;
  ambient->rgb = rgb;
  entry->obj = ambient;
  return (0);
}

// void cp_coord(t_coord *c1, t_coord *c2)
// {
//   c1->x = c2->x;
//   c1->y = c2->y;
//   c1->z = c2->z;
// }

// C -50.0,0,20 0,0,1 70
int process_Camera(t_parser_data *pd, char **parts, t_entry *entry)
{
  t_camera *camera;
  t_coord pos;
  t_coord vector;
  int fov;

  entry->type = CAMERA;
  if (split_len(parts) != 3)
    return (error(pd, "Error: Camera invalid len\n"));

  extract_coord(pd, parts[0], &pos);
  extract_coord(pd, parts[1], &vector);
    fflush(stdout);
  fov = extract_number(pd, parts[2]);

  camera = (t_camera *) malloc(sizeof(camera));
  if (!camera)
    return (error(pd, "Error: Camera malloc failed\n"), 1);
  
  camera->pos = pos;
  camera->vector = vector;
  // cp_coord(&camera->pos, &pos);
  // cp_coord(&camera->vector, &vector);
  camera->fov = fov;
  entry->obj = camera;

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
