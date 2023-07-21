#ifndef RAY_H
#define RAY_H

#include "vec3.h"
#include "color.h"
class ray
{
public:
    ray() {} // Default constructor
    ray(const point3 &origin, const vec3 &direction)
        : orig(origin), dir(direction)
    {
    } // Overload constructor with origin and direction

    // Getters
    point3 origin() const { return orig; }
    vec3 direction() const { return dir; }

    point3 at(double t) const
    {
        return orig + t * dir;
    }

public:
    point3 orig;
    vec3 dir;
};

bool hit_sphere(const point3 &center, double radius, const ray &r)
{
    vec3 oc = r.origin() - center;              // Vector from center to origin
    auto a = dot(r.direction(), r.direction()); // a = b^2
    auto b = 2.0 * dot(oc, r.direction());      // b = 2bh
    auto c = dot(oc, oc) - radius * radius;     // c = h^2 - r^2
    auto discriminant = b * b - 4 * a * c;      // b^2 - 4ac
    return (discriminant > 0);                  // If discriminant is greater than 0, there are 2 real roots, so the ray hit the sphere
}



color ray_color(const ray &r)
{
    if (hit_sphere(point3(0, 0, -1), 0.5, r)) // If ray hits sphere that centers at (0, 0, -1) with radius 0.5
        return color(0.8, 0.2, 0.2);
    vec3 unit_direction = unit_vector(r.direction()); // Unit vector of ray direction
    auto t = 0.8 * (unit_direction.y() + 1.0);        // Scale y to 0.0-1.0 because unit vector has -1.0-1.0 range

    // Linear interpolation
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0); // Blend white and blue to create gradient
}


#endif