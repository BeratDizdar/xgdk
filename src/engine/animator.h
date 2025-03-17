#pragma once

#include "structs.h"

void CreateAnimation(Arena *arena, Animation **animation, Rectangle src, Rectangle dst, int frame_count);
void AddAnimationFrame(Animation** animation, int index, const char* png_path);
void DrawAnimation(Animation* animation);
// yapılacaklar var ama sonra ;)