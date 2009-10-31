#include "../Include/QuickSetup.h"

G_MODULE_EXPORT void on_Button_1_pressed(GtkObject *object, gpointer user_data)
{
	gtk_progress_bar_set_fraction(PROGRESS, 0);
	gtk_progress_bar_set_text(PROGRESS, "QuickSetup");
	switch (STATE)
	{
		case MAIN: 
			QS_ScreenMenu();
			break;
		case SCREEN:
			break;
		case VIDEO:
			break;
		case GAMES:
			break;
		case SPEED:
			RunScript("scripts/set-vram", "Successfully enabled vram.", "Failed enabling vram.");
			break;
		case FIXES:
			break;
		default:
			printf("ERROR: Unknown application state.\n");
			gtk_main_quit();
	}
}
G_MODULE_EXPORT void on_Button_2_pressed(GtkObject *object, gpointer user_data)
{
	gtk_progress_bar_set_fraction(PROGRESS, 0);
	gtk_progress_bar_set_text(PROGRESS, "QuickSetup");
	switch (STATE)
	{
		case MAIN: 
			QS_VideoMenu();
			break;
		case SCREEN:
			break;
		case VIDEO:
			RunScript("scripts/asound", "Successfully set asound.conf.", "Setting asound.conf failed.");
			break;
		case GAMES:
			break;
		case SPEED:
			RunScript("scripts/disable-services", "Successfully disabled services.", "Failed disabling services.");
			break;
		case FIXES:
		default:
			printf("ERROR: Unknown application state.\n");
			gtk_main_quit();
	}
}
G_MODULE_EXPORT void on_Button_3_pressed(GtkObject *object, gpointer user_data)
{
	gtk_progress_bar_set_fraction(PROGRESS, 0);
	gtk_progress_bar_set_text(PROGRESS, "QuickSetup");
	switch (STATE)
	{
		case MAIN:
			QS_GamingMenu();
			break; 
		case SCREEN:
			break;
		case VIDEO:
			system("sudo scripts/youtube-option");			
			break;
		case GAMES:
			break;
		case SPEED:
			RunScript("scripts/xorg-change shadowfb", "Succesfully set ShadowFB to False.", "Disabling ShadowFB failed.");
			break;
		case FIXES:
		default:
			printf("ERROR: Unknown application state.\n");
			gtk_main_quit();
	}
}
G_MODULE_EXPORT void on_Button_4_pressed(GtkObject *object, gpointer user_data)
{
	gtk_progress_bar_set_fraction(PROGRESS, 0);
	gtk_progress_bar_set_text(PROGRESS, "QuickSetup");
	switch (STATE)
	{
		case MAIN:
			QS_SpeedMenu();
			break; 
		case SCREEN:
			break;
		case VIDEO:
			break;
		case GAMES:
			break;
		case SPEED:
			break;
		case FIXES:
			RunScript("scripts/xorg-change wacom", "Successfully enabled the Wacom tablet.", "Failed executing Wacom fix.");
			break;
		default:
			printf("ERROR: Unknown application state.\n");
			gtk_main_quit();
	}
}
G_MODULE_EXPORT void on_Button_5_pressed(GtkObject *object, gpointer user_data)
{
	gtk_progress_bar_set_fraction(PROGRESS, 0);
	gtk_progress_bar_set_text(PROGRESS, "QuickSetup");
	switch (STATE)
	{
		case MAIN:
			QS_FixesMenu();
			break; 
		case SCREEN:
			break;
		case VIDEO:
			break;
		case GAMES:
			break;
		case FIXES:
		default:
			printf("ERROR: Unknown application state.\n");
			gtk_main_quit();
	}
}
G_MODULE_EXPORT void on_Button_6_pressed(GtkObject *object, gpointer user_data)
{
	gtk_progress_bar_set_fraction(PROGRESS, 0);
	gtk_progress_bar_set_text(PROGRESS, "QuickSetup");
	switch (STATE)
	{
		case MAIN:
			gtk_main_quit();
			break;
		case SCREEN:
			QS_MainMenu();
			break;
		case VIDEO:
			QS_MainMenu();
			break;
		case GAMES:
			QS_MainMenu();
			break;
		case SPEED:
			QS_MainMenu();
			break;
		case FIXES:
			QS_MainMenu();
			break;
		default:
			printf("ERROR: Unknown application state.\n");
			gtk_main_quit();
	}
}

