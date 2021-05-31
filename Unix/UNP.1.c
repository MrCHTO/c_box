#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
	pid_t cpid;
	char *temp[2];
	if (argc == 3)
	{
		cpid = fork();
		if (cpid == -1) //Creat Error
		{
			exit(0);
		}
		else if (cpid == 0) //Creat Child
		{
			memset(temp, '\0', sizeof(temp));
			temp[0] = argv[1];
			temp[1] = argv[2];
			if (execv("/usr/bin/cat", argv) < 0)
			{
				perror("Error");
			}
			printf("Child done");
			exit(0);
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
