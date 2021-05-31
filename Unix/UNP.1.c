#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
	pid_t cpid;
	char *temp[1];
	if (argc == 3)
	{
		if (argv[1] == "cat")
		{
			cpid = fork();
			if (cpid == -1) //Creat Error
			{
				exit(0);
			}
			else if (cpid == 0) //Creat Child
			{
				memset(temp, '\0', sizeof(temp));
				temp[0] = argv[2];
				if (execvp("cat", argv) < 0)
				{
					perror("Error");
					printf("Child done\n");
					exit(0);
				}
			}
			else //Creat Father
			{
				wait(&cpid);
				printf("father done\n");
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
