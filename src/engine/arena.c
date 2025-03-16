#include "arena.h"
#include <stdio.h>
#include <stdlib.h>

Arena CreateArena(size_t byte_size)
{
    Arena new;
    new.buffer = (uint8_t *)malloc(byte_size);
    new.size = byte_size;
    new.offset = 0;
    return new;
}

void *ArenaAlloc(Arena *arena, size_t size)
{
    if (arena->offset + size > arena->size) {
        return NULL;
    }
    void *ptr = arena->buffer + arena->offset;
    arena->offset += size;
    return ptr;
}

void ArenaReset(Arena *arena)
{
    arena->offset = 0;
}

void ArenaDestroy(Arena *arena)
{
    free(arena->buffer);
}

void ArenaDebug(cstr_t name, Arena *arena)
{
    printf("Arena \"%s\" usage: %zu / %zu bytes (%.2f%% used)\n",
        name,
        arena->offset, arena->size,
        (arena->offset / (double)arena->size) * 100);
}
