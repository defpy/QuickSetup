// QuickSetup GTK+ GUI
// Made by: Quipeace
// Sole purpose: launching scripts
// run from $HOME/QuickSetup using "start"

#include "../Include/QuickSetup.h"

GtkBuilder* builder;
GtkWidget*  Window_QuickSetup;
GtkWidget*	Window_Multimedia;
GtkWidget*	Window_Installers;
GtkWidget*	Window_Performance;
GtkWidget*	Window_Tweaks;

gint WinX, WinY;

int main (int argc, char *argv[])
{
	system("clear");

	gtk_init (&argc, &argv);

	builder = gtk_builder_new();
	if(gtk_builder_add_from_file(builder, "GUI/Graphics/QuickSetup.glade", NULL) == 0) 
	{
		printf("\n\nGUI XML not found!\nDid you run this script from \"/home/YOURNAME/QuickSetup\", using \"start\"?\n\n");
		return 1;
	}

	SetupMenus();

	gtk_main ();

	system("rm .internet_check.log");
	return 0;
}

void SetupMenus()
{
	gtk_builder_connect_signals(builder, NULL);

	Window_QuickSetup  = GTK_WIDGET(gtk_builder_get_object (builder, "QuickSetup"));
	Window_Multimedia  = GTK_WIDGET(gtk_builder_get_object (builder, "Multimedia"));
	Window_Installers  = GTK_WIDGET(gtk_builder_get_object (builder, "Installers"));
	Window_Performance = GTK_WIDGET(gtk_builder_get_object (builder, "Performance"));
	Window_Tweaks      = GTK_WIDGET(gtk_builder_get_object (builder, "Tweaks"));

	gtk_widget_show(Window_QuickSetup);
	gtk_window_get_position(GTK_WINDOW(Window_QuickSetup), &WinX, &WinY);

	gtk_window_move(GTK_WINDOW(Window_Multimedia) , WinX+80 , WinY-240);
	gtk_window_move(GTK_WINDOW(Window_Installers) , WinX+160, WinY-240);
	gtk_window_move(GTK_WINDOW(Window_Performance), WinX+240, WinY-240);
	gtk_window_move(GTK_WINDOW(Window_Tweaks)     , WinX+320, WinY-240);
}

void ResetBar()
{
	gtk_progress_bar_set_fraction(PROGRESS, 0);
	gtk_progress_bar_set_text(PROGRESS, "QuickSetup");
}
