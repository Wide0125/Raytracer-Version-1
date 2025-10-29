#ifndef VECTOR_H
#define VECTOR_H
#include "point.hpp"

struct Vector {
    double x {};
    double y {};
    double z {};
};

inline constexpr Vector operator+(const Vector& vector1, const Vector& vector2) {
    return {vector1.x + vector2.x,
            vector1.y + vector2.y,
            vector1.z + vector2.z};
}

inline constexpr Vector& operator+=(Vector& vector1, const Vector& vector2) {
    vector1 = {
            vector1.x + vector2.x,
            vector1.y + vector2.y,
            vector1.z + vector2.z
        };
    return vector1;
}

inline constexpr Vector operator-(const Vector& vector1, const Vector& vector2) {
    return {vector1.x - vector2.x,
            vector1.y - vector2.y,
            vector1.z - vector2.z};
}

inline constexpr Vector operator-(const Vector& vector) {
    return {-vector.x,
            -vector.y,
            -vector.z};
}

inline constexpr Vector operator-(const Point& point1, const Point& point2) {
    return {point1.x - point2.x, 
            point1.y - point2.y,
            point1.z - point2.z};
}

inline constexpr Vector operator*(double multiple, const Vector& vector) {
    return {multiple * vector.x,
            multiple * vector.y,
            multiple * vector.z};
}

inline constexpr double dotProduct(const Vector& vector1, const Vector& vector2) {
    return vector1.x * vector2.x +
    vector1.y * vector2.y +
    vector1.z * vector2.z;
}

inline constexpr Vector crossProduct(const Vector& vector1, const Vector& vector2) {
    double a1 = vector1.x;
    double a2 = vector1.y;
    double a3 = vector1.z;

    double b1 = vector2.x;
    double b2 = vector2.y;
    double b3 = vector2.z;

    return Vector{a2 * b3 - a3 * b2, a3 * b1 - a1 * b3, a1 * b2 - a2 * b1};
}

#endif
