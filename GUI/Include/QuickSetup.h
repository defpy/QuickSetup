#ifndef QUICKSETUP
#define QUICKSETUP

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include "Callbacks.h"

#define PROGRESS GTK_PROGRESS_BAR(gtk_builder_get_object(builder, "ProgressBar"))

extern GtkBuilder*	builder; 
extern GtkWidget*	Window_QuickSetup;
extern GtkWidget*	Window_Multimedia;
extern GtkWidget*	Window_Installers;
extern GtkWidget*	Window_Performance;
extern GtkWidget*	Window_Tweaks;

void OpenStream(char Path[]);
int  UpdateFromStream();
void RunScript();

void SetupMenus();
void ResetBar();

#endif
