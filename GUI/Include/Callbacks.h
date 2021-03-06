#ifndef CALLBACKS
#define CALLBACKS
#include "../Include/QuickSetup.h"

////////////////////////
// MAIN MENU
////////////////////////
G_MODULE_EXPORT void Wizard_released();
G_MODULE_EXPORT void Multimedia_released();
G_MODULE_EXPORT void Installers_released();
G_MODULE_EXPORT void Performance_released();
G_MODULE_EXPORT void Tweaks_released();
////////////////////////
// Multimedia
////////////////////////
G_MODULE_EXPORT void Goplayer_released();
G_MODULE_EXPORT void Mplayer_released();
G_MODULE_EXPORT void Youtube_released();
G_MODULE_EXPORT void Asound_released();
////////////////////////
// Installers
////////////////////////
G_MODULE_EXPORT void Applications_released();
G_MODULE_EXPORT void Tools_released();
G_MODULE_EXPORT void Games_released();
////////////////////////
// Performance
////////////////////////
G_MODULE_EXPORT void Vram_released();
G_MODULE_EXPORT void ShadowFB_released();
G_MODULE_EXPORT void Services_released();
////////////////////////
// Tweaks
////////////////////////
G_MODULE_EXPORT void Wacom_released();
G_MODULE_EXPORT void Resolution_released();
G_MODULE_EXPORT void Borders_released();
////////////////////////
// Resolution
////////////////////////
G_MODULE_EXPORT void r480i_released();
G_MODULE_EXPORT void r576p_released();
G_MODULE_EXPORT void r720p_released();
G_MODULE_EXPORT void r1080i_released();
G_MODULE_EXPORT void r1080p_released();
////////////////////////
// Borders
////////////////////////
G_MODULE_EXPORT void FbsetOk_released();

#endif
