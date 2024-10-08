#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <glad/glad.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include "engine/global.h"
#include "engine/config.h"
#include "engine/input.h"
#include "engine/time.h"
#include "engine/physics.h"
#include "engine/util.h"

static bool should_quit = false;

static void input_handle(Body *body_player)
{
    if (global.input.escape)
    {
        should_quit = true;
    }

    f32 velx = 0;
    f32 vely = body_player->velocity[1];

    if (global.input.right)
    {
        velx += 1000;
    }

    if (global.input.left)
    {
        velx -= 1000;
    }

    if (global.input.up)
    {
        vely = 4000;
    }

    if (global.input.down)
    {
        vely -= 800;
    }

    body_player->velocity[0] = velx;
    body_player->velocity[1] = vely;
}

int main(int argc, char *argv[])
{
    time_init(60);
    config_init();
    render_init();
    physics_init();

    SDL_ShowCursor(false);

    u32 body_id = physics_body_create((vec2){100, 400}, (vec2){50, 50});

    f32 width = global.render.width;
    f32 height = global.render.height;

    u32 static_body_a_id = physics_static_body_create((vec2){width * 0.5 - 25, height - 25}, (vec2){width - 50, 50});
    u32 static_body_b_id = physics_static_body_create((vec2){width - 25, height * 0.5 + 25}, (vec2){50, height - 50});
    u32 static_body_c_id = physics_static_body_create((vec2){width * 0.5 + 25, 25}, (vec2){width - 50, 50});
    u32 static_body_d_id = physics_static_body_create((vec2){25, height * 0.5 - 25}, (vec2){50, height - 50});
    u32 static_body_e_id = physics_static_body_create((vec2){width * 0.5, height * 0.5}, (vec2){150, 150});

    while (!should_quit)
    {
        time_update();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                should_quit = true;
                break;
            default:
                break;
            }
        }

        Body *body_player = physics_body_get(body_id);

        Static_Body *static_body_a = physics_static_body_get(static_body_a_id);
        Static_Body *static_body_b = physics_static_body_get(static_body_b_id);
        Static_Body *static_body_c = physics_static_body_get(static_body_c_id);
        Static_Body *static_body_d = physics_static_body_get(static_body_d_id);
        Static_Body *static_body_e = physics_static_body_get(static_body_e_id);

        input_update();
        input_handle(body_player);
        physics_update();

        render_begin();

        render_aabb((f32 *)static_body_a, WHITE);
        render_aabb((f32 *)static_body_b, WHITE);
        render_aabb((f32 *)static_body_c, WHITE);
        render_aabb((f32 *)static_body_d, WHITE);
        render_aabb((f32 *)static_body_e, WHITE);
        render_aabb((f32 *)body_player, CYAN);

        render_end();
        time_update_late();
    }
    return 0;
}