#include "../Include/QuickSetup.h"

G_MODULE_EXPORT void Wizard_released()												// Start the wizard
{
	gtk_progress_bar_set_text(PROGRESS, "Not implemented yet");
}

G_MODULE_EXPORT void Multimedia_released()											// Popup multimedia menu
{
	gtk_widget_show(Window_Multimedia);
	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_Tweaks);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Installers_released()											// Popup installers
{
	gtk_widget_show(Window_Installers);
	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_Tweaks);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Performance_released()											// Popup speed stuff
{
	gtk_widget_show(Window_Performance);
	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Tweaks);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Tweaks_released()												// Popup tweaks
{
	gtk_widget_show(Window_Tweaks);
	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Exit_released()												// Quit PSUbuntu
{
	EXIT = 1;
}
G_MODULE_EXPORT void Resolution_released()											// Popup videomode menu
{
	gtk_widget_show(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Borders_released()												// Popup fbset menu
{
	FbsetGet();
	gtk_widget_show(Window_Borders);
	gtk_widget_hide(Window_VideoMode);
}
G_MODULE_EXPORT void Goplayer_released()											// Install GoPlayer
{
	RunScript("scripts/Multimedia/goplayer/goplayer-install");
}
G_MODULE_EXPORT void Mplayer_released()												// Install Mplayer
{
	gtk_progress_bar_set_text(PROGRESS, "Not implemented yet");
}
G_MODULE_EXPORT void Youtube_released()												// Install greasemonkey
{
	RunScript("scripts/Multimedia/youtube-option");
}
G_MODULE_EXPORT void Asound_released()												// Fix asound
{
	RunScript("scripts/Multimedia/asound");
}
G_MODULE_EXPORT void Applications_released()										// Popup app menu
{
	MoveWindows();
	CreateMenu("scripts/Installers/AppList", 2);
}
G_MODULE_EXPORT void Tools_released()												// Popup tool menu
{
	MoveWindows();
	CreateMenu("scripts/Installers/ToolList", 1);
}
G_MODULE_EXPORT void Games_released()												// Popup game menu
{
	MoveWindows();
	CreateMenu("scripts/Installers/GameList", 0);
}
G_MODULE_EXPORT void Vram_released()												// Enable vram as swap
{
	RunScript("scripts/Performance/set-vram");
}
G_MODULE_EXPORT void ShadowFB_released()											// Disable ShadowFb
{
	RunScript("scripts/Performance/xorg-change shadowfb");
}
G_MODULE_EXPORT void Services_released()											// Disable services
{
	RunScript("scripts/Performance/disable-services");
}
G_MODULE_EXPORT void XMB_released()													// Install OSXMB
{
	RunScript("scripts/Tweaks/osxmb-install");
}
G_MODULE_EXPORT void Wacom_released()												// Enable wacom tablet
{
	gtk_progress_bar_set_text(PROGRESS, "Not implemented yet");
	//RunScript("scripts/Tweaks/xorg-change wacom");
}
G_MODULE_EXPORT void VideoOk_released()												// Change video mode				
{
	ResetBar();
	MoveWindows();
	gtk_widget_hide(Window_VideoMode);
	KbootRun();
}
G_MODULE_EXPORT void FbsetOk_released()												// Change fbset resolution
{
	int x, y;
	int FbX = gtk_adjustment_get_value(FBSETX);
	int FbY = gtk_adjustment_get_value(FBSETY);
	char RunString[28];
	sprintf(RunString, "scripts/Tweaks/fbset-set %d %d", FbX, FbY);
	RunScript(RunString);
	gtk_window_fullscreen(GTK_WINDOW(Window_QuickSetup));
	gtk_window_unfullscreen(GTK_WINDOW(Window_QuickSetup));
}



