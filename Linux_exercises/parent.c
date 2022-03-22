/************************************************************
 * Project: Szoftverrendszerek, process keszites
 * File name: $HOME/cs/parent.c
 * Abstract: Ez a  program elindit egy gyermek processzt, ami 
 *           kulonbozik az indito szulo processztol. 
 *           A szulo megvarja a gyermek process lefutasat.
 *           A gyermek processz egyeduli funkcioja: 10-szer
 *           kiir egy szoveget a standard outputra.
 * Usage:    cc -o parent parent.c -lc_s
 *	     cc -o child child.c -lc_s
 *	     parent
 * Athor: Dr. Vadasz Denes
 * Internals: fork();
 	      execl(path, arg0, arg1,...,(char *)0); 	       
 * Bugs, problems: none
 * History: 
 *   Created: 1992. jun. 8
 *   Modified:
*************************************************************/

#include <stdio.h>
#include <fcntl.h>

main (/*int argc, char *argv[],char *env[]*/)
{
	int status, pid, ppid, gpid;
	
	ppid = getpid();        /* Szulo pid-jet elkaptuk */

	if ((pid = fork()) == 0)   
	{ 	/* innen a gyermek processz */
		//printf("\n A gyermek pid = %d \n", getpid());
		status = execl("/home/g13rfp/child",0);
		if (status == -1)
		{	perror("parent execl failed");
			exit (0);
		}
	}

	/* innen a szulo process */
	
	/*printf("\n %d.sz. szulo var a %d.sz. gyermekre.\n ", ppid,pid);
	if (pid != wait(&status)) perror(" Szulo - varakozas hiba ");*/
}
