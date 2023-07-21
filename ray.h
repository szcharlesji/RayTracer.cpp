#ifndef RAY_H
#define RAY_H

#include "vec3.h"
#include "color.h"
class ray {
    public:
        ray() {} // Default constructor
        ray(const point3& origin, const vec3& direction)
            : orig(origin), dir(direction)
        {} // Overload constructor with origin and direction

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

color ray_color(const ray& r)
{
    vec3 unit_direction = unit_vector(r.direction()); // Unit vector of ray direction
    auto t = 0.5 * (unit_direction.y() + 1.0); // Scale y to 0.0-1.0 because unit vector has -1.0-1.0 range

    // Linear interpolation
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0); // Blend white and blue to create gradient
}

#endif