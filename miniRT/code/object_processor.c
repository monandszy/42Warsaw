#include "miniRT.h"

// A 0.2 255,255,255
int process_Ambient(char **parts, t_entry *entry)
{
  t_ambient *ambient;

  entry->type = AMBIENT;
  ambient = (t_ambient *) malloc(sizeof(ambient));
  if (!ambient)
    return (print_error("Ambient malloc error"), 1);
  if (split_len(parts) != 3)
    return (print_error("Ambient args length error"), 1);
  
  ambient->range = ft_atof(parts[1]);
  ambient->rgb = extract_rgb(parts[2]);
  entry->obj = ambient;
  return (0);
}

// C -50.0,0,20 0,0,1 70
int process_Camera(char **parts, t_entry *entry)
{
  t_camera *camera;

  entry->type = CAMERA;
  camera = (t_camera *) malloc(sizeof(camera));
  if (!camera)
    return (print_error("Camera malloc error"), 1);
  if (split_len(parts) != 4)
    return (print_error("Camera args length error"), 1);
  camera->fov
  (void) parts;
  (void) entry;
  return (0);
}
  
int process_Light(char **parts, t_entry *entry)
{
  entry->type = LIGHT;
  (void) parts;
  (void) entry;
  return (0);
}
  
int process_sphere(char **parts, t_entry *entry)
{
  entry->type = SPHERE;
  (void) parts;
  (void) entry;
  return (0);
}
  
int process_plane(char **parts, t_entry *entry)
{
  entry->type = PLANE;
  (void) parts;
  (void) entry;
  return (0);
}
  
int process_cylinder(char **parts, t_entry *entry)
{
  entry->type = CYLINDER;
  (void) parts;
  (void) entry;
  return (0);
}
