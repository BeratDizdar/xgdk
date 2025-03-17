#include "animator.h"
#include "arena.h"

// aynı şekilde

void CreateAnimation(Arena *arena, Animation **animation, Rectangle src, Rectangle dst, int frame_count)
{
    *animation = ArenaAlloc(arena, sizeof(Animation));
    if (!*animation) {
        printf("Hata: Animation için bellek ayrılamadı!\n");
        return;
    }
    (*animation)->texture = ArenaAlloc(arena, sizeof(Texture) * frame_count);
    if (!(*animation)->texture) {
        printf("Hata: animation->texture için bellek ayrılamadı!\n");
        return;
    }
    (*animation)->current = 0;
    (*animation)->src = src;
    (*animation)->dst = dst;
    (*animation)->origin = (Vector2){0, 0};
    (*animation)->rotation = 0.0f;
}

void AddAnimationFrame(Animation **animation, int index, const char *png_path)
{
    (*animation)->texture[index] = LoadTexture(png_path);
}

void DrawAnimation(Animation *a)
{
    DrawTexturePro(a->texture[a->current],
        a->src,
        a->dst,
        a->origin,
        a->rotation,
        WHITE
    );
}
