#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3
{
    public:
        // Constructors
        vec3() : e{0, 0, 0} {} // Default constructor, initialize to 0
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {} // Overload Constructor

        // Getters
        double x() const { return e[0]; } // Get x
        double y() const { return e[1]; } // Get y
        double z() const { return e[2]; } // Get z

        // Operators
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); } // Unary minus
        double operator[](int i) const { return e[i]; } // Get element
        double& operator[](int i) { return e[i]; } // Get element reference

        vec3& operator+=(const vec3& v) // Add
        {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vec3& operator*=(const double t) // Multiply by scalar
        {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(const double t) // Divide by scalar
        {
            return *this *= 1/t;
        }

        double length() const // Length of vector
        {
            return sqrt(length_squared());
        }

        double length_squared() const // Length squared of vector
        {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

    public:
        double e[3]; // Vector elements
};

// Type aliases for vec3
using point3 = vec3; // 3D point
using color = vec3; // RGB color

// vec3 Utility Functions

inline std::ostream& operator<<(std::ostream& out, const vec3& v) // Print vector
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) // Add
{
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) // Subtract
{
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) // Multiply
{
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) // Multiply by scalar
{
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) // Multiply by scalar
{
    return t * v;
}

inline vec3 operator/(vec3 v, double t) // Divide by scalar
{
    return (1/t) * v;
}

inline double dot(const vec3& u, const vec3& v) // Dot product
{
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) // Cross product
{
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) // Unit vector
{
    return v / v.length();
}

#endif // !VEC3_H
