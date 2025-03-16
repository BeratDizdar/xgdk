#include "bullet.h"
#include "util.h"
#include <math.h>

void InitBullets(Bullet* b, float size) {
    for (int i = 0; i < MAX_BULLET; i++) {
        b->active[i] = false;
    }
    b->size = size;
}

void FireBullet(Bullet* b, Vector2 origin, float speed, float angle) {
    for (int i = 0; i < MAX_BULLET; i++) {
        if (!b->active[i]) {
            b->active[i] = true;
            b->position[i] = origin;
            b->velocity[i].x = cosf(angle) * speed;
            b->velocity[i].y = sinf(angle) * speed;
            break;
        }
    }
}

void UpdateBullets(Bullet* bullets, int ww, int wh, int* frame_counter) {
    bullets->active_count = 0;

    for (int i = 0; i < MAX_BULLET; i++) {
        if (bullets->active[i]) {
            bullets->position[i].x += bullets->velocity[i].x;
            bullets->position[i].y += bullets->velocity[i].y;

            if (bullets->position[i].x < 0 || bullets->position[i].x > ww ||
                bullets->position[i].y < 0 || bullets->position[i].y > wh) {
                bullets->active[i] = false;
            } else {
                bullets->active_count++;
            }
        }
    }
    (*frame_counter)++;
}

void DrawBullets(const Texture *texture, const Bullet *b)
{
    for (int i = 0; i < MAX_BULLET; i++) {
        if (b->active[i]) {
            DrawCircle(b->position[i].x, b->position[i].y, b->size, WHITE);
            //DrawTexture(*texture, b->position[i].x, b->position[i].y, WHITE);
        }
    }
}

int CheckBulletCollision(const Bullet *b, Vector2 *entity_pos, float entity_radius)
{
    for (int i = 0; i < MAX_BULLET; i++) {
        if (b->active[i] && CheckCollisionCircles(*entity_pos, entity_radius, b->position[i], b->size)) {
            return 1;
        }
    }
    return 0;
}
