// QuickSetup GTK+ GUI
// Made by: Quipeace
// Sole purpose: launching scripts
// gcc -Wall -g -o ../../QuickSetup QuickSetup.c Callbacks.c `pkg-config --cflags --libs gtk+-2.0 gmodule-export-2.0`
// run from $HOME/QuickSetup using "start"

#include "../Include/QuickSetup.h"

GtkBuilder* builder;
GtkWidget*  Window_QuickSetup;
GtkWidget*  Window_Progress;
int STATE = MAIN;
int winX, winY;

int main (int argc, char *argv[])
{
	system("clear");

	gtk_init (&argc, &argv);
 
	builder = gtk_builder_new();
	if(gtk_builder_add_from_file(builder, "GUI/Graphics/QuickSetup.glade", NULL) == 0) 
	{
		system("clear");	
		printf("\n\nGUI XML not found!\nDid you run this script from \"/home/YOURNAME/QuickSetup\", using \"start\"?\n\n");
		return 1;
	}

	gtk_builder_connect_signals(builder, NULL);

	Window_QuickSetup = GTK_WIDGET(gtk_builder_get_object (builder, "QuickSetup"));
	Window_Progress = GTK_WIDGET(gtk_builder_get_object (builder, "Progress"));

	gtk_widget_show(Window_QuickSetup);   
	gtk_widget_show(Window_Progress);
	gtk_window_get_position(GTK_WINDOW(Window_QuickSetup), &winX, &winY);
	gtk_window_move(GTK_WINDOW(Window_Progress),winX, (winY+80));
  
	gtk_main ();
	return 0;
}

void QS_MainMenu()
{
	STATE = MAIN;
	gtk_button_set_label(BUTTON_1, "Screen");
	gtk_button_set_label(BUTTON_2, "Video");
	gtk_button_set_label(BUTTON_3, "Games");
	gtk_button_set_label(BUTTON_4, "Speed-up");
	gtk_button_set_label(BUTTON_5, "Fixes");
	gtk_image_set_from_icon_name(IMAGE_6, "window-close", 45); 
}
void QS_ScreenMenu()
{
	STATE = SCREEN;
	gtk_button_set_label(BUTTON_1, "[ ] VidMode");
	gtk_button_set_label(BUTTON_2, "[ ] Borders");
	gtk_button_set_label(BUTTON_3, "");
	gtk_button_set_label(BUTTON_4, "");
	gtk_button_set_label(BUTTON_5, ""); 
	gtk_image_set_from_icon_name(IMAGE_6, "go-previous", 45); 
}
void QS_VideoMenu()
{
	STATE = VIDEO;
	gtk_button_set_label(BUTTON_1, "[ ] mplayer-ps3");
	gtk_button_set_label(BUTTON_2, "[X] Asound");
	gtk_button_set_label(BUTTON_3, "[X] Youtube");
	gtk_button_set_label(BUTTON_4, "");
	gtk_button_set_label(BUTTON_5, "");
	gtk_image_set_from_icon_name(IMAGE_6, "go-previous", 45); 
}
void QS_GamingMenu()
{
	STATE = GAMES;
	gtk_button_set_label(BUTTON_1, "[X] Emus");
	gtk_button_set_label(BUTTON_2, "[X] scaler");
	gtk_button_set_label(BUTTON_3, "");
	gtk_button_set_label(BUTTON_4, "");
	gtk_button_set_label(BUTTON_5, "");
	gtk_image_set_from_icon_name(IMAGE_6, "go-previous", 45); 
}
void QS_SpeedMenu()
{
	STATE = SPEED;
	gtk_button_set_label(BUTTON_1, "[X] vram");
	gtk_button_set_label(BUTTON_2, "[X] services");
	gtk_button_set_label(BUTTON_3, "[X] shadowfb");
	gtk_button_set_label(BUTTON_4, "");
	gtk_button_set_label(BUTTON_5, "");
	gtk_image_set_from_icon_name(IMAGE_6, "go-previous", 45); 
}
void QS_FixesMenu()
{
	STATE = FIXES;
	gtk_button_set_label(BUTTON_1, "[ ] Sixaxis");
	gtk_button_set_label(BUTTON_2, "[ ] MediaB");
	gtk_button_set_label(BUTTON_3, "[ ] XMBLaunch");
	gtk_button_set_label(BUTTON_4, "[X] WacomTabl");
	gtk_button_set_label(BUTTON_5, "");
	gtk_image_set_from_icon_name(IMAGE_6, "go-previous", 45); 
}

void ShowProgress()
{
	GtkProgressBar* Progress = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, "ProgressBar"));

}
