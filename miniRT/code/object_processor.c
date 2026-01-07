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

  ambient = (t_ambient *) malloc(sizeof(t_ambient));
  if (!ambient)
    return (error(pd, "Error: Ambient malloc failed\n"), 1);
  ambient->range = range;
  ambient->rgb = rgb;
  entry->obj = ambient;
  return (0);
}

void cp_coord(t_coord *c1, t_coord *c2)
{
  c1->x = c2->x;
  c1->y = c2->y;
  c1->z = c2->z;
}

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
  fov = extract_number(pd, parts[2]);

  camera = (t_camera *) malloc(sizeof(t_camera));
  if (!camera)
    return (error(pd, "Error: Camera malloc failed\n"), 1);
  
  cp_coord(&camera->pos, &pos);
  cp_coord(&camera->vector, &vector);
  camera->fov = fov;
  entry->obj = camera;

  return (0);
}
  
// L -40.0,50.0,0.0 0.6 10,0,25
int process_Light(t_parser_data *pd, char **parts, t_entry *entry)
{
  t_light *light;
  t_coord pos;
  float brightness;
  int rgb;
  
  entry->type = LIGHT;
  if (split_len(parts) != 3)
    return (error(pd, "Error: Light invalid len\n"));

  extract_coord(pd, parts[0], &pos);
  brightness = extract_decimal(pd, parts[1]);
  rgb = extract_rgb(pd, parts[2]);

  light = (t_light *) malloc(sizeof(t_light));
  if (!light)
    return (error(pd, "Error: light malloc failed\n"), 1);
  
  cp_coord(&light->pos, &pos);
  light->brightness = brightness;
  light->rgb = rgb;
  
  entry->obj = light;
  return (0);
}
  
// sp 0.0,0.0,20.6 12.6 10,0,255
int process_sphere(t_parser_data *pd, char **parts, t_entry *entry)
{
  t_sphere *sphere;
  t_coord pos;
  float diameter;
  int rgb;

  entry->type = SPHERE;

  if (split_len(parts) != 3)
    return (error(pd, "Error: Sphere invalid len\n"));

  extract_coord(pd, parts[0], &pos);
  diameter = extract_decimal(pd, parts[1]);
  rgb = extract_rgb(pd, parts[2]);

  sphere = (t_sphere *) malloc(sizeof(t_sphere));
  if (!sphere)
    return (error(pd, "Error: Sphere malloc failed\n"), 1);
  
  cp_coord(&sphere->pos, &pos);
  sphere->diameter = diameter;
  sphere->rgb = rgb;
  
  entry->obj = sphere;
  return (0);
}

// 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
int process_plane(t_parser_data *pd, char **parts, t_entry *entry)
{
  t_plane *plane;
  t_coord pos;
  t_coord vector;
  int rgb;

  entry->type = PLANE;

  if (split_len(parts) != 3)
    return (error(pd, "Error: Plane invalid len\n"));

  extract_coord(pd, parts[0], &pos);
  extract_coord(pd, parts[1], &vector);
  rgb = extract_rgb(pd, parts[2]);

  plane = (t_plane *) malloc(sizeof(t_plane));
  if (!plane)
    return (error(pd, "Error: Plane malloc failed\n"), 1);
  
  cp_coord(&plane->pos, &pos);
  cp_coord(&plane->vector, &vector);
  plane->rgb = rgb;
  
  entry->obj = plane;
  return (0);
}

// cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
int process_cylinder(t_parser_data *pd, char **parts, t_entry *entry)
{
  t_cylinder *cylinder;
  t_coord pos;
  t_coord vector;
  float diameter;
  float height;
  int rgb;

  entry->type = CYLINDER;

  if (split_len(parts) != 5)
    return (error(pd, "Error: Cylinder invalid len\n"));

  extract_coord(pd, parts[0], &pos);
  extract_coord(pd, parts[1], &vector);
  diameter = extract_decimal(pd, parts[2]);
  height = extract_decimal(pd, parts[3]);
  rgb = extract_rgb(pd, parts[4]);

  cylinder = (t_cylinder *) malloc(sizeof(t_cylinder));
  if (!cylinder)
    return (error(pd, "Error: Cylinder malloc failed\n"), 1);
  
  cp_coord(&cylinder->pos, &pos);
  cp_coord(&cylinder->vector, &vector);
  cylinder->diameter = diameter;
  cylinder->height = height;
  cylinder->rgb = rgb;
  
  entry->obj = cylinder;
  return (0);
}
