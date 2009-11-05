#include "../Include/QuickSetup.h"

G_MODULE_EXPORT void Wizard_released()
{
	ResetBar();
}

G_MODULE_EXPORT void Multimedia_released()
{
	ResetBar();
	gtk_widget_show(Window_Multimedia);

	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_Tweaks);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}

G_MODULE_EXPORT void Installers_released()
{
	ResetBar();
	gtk_widget_show(Window_Installers);

	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_Tweaks);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}


G_MODULE_EXPORT void Performance_released()
{
	ResetBar();
	gtk_widget_show(Window_Performance);

	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Tweaks);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}


G_MODULE_EXPORT void Tweaks_released()
{
	ResetBar();
	gtk_widget_show(Window_Tweaks);

	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}


G_MODULE_EXPORT void Goplayer_released()
{
	ResetBar();
	RunScript("scripts/goplayer/goplayer-install");
}
G_MODULE_EXPORT void Mplayer_released()
{
	ResetBar();
}
G_MODULE_EXPORT void Youtube_released()
{
	ResetBar();
	RunScript("scripts/youtube-option");
}
G_MODULE_EXPORT void Asound_released()
{
	ResetBar();
	RunScript("scripts/asound");
}


G_MODULE_EXPORT void Applications_released()
{
	ResetBar();
}
G_MODULE_EXPORT void Tools_released()
{
	ResetBar();
}
G_MODULE_EXPORT void Games_released()
{
	ResetBar();
}


G_MODULE_EXPORT void Vram_released()
{
	ResetBar();
	RunScript("scripts/asound");
}
G_MODULE_EXPORT void ShadowFB_released()
{
	ResetBar();
	RunScript("scripts/xorg-change shadowfb");
}
G_MODULE_EXPORT void Services_released()
{
	ResetBar();
	RunScript("scripts/disable-services");
}


G_MODULE_EXPORT void Wacom_released()
{
	ResetBar();
	RunScript("scripts/xorg-change wacom");
}
G_MODULE_EXPORT void Resolution_released()
{
	ResetBar();
	gtk_widget_show(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}
G_MODULE_EXPORT void Borders_released()
{
	ResetBar();
	gtk_widget_show(Window_Borders);
	gtk_widget_hide(Window_VideoMode);
}


G_MODULE_EXPORT void r480i_released()
{
	ResetBar();
	gtk_widget_hide(Window_VideoMode);
	RunScript("scripts/kboot-ed 480i");
}
G_MODULE_EXPORT void r576p_released()
{
	gtk_widget_hide(Window_VideoMode);
	RunScript("scripts/kboot-ed 576p");
}
G_MODULE_EXPORT void r720p_released()
{
	gtk_widget_hide(Window_VideoMode);
	RunScript("scripts/kboot-ed 720p");
}
G_MODULE_EXPORT void r1080i_released()
{
	gtk_widget_hide(Window_VideoMode);
	RunScript("scripts/kboot-ed 1080i");
}
G_MODULE_EXPORT void r1080p_released()
{
	gtk_widget_hide(Window_VideoMode);
	RunScript("scripts/kboot-ed 1080p");
}

G_MODULE_EXPORT void FbsetOk_released()
{
	int FbX = gtk_adjustment_get_value(FBSETX);
	int FbY = gtk_adjustment_get_value(FBSETY);
	char RunString[50];
	char Buffer[50];

	sprintf(Buffer, "%d %d", FbX, FbY);
	strcat(RunString, "scripts/fbset ");
	strcat(RunString, Buffer);
	RunScript(RunString);
}

