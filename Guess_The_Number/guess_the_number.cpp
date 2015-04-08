# include <iostream>
# include <time.h>
# include <cstdlib>

using namespace std;

int main(int argc, char ** argv)
{

    /* If an argument was passed on the command line, set max to it's value. */

    int max;

    if (argc > 1)
        max = atoi(argv[1]); // Converts the parameter (String) to an integer.
    else
        max = 100;           // Else, default value is 100.

    /* -------- Generates a random number in the range [0 - max]. ---------- */

    srand(time(NULL));

    int hiddenNumber = rand() % (max + 1);

    /* ------------------------ Start the game. ---------------------------- */

    cout << "Guess the number! Range is [0 - " << max << "]" << endl ;

    int guess;

    while (true) {

        cout << "Input number: " ; cin >> guess;

        if (guess > hiddenNumber)
            cout << "Lower! Try again!"  << endl << endl ;
        else if (guess < hiddenNumber)
            cout << "Higher! Try again!" << endl << endl ;
        else
            break;

    }

    /* --------------- End game: Terminates the program. ------------------- */

    cout << "Found!" << endl ;

    return 0;

}
