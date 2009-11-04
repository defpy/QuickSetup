#include "../Include/QuickSetup.h"

G_MODULE_EXPORT void Wizard_released()
{
	ResetBar();
}

G_MODULE_EXPORT void Multimedia_released()
{
	ResetBar();
	if(!gtk_widget_get_visible(Window_Multimedia)) gtk_widget_show(Window_Multimedia);
	else gtk_widget_hide(Window_Multimedia);

	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_Tweaks);
}

G_MODULE_EXPORT void Installers_released()
{
	ResetBar();
	if(!gtk_widget_get_visible(Window_Installers)) gtk_widget_show(Window_Installers);
	else gtk_widget_hide(Window_Installers);

	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Performance);
	gtk_widget_hide(Window_Tweaks);
}


G_MODULE_EXPORT void Performance_released()
{
	ResetBar();
	if(!gtk_widget_get_visible(Window_Performance)) gtk_widget_show(Window_Performance);
	else gtk_widget_hide(Window_Performance);

	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Tweaks);
}


G_MODULE_EXPORT void Tweaks_released()
{
	ResetBar();
	if(!gtk_widget_get_visible(Window_Tweaks)) gtk_widget_show(Window_Tweaks);
	else gtk_widget_hide(Window_Tweaks);

	gtk_widget_hide(Window_Multimedia);
	gtk_widget_hide(Window_Installers);
	gtk_widget_hide(Window_Performance);
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
}
G_MODULE_EXPORT void Borders_released()
{
	ResetBar();
}

