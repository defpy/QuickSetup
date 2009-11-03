#include "../Include/QuickSetup.h"

FILE*	STREAM;
char	STREAM_OUT[500];
char	ProgText;
char*	TempPt;
float	Percent;
float	TempP;
int 	i = 1;

void OpenStream(char Path[])
{
	STREAM = popen(Path, "r");
	if(!STREAM)
	{
		printf("Failed executing \"%s\".", Path);
		gtk_main_quit();
	}
}

int UpdateFromStream()
{
	fgets(STREAM_OUT, 500, STREAM);

	if(!strncmp(STREAM_OUT, "-", 1))
	{
		TempPt = strstr(STREAM_OUT, "\n");
		if(TempPt) *TempPt = NULL;
		gtk_progress_bar_set_text(PROGRESS, STREAM_OUT);
	}
	else if(strcmp(STREAM_OUT, "Success\n"))
	{
		usleep(300000);
		TempP = atoi(STREAM_OUT);
		TempP = TempP/100;
		Percent += TempP;
		if(Percent > 1) Percent = 1;
		gtk_progress_bar_set_fraction(PROGRESS, Percent);
		while (g_main_context_iteration(NULL, FALSE));
		return 1;
	}
	else if(strcmp(STREAM_OUT, "Failed\n"))	return 0;
	else if(strncmp(STREAM_OUT, "1234567890", 2)) printf("%s", STREAM_OUT);
	else 
	{
		gtk_progress_bar_set_fraction(PROGRESS, 0);	
		return -1;
	}
}

void RunScript(char Path[50])
{
	OpenStream(Path);

	system("clear");

	while(i == 1) i = UpdateFromStream();
	
	while (g_main_context_iteration(NULL, FALSE));

	Percent = 0;
	TempP	= 0;
	i		= 1;
}
