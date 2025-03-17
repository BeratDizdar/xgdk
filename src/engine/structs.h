#pragma once

#include <stdint.h>
#include <stdio.h>
#include "raylib.h"

#define WIDTH GetScreenWidth()
#define HEIGHT GetScreenWidth()

typedef const char* cstr_t;
typedef int         flag;

typedef struct App {
    struct Logic {
        float delta_time;
    } Logic;
    struct Flags {
        flag is_running;
        flag changed; // TODO Changed fonksiyonu yap.
        flag logs;
    } Flags;
    struct Window {
        int width, height;
        cstr_t title;
    } Window;
    struct Renderer {
        cstr_t ui_style;
    } Renderer;
} App;

typedef struct Arena {
    uint8_t *buffer;
    size_t offset;
    size_t size;
} Arena;

typedef struct Animation {
    Texture *texture;
    int current;
    Rectangle src;
    Rectangle dst;
    Vector2 origin;
    float rotation;
} Animation;


typedef struct {
    Vector2 position;
    float angle;
} Enemy;

#ifndef MAX_BULLET
    #define MAX_BULLET 10000
#endif

typedef struct {
    float size;
    Vector2 position[MAX_BULLET];
    Vector2 velocity[MAX_BULLET];
    bool active[MAX_BULLET];
    int active_count;
} Bullet;