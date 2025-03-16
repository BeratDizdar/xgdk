#pragma once

#include "structs.h"

Arena CreateArena(size_t byte_size);
void *ArenaAlloc(Arena *arena, size_t size);
void ArenaReset(Arena *arena);
void ArenaDestroy(Arena *arena);
void ArenaDebug(cstr_t name, Arena *arena);