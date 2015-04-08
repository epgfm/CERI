# include "othello.h"

/**
 * \file    Othello.cpp
 * \brief   Implementation of "Othello" class object-specific methods.
 * \author  Etienne Papegnies
 * \version 0.9
 * \date    May 6, 2012
 * \section DESCRIPTION
 *
 *  PROGRAMMING ASSIGNMENT 
 *    AVIGNON UNIVERSITY   
 *         L2 - TD3
 *      
 * \section IMPLEMENTS
 *
 *  -  Othello::Othello(int arenaSize_)
 *  -  Othello::Othello(Othello & source)
 *  - ~Othello()
 *  -  void Othello::display()
 *  -  bool Othello::isLegalMove(int y, int x, const char player)
 *  -  void Othello::play(int & y, int & x, char player)
 *
 */


/**
 * \brief   Object constructor.
 *
 * Allocates memory for the object and initialize private data.
 *
 */
Othello::Othello(int arenaSize_) {
    arenaSize = arenaSize_;
    try {

        arena = new char*[arenaSize];
        for (int i = 0 ; i < arenaSize ; ++i)
            arena[i] = new char[arenaSize];

        for (int x = arenaSize-1 ; x >= 0 ; --x)        // This is so that
            for (int y = arenaSize-1 ; y >= 0 ; --y)    //  Valgrind doesn't
                arena[y][x] = 0;                        //  yell at me.

        arena[3][3] = 'X'; arena[3][4] = 'O';
        arena[4][3] = 'O'; arena[4][4] = 'X';

    } catch (...) { std::cerr << "Memory allocation raised." << std::endl; }
}



/**
 * \brief   Copy-Constructor.
 *
 * Create a new Othello class object that's a clone of the Othello passed as the
 * parameter. (ie: It copies both the structure and it's current state.)
 *
 */
Othello::Othello(const Othello & source) {

    arenaSize = source.arenaSize;

    // Allocates.
    try {
        arena = new char*[arenaSize];
        for (int i = 0 ; i < arenaSize ; ++i)
            arena[i] = new char[arenaSize];
    }
    catch (...) { 
        std::cerr << "Memory allocation raised." << std::endl;
        return;        
    }

    // Clone.
    for (int x = 0 ; x < arenaSize ; ++x)
        for (int y = 0 ; y < arenaSize ; ++y)
            arena[y][x] = source.arena[y][x];

}



/**
 * \brief   Object destructor.
 *
 * Releases allocated memory space.
 *
 */
Othello::~Othello() { 
    for (int y = arenaSize - 1 ; y >= 0 ; --y)
        delete [] arena[y];
    delete [] arena;
}



/**
 * \brief   Display routine.
 *
 * Displays the Othello arena in it's current state.
 *
 */
void Othello::display() {
    std::cout <<           "    A B C D E F G H    "        << std::endl ;
    std::cout << "\033[32;1m  * * * * * * * * * *  \033[0m" << std::endl ;
    for (int y = 0 ; y < arenaSize ; ++y) {
        std::cout << y+1 << "\033[32;1m"<< " *" <<"\033[0m" ;
        for (int x = 0 ; x < arenaSize ; ++x) {
            switch (arena[y][x]) {
                case  0  :
                    std::cout << "  " ;
                    break;
                case 'X' :
                    std::cout << "\033[37;1m" << " \u2B24" << "\033[0m" ;
                    break;
                case 'O' :
                    std::cout << "\033[30;1m" << " \u2B24" << "\033[0m" ;
                    break;
            }
        }
        std::cout <<"\033[32;1m"<< " *" <<"\033[0m"<< std::endl ;
    }
    std::cout << "\033[32;1m  * * * * * * * * * *  \033[0m" << std::endl;
}



/**
 * \brief Raw display routine
 *
 * This is a variant of the display routine used to provide an output that's
 * easier to analyse from a secondary program. That way the Tcl script in charge
 * of providing the GUI interface can quickly detect / apply changes to the
 * game arena with minimal effort. (A simple switch statement.)
 *
 */
void Othello::rawDisplay() {
    for (int y = 0 ; y < arenaSize ; ++y) {
        std::cout << "BOARD " << y << " ";
        for (int x = 0 ; x < arenaSize ; ++x) {
            switch (arena[y][x]) {
                case  0  :
                    std::cout << "E " ;
                    break;
                case 'X' :
                    std::cout << "X " ;
                    break;
                case 'O' :
                    std::cout << "O " ;
                    break;
            }
        }
        std::cout << std::endl ;
    }
}



/**
 * \brief   Legality check.
 *
 * Checks if placing a disc on column y, row x is a legal move for "player".
 * For a move to be legal there must be a full line of enemy discs between
 * the starting point and a friendly disc.
 *
 */
