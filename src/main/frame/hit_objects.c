#include "frame.h"

double discriminant(double a, double b, double c) {
  return (b * b - 4 * a * c);
}

t_root roots(double a, double b, double discriminant) {
  t_root root;
  double temp;

  if (discriminant < 0)
    root.root_number = 0;
  else if (discriminant == 0) {
    root.root_number = 1;
    root.root1 = -b / (2 * a);
  } else {
    root.root_number = 2;
    root.root1 = (-b + sqrt(discriminant)) / (2 * a);
    root.root2 = (-b - sqrt(discriminant)) / (2 * a);
    if (root.root1 > root.root2) {
      temp = root.root1;
      root.root1 = root.root2;
      root.root2 = temp;
    }
  }
  return root;
}

t_root hit_sphere(const point3 center, double rad, const t_ray r) {
  t_vec3 oc;

  oc = vec3_subtract(r.orig, center);
  double a = vec3_dot(&r.dir, &r.dir);
  double b = 2.0 * vec3_dot(&oc, &r.dir);
  double c = vec3_dot(&oc, &oc) - rad * rad;
  return (roots(a, b, discriminant(a, b, c)));
}

t_root hit_plane(const point3 center, const point3 normal_vec,
                 const t_ray ray) {
	t_root root;
	double denom = vec3_dot(&ray.dir, &normal_vec);

	if (fabs(denom) < 1e-6)
		root.root_number = 0;
	else
	{	
		t_vec3 oc = vec3_subtract(center, ray.orig);
		root.root1 = vec3_dot(&oc, &normal_vec) / denom;
		if(root.root1 > 0)
			root.root_number = 1;
		else
			root.root_number = 0;}
  return root;
}

t_root hit_cylinder(point3 center, const point3 normal_vec, t_ray r,
                    const double radius,
                    const double height) // sınırsız silindir?
{
  double a;
  double b;
  double c;
  t_root root;
  t_ray   local_ray;

  local_ray = transformed_ray(normal_vec, center, r, 1);
  
  if (local_ray.dir.z)
    a = pow(local_ray.dir.x, 2) + pow(local_ray.dir.z, 2);
  b = 2 * (local_ray.orig.x * local_ray.dir.x + local_ray.orig.z * local_ray.dir.z);
  c = pow(local_ray.orig.x, 2) + pow(local_ray.orig.z, 2) - pow(radius, 2);

  root = roots(a, b, discriminant(a, b, c));
  double hit_y = local_ray.orig.y + root.root1 * local_ray.dir.y;

  if (hit_y < -height / 2.0 || hit_y > height / 2.0)
    {
        hit_y = local_ray.orig.y + root.root2 * local_ray.dir.y;
        if (hit_y < -height / 2.0 || hit_y > height / 2.0){
          root.root_number = 0;
            return (root);}
    }
  return (root);
}

// En yakın pozitif kökü döndürür; geçerli kök yoksa -1 döner
double closest_positive_root(t_root root) {
    double t = -1.0;
    if (root.root_number > 0 && root.root1 > 0.001)
        t = root.root1;
    if (root.root_number > 1 && root.root2 > 0.001 && (t < 0 || root.root2 < t))
        t = root.root2;
    return t;
}