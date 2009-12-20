#include "../Include/QuickSetup.h"

G_MODULE_EXPORT void Wizard_released()
{
	gtk_progress_bar_set_text(PROGRESS, "Not implemented yet");
}

G_MODULE_EXPORT void Multimedia_released()
{
	MoveWindows();
	gtk_widget_show(Window_Multimedia);

	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_Tweaks);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Installers_released()
{
	MoveWindows();
	gtk_widget_show(Window_Installers);

	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_Tweaks);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Performance_released()
{
	MoveWindows();
	gtk_widget_show(Window_Performance);

	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Tweaks);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Tweaks_released()
{
	MoveWindows();
	gtk_widget_show(Window_Tweaks);

	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Exit_released()
{
	gtk_main_quit();
}
G_MODULE_EXPORT void Goplayer_released()
{
	RunScript("scripts/goplayer/goplayer-install");
}
G_MODULE_EXPORT void Mplayer_released()
{
	gtk_progress_bar_set_text(PROGRESS, "Not implemented yet");
}
G_MODULE_EXPORT void Youtube_released()
{
	RunScript("scripts/youtube-option");
}
G_MODULE_EXPORT void Asound_released()
{
	RunScript("scripts/asound");
}
G_MODULE_EXPORT void Applications_released()
{
	MoveWindows();
	CreateMenu("scripts/.AppList");
}
G_MODULE_EXPORT void Tools_released()
{
	MoveWindows();
	CreateMenu("scripts/.ToolList");
}
G_MODULE_EXPORT void Games_released()
{
	MoveWindows();
	CreateMenu("scripts/.GameList");
}
G_MODULE_EXPORT void Vram_released()
{
	RunScript("scripts/set-vram");
}
G_MODULE_EXPORT void ShadowFB_released()
{
	RunScript("scripts/xorg-change shadowfb");
}
G_MODULE_EXPORT void Services_released()
{
	RunScript("scripts/disable-services");
}
G_MODULE_EXPORT void XMB_released()
{
	RunScript("scripts/osxmb-install");
}
G_MODULE_EXPORT void Wacom_released()
{
	gtk_progress_bar_set_text(PROGRESS, "Not implemented yet");
	//RunScript("scripts/xorg-change wacom");
}
G_MODULE_EXPORT void Resolution_released()
{
	MoveWindows();
	gtk_widget_show(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Borders_released()
{
	MoveWindows();
	FbsetGet();
	gtk_widget_show(Window_Borders);
	gtk_widget_hide(Window_VideoMode);
}

G_MODULE_EXPORT void VideoOk_released()
{
	ResetBar();
	MoveWindows();
	gtk_widget_hide(Window_VideoMode);
	KbootRun();
}
G_MODULE_EXPORT void FbsetOk_released()
{
	int FbX = gtk_adjustment_get_value(FBSETX);
	int FbY = gtk_adjustment_get_value(FBSETY);
	char RunString[28];
	sprintf(RunString, "scripts/fbset-set %d %d", FbX, FbY);
	RunScript(RunString);
}