bool Othello::isLegalMove(int & y, int & x, const char player) {
    if (arena[y][x] != 0) return false;
    char enemy;
    
    player == 'X' ? enemy = 'O' : enemy = 'X';

    int i, j;

    /* Check East. */
    if ((x+1 < arenaSize) && (arena[y][x+1] == enemy))
        for (i = y, j = x+1 ; j < arenaSize ; ++j)
            if (arena[i][j] != enemy)
                if (arena[i][j] == player)
                    return true;
                else
                    break;
    /* Check West. */
    if ((x-1 >= 0) && (arena[y][x-1] == enemy))
        for (i = y, j = x-1 ; j >= 0 ; --j)
            if (arena[i][j] != enemy)
                if (arena[i][j] == player)
                    return true;
                else
                    break;
    /* Check North. */
    if ((y-1 >= 0) && (arena[y-1][x] == enemy))
        for (i = y-1, j = x ; i >= 0 ; --i)
            if (arena[i][j] != enemy)
                if (arena[i][j] == player)
                    return true;
                else
                    break;
    /* Check South. */
    if ((y+1 < arenaSize) && (arena[y+1][x] == enemy))
        for (i = y+1, j = x ; i < arenaSize ; ++i)
            if (arena[i][j] != enemy)
                if (arena[i][j] == player)
                    return true;
                else
                    break;


    /* Check N-E. */
    if ((y-1 >= 0) && (x+1 < arenaSize) && (arena[y-1][x+1] == enemy))
        for (i = y-1, j = x+1 ; i >= 0 && j < arenaSize ; --i, ++j)
            if (arena[i][j] != enemy)
                if (arena[i][j] == player)
                    return true;
                else
                    break;
    /* Check S-E. */
    if ((y+1 < arenaSize) && (x+1 < arenaSize) && (arena[y+1][x+1] == enemy))
        for (i = y+1, j = x+1 ; i < arenaSize && j < arenaSize ; ++i, ++j)
            if (arena[i][j] != enemy)
                if (arena[i][j] == player)
                    return true;
                else
                    break;
    /* Check S-W. */
    if ((y+1 < arenaSize) && (x-1 >= 0) && (arena[y+1][x-1] == enemy))
        for (i = y+1, j = x-1 ; i < arenaSize && j >= 0 ; ++i, --j)
            if (arena[i][j] != enemy)
                if (arena[i][j] == player)
                    return true;
                else
                    break;
    /* Check N-W. */
    if ((y-1 >= 0) && (x-1 >= 0) && (arena[y-1][x-1] == enemy))
        for (i = y-1, j = x-1 ; i >= 0 && j >= 0 ; --i, --j)
            if (arena[i][j] != enemy)
                if (arena[i][j] == player)
                    return true;
                else
                    break;

    return false;
}



/**
 * \brief   Play a move.
 *
 * Place one of player's disc at column y, row x.
 * Flip enemy discs accordingly.
 *
 */
void Othello::play(int & y, int & x, char player) {
    // Place the disc.
    arena[y][x] = player;
    // The fliping part will be a savant rip-off of the isLegalMove routine.
    // The thing is, the algorithm is basically the same except once it is
    //  established that the mode is, indeed, legal, it proceeds onto flipping
    //  the affected discs while backtracking.

    char enemy = 'O';
    if (player == 'O') enemy = 'X';
    int i, j;
   
    /* Go East. */
    if ((x+1 < arenaSize) && (arena[y][x+1] == enemy))
        for (i = y, j = x+1 ; j < arenaSize ; ++j)
            if (arena[i][j] != enemy) {
                if (arena[i][j] == player) {
                    for (--j ; j > x ; --j)
                        arena[i][j] = player;
                }
                break;
            }
    /* Go South. */
    if ((y+1 < arenaSize) && (arena[y+1][x] == enemy))
        for (i = y+1, j = x ; i < arenaSize ; ++i)
            if (arena[i][j] != enemy) {
                if (arena[i][j] == player) {
                    for (--i ; i > y ; --i)
                        arena[i][j] = player;
                }
                break;
            }
    /* Go West. */
    if ((x-1 >= 0) && (arena[y][x-1] == enemy))
        for (i = y, j = x-1 ; j >= 0 ; --j)
            if (arena[i][j] != enemy) {
                if (arena[i][j] == player) {
                    for (++j ; j < x ; ++j)
                        arena[i][j] = player;
                }
                break;
            }
    /* Go North. */
    if ((y-1 >= 0) && (arena[y-1][x] == enemy))
        for (i = y-1, j = x ; i >= 0 ; --i)
            if (arena[i][j] != enemy) {
                if (arena[i][j] == player) {
                    for (++i ; i < y ; ++i)
                        arena[i][j] = player;
                }
                break;
            }


    /* Go N-E. */
    if ((y-1 >= 0) && (x+1 < arenaSize) && (arena[y-1][x+1] == enemy))
        for (i = y-1, j = x+1 ; i >= 0 && j < arenaSize ; --i, ++j)
            if (arena[i][j] != enemy) {
                if (arena[i][j] == player) {
                    for (++i, --j ; i < y && j > x ; ++i, --j)
                        arena[i][j] = player;
                }
                break;
            }
    /* Go S-E. */
    if ((y+1 < arenaSize) && (x+1 >= 0) && (arena[y+1][x+1] == enemy))
        for (i = y+1, j = x+1 ; i < arenaSize && j < arenaSize ; ++i, ++j)
            if (arena[i][j] != enemy) {
                if (arena[i][j] == player) {
                    for (--i, --j ; i > y && j > x ; --i, --j)
                        arena[i][j] = player;
                }
                break;
            }

    /* Go S-W. */
    if ((y+1 < arenaSize) && (x-1 >= 0) && (arena[y+1][x-1] == enemy))
        for (i = y+1, j = x-1 ; i < arenaSize && j >= 0 ; ++i, --j)
            if (arena[i][j] != enemy) {
                if (arena[i][j] == player) {
                    for (--i, ++j ; i > y && j < x ; --i, ++j)
                        arena[i][j] = player;
                }
                break;
            }
    /* Go N-W. */
    if ((y-1 >= 0) && (x-1 >= 0) && (arena[y-1][x-1] == enemy))
        for (i = y-1, j = x-1 ; i >= 0 && j >= 0 ; --i, --j)
            if (arena[i][j] != enemy) {
                if (arena[i][j] == player) {
                    for (++i, ++j ; i < y && j < x ; ++i, ++j)
                        arena[i][j] = player;
                }
                break;
            }
}

