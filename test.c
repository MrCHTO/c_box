//client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>

#define Num 256

typedef struct sockaddr SA;

void commd_exit();
void commd_help();
void commd_ls(struct sockaddr_in, char *);
void commd_get(struct sockaddr_in, char *);
void commd_put(struct sockaddr_in, char *);

int main(int argc, char *argv[])
{
	int len;
	char command[Num];
	struct sockaddr_in addr;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(8989);
	len = sizeof(addr);

	while (1)
	{
		printf("ftp>");
		bzero(command, Num);

		if (fgets(command, Num, stdin) == NULL)
		{
			printf("Fgets error!\n");
			return -1;
		}

		command[strlen(command) - 1] = '\0';

		printf("Input Command Is [ %s ]\n", command);

		if (strncmp(command, "help", 4) == 0)
		{
			command_help();
		}
		else if (strncmp(command, "exit", 4) == 0)
		{
			command_exit();
			exit(0);
		}
		else if (strncmp(command, "ls", 2) == 0)
		{
			command_ls(addr, command);
		}
		else if (strncmp(command, "get", 3) == 0)
		{
			command_get(addr, command);
		}
		else if (strncmp(command, "put", 3) == 0)
		{
			command_put(addr, command);
		}
		else
		{
			printf("Command Is error!   Try Again!\n");
		}
	}
	return 0;
}

void command_help()
{

	printf("\n=------------------- Welcome to Use the Ftp ----------------=\n");
	printf("|                                                           |\n");
	printf("|  help : Display  All  Command  For  The  Server                |\n");
	printf("|                                                           |\n");
	printf("|   exit: Quit The Sever                                    |\n");
	printf("|                                                           |\n");
	printf("|   ls : Display All File On The Ftp Server                 |\n");
	printf("|                                                           |\n");
	printf("| get : Download FIle From The Ftp Server             |\n");
	printf("|                                                           |\n");
	printf("| put : Upload FIle To The Ftp Server                 |\n");
	printf("|                                                           |\n");
	printf("=-----------------------------------------------------------=\n");
	return;
}

void command_exit()
{
	printf("Byte!\n");
}

void command_ls(struct sockaddr_in addr, char *command)
{
	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Socket error!\n");
		exit(1);
	}

	if (connect(sockfd, (SA *)&addr, sizeof(addr)) < 0)
	{
		printf("Connect error!\n");
		exit(1);
	}

	if (write(sockfd, command, Num) < 0)
	{
		printf("Write error!\n");
		exit(1);
	}

	while (read(sockfd, command, Num) > 0)
	{
		printf(" %s ", command);
	}
	printf("\n");
	close(sockfd);
	return;
}

void command_get(struct sockaddr_in addr, char *command)
{
	int fd;
	int sockfd;
	int nbytes;
	char buffer[Num];

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Socket error!\n");
		exit(1);
	}

	if (connect(sockfd, (SA *)&addr, sizeof(addr)) < 0)
	{
		printf("Connect error!\n");
		exit(1);
	}

	if (write(sockfd, command, Num) < 0)
	{
		printf("Write error!At command_get 1\n");
		exit(1);
	}

	if (read(sockfd, buffer, Num) < 0)
	{
		printf("Read error!At command_get 1\n");
		exit(1);
	}

	if (buffer[0] == 'Num')
	{
		close(sockfd);
		printf("Can't Open The File!\n");
		return;
	}

	if ((fd = open(command + 4, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
	{
		printf("Open error!\n");
		exit(1);
	}

	while ((nbytes = read(sockfd, buffer, Num)) > 0)
	{

		if (write(fd, buffer, nbytes) < 0)
		{
			printf("Write error!At command_get 2");
		}
	}
	close(fd);
	close(sockfd);
	return;
}

void command_put(struct sockaddr_in addr, char *command)
{
	int fd;
	int sockfd;
	char buffer[Num];
	int nbytes;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Socket error!\n");
		exit(1);
	}

	if (connect(sockfd, (SA *)&addr, sizeof(addr)) < 0)
	{
		printf("Connect error!\n");
		exit(1);
	}

	if (write(sockfd, command, N) < 0)
	{
		printf("Wrtie error!At command_put 1\n");
		exit(1);
	}

	if ((fd = open(command + 4, O_RDONLY)) < 0)
	{
		printf("Open error!\n");
		exit(1);
	}

	while ((nbytes = read(fd, buffer, Num)) > 0) ////从buffer中读取nbytes字节数据并写入套接字中
	{

		if (write(sockfd, buffer, nbytes) < 0)
		{
			printf("Write error!At command_put 2");
		}
	}
	close(fd);
	close(sockfd);
	return;
}
