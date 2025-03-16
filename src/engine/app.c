#include "app.h"
#include "raylib.h"


App CreateApp()
{
    App new;
    new.Logic.delta_time = 0.0f;

    new.Flags.is_running = 1;
    new.Flags.changed = 0;
    new.Flags.logs = LOG_ALL;

    new.Renderer.ui_style = "";

    new.Window.title = "Bellum?";
    new.Window.width = 800;
    new.Window.height = 600;
    return new;
}

void CreateAppWindow(App* app)
{
    SetTraceLogLevel(app->Flags.logs);
    InitWindow(app->Window.width, app->Window.height, app->Window.title);
    InitAudioDevice();
    SetTargetFPS(60);
}

int DestroyApp()
{
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

int AppRun(App* app, void (*init)(App*), void (*mainloop)(), void (*shutdown)())
{
    init(app);
    while(IsAppRunning(app))
    {
        mainloop();
    }
    shutdown();

    return DestroyApp();
}

int IsAppRunning(App* app)
{
    return !WindowShouldClose() && app->Flags.is_running;  
}