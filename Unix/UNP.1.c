#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
	pid_t cpid;
	if (argc == 3)
	{

		cpid = fork();
		if (cpid == -1) //Creat Error
		{
			exit(0);
		}
		else if (cpid == 0) //Creat Child
		{
			char *execv_str[] = {"echo", "executed by execv", NULL};
			if (execv("/usr/bin/echo", execv_str) < 0)
			{
				perror("error on exec");
				exit(0);
			}

			/*
				if (execv("/usr/bin/cat", argv) < 0)
				{
					perror("Error");
				}
				printf("Child done");
				exit(0);
				*/
		}
		else //Creat Father
		{
			wait(&cpid);
			printf("father done");
		}
	}
	else
	{
		exit(0);
	}
}
