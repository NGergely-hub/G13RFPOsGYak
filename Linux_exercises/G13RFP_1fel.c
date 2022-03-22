#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include	<stdlib.h>

int
main(void)
{
	int		status;

	if ( (status = system("tree")) < 0)
		perror("system() error");
	pr_exit(status); 	/* v�rhat�an 0 */

	if ( (status = system("nosuchcommand")) < 0)
		perror("system() error");
	pr_exit(status);	/* v�rhat�an nem 0 */

	if ( (status = system("who; exit 44")) < 0)
		perror("system() error");
	pr_exit(status);	/* status = 44 */

	exit(0);
}

void
pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("Norm�lis befejez�d�s, visszaadott �rt�k = %d\n",
				WEXITSTATUS(status));
	else 
	if (WIFSIGNALED(status))
		printf("Abnorm�lis befejez�s, a szign�l sorsz�m = %d\n",
				WTERMSIG(status));
}



