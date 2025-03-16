#pragma once

#include "structs.h"

void InitBullets(Bullet* bullets, float size);
void FireBullet(Bullet* b, Vector2 origin, float speed, float angle);
void UpdateBullets(Bullet* bullets, int ww, int wh, int* frame_counter);
void DrawBullets(const Texture *texture, const Bullet *b);
int CheckBulletCollision(const Bullet *b, Vector2 *entity_pos, float entity_radius);