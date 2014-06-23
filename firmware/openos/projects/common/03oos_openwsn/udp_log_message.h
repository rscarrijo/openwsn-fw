#ifndef __UDP_LOG_MESSAGE_H
#define __UDP_LOG_MESSAGE_H

#ifdef _MSC_VER
	//#include "stdio.h"
	#include <winsock2.h>
	#pragma comment(lib,"ws2_32.lib") //Winsock Library

	#define SERVER_IP "127.0.0.1"	//ip address of udp server
	#define BUFLEN 512				//Max length of buffer
	#define SERVER_PORT 8888		//The port on which to listen for incoming data

	struct sockaddr_in si_other;
	int s, slen=sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];
	WSADATA wsa;

	void initialize_udp_log_message()
	{
		//printf("\nInitialising Winsock...");

		if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
		{
			//printf("Failed. Error Code : %d",WSAGetLastError());
			//exit(EXIT_FAILURE);
		}

		//printf("Initialised.\n");
     
		//create socket
		if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
		{
			//printf("socket() failed with error code : %d" , WSAGetLastError());
		   // exit(EXIT_FAILURE);
		}
     
		//setup address structure
		memset((char *) &si_other, 0, sizeof(si_other));
		si_other.sin_family = AF_INET;
		si_other.sin_port = htons(SERVER_PORT);
		si_other.sin_addr.S_un.S_addr = inet_addr(SERVER_IP);
	}

	void udp_log_message(const char *message)
	{
		//send the message
		if (sendto(s, message, strlen(message) , 0 , (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
		{
			//printf("sendto() failed with error code : %d" , WSAGetLastError());
			//exit(EXIT_FAILURE);
		}
	}

	void terminate_udp_log_message()
	{
		closesocket(s);
		WSACleanup();
	}
#else /* GCC compiler */

	//#include <sys/types.h> 
	//#include <sys/socket.h> 
	//#include <netinet/in.h> 
	//#include <arpa/inet.h> 
	//#include <netdb.h> 
	//#include <stdio.h> 
	//#include <stdlib.h> 

	//#include <arpa/inet.h>  
	//#include <assert.h>  
	//#include <errno.h>  
	//#include <signal.h>  
	//#include <string.h>  
	//#include <sys/wait.h>  
	//#include <netdb.h>  
	//#include <unistd.h>  

	//#define SERVER_IP "10.0.1.111"
	//#define SERVER_PORT 8919

	//int sock, length, n; 
	//struct sockaddr_in server, from; 
	//struct hostent *hp; 
	//char buffer[512]; 

	// TODO
	void initialize_udp_log_message()
	{
		//sock= socket(AF_INET, SOCK_DGRAM, 0); 
		////if (sock < 0) error("socket"); 

		//server.sin_family = AF_INET; 
		//hp = gethostbyname(SERVER_IP); 
		////if (hp==0) error("Unknown host"); 

		//bcopy((char *)hp->h_addr,  
		//	(char *)&server.sin_addr, 
		//		hp->h_length); 
		//server.sin_port = htons(SERVER_PORT); 
		//length=sizeof(struct sockaddr_in); 		
	}

	void udp_log_message(const char *message)
	{
		//n=sendto(sock,message, 512,0,&server,length); 	
	}

	void terminate_udp_log_message()
	{
	
	}

#endif

#endif
