#ifndef QUICKSETUP
#define QUICKSETUP

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include "Callbacks.h"

#define PROGRESS GTK_PROGRESS_BAR(gtk_builder_get_object(builder, "ProgressBar"))
#define FBSETX GTK_ADJUSTMENT(gtk_builder_get_object(builder, "FbsetX"))
#define FBSETY GTK_ADJUSTMENT(gtk_builder_get_object(builder, "FbsetY"))
#define COMBOBOX GTK_COMBO_BOX(gtk_builder_get_object(builder, "ComboBox"))
#define TOGGLEBUTTON GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "CheckFullscreen"))

extern GtkBuilder*	builder; 
extern GtkWidget*	Window_QuickSetup;
extern GtkWidget*	Window_Multimedia;
extern GtkWidget*	Window_Installers;
extern GtkWidget*	Window_Performance;
extern GtkWidget*	Window_Tweaks;
extern GtkWidget*	Window_VideoMode;
extern GtkWidget*  Window_Borders;

extern int MainLoop;

void OpenStream(char Path[]);
int  UpdateFromStream();
void RunScript();

void SetupMenus();
void MoveWindows();
void ResetBar();

#endif
