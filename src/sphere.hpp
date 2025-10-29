#ifndef SPHERE_H
#define SPHERE_H
#include "point.hpp"
#include "line.hpp"
#include "camera.hpp"
#include <raylib-cpp.hpp>

struct Sphere {
        Point center {0.0, 0.0, 0.0};
        double radius {1};
        raylib::Color color {RED};
};

inline constexpr bool rayIntersectWithSphere(const Line& ray, const Sphere& sphere) {
    const auto a {dotProduct(ray.direction, ray.direction)};
    const auto b {2 * dotProduct(ray.origin - sphere.center, ray.direction)};
    const auto c {dotProduct(ray.origin - sphere.center, ray.origin - sphere.center) - pow(sphere.radius, 2)};
    return pow(b, 2) - (4 * a * c) >= 0 and -b/a >= 0 and c/a >= 0;
    // solve for t to see if the ray intersects with sphere, use discriminant to see if t exists
}

inline void displaySphere(const Custom::Camera& camera, const Sphere& sphere) {
    for (int pixelY {0}; pixelY < camera.screenHeight(); ++pixelY) {
        for (int pixelX {0}; pixelX < camera.screenWidth(); ++pixelX) {
            if(rayIntersectWithSphere(getPixelLine(pixelX, pixelY, camera), sphere)) {
                DrawPixel(pixelX, pixelY, sphere.color);
            }
        }
    }
}

#endif
