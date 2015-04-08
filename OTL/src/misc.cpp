# include "misc.h"

/**
 * \file    ia.cpp
 * \brief   Implementation of miscellaneous methods.
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
 *  - bool strcmp(char * s, const char * c)
 *  - int validInput(char * input)
 *  - int validInput(char * input)
 *
 */

bool strcmp(char * s, const char * c) {
    int i = 0;
    while (s[i] != 0 && c[i] != 0) {
        if (s[i] != c[i])
            return false;
        ++i;
    }
    return true;
}

int validInput(char * input) {
    if (strcmp(input, "PLAY ") && 'A' <= input[5] &&  input[5] <= 'H'
                               && '1' <= input[6] &&  input[6] <= '8')
        return 1;
    if ('A' <= input[0] &&  input[0] <= 'H' && 
        '1' <= input[1] &&  input[1] <= '8' && input[2] == 0)
        return 2;
    if (strcmp(input, "PASS"))
        return -1;
    return 0;
}

int validRemoteInput(char * input) {
    if ('A' <= input[1] &&  input[1] <= 'H' && 
        '1' <= input[0] &&  input[0] <= '8' && input[2] == 0)
        return 1;
    if (strcmp(input, "PASSE"))
        return -1;
    return 0;
}


