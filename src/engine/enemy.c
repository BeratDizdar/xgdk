#include "enemy.h"

Enemy CreateEnemy(float posx, float posy, float angle)
{
    Enemy new_enemy;
    new_enemy.angle = angle;
    new_enemy.position = (Vector2){posx, posy};
    return new_enemy;
}
