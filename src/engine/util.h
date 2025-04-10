#pragma once

#include "structs.h"

bool CheckCollision(Vector2 p, Vector2 b);
float SetAngle(Vector2 point1, Vector2 point2);
void LookAt(float *angle, Vector2 p1, Vector2 p2);
void handleAnimation(float *time, int *index, float *dt, float duration, int ani_count);