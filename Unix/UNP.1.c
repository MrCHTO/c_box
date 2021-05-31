#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
	pid_t cpid;
	char *temp[2];
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
				*temp[0] = *argv[1];
				*temp[1] = *argv[2];
				*temp[2] == NULL;
				execv("usr/bin/cat", temp);
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
