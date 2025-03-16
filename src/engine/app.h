#pragma once

#include "structs.h"

App CreateApp();
void CreateAppWindow(App* app);
int DestroyApp();
int AppRun(App* app, void (*init)(App*), void (*mainloop)(), void (*shutdown)());
int IsAppRunning(App* app);
// bütün özellikler için fonksiyon ekle
// daha sonra bunları if ile kontrol eden fonksiyon ekle ana döngü için
// void CheckAppSettings();
// app.Flags.changed ile kontrol etsin ve değiştirsin diğer fonksiyonlar
void ChangeAppSettings(App* app); // bunu static yap .c'de

void UpdateDeltaTime(App* app);