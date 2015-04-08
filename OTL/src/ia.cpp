# include "othello.h"

/**
 * \file    ia.cpp
 * \brief   Implementation of "Othello" class ia-specific methods.
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
 *  -  int Othello::evaluates(PlayerStats & Player, PlayerStats & Enemy)
 *  -  int Othello::ab(char & player, int alpha, int beta, char depth)
 *  -  void Othello::selectMove(int & y, int & x, const char player)
 *
 */

/**
 * \brief  Evaluation function.
 * 
 * Weigh the score attached to the current game state for player.
 * This is a critical feature of the AI because a good evaluation function can 
 * mean the game. There are several points to consider, we will start with
 * only a few of them for testing purposes. We'll take into account:
 *
 * - The number of discs owned. (Secondary.)
 *   (+ 10   p Each)
 * - The number of legal moves for the player at that point in the game.
 *   (+ 10000 p Each)
 * - Whether the player owns some corners or not.
 *   (+ 10000000 p Each)
 * - Whether player has won the game. (or not)
 *   (+ infinity) (or well, - infinity)
 *
 * I believe computing the difference between the two players provides better
 * results, because that way a move can be slightly bad (ie: -1080) instead
 * of either good or full blown disastrous (-inf) as it was until now.
 * Anyway the Bot Vs Bot game result seems to show that it is the case.
 *
 */
int Othello::evaluates(PlayerStats & Player, PlayerStats & Enemy) {
    int score = 0;

    // Step 1 : Each disc owned is worth some scraps.
    score += (Player.numberOfDiscs - Enemy.numberOfDiscs) * 10;

    // Step 2 : Each available legal move is worth a lot.
    score += (Player.numberOfLegalMoves - Enemy.numberOfLegalMoves) * 10000;

    // Step 3 : Each corner owned is worth it's weight in gold.
    score += (Player.numberOfCorners - Enemy.numberOfCorners) * 10000000;

    // Step 4 : A game won is worth all the gold in the world.
    if (Player.numberOfLegalMoves == 0 && Enemy.numberOfLegalMoves == 0)
        // EndGame reached.
        if (Player.numberOfDiscs > Enemy.numberOfDiscs) {
            // Game won.
            score = 1;                      // Score is like : 00001
            score <<=  sizeof(int)*8 - 1;   // Score is like : 10000 ( min )
            score = ~score;                 // Score is like : 01111 ( max )
        }
        else {
            // Game not won.
            score = 1;
            score <<=  sizeof(int)*8 - 1;
        }
    // Step 5 : Completion
    return score;
}



/**
 * \brief Decision function
 *
 * Minimax decision function. Evaluates a state for a given player.
 * Uses the standard fail-hard alpha-beta pruning enhanced with move ordering.
 * The ordering process is performed up to depth == five.
 * This "sweet spot" was determined empirically. (Trial & Error)
 *
 */
int Othello::ab(char & player, int alpha, int beta, char depth) {
    // If depth is low enough, returns the result of the evaluation function.
    // A low enough depth can also be an end-game state. (Leaf node)
    char enemy;
    player == 'X' ? enemy = 'O' : enemy = 'X';

    PlayerStats Player(player), Enemy(enemy);
    bool gameOver = getGameState(Player, Enemy);

    if (gameOver || depth == 7)
        return evaluates(Player, Enemy);
    else {
        // Check depth to determines if min node or max node.
        // We assume root node has depth 0, so nodes with depth that are odd
        //  correspond to min nodes.
        if (depth & 1) {
            //  [MIN] Node. Get the min of the recursives calls on each child.
            int candidate;
            if (Enemy.numberOfLegalMoves == 0) {
                candidate = ab(player, alpha, beta, depth + 1);
                if (candidate < beta) beta = candidate;
            }
            else {
                int x, y;
                // So it's time to order the moveStack.
                if (depth < 5)
                    orderStack(Enemy);
                // For each legal move...
                while (Enemy.numberOfLegalMoves > 0) {
                    Enemy.popMove(y, x);
                    // Recursive call and check if it's a new min.
                    Othello * Clone = new Othello(*this);
                    (*Clone).play(y, x, enemy);
                    candidate = (*Clone).ab(player, alpha, beta, depth + 1);
                    delete Clone; // Release memory ASAP.
                    if (candidate < beta) beta = candidate;
                    if (beta <= alpha) break;
                }
            }
            return beta;
        }
        else {
            // [MAX] Node. Get the max of the recursives calls on each child.
            int candidate;
            if (Player.numberOfLegalMoves == 0) {
                candidate = ab(player, alpha, beta, depth + 1);
                if (alpha < candidate) alpha = candidate;
            }
            else {
                int x, y;
                // So it's time to order the moveStack.
                if (depth < 5)
                    orderStack(Player);
                // For each legal move...
                while (Player.numberOfLegalMoves > 0) {
                    Player.popMove(y, x);
                    // Recursive call and check if it's a new min.
                    Othello * Clone = new Othello(*this);
                    (*Clone).play(y, x, player);
                    candidate = (*Clone).ab(player, alpha, beta, depth + 1);
                    delete Clone; // Release memory ASAP.
                    if (alpha < candidate) alpha = candidate;
                    if (beta <= alpha) break;
                }
            }
            return alpha;
        }
    }
}



/**
 * \brief Select a move.
 * \return true if there is a legal move available.
 *
 * Computes the minimax value to select the best available move for a given
 * player. The coordinates for the move are stored in the arguments at calling
 * level. ( The arguments are passed by reference. )
 * Before calling the decision algorithm, the moves are evaluated on a very
 * shallow level once to decide in which order they should be analyzed.
 *
 */
bool Othello::selectMove(int & y, int & x, char & player) {
    int max = 1;
    max <<= sizeof(int)*8 - 1; // Max has now min value.
    int min = 1;
    min <<= sizeof(int)*8 - 1;
    min = ~min;                // Min has now max value.
    int candidate;
    char enemy;
    player == 'X' ? enemy = 'O' : enemy = 'X' ;
    PlayerStats Player(player), Enemy(enemy);
    getGameState(Player, Enemy);
    if (Player.numberOfLegalMoves > 0) {
        orderStack(Player); // Here the shallow evaluation is performed.
        int iy, ix;
        Player.popMove(iy, ix);
        y = iy;
        x = ix;
        Player.pushMove(iy, ix);
        while (Player.numberOfLegalMoves > 0) {
            Player.popMove(iy, ix);
            Othello * Clone = new Othello(*this);
            (*Clone).play(iy, ix, player);
            candidate = (*Clone).ab(player, max, min, 1);
            delete Clone;
            if (max < candidate) {
                max = candidate;
                y = iy;
                x = ix;
            }
        }
        return true;
    }
    return false;
}


//*/
