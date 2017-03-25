// DNS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <conio.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

int _tmain(int argc, _TCHAR* argv[])
{
	// Khoi tao WinSock
	WSADATA	wsaData;
	WORD	wVersion = MAKEWORD(2,2);
	int		ret;
	ret = WSAStartup(wVersion,&wsaData);

	// Dien dia chi IP 192.168.0.1:80
	SOCKADDR_IN	addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("192.168.0.1");
	addr.sin_port = htons(80);

	// Phan giai ten mien www.hust.edu.vn:http
	addrinfo *	pList,*pHead;
	SOCKADDR_IN	result;

	char	tenmien[1024];
	printf("Nhao vao mot ten mien:");
	scanf("%s",tenmien);
	ret = getaddrinfo(tenmien,"8888",
		0,&pList);
	if (ret==0)	// Thanh cong
	{
		pHead = pList;
		while (pList!=0)
		{
			memcpy(&result,pList->ai_addr,
			pList->ai_addrlen);
			printf("Dia chi IP:Port la %s:%d\n",
			inet_ntoa(result.sin_addr),
			ntohs(result.sin_port));
			pList=pList->ai_next;
		}
		freeaddrinfo(pHead);
	}
	else
		printf("Loi:%d",ret);
	getch();
	WSACleanup();
	return 0;
}

