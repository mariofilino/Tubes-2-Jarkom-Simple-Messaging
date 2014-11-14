#include <iostream>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <unistd.h>
#include <cstdlib>
#include <errno.h>
#include <cstring>
#include <vector>

using namespace std;

#ifndef _SERVER_H
#define _SERVER_H

class Server{
	public: 
		Server(int portnumber);
		~Server();
		startServer(int portnumber);
		void error(const char *msg);
		
	private:
		int portnumber;
		vector<Group> listofgroup;
		vector<User> listofuser;
		typedef struct{
			string eventmessage;
			time_t time;
		} event;
		vector<event> log;
		int sockfd, newsockfd, portno;
		socklen_t clilen;
		char buffer[1024];
		struct sockaddr_in server_address, client_address;	
};

#endif