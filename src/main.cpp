#include "interfaces.h"


int main()
{
    //for random numbers
    srand((unsigned) time(NULL));

    //start game
    Game game1(800, 600);
    game1.run();
  
    return 0;
}
