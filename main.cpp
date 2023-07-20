// Creator: Cheng Ji

#include <iostream>

int main()
{
    // Creating an image

    // Image size
    const int image_width = 256;
    const int image_height = 256;

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
            // Pixel color in RGB
            double r = double(i) / (image_width - 1);
            double g = double(j) / (image_height - 1);
            double b = 0.25;

            // Convert to 0-255
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    // Print done when rendering is finished
    std::cerr << "\nDone.\n";
}
