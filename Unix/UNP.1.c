#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
	pid_t cpid;
	char *temp[1];
	int flag = 0;
	if (argc == 3)
	{
		if (strcmp(argv[1], "cat") == 0)
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
		if (flag == 0)
		{
			cpid = fork();
			if (cpid == -1) //Creat Error
			{
				exit(0);
			}
			else if (cpid == 0) //Creat Child
			{

				execvp("cat", argv);

				/*
				char *execv_str[] = {"echo", "executed by execv", NULL};
				if (execv("/usr/bin/echo", execv_str) < 0)
				{
					perror("error on exec");
					printf("Child done\n");
					exit(0);
				}
				
				memset(temp, '\0', sizeof(temp));
				if (execvp("cat", temp) < 0)
				{
					perror("Error");
					printf("Child done\n");
					exit(0);
				}
				*/
			}
			else //Creat Father
			{
				wait(&cpid);
				printf("Father done\n");
			}
		}
		else
		{
			exit(0);
		}
	}
	else
	{
		exit(0);
	}
}
