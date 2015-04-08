# include "othello.h"
# include "player.h"


/**
 * \file    main.cpp
 * \brief   Test program for the "othello" game class.
 * \author  Etienne Papegnies
 * \version 0.9
 * \date    May 6, 2012
 * \section DESCRIPTION
 *
 *  PROGRAMMING ASSIGNMENT
 *    AVIGNON UNIVERSITY
 *         L2 - TD3
 */

using namespace std;

int main(int argc, char ** argv)
{

    Othello game;
    PlayerStats Black, White;

    Player black, white;

    White.id = 'X'; Black.id = 'O';

    std::cout << " -- \t GAME START \t -- " << std::endl ;

    bool isWhiteTurn = false;
    bool gameOver = false;
    while (gameOver == false) {

        if (argc == 1)
            game.display();
        else
            game.rawDisplay();


        if (isWhiteTurn)
            white.play(game);
        else
            black.play(game);

        gameOver = game.getGameState(White, Black);

        isWhiteTurn = !isWhiteTurn;

    }

    if (argc == 1)
        game.display();
    else
        game.rawDisplay();

    if (White.numberOfDiscs > Black.numberOfDiscs)
        std::cout << " -- \t WHITE WINS \t -- " << std::endl ;
    else if (White.numberOfDiscs < Black.numberOfDiscs)
        std::cout << " -- \t BLACK WINS \t -- " << std::endl ;
    else
        std::cout << " -- \t    DRAW    \t -- " << std::endl ;
    std::cout << " -- \t GAME  OVER \t -- " << std::endl;

    return 0;

}

