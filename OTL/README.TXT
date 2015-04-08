                            [Othello game program.]
*******************************************************************************

To compile and execute: 
    * cd for the Makefile's one.
    * Type "make"
    * Type "./main"

If you wish to play against the 'IA' input the init sequence:
    "H" then "B" to play as the BLACK player.
    "B" then "H" to play as the WHITE player.

If you whish to use the GUI and not the console mode:
    Type ./gui.tcl

   For a desciption of the sources layout jump to the end of this document.
*******************************************************************************

Primary focus was on restricting the number of walks of the game environment
necessary at each level of the game.

The program feature an "AI" that uses the standard fail-hard alpha-beta pruning
algorithm enhanced with move ordering to compute the minimax value for each
possible move available at a given point in the game.

The program is divided into modules grouping routines and functions of similar
purposes.

Each source file begins with a summary of the implemented methods.

The cornerstone of the concept used here is the Stats module and the associated
structure PlayerStats.

Because I wanted to achieve a single-pass information mining capability I 
needed a structure to store every information obtained during that one pass so
that they could be reused at will afterwards.
The PlayerStats structure stores those informations on a given player:

    * It's ID
    * The number of discs he owns
    * The number of corners he conquered.
    * The number of legal moves available to him
    * Every ones of those moves stored in a FILO structure.

Associated with that structure are the classic push/pop methods needed to
operate the stack.

Three main methods are relying on that structure:

 - The getGameState function does the actual walk of the grid while filling the
two structures passed by reference and as a side effect it returns a boolean
value saying if the game is over.

 - The evaluation function, core of the ia module analyzes the information
contained in the two structures passed as parameters and yield a note for the
described state of the game as a result.

 - The orderStack routine reorganise the stack of moves so that the best ones
will be poped out first.


                                   [MODULES]
*******************************************************************************

othello.cpp : othello.h

    Implementation of every game-specific functionnalities. 
        * Constructors and Destructors.
        * Display of the grid.
        * Legality of a move.
        * Mechanism to play a move.

stats.cpp : stats.h

    Implementation of the PlayerStats structure and the attached methods.
    Implementation of the othello class methods that rely on that structure.

ia.cpp : othello.h

    Implementation of ia-related methods:
        * Evaluation function.
        * Minimax function.
        * Selection function (Initial minimax call)

player.cpp : player.h misc.h

    Implementation of the player class. Handles the three type of players:
        * Human (Local)
        * RoBoT (Local)
        * Remote (Someone connected over a socket.)

misc.cpp : misc.h

    Various stuff used inside the player module.

