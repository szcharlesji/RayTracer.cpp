#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

void write_color (std::ostream& out, color pixel_color)
{
    // Convert to 0-255
    int ir = static_cast<int>(255.999 * pixel_color.x());
    int ig = static_cast<int>(255.999 * pixel_color.y());
    int ib = static_cast<int>(255.999 * pixel_color.z());

    // Print pixels
    out << ir << ' ' << ig << ' ' << ib << '\n';
}

#endif