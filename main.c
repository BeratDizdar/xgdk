//#include "src/macro_libs.h"

#include "src/engine/app.h"
#include "src/game/game.h"

int main(void) {
    
    App app = CreateApp();
    app.Flags.logs = LOG_NONE;
    app.Window.title = "Bullet Hell? Bellum?";
    app.Window.height = 720;
    app.Window.width = 1280;
    CreateAppWindow(&app);

    return AppRun(&app, GameInit, GameMainloop, GameShutdown);
}
