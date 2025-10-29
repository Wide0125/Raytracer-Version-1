#include <raylib-cpp.hpp>
#include "camera.hpp"
#include "sphere.hpp"

int main() {
    Custom::Camera camera {};
    raylib::InitWindow(camera.screenWidth(), camera.screenHeight(), "3D Render Playground");
    Sphere sphere {{0, 0, 3}, 0.5, raylib::GREEN};
    DisableCursor();
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(raylib::WHITE);
        displaySphere(camera, sphere);
        EndDrawing();
    }

    return 0;
}
