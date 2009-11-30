#include "../Include/QuickSetup.h"

G_MODULE_EXPORT void Wizard_released()
{
	ResetBar();
	MoveWindows();
}

G_MODULE_EXPORT void Multimedia_released()
{
	ResetBar();
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
	ResetBar();
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
	ResetBar();
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
	ResetBar();
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
	system("scripts/cleanup");
	gtk_main_quit();
}

G_MODULE_EXPORT void Goplayer_released()
{
	ResetBar();
	MoveWindows();
	RunScript("scripts/goplayer/goplayer-install");
}
G_MODULE_EXPORT void Mplayer_released()
{
	ResetBar();
	MoveWindows();
}
G_MODULE_EXPORT void Youtube_released()
{
	ResetBar();
	MoveWindows();
	RunScript("scripts/youtube-option");
}
G_MODULE_EXPORT void Asound_released()
{
	ResetBar();
	MoveWindows();
	RunScript("scripts/asound");
}


G_MODULE_EXPORT void Applications_released()
{
	ResetBar();
	MoveWindows();
}
G_MODULE_EXPORT void Tools_released()
{
	ResetBar();
	MoveWindows();
}
G_MODULE_EXPORT void Games_released()
{
	ResetBar();
	MoveWindows();
}


G_MODULE_EXPORT void Vram_released()
{
	ResetBar();
	MoveWindows();
	RunScript("scripts/set-vram");
}
G_MODULE_EXPORT void ShadowFB_released()
{
	ResetBar();
	MoveWindows();
	RunScript("scripts/xorg-change shadowfb");
}
G_MODULE_EXPORT void Services_released()
{
	ResetBar();
	MoveWindows();
	RunScript("scripts/disable-services");
}

G_MODULE_EXPORT void XMB_released()
{
	ResetBar();
	MoveWindows();
	RunScript("scripts/osxmb-install");
}
G_MODULE_EXPORT void Wacom_released()
{
	ResetBar();
	MoveWindows();
	RunScript("scripts/xorg-change wacom");
}
G_MODULE_EXPORT void Resolution_released()
{
	ResetBar();
	MoveWindows();
	gtk_widget_show(Window_VideoMode);
	gtk_widget_hide(Window_Borders);
}

G_MODULE_EXPORT void Borders_released()
{
	ResetBar();
	MoveWindows();
	char STREAM_OUT[15];
	char temp[5];
	int x, y, i;
	
	FILE* STREAM = popen("scripts/fbset-set read", "r");
	if(!STREAM) printf("Could not execute scripts/fbset read.\n");
	else fgets(STREAM_OUT, 20, STREAM);

	i = strcspn (STREAM_OUT,"x");
	memcpy (temp,STREAM_OUT+1,i);
	x = atoi(temp);
	memcpy (temp,STREAM_OUT+(i+1),strcspn (STREAM_OUT,"-"));
	y = atoi(temp);

	gtk_adjustment_set_value(FBSETX, x);
	gtk_adjustment_set_value(FBSETY, y);
	gtk_widget_show(Window_Borders);
	gtk_widget_hide(Window_VideoMode);
}

G_MODULE_EXPORT void VideoOk_released()
{
	ResetBar();
	MoveWindows();
	char* Mode = gtk_combo_box_get_active_text(COMBOBOX);
	gtk_widget_hide(Window_VideoMode);
	if(gtk_toggle_button_get_active(TOGGLEBUTTON))
	{	
		if(!strcmp(Mode, "480i")) 	RunScript("scripts/kboot-ed f480i");
		if(!strcmp(Mode, "576p")) 	RunScript("scripts/kboot-ed f576p");
		if(!strcmp(Mode, "720p")) 	RunScript("scripts/kboot-ed f720p");
		if(!strcmp(Mode, "1080i"))	RunScript("scripts/kboot-ed f1080i");
		if(!strcmp(Mode, "1080p")) 	RunScript("scripts/kboot-ed f1080p");
	}	
	else
	{	
		if(!strcmp(Mode, "480i")) 	RunScript("scripts/kboot-ed 480i");
		if(!strcmp(Mode, "576p")) 	RunScript("scripts/kboot-ed 576p");
		if(!strcmp(Mode, "720p")) 	RunScript("scripts/kboot-ed 720p");
		if(!strcmp(Mode, "1080i"))	RunScript("scripts/kboot-ed 1080i");
		if(!strcmp(Mode, "1080p")) 	RunScript("scripts/kboot-ed 1080p");
	}	
}

G_MODULE_EXPORT void FbsetOk_released()
{
	int FbX = gtk_adjustment_get_value(FBSETX);
	int FbY = gtk_adjustment_get_value(FBSETY);
	char RunString[28];

	sprintf(RunString, "scripts/fbset-set %d %d", FbX, FbY);
	RunScript(RunString);
}

