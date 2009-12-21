#include "../Include/QuickSetup.h"

G_MODULE_EXPORT void Wizard_released()												// Start the wizard
{
	gtk_progress_bar_set_text(PROGRESS, "Not implemented yet");
}

G_MODULE_EXPORT void Multimedia_released()											// Popup multimedia menu
{
	MoveWindows();
	gtk_widget_show(Window_Multimedia);

	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_Tweaks);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Installers_released()											// Popup installers
{
	MoveWindows();
	gtk_widget_show(Window_Installers);

	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_Tweaks);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Performance_released()											// Popup speed stuff
{
	MoveWindows();
	gtk_widget_show(Window_Performance);

	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Tweaks);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Tweaks_released()												// Popup tweaks
{
	MoveWindows();
	gtk_widget_show(Window_Tweaks);

	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Exit_released()												// Quit PSUbuntu
{
	gtk_main_quit();
}
G_MODULE_EXPORT void Goplayer_released()											// Install GoPlayer
{
	RunScript("scripts/goplayer/goplayer-install");
}
G_MODULE_EXPORT void Mplayer_released()												// Install Mplayer
{
	gtk_progress_bar_set_text(PROGRESS, "Not implemented yet");
}
G_MODULE_EXPORT void Youtube_released()												// Install greasemonkey
{
	RunScript("scripts/youtube-option");
}
G_MODULE_EXPORT void Asound_released()												// Fix asound
{
	RunScript("scripts/asound");
}
G_MODULE_EXPORT void Applications_released()										// Popup app menu
{
	MoveWindows();
	CreateMenu("scripts/.AppList");
}
G_MODULE_EXPORT void Tools_released()												// Popup tool menu
{
	MoveWindows();
	CreateMenu("scripts/.ToolList");
}
G_MODULE_EXPORT void Games_released()												// Popup game menu
{
	MoveWindows();
	CreateMenu("scripts/.GameList");
}
G_MODULE_EXPORT void Vram_released()												// Enable vram as swap
{
	RunScript("scripts/set-vram");
}
G_MODULE_EXPORT void ShadowFB_released()											// Disable ShadowFb
{
	RunScript("scripts/xorg-change shadowfb");
}
G_MODULE_EXPORT void Services_released()											// Disable services
{
	RunScript("scripts/disable-services");
}
G_MODULE_EXPORT void XMB_released()													// Install OSXMB
{
	RunScript("scripts/osxmb-install");
}
G_MODULE_EXPORT void Wacom_released()												// Enable wacom tablet
{
	gtk_progress_bar_set_text(PROGRESS, "Not implemented yet");
	//RunScript("scripts/xorg-change wacom");
}
G_MODULE_EXPORT void Resolution_released()											// Popup videomode menu
{
	MoveWindows();
	gtk_widget_show(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Borders_released()												// Popup fbset menu
{
	MoveWindows();
	FbsetGet();
	gtk_widget_show(Window_Borders);
	gtk_widget_hide(Window_VideoMode);
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
	sprintf(RunString, "scripts/fbset-set %d %d", FbX, FbY);
	RunScript(RunString);
	gtk_window_fullscreen(GTK_WINDOW(Window_QuickSetup));
	gtk_window_unfullscreen(GTK_WINDOW(Window_QuickSetup));
}



