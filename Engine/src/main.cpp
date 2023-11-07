#include "Window.hpp"
#include "Vector3.hpp"
#include "Camera3D.hpp"

int main(int argc, char const *argv[])
{
    raylib::Window window(1280, 720);

    raylib::Camera3D camera;
    camera.position = {10, 10, 10};
    camera.target = {0, 0, 0};
    camera.up = {0, 1, 0};
    camera.projection = CameraProjection::CAMERA_ORTHOGRAPHIC;
    camera.fovy = 10;

    while (!window.ShouldClose())
    {
        BeginDrawing();

        float dt = GetFrameTime();

        raylib::Vector2 input = {(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) * dt - // Move forward-backward
                                (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) * dt ,
                                (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) * dt - // Move right-left
                                (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) * dt};
        input.Clamp(0.0f, 1.0f);

        camera.Update(raylib::Vector3(input.x, input.y, 0.0f) * 10, raylib::Vector3::Zero(), 0.0f);
        window.ClearBackground();
        camera.BeginMode();
        DrawGrid(10, 1);

        camera.EndMode();
        EndDrawing();
    }
    return 0;
}
