#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int pid, status, child_pid;
	
	printf("Ben ust islemim ve numaram %d\n", getpid());
    pid = fork();

    if (pid == 0)
	{
		printf("Ben cocuk islemim, numaram %d, ust islem numaram %d.\n", getpid(), getppid());
        exit(42);
	}
	else  
	{
		printf("Ben ust islemim, numaram %d, ust islem numaram %d.\n", getpid(), getppid());

        child_pid = wait(&status);
		printf("Numarasi %d olan cocuk %d cikis kodu ile sonlandi.\n", child_pid, WEXITSTATUS(status));
	}

	printf("%d numarali islem sonlaniyor.\n", getpid()); 
	
	return 0;
}
