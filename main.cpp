// Creator: Cheng Ji

#include "color.h"
#include "vec3.h"
#include "ray.h"

#include <iostream>

int main()
{
    // Creating an image
    // Image size
    const auto aspect_ratio = 16.0 / 9.0;
    const auto image_width = 400;
    const auto image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera
    auto viewport_height = 2.0; // Height of viewport
    auto viewport_width = aspect_ratio * viewport_height; // Width of viewport
    auto focal_length = 1.0; // Distance between camera and viewport

    auto origin = point3(0, 0, 0); // Camera origin
    auto horizontal = vec3(viewport_width, 0, 0); // Horizontal direction
    auto vertical = vec3(0, viewport_height, 0); // Vertical direction
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length); // Lower left corner of viewport

    // Render
    std::cout << "P3\n"
              << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j)
    {
        // Print progress when rendering
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

        // Print pixels
        for (int i = 0; i < image_width; ++i)
        {
            // color pixel_color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.25);
            auto u = double(i) / (image_width - 1); // Horizontal percentage position of pixel
            auto v = double(j) / (image_height - 1); // Vertical percentage position of pixel
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin); // Ray from origin to pixel
            color pixel_color = ray_color(r); // Color of pixel
            write_color(std::cout, pixel_color);
        }
    }

    // Print done when rendering is finished
    std::cerr << "\nDone.\n";
}
