//套接字
#include <stdio.h>
#include <sys/socket.h>
/*
int socket(int domain, int type, int protocol)
声明一个套接字
domain:指明网络层协议 AF_UNIX(UNIX预套接字协议),AF_INET(IPV4协议)
type:指明运输层协议 SOCK_STREAM(TCP协议),SOCK_DGRAM(UDP协议)
protocol:为0
第一次被调用时返回描述符为主动套接字，用来传送数据(对客户端来说)，接受请求(监听套接字，对服务器来说)
*/
/*
int bind(int scoket_fd, const struct sockaddr *sa, socklen_t sa_len)
将套接字描述符和套接字地址绑定
*/