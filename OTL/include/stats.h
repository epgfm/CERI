# ifndef _STATS_H_
# define _STATS_H_

struct PlayerStats {

    PlayerStats();
    PlayerStats(const char);

    char id;
    int numberOfDiscs;
    int numberOfCorners;
    int numberOfLegalMoves;

    int moveStack[128];

    void pushMove(int  y, int   x);
    void popMove(int & y, int & x);

};


# endif // _STATS_H_
