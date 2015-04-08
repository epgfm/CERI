# include "othello.h"

/**
 * \file    stats.cpp
 * \brief   Implementation of "PlayerStats" class methods and related Othello
 *           methods.
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
 *  -  PlayerStats::PlayerStats()
 *  -  PlayerStats::PlayerStats(const char id_)
 *  -  void PlayerStats::pushMove(int y, int x)
 *  -  void PlayerStats::popMove(int & y, int & x)
 *  -  void Othello::getGameState(PlayerStats & Player, PlayerStats & Enemy)
 *
 */


/**
 * \brief PlayerStats void contructor.
 *
 * Initialize the PlayerStats structure to zero values upon construction.
 *
 */
PlayerStats::PlayerStats() {
    numberOfDiscs = 0;
    numberOfLegalMoves = 0;
    numberOfCorners = 0;
}

/**
 * \brief PlayerStats contructor.
 *
 * Initialize the PlayerStats structure to zero values upon construction.
 *
 */
PlayerStats::PlayerStats(const char id_) {
    id = id_;
    numberOfDiscs = 0;
    numberOfLegalMoves = 0;
    numberOfCorners = 0;
}



/**
 * \brief Move Stack push routine.
 *
 * Push a move's coordinates onto the stack.
 *
 */
void PlayerStats::pushMove(int y, int x) {
    moveStack[numberOfLegalMoves * 2]     = y;
    moveStack[numberOfLegalMoves * 2 + 1] = x;
    ++numberOfLegalMoves;
}



/**
 * \brief Move Stack pop routine.
 *
 * Pop a move's coordinates from the stack into the values passed as
 * parameters.
 *
 */
void PlayerStats::popMove(int & y, int & x) {
    --numberOfLegalMoves;
    y = moveStack[numberOfLegalMoves * 2];
    x = moveStack[numberOfLegalMoves * 2 + 1];
}



/**
 * \brief Get game stats.
 *
 * Walk the game arena and get satistics about the current state. 
 * Those include:
 *  - Number of discs for each player.
 *  - Number of legal moves for each players.
 *  - Number of corners owned by each player.
 *
 */
bool Othello::getGameState(PlayerStats & Player, PlayerStats & Enemy) {
    // Clear the previous stats.
    Player.numberOfDiscs = 0;           Enemy.numberOfDiscs = 0;
    Player.numberOfLegalMoves = 0;      Enemy.numberOfLegalMoves = 0;
    Player.numberOfCorners = 0;         Enemy.numberOfCorners = 0;
    
    // Count the corners.
    int max = arenaSize - 1;
    if (arena[0][0] == Player.id)
        ++Player.numberOfCorners;
    else if (arena[0][0] == Enemy.id)
        ++Enemy.numberOfCorners;

    if (arena[0][max] == Player.id)
        ++Player.numberOfCorners;
    else if (arena[0][max] == Enemy.id)
        ++Enemy.numberOfCorners;

    if (arena[max][0] == Player.id)
        ++Player.numberOfCorners;
    else if (arena[max][0] == Enemy.id)
        ++Enemy.numberOfCorners;

    if (arena[max][max] == Player.id)
        ++Player.numberOfCorners;
    else if (arena[max][max] == Enemy.id)
        ++Enemy.numberOfCorners;

    // Walk the board counting other stuff.
    for (int x = max ; x >= 0 ; --x)
        for (int y = max ; y >= 0 ; --y) {
            // Count the number of discs owned by each player.
            if (arena[y][x] == Player.id)
                ++Player.numberOfDiscs;
            else if (arena[y][x] == Enemy.id)
                ++Enemy.numberOfDiscs;
            else {
                // Count the number of legal moves for each player.
                if (isLegalMove(y, x, Player.id))
                    Player.pushMove(y, x);
                if (isLegalMove(y, x, Enemy.id))
                    Enemy.pushMove(y, x);
            }
        }
    // Return true if game over.
    return Player.numberOfLegalMoves == 0 && Enemy.numberOfLegalMoves == 0;
}



void Othello::orderStack(PlayerStats & Player) {

    char player, enemy;
    // Establish who's the good guy, who's the bad guy.

    player = Player.id;
    player == 'X' ? enemy = 'O' : enemy = 'X' ;

    PlayerStats * tempPlayer, * tempEnemy;  // We'll need those later.
    int nMoves = Player.numberOfLegalMoves; // We'll need this backup later.

    // We'll need an array of noted moves. (A noted move is a set of 3 ints.)
    int ** notedMoves = new int*[nMoves + 2];
    // Let's initialize the array to NULL.
    for (int i = 0 ; i < nMoves ; ++i)
        notedMoves[i] = NULL;
    // Those will be used for temporary move storage.
    int y, x;
    int * move;
    // While there is some moves to process.
    int cursor; // This will be used to access the array of noted moves.
    /* Pop moves from the stack, note and store them in order in an array. */
    while (Player.numberOfLegalMoves > 0) {
        // Pop the move in local variables.
        Player.popMove(y, x);
        // Create a clone of the game and some structs to analyse it.
        Othello * clone = new Othello(*this);
        tempPlayer      = new PlayerStats(player);
        tempEnemy       = new PlayerStats(enemy);
        // Simulates the move, then evaluates the resulting state and store
        //  the result of the evaluation.
        (*clone).play(y, x, player);
        (*clone).getGameState(*tempPlayer, *tempEnemy);
        move = new int[3];
        move[0] = (*clone).evaluates(*tempPlayer, *tempEnemy);
        move[1] = y; // Associates the coordonates of the move with the score.
        move[2] = x; //
        // We don't need that clone and the stats anymore: Release the memory.
        delete clone;
        delete tempPlayer;
        delete tempEnemy;
        // Insert the move at it's place depending on his value.
        cursor = 0;
        while (notedMoves[cursor] != NULL && notedMoves[cursor][0] > move[0])
            ++cursor;
        // Cursor is now at the insertion point.
        int * temporary;                // Temporary pointer to do the swaps.
        temporary = notedMoves[cursor]; // backup what was there.
        notedMoves[cursor] = move;      // Insert the new move...
        ++cursor;

        // ... then proceed on shifting what's left of the array.
        while (cursor <= nMoves) {
            move = notedMoves[cursor];
            notedMoves[cursor] = temporary;
            temporary = move;
            ++cursor;
        }
    }
    /* Now every move is stored in the array, with the best moves first. */
    // Let's re-fill the stack.
    // Starting with the moves at the end. (The worst ones.)
    // That way they will be poped out last thanks to the LIFO structure.
    for (int j = nMoves-1 ; j >= 0 ; --j)
        Player.pushMove(notedMoves[j][1], notedMoves[j][2]);

    /* The stack is now ordered. Let's release the memory for the array. */
    for (int k = nMoves ; k >= 0 ; --k)
        if (notedMoves[k] != NULL)
            delete [] notedMoves[k];
    delete [] notedMoves;
}




