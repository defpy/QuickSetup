#include "../Include/QuickSetup.h"

FILE*	STREAM;
char	STREAM_OUT[500];
char	ProgText;
float	Percent;
float	TempP;
int 	i = 1;

void OpenStream(char Path[])																	// Open a stream to read from
{
	STREAM = popen(Path, "r");
	if(!STREAM)
	{
		printf("Failed executing \"%s\".\n", Path);
		gtk_main_quit();
	}
}

int UpdateFromStream()																			// This will check for input from script	
{
	fgets(STREAM_OUT, 500, STREAM);

	if(!strncmp(STREAM_OUT, "-", 1))															// starts with a '-', so change the progress bar text
	{
		memset(strstr(STREAM_OUT, "\n"), 0, 2);
		gtk_progress_bar_set_text(PROGRESS, STREAM_OUT);
		return 1;
	}
	else if(!strncmp(STREAM_OUT, "#", 1))														// starts with a '#', so print to terminal
	{
		printf("%s\n", STREAM_OUT);
		return 1;
	}
	else if(!strcmp(STREAM_OUT, "Success\n") || !strcmp(STREAM_OUT, "Failed\n")) return 0;		// either Succes or Failed, indicate script ended
	else																						// else update the progress bar percentage
	{
		usleep(300000);
		TempP = atoi(STREAM_OUT);
		TempP = TempP/100;
		Percent += TempP;
		if(Percent > 1) Percent = 1;
		gtk_progress_bar_set_fraction(PROGRESS, Percent);
		while(gtk_events_pending()) gtk_main_iteration();
		return 1;
	}
}	

void RunScript(char Path[50])																	// Easily run a script with the above functions
{
	MoveWindows();
	ResetBar();

	OpenStream(Path);
	system("clear");

	while(i == 1) i = UpdateFromStream();
	while(gtk_events_pending()) gtk_main_iteration();

	Percent = 0;
	TempP	= 0;
	i		= 1;
}

void FbsetGet()																// Grab X and Y values from "fbset-set read" and output them to the entryboxes
{
	char STREAM_X[5];
	char STREAM_Y[5];
	int i;
	
	FILE* STREAM = popen("scripts/Tweaks/fbset-set read", "r");
	if(!STREAM) printf("Could not execute scripts/fbset read.\n");
	
	fgets(STREAM_X, 5, STREAM);
	fgets(STREAM_Y, 5, STREAM);
	
	gtk_adjustment_set_value(FBSETX, atoi(STREAM_Y));
	gtk_adjustment_set_value(FBSETY, atoi(STREAM_X));
}

void KbootRun()																// Grab values from the togglebox and combobox and run kboot-ed
{
	char* Mode = gtk_combo_box_get_active_text(COMBOBOX);
	if(gtk_toggle_button_get_active(TOGGLEBUTTON))
	{	
		if(!strcmp(Mode, "480i")) 	RunScript("scripts/Tweaks/kboot-ed f480i");
		if(!strcmp(Mode, "576p")) 	RunScript("scripts/Tweaks/kboot-ed f576p");
		if(!strcmp(Mode, "720p")) 	RunScript("scripts/Tweaks/kboot-ed f720p");
		if(!strcmp(Mode, "1080i"))	RunScript("scripts/Tweaks/kboot-ed f1080i");
		if(!strcmp(Mode, "1080p")) 	RunScript("scripts/Tweaks/kboot-ed f1080p");
	}	
	else
	{	
		if(!strcmp(Mode, "480i")) 	RunScript("scripts/Tweaks/kboot-ed 480i");
		if(!strcmp(Mode, "576p")) 	RunScript("scripts/Tweaks/kboot-ed 576p");
		if(!strcmp(Mode, "720p")) 	RunScript("scripts/Tweaks/kboot-ed 720p");
		if(!strcmp(Mode, "1080i"))	RunScript("scripts/Tweaks/kboot-ed 1080i");
		if(!strcmp(Mode, "1080p")) 	RunScript("scripts/Tweaks/kboot-ed 1080p");
	}
}

void CreateMenu(char ListPath[20], int TabNumber)    // Universal menu creator that grabs values from a file.
{
	char LISTOUT[100];	
	int i, j;
	GtkWidget* MenuItem[10];
	GtkWidget* Menu = gtk_menu_new();
	
	FILE* LISTSTREAM = fopen(ListPath, "r");
	fgets(LISTOUT, 100, LISTSTREAM);

	for(i = atoi(LISTOUT); i>0; i--)
	{	
		fgets(LISTOUT, 100, LISTSTREAM);
		memset(strstr(LISTOUT, "\n"), 0, 2);
		MenuItem[j] = gtk_check_menu_item_new_with_label(LISTOUT);
		gtk_menu_shell_append(GTK_MENU_SHELL(Menu), MenuItem[j]);
		gtk_widget_show(MenuItem[j]);
		j++;
	}
	
	gtk_menu_popup (GTK_MENU(Menu), NULL, NULL, NULL, NULL, 1, gtk_get_current_event_time());
}





