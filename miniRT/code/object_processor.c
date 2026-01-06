#include "miniRT.h"

// A 0.2 255,255,255
void process_Ambient(char **parts, t_entry *entry)
{
  t_ambient *ambient;

  entry->type = AMBIENT;
  ambient = (t_ambient *) malloc(sizeof(ambient));
  if (!ambient)
    return ;
  
  if (split_len(parts) == 3)
  {
    ambient->range = extract_decimal(parts[1]);
    ambient->rgb = extract_rgb(parts[2]);
  }
  else
  {
    write()
    ambient->range = 0.0f;
    ambient->rgb = get_color(0, 0, 0);
  }
  entry->obj = ambient;
}

void process_Camera(char **parts, t_entry *entry)
{
  entry->type = CAMERA;
  (void) parts;
  (void) entry;
}
  
void process_Light(char **parts, t_entry *entry)
{
  entry->type = LIGHT;
  (void) parts;
  (void) entry;
}
  
void process_sphere(char **parts, t_entry *entry)
{
  entry->type = SPHERE;
  (void) parts;
  (void) entry;
}
  
void process_plane(char **parts, t_entry *entry)
{
  entry->type = PLANE;
  (void) parts;
  (void) entry;
}
  
void process_cylinder(char **parts, t_entry *entry)
{
  entry->type = CYLINDER;
  (void) parts;
  (void) entry;
}
