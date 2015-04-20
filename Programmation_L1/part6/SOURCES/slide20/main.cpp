# include "test.h"

void function(int p)
{ 
    Test t(2 * p); 
}

int main(int argc, char ** argv)
{
    Test t(1);
    for (int i = 1 ; i <= 2 ; i++)
        function(i);
    return 0;
}

