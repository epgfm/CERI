# include "player.h"
# include "misc.h"
# include "client-jeu.h"
# include <unistd.h>

/**
 * \file    player.cpp
 * \brief   Implementation of "Player" class methods.
 * \author  Etienne Papegnies
 * \version 0.9
 * \date    June 4, 2012
 * \section DESCRIPTION
 *
 *  PROGRAMMING ASSIGNMENT
 *    AVIGNON UNIVERSITY
 *         L2 - TD3
 *
 * \section IMPLEMENTS
 *
 *  -  Player::Player()
 *  -  void Player::play(Othello & game)
 *  -  void Player::broadCast(int messageType, char * message)
 *  -  Player::~Player()
 *
 */


/**
 * \brief Static Player class variable initialization.
 *
 * Initialize static variable of the Player class that keeps track of a
 *  previously existing instance of the class.
 *
 */
int Player::nPlayers = 0;
ClientJeu * Player::networkPipe = NULL;



/**
 * \brief Object constructor
 *
 * Initialize object from user input. The only parameter for which the user is
 * prompted is the type of player. The color parameter is assigned depending
 * on whether or not this object is the first to be created.
 *
 */
Player::Player() {
    if (nPlayers == 0) {
        std::cout << 
            "Legal types:    'H' - Human"
                      "\n\t\t'B' - RoBot"
                      "\n\t\t'R' - Remote (Somewhat running)\n" ;
        std::cout << "Input [ BLACK ] player type: " ;
        color = 'O';
    }
    else {
        std::cout << "Input [ WHITE ] player type: " ;
        color = 'X';
    }

    type = 0;
    while ((type != 'H') && (type != 'B') && (type != 'R'))
        std::cin >> type;
    std::cin.ignore();

    if (type == 'R') {
        networkPipe = new ClientJeu("harta.wxcvbn.org", 12345, "ouroumov");
        if (networkPipe != NULL)
            (*networkPipe).info_client();
    }

    ++nPlayers;
}



/**
 * \brief Play a move for a player.
 *
 * Depending on the type of user, that can mean either:
 * 'H' - Prompting the user to enter the coordinates through stdin.
 * 'B' - Running the selection algorithm to compute the best move.
 * 'R' - Listening to the socket for the remote player to send his move.
 *
 */
void Player::play(Othello & game) {
    int x = 0, y = 0;
    switch (type) {

        case 'H' :

            char buffer[10];
            int inputType;
            // Because input from an human has a great chance at being flawed,
            //  let's place the input sequence in a while loop so that the
            //  stupid human can fail as much as he like.
            while (true) {

                std::cout << "Please input next move: " ;
                std::cin.getline(buffer, 10);
                inputType = validInput(buffer);

                // Input is of the form "PLAY XX" : Play the move.
                if (inputType == 1) {
                    std::cout << "Matching type 1" << std::endl ;
                    x = buffer[5] - 'A';
                    y = buffer[6] - '1';
                    if (game.isLegalMove(y, x, color)) {
                        std::cout << std::endl ;
                        game.play(y, x, color);
                        break;
                    }
                    else {
                        std::cout << "ERROR --> Illegal move." << std::endl ;
                    }
                }

                // Input is of the form "XX" : Play the move.
                if (inputType == 2) {
                    std::cout << "Matching type 2" << std::endl ;
                    x = buffer[0] - 'A';
                    y = buffer[1] - '1';
                    if (game.isLegalMove(y, x, color)) {
                        std::cout << std::endl ;
                        game.play(y, x, color);
                        break;
                    }
                    else {
                        std::cout << "ERROR --> Illegal move." << std::endl ;
                    }
                }

                // Input is of the form "PASS": 
                else if (inputType == -1)
                    break;

                // If input has an illegal form: Go back into the loop.
                std::cout << "ERROR --> Illegal move, please retry.\n" ;
            }

            if (networkPipe != NULL) {
                broadCast(inputType, buffer);
                // Discards the OK reply
                string dump;
                (*networkPipe).lis(dump);
                cout << dump << endl ;
            }

            break;

        case 'B' :
            if (game.selectMove(y, x, color)) {
                game.play(y, x, color);
                std::cout << "PLAY " << (char)(x+'A')
                                     << (char)(y+'1') << (char)0 << std::endl ;
                if (networkPipe != NULL) {
                    char message[3];
                    message[0] = (x+'A');
                    message[1] = (y+'1');
                    message[2] = 0;
                    broadCast(2, message);
                    cout << "-- > Outbound message: " << message << endl;
                    // Discards the OK reply
                    string dump;
                    (*networkPipe).lis(dump);
                    cout << dump << endl ;
                }
            }
            else { 
                std::cout << "PASS" << std::endl ;
                if (networkPipe != NULL) {
                    broadCast(-1);
                    // Discards the OK reply
                    string dump;
                    (*networkPipe).lis(dump);
                    cout << dump << endl ;
                }
            }
            break;

        case 'R' : // To implement.
            while (nPlayers != 2) {
                sleep(1);
            }
            if (networkPipe != NULL) {
                // Get the message from the socket, convert and validate it.
                string msg;
                (*networkPipe).lis(msg);
                cout << "<-- Inbound message: " << msg << endl ;
                char message[1024];
                msg.copy(message, 10, 0);
                message[9] = 0;
                inputType = validRemoteInput(message);
                // Process the message according to it's type.
                if (inputType == 1) {
                    int y = message[0] - '1';
                    int x = message[1] - 'A';
                    cout << "Input type matched." << y << "," << x << endl ;
                    if (game.isLegalMove(y, x, color))
                        game.play(y, x, color);
                    else {
                        cerr << "Error: Illegal remote move." << endl ;
                        delete networkPipe;
                    }
                }
                else if (inputType != -1) {
                    cerr << "Error: Illegal remote input." << endl ;
                    delete networkPipe;
                }
            }
            break;

    }

}



/**
 * \brief   Broadcast method.
 *
 * Broadcast a message over a socket if such a socket is active.
 * Converted messages can be of types "PLAY XX" or "XX", any other message
 * is converted to "PASSE".
 *
 */
void Player::broadCast(int messageType, char * message) {
    if (messageType == 1) {
        message[0] = message[6];
        message[1] = message[5];
        message[2] = 0;
        string msg(message);
        (*networkPipe).ecris(msg);
    }
    else if (messageType == 2) {
        message[2] = message[0];
        message[0] = message[1];
        message[1] = message[2];
        message[2] = 0;
        string msg(message);
        (*networkPipe).ecris(msg);
    }
    else {
        string msg("PASSE");
        (*networkPipe).ecris(msg);
    }
}



/**
 * \brief Player destructor.
 *
 * Will be usefull for stuff like closing the sockets or writing the scores at
 * the end of a game.
 * [edit] I knew it! Here it is, closing the socket.
 *
 */
Player::~Player() {
    if (networkPipe != NULL) {
        delete networkPipe;
        std::cout << "Remote player disconected." << std::endl ;
    }
}


