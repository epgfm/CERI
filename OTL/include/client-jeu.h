#ifndef _CLIENT_JEU_H_
#define _CLIENT_JEU_H_

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

class ClientJeu
{
	string CRLF;

	string nom_serveur;
	string nom_client;
	string nom_adversaire;
	string message;
	string couleur;
	int position;
	
	int port_serveur;
	int sock_client;
	struct sockaddr_in sockaddr_serveur; 
	struct hostent *serveur; 

public:

	ClientJeu(string ns, int port, string nc);
	~ClientJeu();

	ssize_t ecris(string message);
	ssize_t lis(string & message);
	void discute();
	void info_client();

};

#endif
