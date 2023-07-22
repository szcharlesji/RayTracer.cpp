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

    point3 at(double t) const // t is the distance from the origin
    {
        return orig + t * dir;
    }

public:
    point3 orig;
    vec3 dir;
};

double hit_sphere(const point3 &center, double radius, const ray &r)
{
    // center means the position of the sphere
    // radius means the radius of the sphere
    // r means the ray that has origin r.origin() and direction r.direction()
    // r is the vector from the camera to the pixel

    // oc is the vector from the center of the sphere to the origin of the ray
    vec3 oc = r.origin() - center;              // Vector from center to origin
    auto a = dot(r.direction(), r.direction()); // a = b^2
    auto b = 2.0 * dot(oc, r.direction());      // b = 2bh
    auto c = dot(oc, oc) - radius * radius;     // c = h^2 - r^2
    auto discriminant = b * b - 4 * a * c;      // b^2 - 4ac
    if (discriminant > 0)
    {
        return (-b - sqrt(discriminant)) / (2.0 * a); // Return the smaller root
    }                                                 // If discriminant is greater than 0, there are 2 real roots, so the ray hit the sphere
    else
    {
        return -1.0; // If discriminant is less than 0, there are no real roots, so the ray missed the sphere
    }
}

color ray_color(const ray &r)
{
    auto t = hit_sphere(point3(0, 0, -1), 0.5, r); // Check if ray hits sphere
    if (t > 0.0)
    {                                                        // If ray hits sphere
        vec3 N = unit_vector(r.at(t) - vec3(0, 0, -1));      // Normal vector
        return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1); // Return color based on normal vector
    }
    vec3 unit_direction = unit_vector(r.direction()); // Unit vector of ray direction
    t = 0.8 * (unit_direction.y() + 1.0);             // Scale y to 0.0-1.0 because unit vector has -1.0-1.0 range

    // Linear interpolation
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0); // Blend white and blue to create gradient
}

#endif