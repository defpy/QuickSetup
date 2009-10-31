#ifndef QUICKSETUP
#define QUICKSETUP

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include "Callbacks.h"

#define BUTTON_1 GTK_BUTTON(gtk_builder_get_object(builder, "Button_1"))
#define BUTTON_2 GTK_BUTTON(gtk_builder_get_object(builder, "Button_2"))
#define BUTTON_3 GTK_BUTTON(gtk_builder_get_object(builder, "Button_3"))
#define BUTTON_4 GTK_BUTTON(gtk_builder_get_object(builder, "Button_4"))
#define BUTTON_5 GTK_BUTTON(gtk_builder_get_object(builder, "Button_5"))
#define BUTTON_6 GTK_BUTTON(gtk_builder_get_object(builder, "Button_6"))

#define IMAGE_1 GTK_IMAGE(gtk_builder_get_object(builder, "Image_1"))
#define IMAGE_2 GTK_IMAGE(gtk_builder_get_object(builder, "Image_2"))
#define IMAGE_3 GTK_IMAGE(gtk_builder_get_object(builder, "Image_3"))
#define IMAGE_4 GTK_IMAGE(gtk_builder_get_object(builder, "Image_4"))
#define IMAGE_5 GTK_IMAGE(gtk_builder_get_object(builder, "Image_5"))
#define IMAGE_6 GTK_IMAGE(gtk_builder_get_object(builder, "Image_6"))

#define PROGRESS GTK_PROGRESS_BAR(gtk_builder_get_object(builder, "ProgressBar"))

#define MAIN     1
#define SCREEN   2
#define VIDEO    3
#define GAMES    4
#define SPEED    5
#define FIXES	 6

extern GtkBuilder	*builder; 
extern GtkWidget	*Window_QuickSetup;
extern GtkWidget	*Window_Progress;
extern int STATE;

void QS_MainMenu();
void QS_ScreenMenu();
void QS_VideoMenu();
void QS_GamingMenu();
void QS_SpeedMenu();
void QS_FixesMenu();

void Fix_Asound();

#endif
