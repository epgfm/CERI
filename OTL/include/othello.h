# ifndef _OTHELLO_H_
# define _OTHELLO_H_

/**
 * \file    Othello.h
 * \brief   Declaration of "Othello" class & methods.
 * \author  Etienne Papegnies
 * \version 0.9
 * \date    May 6, 2012
 *
 * \section DESCRIPTION
 *
 *  PROGRAMMING ASSIGNMENT
 *    AVIGNON UNIVERSITY
 *    PAPEGNIES ETIENNE
 *        L2 - TD3
 */

# include <iostream>

# include "stats.h"

# define DEFAULT_BOARD_SIZE (8)
# define DEFAULT_DEPTH_LEVEL (4)

class Othello {

    public:

        /* Othello.cpp */
        Othello(int = DEFAULT_BOARD_SIZE);
        void display();
        void rawDisplay();
        bool isLegalMove(int & y, int & x, const char player);
        void play(int & y, int & x, const char player);

        /* stats.cpp */
        bool getGameState(PlayerStats & Player, PlayerStats & Enemy);

        /* ia.cpp */
        bool selectMove(int & y, int & x, char & player);

    private:

        int evaluates(PlayerStats & Player, PlayerStats & Enemy);
        int ab(char & player, int alpha, int beta, char depth);
        void orderStack(PlayerStats & player);

        /* Othello.cpp */
        char ** arena;
        int arenaSize;

        Othello(const Othello & source);

    public:

       ~Othello();

};



# endif // _Othello_H_


