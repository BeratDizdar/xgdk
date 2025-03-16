#include "util.h"
#include <math.h>

bool CheckCollision(Vector2 p, Vector2 b) {
    return (fabs(p.x - b.x) < 10 && fabs(p.y - b.y) < 10);
}

float SetAngle(Vector2 point1, Vector2 point2)
{
    float dx = point1.x - point2.x;
    float dy = point1.y - point2.y;
    return atan2f(dy, dx);
}

void LookAt(float *angle, Vector2 p1, Vector2 p2)
{
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    *angle = atan2f(dy, dx);
}

void handleAnimation(float *animation_time, int *animation_index, float *dt)
{
    *animation_time += *dt;
    if(*animation_time > 1.0f) {
        *animation_index += 1;
        if(*animation_index > 1) {
            *animation_index = 0;
        }
        *animation_time = 0.0f;
    }
}