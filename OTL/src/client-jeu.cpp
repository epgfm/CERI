#include "client-jeu.h"

ClientJeu::ClientJeu(string ns, int port, string nc) {
	CRLF = "\015\012";

	if (port == 0) { 
        cout << "Server port: "; cin >> port_serveur;
    }
	else
        port_serveur = port;

	if (ns.compare("") == 0) {
        cout << "Server Name: "; cin >> nom_serveur;
    }
	else
		nom_serveur = ns;

	if (nc.compare("") == 0) {
		cout << "Client Name: "; cin >> nom_client;
	}
	else
		nom_client = nc;

	if ((sock_client = socket( AF_INET, SOCK_STREAM, 0 )) < 0) {
		perror("Socket problem: "); exit(__LINE__);
	}

	sockaddr_serveur.sin_family = AF_INET;

	if ((serveur = gethostbyname(nom_serveur.c_str())) == (struct hostent *)NULL) {
		perror("Probleme avec gethostbyname "); exit(__LINE__);
	}

	bcopy((char *) serveur -> h_addr, (char *)&sockaddr_serveur.sin_addr, serveur -> h_length);

	sockaddr_serveur.sin_port = htons(port_serveur);

	if ( connect(sock_client, (struct sockaddr *) &sockaddr_serveur, sizeof sockaddr_serveur ) < 0 ) {
		perror("Probleme avec connect "); exit(__LINE__);
	}

	lis(message);
	ecris(nom_client);
	
	lis(couleur);

	if (couleur.compare(0, 4, "NOIR") == 0)
		position = 0;
	else
		position = 1;

	lis(nom_adversaire);

}

ClientJeu::~ClientJeu() {
	shutdown(sock_client,SHUT_RDWR);
	close(sock_client);
}

void ClientJeu::info_client() {
	cout << "Je suis : " << nom_client << endl;
	cout << "Mon adversaire est : " << nom_adversaire << endl;
	cout << "Je joue : " << couleur << endl;
}

ssize_t ClientJeu::ecris(string message) {
  ssize_t w;
	
	message += CRLF;
  if ( 0 > (w = write(sock_client,message.c_str(),message.size())) )
    cout << "Fin premature du client" << endl; 
  return w;
}

ssize_t ClientJeu::lis(string & message) {
  ssize_t w;
  char chaine[1024];

  bzero(chaine,1024);
  if ( 0 > (w = read(sock_client,chaine,1023)) )
    cout << "Fin premature du client" << endl;
  message.assign(chaine,w - 2);
// Pour voir les messages
//  cout << "lis " << w << '<' << chaine << '>' << endl;
  return w;
}

void ClientJeu::discute() {
	if (position == 0) {
		while (true) {
          do {
            cout << "Message a envoyer : ";
            cin >> message;
            ecris(message);
            lis(message);
          } while (message.compare(0,5,"PASOK") == 0);
			if (message.compare(0,3,"FIN") == 0)
				break;
			lis(message);
			cout << "Message recu : " << message << endl;
			if (message.compare(0,3,"FIN") == 0)
				break;
		}
	}
	else {
		while (true) {
			cout << "Attente" << endl;
			lis(message);
			cout << "Message recu : " << message << endl;
			if (message.compare(0,3,"FIN") == 0)
				break;
          do {
            cout << "Message a envoyer : ";
            cin >> message;
            ecris(message);
            lis(message);
          } while (message.compare(0,5,"PASOK") == 0);
			if (message.compare(0,3,"FIN") == 0)
				break;
		}
	}
	cout << "Fin de partie" << endl;
	cout << "resultat : " << message.substr(3,5) << endl;
}
