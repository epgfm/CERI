# ifndef _PLAYER_H_
# define _PLAYER_H_

# include "othello.h"
# include "client-jeu.h"

# include <unistd.h>

class Player {

    public:

        Player();
        void play(Othello &);

        void broadCast(int messageType, char * message = NULL);

    private:

        static int nPlayers;
        static ClientJeu * networkPipe;

        char type; // Human (H) ; (ro)Bot (B) ; Remote (R)
        char color;

    public:

       ~Player();

};



# endif // _PLAYER_H_
